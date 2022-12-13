#ifndef BLOCKCHAIN_BLOCK_INFO_H
#define BLOCKCHAIN_BLOCK_INFO_H

#include <QObject>

class blockchain_block_info : public QObject
{
    Q_OBJECT
public:
    explicit blockchain_block_info(QObject *parent = nullptr);

signals:

};

#endif // BLOCKCHAIN_BLOCK_INFO_H
