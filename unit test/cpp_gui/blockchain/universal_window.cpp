#include "universal_window.h"

universal_window::universal_window(QWidget *parent) : QWidget(parent)
{

}

void universal_window::initialize()
{
    this->setWindowTitle("Blockchain");
    mainlayout = new QVBoxLayout(0);
    this->setLayout(mainlayout);
        tabs_widget = new QWidget();
        mainlayout->addWidget(tabs_widget);
            tabs_layout = new QHBoxLayout();
            tabs_widget->setLayout(tabs_layout);
            blockchain_btn =  new QPushButton("Blockchain");
            tabs_layout->addWidget(blockchain_btn);
            wallet_btn = new QPushButton("Wallet");
            tabs_layout->addWidget(wallet_btn);
        blockchain_widget = new QWidget();
        mainlayout->addWidget(blockchain_widget);

        wallet_widget = new QWidget();
        mainlayout->addWidget(wallet_widget);
        wallet_layout = new QVBoxLayout();
        wallet_widget->setLayout(wallet_layout);
            address_list_table = new QTableWidget(0, 3, nullptr);
            QStringList list;
            list.append("Address");
            list.append("Timestamp Created");
            list.append("Balance");
            address_list_table->setHorizontalHeaderLabels(list);
            wallet_layout->addWidget(address_list_table, 1);

            generate_address = new QPushButton(QString("Generate New Address"));
            wallet_layout->addWidget(generate_address, 1);
            connect(generate_address, SIGNAL(pressed()), this, SLOT(generate_address_button_pressed()));

}

void universal_window::generate_address_button_pressed()
{
    QProcess process;
    process.start("python3", QStringList("./../blockchain/python/generate_keypair.py"), QIODevice::ReadOnly);
    process.waitForFinished();
    QByteArray private_key = process.readLine(0);
    QByteArray public_key = process.readLine(0);
    qDebug() << private_key;
    qDebug() << public_key;
}
