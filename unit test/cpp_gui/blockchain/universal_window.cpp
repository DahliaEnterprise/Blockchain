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
            address_list_table = new QTableWidget(1, 3, nullptr);
            QStringList list;
            list.append("Address");
            list.append("Timestamp Created");
            list.append("Balance");
            address_list_table->setHorizontalHeaderLabels(list);
            wallet_layout->addWidget(address_list_table, 1);

}
