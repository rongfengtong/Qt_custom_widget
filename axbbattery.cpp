#include "axbbattery.h"
#include<QPainter>

AXBBattery::AXBBattery(QWidget *parent)
    : QWidget{parent}
{

}

int AXBBattery::power_leve() const
{
    return m_power_leve;
}

void AXBBattery::setPower_leve(int newPower_leve)
{
    m_power_leve = newPower_leve;
    repaint();
}


void AXBBattery::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QRect rect(0, 0, width(), height());

    painter.setViewport(rect);
    painter.setWindow(0,0, 120,50);
    painter.setRenderHint(QPainter::Antialiasing);      //抗锯齿
    painter.setRenderHint(QPainter::TextAntialiasing);

    //初始化 QPen 和 QBrush
    QPen pen;
    pen.setWidth(2);
    pen.setColor(m_color_border);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(m_color_back);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //绘制电池边框 和 正极
    rect.setRect(1,1, 109, 48);
    painter.drawRect(rect);

    brush.setColor(m_color_back);
    painter.setBrush(brush);

    rect.setRect(110,15, 10,20);
    painter.drawRect(rect);

    //电量
    if(m_power_leve > m_warning){
        brush.setColor(m_color_power);
        pen.setColor(m_color_power);
    }else{
        brush.setColor(m_color_warning);
        pen.setColor(m_color_warning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    if(m_power_leve > 0){
        rect.setRect(5,5, m_power_leve, 40);
        painter.drawRect(rect);
    }

    //百分比文字
    QFontMetrics textSize(this->font());
    QString powStr = QString::asprintf("%d%%", m_power_leve);
    QRect textRect = textSize.boundingRect(powStr);

    pen.setColor(m_color_border);
    painter.setPen(pen);
    painter.drawText(55-textRect.width()/2,
                     23+textRect.height()/2, powStr);

}










