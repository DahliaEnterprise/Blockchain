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

#include "blockchain_limbo_database_of_blocks.h"
#include "blockchain_longest_chain_of_blocks.h"

class blockchain : public QObject
{
    Q_OBJECT
public:
    explicit blockchain(QObject *parent = nullptr);
    void initialize();

private:
    uint difficulty(QByteArray hash);

    /*uint assist_network_with_validation;
    QVector<QByteArray> hash_list;
    QVector<QByteArray> message_list;
    */

    blockchain_limbo_database_of_blocks * limbo_database;
    blockchain_longest_chain_of_blocks * longest_chain_database;

    QTcpServer * tcp_server_miner;
    QTcpSocket * tcp_socket_miner;
    uint miner_connected;

signals:

private slots:
    void search_for_next_block_validation();
    void miner_new_connection();
    void miner_ready_read();

};

#endif // BLOCKCHAIN_H
