#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>
#include <QJsonObject>

class ConfigManager {
public:
    static ConfigManager& instance();
    
    bool load();
    bool isLoaded() const;
    QString getErrorString() const;
    
    QString getValue(const QString& key, const QString& defaultValue = "") const;
    
private:
    ConfigManager();
    ~ConfigManager() = default;
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    QJsonObject m_configObject;
    bool m_loaded = false;
    QString m_errorString;
};

#endif // CONFIGMANAGER_H
