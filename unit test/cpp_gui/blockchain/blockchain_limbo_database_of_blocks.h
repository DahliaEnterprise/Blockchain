#ifndef BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H
#define BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H

#include <QObject>

class blockchain_limbo_database_of_blocks : public QObject
{
    Q_OBJECT
public:
    explicit blockchain_limbo_database_of_blocks(QObject *parent = nullptr);

signals:

};

#endif // BLOCKCHAIN_LIMBO_DATABASE_OF_BLOCKS_H
