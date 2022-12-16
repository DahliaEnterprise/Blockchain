#ifndef BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H
#define BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H

#include <QObject>
#include <QVector>
#include <QJsonObject>
#include <QCryptographicHash>

#include "blockchain_block_info.h"

class blockchain_limbo_database_of_blocks : public QObject
{
    Q_OBJECT
public:
    explicit blockchain_limbo_database_of_blocks(QObject *parent = nullptr);
    void initalize();
    void append_block(QByteArray hash, QByteArray exact_message);

private:
    QVector<blockchain_block_info *> * list_of_unordered_blocks;

     int difficulty(QByteArray hash);
signals:

};

#endif // BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H
