#include "blockchain.h"

blockchain::blockchain(QObject *parent) : QObject(parent)
{

}

void blockchain::initialize()
{
    tcp_server_miner = new QTcpServer();
    QObject::connect(tcp_server_miner, SIGNAL(newConnection()), this, SLOT(miner_new_connection()));
    tcp_server_miner->listen(QHostAddress::AnyIPv4, 2100);

    miner_connected = 0;

    limbo_database = new blockchain_limbo_database_of_blocks();
    limbo_database->initalize();

    longest_chain_database = new blockchain_longest_chain_of_blocks();
    longest_chain_database->initialize();

    /*
    assist_network_with_validation = search;
    if(generate_initial_blockchain == 1)
    {
        int blockchain_difficulty = 2;
        QJsonObject root;
        root.insert("block_number", QJsonValue("0"));
        root.insert("difficulty", QJsonValue(blockchain_difficulty));
        root.insert("is_checkpoint", QJsonValue("0"));


        QCryptographicHash hash(QCryptographicHash::Sha256);
        QString strJson;

        uint keep_searching = 1;
        while(keep_searching == 1)
        {
            root.insert("timestamp", QJsonValue(QString("%1").arg(QDateTime::currentMSecsSinceEpoch())));

            quint64 random_nonce = QRandomGenerator::global()->generate64();
            root.insert("nonce", QJsonValue(QString("%1").arg(random_nonce)));
            QJsonDocument doc(root);
            strJson.clear();
            strJson.append(doc.toJson(QJsonDocument::Compact));
            //qDebug() << strJson;

            hash.addData(strJson.toLatin1());
            QByteArray result = hash.result();

            uint difficulty = this->difficulty(result);
            if(difficulty >= blockchain_difficulty)
            {
                keep_searching = 0;
            }
        }

        //append to blockchain
        hash_list.append(hash.result());
        message_list.append(strJson.toUtf8());
        //qDebug() << "hash " << hash_list;
        qDebug() << "message " << message_list;
    }

    if(blockchain_server == 1)
    {
        tcp_server = new QTcpServer();
        QObject::connect(tcp_server, SIGNAL(newConnection()), this, SLOT(new_connection()));
        tcp_server->listen(QHostAddress::Any, 2031);
    }

    if(assist_network_with_validation == 1)
    {
        QTimer::singleShot(100, this, SLOT(search_for_next_block_validation()));
    }
    */
}

void blockchain::search_for_next_block_validation()
{
    /*
    //determine previous block status
    QByteArray last_hash = hash_list.last();
    QByteArray last_block_message = message_list.last();

    //begin search
        //create block message
            //get last diffculty
            QJsonDocument get_info_jsondoc = QJsonDocument::fromJson(last_block_message);
            int last_difficulty = get_info_jsondoc["difficulty"].toString().toInt();

            //get last timestamp
            qint64 last_timestamp = get_info_jsondoc["timestamp"].toString().toLongLong();


        QJsonObject root;
        root.insert("block_number", QJsonValue(hash_list.length()));
        root.insert("is_checkpoint", QJsonValue("0"));
        root.insert("previous_hash", QJsonValue(QString::fromUtf8(last_hash.toHex())));

        //hash message
        QCryptographicHash hash(QCryptographicHash::Sha256);
        QString strJson;

        uint keep_searching = 0;
        while(keep_searching < 100)
        {
            //millisecond precision timestamp.
            root.insert("timestamp", QJsonValue(QString("%1").arg(QDateTime::currentMSecsSinceEpoch())));

            //determine next difficulty
            qint64 current_time = QDateTime::currentMSecsSinceEpoch();
            qint64 timepassed = current_time - last_timestamp;
            qint64 ten_minutes = 1000;//1000 * 60 * 10;
            int new_difficulty = last_difficulty;
            qDebug() << timepassed << " <= " << ten_minutes;
            if(timepassed <= ten_minutes)
            {
                new_difficulty += 1;
                qDebug() << "NEW";
            }else if(timepassed > ten_minutes)
            {
                new_difficulty -= 1;
                if(new_difficulty <= 0)
                {
                    new_difficulty = 1;
                }
            }
            qDebug() << new_difficulty;
            root.insert("difficulty", QJsonValue(new_difficulty));

            //nonce
            quint64 random_nonce = QRandomGenerator::global()->generate64();
            root.insert("nonce", QJsonValue(QString("%1").arg(random_nonce)));
            QJsonDocument doc(root);
            strJson.clear();
            strJson.append(doc.toJson(QJsonDocument::Compact));
            //qDebug() << strJson;

            hash.addData(strJson.toLatin1());
            QByteArray result = hash.result();

            uint difficulty = this->difficulty(result);
            if(difficulty >= new_difficulty)
            {
                keep_searching = 101;
            }
        }

    //append to blockchain
    hash_list.append(hash.result());
    message_list.append(strJson.toUtf8());
    qDebug() << "hash " << hash_list.last();
    qDebug() << "message " << message_list.last();

    QTimer::singleShot(100, this, SLOT(search_for_next_block_validation()));
    */
}

uint blockchain::difficulty(QByteArray hash)
{
    /*
    uint keep_searching = 1;
    uint index = 0;
    uint difficulty = 0;
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
    */
}
void blockchain::miner_new_connection()
{
    miner_connected = 1;
    tcp_socket_miner = tcp_server_miner->nextPendingConnection();
    connect(tcp_socket_miner, SIGNAL(readyRead()), this, SLOT(miner_ready_read()));
}

void blockchain::miner_ready_read()
{
    //Parse Incoming JSON HERE
        //Determine request type.
        QJsonDocument jdoc = QJsonDocument::fromJson(tcp_socket_miner->readAll());
        QJsonObject jobj = jdoc.object();
        qDebug() << "READY READ:" << jobj;
        QString request_type = jobj.value(QString("request")).toString();
        qDebug() << request_type;

        if(request_type.compare(QString("next_block")) == 0)
        {
            QJsonObject response;
            response.insert("block_number", QJsonValue("0"));
            response.insert("difficulty", QJsonValue("1"));
            QJsonDocument response_jdoc(response);
            QByteArray response_json_qbytearray = response_jdoc.toJson(QJsonDocument::Compact);
            tcp_socket_miner->write(response_json_qbytearray);
        }else if(request_type.compare(QString("block_found")) == 0)
        {
            qDebug() << "BLOCK FOUND";
        }

}
