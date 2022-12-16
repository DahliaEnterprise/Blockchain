#ifndef UNIVERSAL_WINDOW_H
#define UNIVERSAL_WINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QStringList>
#include <QProcess>
#include <QDebug>

class universal_window : public QWidget
{
    Q_OBJECT
public:
    explicit universal_window(QWidget *parent = nullptr);
    void initialize();

private:
    QVBoxLayout * mainlayout;
        QWidget * tabs_widget;
        QHBoxLayout * tabs_layout;
            QPushButton * blockchain_btn;
            QPushButton * wallet_btn;

        QWidget * blockchain_widget;
        QHBoxLayout * blockchain_layout;

        QWidget * wallet_widget;
        QVBoxLayout * wallet_layout;
            QTableWidget * address_list_table;
            QPushButton * generate_address;

signals:

private slots:
    void generate_address_button_pressed();

};

#endif // UNIVERSAL_WINDOW_H
