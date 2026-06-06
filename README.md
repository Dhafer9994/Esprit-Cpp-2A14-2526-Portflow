<div align="center">

#  PortFlow

**Système Intelligent de Gestion de Port de Pêche**

*Application de bureau C++/Qt intégrant IoT, IA et optimisation opérationnelle*

![C++](https://img.shields.io/badge/C++-17-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-6.8-41CD52?style=flat-square&logo=qt&logoColor=white)
![Python](https://img.shields.io/badge/Python-3.9+-3776AB?style=flat-square&logo=python&logoColor=white)
![Oracle](https://img.shields.io/badge/Oracle-Database-F80000?style=flat-square&logo=oracle&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-IoT-00979D?style=flat-square&logo=arduino&logoColor=white)
![License](https://img.shields.io/badge/Licence-Académique-lightgrey?style=flat-square)

</div>

---

##  Table des matières

- [Description](#-description)
- [Modules du système](#-modules-du-système)
- [Fonctionnalités avancées](#-fonctionnalités-avancées)
- [Technologies utilisées](#-technologies-utilisées)
- [Architecture](#-architecture)
- [Prérequis](#-prérequis)
- [Installation](#-installation)
- [Configuration](#-configuration)
- [Lancement](#-lancement)
- [Démo](#-démo)
- [Auteurs](#-auteurs)
- [Encadrant](#-encadrant)
- [Licence](#-licence)

---

##  Description

**PortFlow** est une application de bureau développée pour automatiser et optimiser la gestion quotidienne d'un port de pêche intelligent.

L'application centralise les opérations portuaires à travers plusieurs modules métiers, tout en intégrant des technologies **IoT**, des **algorithmes d'optimisation** et des fonctionnalités d'**intelligence artificielle**.

Le système permet de :
- Gérer efficacement les ressources portuaires
- Améliorer la productivité globale des opérations
- Encourager une gestion durable des activités de pêche

---

##  Modules du système

###  Module Pêches
- Gestion des opérations de pêche
- Enregistrement des captures
- Historique des activités

###  Module Bateaux
- Ajout et gestion des bateaux
- Suivi des mouvements
- Consultation des informations des navires

###  Module Quais
- Gestion des quais
- Suivi de l'occupation en temps réel
- Organisation des postes disponibles

###  Module Employés
- Gestion des employés
- Évaluation intelligente des performances
- Analyse statistique

###  Module Chambres Froides
- Surveillance thermique en continu
- Gestion du stockage
- Communication avec les dispositifs Arduino

###  Module Livraisons
- Gestion des livraisons
- Suivi logistique
- Historique des opérations

---

##  Fonctionnalités avancées

###  Attribution automatique des pêches
Le système intègre des algorithmes d'optimisation inspirés des approches de recherche opérationnelle afin d'attribuer automatiquement les activités de pêche selon les ressources disponibles et les contraintes opérationnelles.

###  Système contre la surpêche
PortFlow intègre un mécanisme intelligent permettant :
- Le suivi des quantités pêchées
- Le contrôle des limites autorisées
- La génération d'alertes automatiques
- L'aide à une exploitation durable des ressources marines

###  Authentification intelligente
- **Face ID** — Authentification biométrique par reconnaissance faciale (OpenCV + DeepFace)
- **RFID** — Contrôle d'accès physique via carte
- **Arduino** — Intégration matérielle pour la gestion des accès

###  Analyse et visualisation
- Tableaux de bord interactifs (Qt Charts)
- Statistiques en temps réel
- Suivi des performances individuelles et globales

---

##  Technologies utilisées

| Couche | Technologies |
|---|---|
| **Frontend** | Qt Widgets, Qt Charts, QSS |
| **Backend** | C++17, Qt Core, Qt Network, Qt SerialPort |
| **Intelligence Artificielle** | Python, OpenCV, DeepFace |
| **Base de données** | Oracle Database (ODBC via QODBC), SQLite (Face ID) |
| **IoT** | Arduino IDE, Communication série |

---

##  Architecture

```
Utilisateur
     │
     ▼
Interface Qt (Qt Widgets / Qt Charts)
     │
     ▼
Backend C++ (Qt Core / Qt Network / Qt SerialPort)
     │
     ├──────────────────────┬───────────────────────┐
     ▼                      ▼                       ▼
Oracle Database        Modules IA              Arduino / IoT
(QODBC)           (Python / OpenCV /       (Contrôle d'accès /
                      DeepFace)            Chambres froides)
```

---

##  Prérequis

Avant de commencer, assurez-vous d'avoir installé :

- **Qt Creator** 16.x
- **Qt** 6.8.x
- **Compilateur C++17** — MinGW 64-bit ou MSVC 2022
- **Python** 3.9 ou supérieur
- **Oracle ODBC Driver** avec la source ODBC nommée `source_projet2a`
- **Arduino IDE**

---

##  Installation

### 1. Configurer Oracle

Modifiez le fichier de connexion pour correspondre à votre environnement Oracle :

```cpp
// connection.cpp
// Renseignez vos identifiants Oracle et le nom de la source ODBC
```

### 2. Mettre à jour la base de données

Exécutez le script SQL fourni pour initialiser ou mettre à jour le schéma :

```sql
-- Exécuter dans votre client Oracle
@update_db_schema.sql
```

### 3. Installer les dépendances Python (Face ID)

```bash
cd face_id
pip install -r requirements.txt
```

### 4. Téléverser les programmes Arduino

| Carte | Fichier |
|---|---|
| Contrôle d'accès | `arduino_port.ino` |
| Surveillance chambres froides | `fridge_monitor.ino` |

Téléversez chaque sketch via l'**Arduino IDE** sur la carte correspondante.

---

##  Configuration

PortFlow supporte des variables d'environnement optionnelles pour connecter des services IA externes. Si aucune variable n'est définie, le système bascule automatiquement sur ses **mécanismes locaux**.

```env
# Services IA externes (optionnel)
PORTFLOW_AI_ASSIGNMENT_URL=
PORTFLOW_AI_ANALYSIS_URL=
PORTFLOW_AI_EMPLOYEE_URL=
PORTFLOW_AI_TOKEN=
PORTFLOW_AI_TIMEOUT_MS=3000
```

---

##  Lancement

### Ouvrir le projet

```text
Ouvrir le fichier : projet1.pro
dans Qt Creator
```

### Compiler et exécuter

```
Ctrl + R
```

### Enregistrer un visage (Face ID)

```bash
python face_id/face_auth.py register "Prenom_Nom" "Role"
```

---

##  Démo

>  Une vidéo de démonstration complète : https://www.youtube.com/watch?v=joQ11ZCKwL0&t=21s

---

##  Auteurs

Projet réalisé dans le cadre du module **C++** — **ESPRIT**, Groupe **2A14**

| Nom |
|---|
| Azri Med Aziz |
| Smaoui Dhafer |
| Saidi Anas |
| Mofti Yoser |
| Zayati Eya |
| Ben Issa Manena |

 Année universitaire **2025–2026**

---

##  Encadrant

**Mme Soumaya NHERI**

---

##  Licence

Ce projet est réalisé dans un cadre **académique** — ESPRIT.
Toute réutilisation à des fins commerciales est interdite sans autorisation préalable.

---

<div align="center">

 *PortFlow — Vers une gestion portuaire intelligente et durable*

</div>
