#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost("192.168.0.133", 12347); // Adresse IP de l'ordinateur de votre ami et port 12347

    if (!socket->waitForConnected(3000)) { // Attendre jusqu'à 3 secondes pour la connexion
        qDebug() << "Erreur de connexion:" << socket->errorString();
    } else {
        qDebug() << "Client connecté au serveur.";
    }
}

void Client::sendMovementCommand(const QString &command)
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QString message = "MOUVEMENT:" + command; // Préparez le message
        socket->write(message.toUtf8()); // Envoyer la commande
        socket->flush(); // Assurez-vous que les données sont envoyées
        qDebug() << "Commande de mouvement envoyée:" << message;
    } else {
        qDebug() << "Le client n'est pas connecté au serveur.";
    }
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
