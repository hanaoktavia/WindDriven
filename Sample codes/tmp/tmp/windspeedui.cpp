#include "windspeedui.h"
#include "ui_windspeedui.h"

WindspeedUI::WindspeedUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindspeedUI)
{
    ui->setupUi(this);
    ui->lcdNumber->display(69);
}

WindspeedUI::~WindspeedUI()
{
    delete ui;
}
