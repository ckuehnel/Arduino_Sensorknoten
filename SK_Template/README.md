## SK_Template

Das baukastenartige Zusammensetzen der einzelnen Funktionen wird durch ein Template für die Software unterstützt. 

In das File getValue.ino wird der Zugriff auf den Sensor ausgelagert. 

Im File arduino_secrets.h sind die Zugriffsdaten für den WiFi Access Point oder bestimmte Server ausgelagert. Bei der Weitergabe von Software kann dieses File dann durch ein neutrales File ersetzt werden, wodurch die eigenen Credentials geschützt bleiben.
