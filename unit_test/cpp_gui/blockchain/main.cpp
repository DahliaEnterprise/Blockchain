#include "blockchain.h"
#include "universal_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    uint generate_initial_blockchain = 1;
    uint blockchain_server = 1;
    uint search = 1;

    blockchain * block_chain = new blockchain();
    block_chain->initialize(generate_initial_blockchain, blockchain_server, search);
    universal_window * window = new universal_window();
    window->initialize();
    window->show();

    return a.exec();
}
