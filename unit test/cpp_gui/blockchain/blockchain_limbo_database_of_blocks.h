#ifndef BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H
#define BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H

#include <QObject>
#include <QVector>
#include <QJsonObject>

#include "blockchain_block_info.h"

class blockchain_limbo_database_of_blocks : public QObject
{
    Q_OBJECT
public:
    explicit blockchain_limbo_database_of_blocks(QObject *parent = nullptr);
    void initalize();


private:
    QVector<blockchain_block_info *> * list_of_unordered_blocks;

signals:

};

#endif // BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H
