#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    // Remplacez par l'adresse IP réelle du serveur
    socket->connectToHost("192.168.1.100", 12345); // Exemple d'adresse IP du serveur
}

void Client::sendMovementCommand(const QString &command)
{
    qDebug() << "Commande de mouvement envoyée: " << command;
}

void Client::sendCameraCommand(const QString &command)
{
    qDebug() << "Commande de caméra envoyée: " << command;
}

void Client::sendGasSensorData(float gasValue)
{
    qDebug() << "Donnée de capteur de gaz envoyée: " << gasValue;
}

void Client::sendMessage(const QString &message)
{
    qDebug() << "Message envoyé: " << message;
}

void Client::sendSensorData(const QString &sensorType, float value) // Nouvelle méthode
{
    qDebug() << "Donnée de capteur envoyée: " << sensorType << " - " << value;
    emit sensorDataReceived(sensorType, value); // Émettre le nouveau signal
}

void Client::fetchData()
{
    qDebug() << "Récupération des données demandée";
}
