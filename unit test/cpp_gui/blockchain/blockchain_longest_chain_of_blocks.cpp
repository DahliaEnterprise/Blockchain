#include "blockchain_longest_chain_of_blocks.h"

blockchain_longest_chain_of_blocks::blockchain_longest_chain_of_blocks(QObject *parent)
    : QObject{parent}
{

}

void blockchain_longest_chain_of_blocks::initialize()
{
    hash_list = new QVector<QByteArray>();
    message_list = new QVector<QJsonObject>();

}

quint64 blockchain_longest_chain_of_blocks::largest_height()
{

    return 0;
}
