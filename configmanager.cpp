#include "configmanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

ConfigManager& ConfigManager::instance() {
    static ConfigManager inst;
    return inst;
}

ConfigManager::ConfigManager() {
    load();
}

bool ConfigManager::load() {
    m_loaded = false;
    m_errorString = "";
    
    // Rechercher le fichier config.json dans plusieurs répertoires potentiels (application path, working path, et dossiers parents)
    QStringList potentialPaths = {
        QCoreApplication::applicationDirPath() + "/config.json",
        QCoreApplication::applicationDirPath() + "/../config.json",
        QCoreApplication::applicationDirPath() + "/../../config.json",
        QCoreApplication::applicationDirPath() + "/../../../config.json",
        QDir::current().absoluteFilePath("config.json"),
        QDir::current().absoluteFilePath("../config.json"),
        QDir::current().absoluteFilePath("../../config.json"),
        QDir::current().absoluteFilePath("../../../config.json")
    };

    QString path;
    for (const QString& p : potentialPaths) {
        if (QFile::exists(p)) {
            path = p;
            break;
        }
    }
    
    if (path.isEmpty()) {
        m_errorString = "Le fichier config.json est introuvable. Veuillez copier config.example.json sous le nom config.json dans la racine de votre projet.";
        qWarning() << "ConfigManager:" << m_errorString;
        return false;
    }
    
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        m_errorString = QString("Impossible de lire config.json (%1)").arg(file.errorString());
        qWarning() << "ConfigManager:" << m_errorString;
        return false;
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if (doc.isNull()) {
        m_errorString = QString("Format JSON invalide dans config.json : %1").arg(parseError.errorString());
        qWarning() << "ConfigManager:" << m_errorString;
        return false;
    }
    
    if (!doc.isObject()) {
        m_errorString = "Le document racine de config.json doit etre un objet.";
        qWarning() << "ConfigManager:" << m_errorString;
        return false;
    }
    
    m_configObject = doc.object();
    m_loaded = true;
    qDebug() << "ConfigManager: Fichier de configuration charge avec succes depuis" << path;
    return true;
}

bool ConfigManager::isLoaded() const {
    return m_loaded;
}

QString ConfigManager::getErrorString() const {
    return m_errorString;
}

QString ConfigManager::getValue(const QString& key, const QString& defaultValue) const {
    if (!m_loaded) {
        return defaultValue;
    }
    if (m_configObject.contains(key)) {
        // Supporter les types de valeurs chaînes de caractères
        return m_configObject.value(key).toString(defaultValue);
    }
    return defaultValue;
}
