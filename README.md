# PortFlow

## Description
PortFlow est une application de bureau conçue pour automatiser et optimiser la gestion quotidienne d'un port de pêche intelligent. Elle permet de suivre l'état d'occupation des quais en temps réel, de gérer les mouvements des bateaux, d'assurer la surveillance thermique des chambres froides et de contrôler les accès physiques via des dispositifs IoT Arduino. L'application intègre également des fonctionnalités avancées d'intelligence artificielle pour l'évaluation de la performance des employés et la reconnaissance faciale (Face ID) lors de l'authentification des utilisateurs, tout en s'appuyant sur des algorithmes d'optimisation (inspirés de Google OR-Tools) pour l'attribution des postes d'amarrage.
## Fonctionnalités

- Gestion des bateaux
- Gestion des quais
- Gestion des chambres froides
- Contrôle d'accès par RFID
- Surveillance IoT via Arduino
- Authentification Face ID
- Statistiques et tableaux de bord
- Évaluation intelligente des employés
- Attribution optimisée des postes d'amarrage

## Technologies utilisées
Frontend : Qt Widgets, Qt Charts, QSS (styles)  
Backend : C++17 (Qt Core, Network, SerialPort), Python (OpenCV, DeepFace)  
Base de données : Oracle Database (connexion ODBC via QODBC), SQLite (locale pour les visages Face ID)

## Prérequis
- Qt Creator 16.x
- Qt 6.8.x
- C++17
- MinGW 64-bit ou MSVC 2022
- Python 3.9 ou supérieur (avec pip)
- Pilote Oracle ODBC installé et source de données nommée `source_projet2a`
- Arduino IDE (pour le téléversement des microcontrôleurs)

## Installation
1. Configurez les paramètres de connexion Oracle dans le fichier connection.cpp.
2. Mettez à jour votre base de données Oracle en exécutant le script [update_db_schema.sql](update_db_schema.sql)
3. Installez les paquets Python requis pour le module biométrique :
   ```bash
   cd face_id
   pip install -r requirements.txt
   ```
4. Téléversez les programmes Arduino :
   *   [arduino_port.ino](arduino_port/arduino_port.ino)sur la carte de contrôle d'accès.
   *   [fridge_monitor.ino](fridge_monitor.ino) sur la carte de surveillance de température.

## Lancement
1. Ouvrez le fichier [projet1.pro](projet1.pro) dans Qt Creator.
2. Compilez et lancez le projet avec Qt Creator (raccourci `Ctrl + R`).
3. *(Optionnel)* Pour enregistrer des visages pour Face ID, utilisez la commande suivante :
   ```bash
   python face_id/face_auth.py register "Prenom_Nom" "Role"
   ```

## Variables d'environnement
Variables facultatives pour l'activation des fonctionnalités d'IA distantes (sinon, le système utilise automatiquement ses algorithmes d'évaluation et d'affectation locaux) :
*   `PORTFLOW_AI_ASSIGNMENT_URL` : URL de l'API de recommandation d'affectation des quais
*   `PORTFLOW_AI_ANALYSIS_URL` : URL de l'API d'analyse de l'état des quais
*   `PORTFLOW_AI_EMPLOYEE_URL` : URL de l'API de reporting des employés
*   `PORTFLOW_AI_TOKEN` : Jeton Bearer d'authentification aux APIs
*   `PORTFLOW_AI_TIMEOUT_MS` : Temps d'attente maximum pour les requêtes réseau (3000 ms par défaut)

## Démo
Vidéo : https://www.youtube.com/watch?v=joQ11ZCKwL0&t=5s

## Auteurs

Projet réalisé dans le cadre du module C++ à ESPRIT.

Groupe 2A14

- Azri Med Aziz
- Smaoui Dhafer
- Saidi Anas
- Mofti Yoser
- Zayati Eya
- Ben Issa Manena


Année universitaire 2025-2026

---

## Encadrant

Mme Amani Lamine. 
