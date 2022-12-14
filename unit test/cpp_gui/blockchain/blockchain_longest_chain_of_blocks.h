#ifndef BLOCKCHAIN_LONGEST_CHAIN_OF_BLOCKS_H
#define BLOCKCHAIN_LONGEST_CHAIN_OF_BLOCKS_H

#include <QObject>
#include <QJsonObject>
#include <QByteArray>

class blockchain_longest_chain_of_blocks : public QObject
{
    Q_OBJECT
public:
    explicit blockchain_longest_chain_of_blocks(QObject *parent = nullptr);
    void initialize();
    quint64 largest_height();

private:
    QVector<QByteArray> * hash_list;
    QVector<QJsonObject> * message_list;

signals:

};

#endif // BLOCKCHAIN_LONGEST_CHAIN_OF_BLOCKS_H
