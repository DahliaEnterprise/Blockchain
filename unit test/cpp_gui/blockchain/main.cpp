#include "blockchain.h"
#include "universal_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    blockchain * block_chain = new blockchain();
    block_chain->initialize();
    universal_window * window = new universal_window();
    window->initialize();
    window->show();

    return a.exec();
}
