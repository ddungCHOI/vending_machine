#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{   ui->setupUi(this);
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbcoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMONEY(int n) {
    MONEY += n;
    ui->lcdNumber->display(MONEY);

    if (MONEY >= 200){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbcoke->setEnabled(true);
    }
    if (MONEY < 200 && MONEY >= 150){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbcoke->setEnabled(false);
    }
    if (MONEY < 150 && MONEY >= 100){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(false);
        ui->pbcoke->setEnabled(false);
    }
    if (MONEY < 100){
        ui->pbcoffee->setEnabled(false);
        ui->pbtea->setEnabled(false);
        ui->pbcoke->setEnabled(false);
    }
}

void Widget::on_pb10_clicked()
{
    changeMONEY(10);

}

void Widget::on_pb50_clicked()
{
    changeMONEY(50);

}

void Widget::on_pb100_clicked()
{
    changeMONEY(100);

}

void Widget::on_pb500_clicked()
{
    changeMONEY(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMONEY(-100);
}

void Widget::on_pbtea_clicked()
{
    changeMONEY(-150);
}

void Widget::on_pbcoke_clicked()
{
    changeMONEY(-200);
}

void Widget::on_pbreturn_clicked()
{
    QMessageBox msg;

    int coin[4] = {0};
    for (int var = 0; MONEY > 0 ; ++var) {
        if (MONEY % 500 == 0){
            ++coin[0];
            MONEY -= 500;
            continue;
        }
        else if (MONEY % 100 == 0){
            ++coin[1];
            MONEY -= 100;
            continue;
        }
        else if (MONEY % 50 == 0){
            ++coin[2];
            MONEY -= 50;
            continue;
        }
        else {
            ++coin[3];
            MONEY -= 10;
            continue;
        }

    }
    msg.information(nullptr, "return", "500 : " + QString::number(coin[0]) + "\n" + "100 : " + QString::number(coin[1]) + "\n" + "50 : " + QString::number(coin[2]) + "\n" + "10 : " + QString::number(coin[3]));
}
