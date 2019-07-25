#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbcoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changemoney(int n) {
    money += n;
    ui->lcdNumber->display(money);

    if (money >= 200){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbcoke->setEnabled(true);
    }
    if (money < 200 && money >= 150){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbcoke->setEnabled(false);
    }
    if (money < 150 && money >= 100){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(false);
        ui->pbcoke->setEnabled(false);
    }
    if (money < 100){
        ui->pbcoffee->setEnabled(false);
        ui->pbtea->setEnabled(false);
        ui->pbcoke->setEnabled(false);
    }
}

void Widget::on_pb10_clicked()
{
    changemoney(10);
}

void Widget::on_pb50_clicked()
{
    changemoney(50);
}

void Widget::on_pb100_clicked()
{
    changemoney(100);
}

void Widget::on_pb500_clicked()
{
    changemoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changemoney(-100);
}

void Widget::on_pbtea_clicked()
{
    changemoney(-150);
}

void Widget::on_pbcoke_clicked()
{
    changemoney(-200);
}

void Widget::on_pbreturn_clicked()
{
    QMessageBox msg;
    int coin[4] = {0};

    for (int var = 0; money > 0 ; ++var) {
        if (money % 500 == 0){
            money -= 500;
            ++coin[0];
            continue;
        }
        else if (money % 100 == 0){
            money -= 100;
            ++coin[1];
            continue;
        }
        else if (money % 50 == 0){
            money -= 50;
            ++coin[2];
            continue;
        }
        else {
            money -= 10;
            ++coin[3];
            continue;
        }

    }
    msg.information(nullptr, "return", "500원 : " + QString::number(coin[0]) + "개 받고\n100원 : " + QString::number(coin[1]) + "개 받고\n50원 : " + QString::number(coin[2]) + "받고\n10원 : " + QString::number(coin[3]) + "개 받음");
}
