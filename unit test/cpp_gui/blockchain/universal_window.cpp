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


}
