##ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QCryptographicHash>
#include <QByteArray>
#include <QRandomGenerator>
class blockchain : public QObject
{
    Q_OBJECT
public:
    explicit blockchain(QObject *parent = nullptr);
    void initialize(uint generate_initial_blockchain);

private:
    uint difficulty(QByteArray hash);

    QList<QByteArray> hash_list;
    QList<QByteArray> message_list;


signals:

};

#endif // BLOCKCHAIN_H
