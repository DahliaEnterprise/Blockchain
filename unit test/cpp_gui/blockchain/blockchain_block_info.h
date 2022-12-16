#ifndef BLOCKCHAIN_BLOCK_INFO_H
#define BLOCKCHAIN_BLOCK_INFO_H

#include <QObject>
#include <QByteArray>

class blockchain_block_info : public QObject
{
    Q_OBJECT
public:
    explicit blockchain_block_info(QObject *parent = nullptr);
    void set_block_parameters(QByteArray set_exact_message);
    void set_hash(QByteArray set_hash);

private:
    QByteArray exact_message;
    QByteArray hash;

signals:

};

#endif // BLOCKCHAIN_BLOCK_INFO_H
