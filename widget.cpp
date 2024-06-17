#include "widget.h"
#include "ui_widget.h"

# include<axbbattery.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->Slider->setRange(0,100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Slider_valueChanged(int value)
{
    ui->battery->setPower_leve(value);
    ui->label->setText(QString::asprintf("当前电量：%d%%", value));
}

