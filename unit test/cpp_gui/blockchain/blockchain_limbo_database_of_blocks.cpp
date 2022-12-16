#include "blockchain_limbo_database_of_blocks.h"

blockchain_limbo_database_of_blocks::blockchain_limbo_database_of_blocks(QObject *parent)
    : QObject{parent}
{

}

void blockchain_limbo_database_of_blocks::initalize()
{
    list_of_unordered_blocks = new QVector<blockchain_block_info *>();
}

void blockchain_limbo_database_of_blocks::append_block(QByteArray hash, QByteArray exact_message)
{
    qDebug() << "-----";
    qDebug() << hash;
    qDebug() << exact_message;
    qDebug() << "------";

    //Hash exact message, to determine if provided hash is correct(this IS the proof of work "check")
    QCryptographicHash check_message_hash(QCryptographicHash::Sha256);
    check_message_hash.addData(exact_message);
    QByteArray check_message_hash_qbytearray = check_message_hash.result();
    if(check_message_hash_qbytearray.compare(hash) == 0) //No need to secure compare this isn't a password prompt.
    {
        //Provided hash matches exact message.
        blockchain_block_info * next_block = new blockchain_block_info();
        next_block->set_block_parameters(exact_message);
        next_block->set_hash(hash);
        list_of_unordered_blocks->append(next_block);
    }
}

int blockchain_limbo_database_of_blocks::difficulty(QByteArray hash)
{
    uint keep_searching = 1;
    uint index = 0;
    int difficulty = 0;
    while(keep_searching == 1)
    {
        QByteArray first_character;
        first_character.append(hash.toHex().at(index));

        QByteArray zero;
        zero.append((char)'0');
        if(strncmp((const char *)first_character.data(), (const char *)zero.data(), 1) == 0)
        {
           index += 1;
           difficulty += 1;

        }else{
            keep_searching = 0;
        }
    }
    return difficulty;
}
