QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blockchain.cpp \
    blockchain_block_info.cpp \
    blockchain_limbo_database_of_blocks.cpp \
    blockchain_longest_chain_of_blocks.cpp \
    main.cpp \
    universal_window.cpp

HEADERS += \
    blockchain.h \
    blockchain_block_info.h \
    blockchain_limbo_database_of_blocks.h \
    blockchain_longest_chain_of_blocks.h \
    universal_window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    python/generate_keypair.py
