#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <QObject>

class blockchain : public QObject
{
    Q_OBJECT
public:
    explicit blockchain(QObject *parent = nullptr);
    void initialize();

signals:

};

#endif // BLOCKCHAIN_H
