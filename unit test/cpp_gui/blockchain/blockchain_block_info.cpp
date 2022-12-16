#include "blockchain_block_info.h"

blockchain_block_info::blockchain_block_info(QObject *parent)
    : QObject{parent}
{

}

void blockchain_block_info::set_block_parameters(QByteArray set_exact_message)
{
    exact_message.append(set_exact_message);
}

void blockchain_block_info::set_hash(QByteArray set_hash)
{
    hash.append(set_hash);
}
