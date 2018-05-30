#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void readSerial();
    void updateWindmill(QString);
    void updateVoltage(QString);
    void updateBattery(QString);
    void updateOverVolt(QString);
    void updateOverHeat(QString);

private:
    Ui::Dialog *ui;

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 10755;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data1;
    QString parsed_data2;
    QString parsed_data3;
    QString parsed_data4;
    QString parsed_data5;

    double windmill_val;
    double supercaps_val;
    double battery_val;
    int digital1temp;
    int digital2ov;

};

#endif // DIALOG_H
