#include "blockchain_limbo_database_of_blocks.h"

blockchain_limbo_database_of_blocks::blockchain_limbo_database_of_blocks(QObject *parent)
    : QObject{parent}
{

}

void blockchain_limbo_database_of_blocks::initalize()
{
    list_of_unordered_blocks = new QVector<blockchain_block_info *>();
}


