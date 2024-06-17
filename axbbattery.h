#ifndef AXBBATTERY_H
#define AXBBATTERY_H

#include <QWidget>
#include<QColor>


class AXBBattery : public QWidget
{
    Q_OBJECT

public:
    explicit AXBBattery(QWidget *parent = nullptr);


    int power_leve() const;
    void setPower_leve(int newPower_leve);


private:
    QColor m_color_back = Qt::white;
    QColor m_color_border = Qt::black;
    QColor m_color_power = Qt::green;
    QColor m_color_warning = Qt::red;
    int m_power_leve = 50;      //水平长度50
    int m_warning = 20;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


signals:
};

#endif // AXBBATTERY_H
