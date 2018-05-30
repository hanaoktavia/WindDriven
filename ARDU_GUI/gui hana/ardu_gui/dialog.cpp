#include "dialog.h"
#include "ui_dialog.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->windmill_val->display("----");
    ui->supercaps_volt->display("----");
    ui->externBat_volt->display("----");
    ui->supercap_stat_oh->setValue(1);
    ui->supercap_stat_ov->setValue(1);

    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data1 = "";
    parsed_data2 = "";
    parsed_data3 = "";
    parsed_data4 = "";
    parsed_data5 = "";
    windmill_val = 0.0;
    supercaps_val = 0.0;
    battery_val = 0.0;

    digital1temp = 0;
    digital2ov = 0;

    /*  Testing code, prints the description, vendor id, and product id of all ports.
         *  Used it to determine the values for the arduino uno.
         *
        qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Description: " << serialPortInfo.description() << "\n";
            qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
            qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
        }*/
    /*
     *   Identify the port the arduino uno is on.
     */

    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }
    /*
     *  Open and configure the arduino port if available
     */
    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}


Dialog::~Dialog()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    delete ui;
}

void Dialog::readSerial()
{
    /*
     * readyRead() doesn't guarantee that the entire message will be received all at once.
     */

    // QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator

    //  Check to see if there less than 3 tokens in buffer_split.
    //  If there are at least 3 then this means there were 2 commas,
    //  means there is a parsed temperature value as the second token (between 2 commas)
    QStringList bufferSplit = serialBuffer.split(",");
    qDebug()<<serialBuffer.count();
    if(bufferSplit.length() < 7){
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
        qDebug()<<serialBuffer;
    }else{
        // the second element of buffer_split is parsed correctly, update the ir
        serialBuffer="";
        qDebug()<<bufferSplit<<"\n";

        parsed_data1=bufferSplit[0]; // digitalT
        parsed_data2=bufferSplit[1]; // digitalV
        parsed_data3=bufferSplit[2]; // Supercap volt
        parsed_data4=bufferSplit[3]; // Battery volt
        parsed_data5=bufferSplit[4]; // rpm

        digital1temp = parsed_data1.toDouble();
        digital2ov = parsed_data2.toDouble();
        supercaps_val = parsed_data3.toDouble();
        battery_val = parsed_data4.toDouble();
        windmill_val = parsed_data5.toDouble();

        qDebug()<<"WindmillRPM: "<<windmill_val<<"\n";
        qDebug()<<"SupercapsVoltage: "<<supercaps_val<<"\n";
        qDebug()<<"BatteryVoltage: "<<battery_val<<"\n";
        qDebug()<<"Overheating: "<<digital1temp<<"\n";
        qDebug()<<"Overvoltage: "<<digital2ov<<"\n";

        parsed_data1 = QString::number(digital1temp,'g',4);
        parsed_data2 = QString::number(digital2ov,'g',4);
        parsed_data3 = QString::number(supercaps_val,'g',4);
        parsed_data4 = QString::number(battery_val,'g',4);
        parsed_data5 = QString::number(windmill_val,'g',4);

        Dialog::updateOverHeat(parsed_data1);
        Dialog::updateOverVolt(parsed_data2);
        Dialog::updateVoltage(parsed_data3);
        Dialog::updateBattery(parsed_data4);
        Dialog::updateWindmill(parsed_data5);

    }
}

void Dialog::updateWindmill(const QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    ui->windmill_val->display(sensor_reading);
}

void Dialog::updateVoltage(const QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    ui->supercaps_volt->display(sensor_reading);
}

void Dialog::updateBattery(QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    ui->externBat_volt->display(sensor_reading);
}

void Dialog::updateOverVolt(QString sensor_reading){
    ui->supercap_stat_ov->setValue(sensor_reading.toInt());
}

void Dialog::updateOverHeat(QString sensor_reading){
    ui->supercap_stat_oh->setValue(sensor_reading.toInt());
}
