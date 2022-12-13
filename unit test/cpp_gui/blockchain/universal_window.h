#ifndef UNIVERSAL_WINDOW_H
#define UNIVERSAL_WINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

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

signals:

};

#endif // UNIVERSAL_WINDOW_H
