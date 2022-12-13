#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QCryptographicHash>
#include <QByteArray>
#include <QRandomGenerator>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QTimer>

class blockchain : public QObject
{
    Q_OBJECT
public:
    explicit blockchain(QObject *parent = nullptr);
    void initialize();

private:
    uint difficulty(QByteArray hash);

    uint assist_network_with_validation;
    QVector<QByteArray> hash_list;
    QVector<QByteArray> message_list;

    QTcpServer * tcp_server;
    QVector<QTcpSocket *> list_of_client_socket;

signals:

private slots:
    void search_for_next_block_validation();
    void new_connection();
};

#endif // BLOCKCHAIN_H
