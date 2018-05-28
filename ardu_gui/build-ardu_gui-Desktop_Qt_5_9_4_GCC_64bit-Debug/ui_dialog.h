/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *ardu_label;
    QLCDNumber *ir_val;
    QLabel *gen_i;
    QLCDNumber *gen_current;
    QLabel *supercaps_v;
    QLCDNumber *supercaps_volt;
    QLabel *supercaps_oh;
    QProgressBar *supercap_stat_oh;
    QLabel *supercaps_ov;
    QProgressBar *supercap_stat_ov;
    QLabel *ext_bat;
    QProgressBar *bat_stat;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(376, 288);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ardu_label = new QLabel(Dialog);
        ardu_label->setObjectName(QStringLiteral("ardu_label"));
        QPalette palette;
        QBrush brush(QColor(52, 101, 164, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        ardu_label->setPalette(palette);
        QFont font;
        font.setPointSize(14);
        ardu_label->setFont(font);

        gridLayout->addWidget(ardu_label, 0, 0, 1, 1);

        ir_val = new QLCDNumber(Dialog);
        ir_val->setObjectName(QStringLiteral("ir_val"));
        QPalette palette1;
        QBrush brush3(QColor(239, 41, 41, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        ir_val->setPalette(palette1);
        ir_val->setDigitCount(7);

        gridLayout->addWidget(ir_val, 0, 1, 1, 1);

        gen_i = new QLabel(Dialog);
        gen_i->setObjectName(QStringLiteral("gen_i"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        gen_i->setPalette(palette2);
        gen_i->setFont(font);

        gridLayout->addWidget(gen_i, 1, 0, 1, 1);

        gen_current = new QLCDNumber(Dialog);
        gen_current->setObjectName(QStringLiteral("gen_current"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        gen_current->setPalette(palette3);
        gen_current->setDigitCount(7);

        gridLayout->addWidget(gen_current, 1, 1, 1, 1);

        supercaps_v = new QLabel(Dialog);
        supercaps_v->setObjectName(QStringLiteral("supercaps_v"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        supercaps_v->setPalette(palette4);
        supercaps_v->setFont(font);

        gridLayout->addWidget(supercaps_v, 2, 0, 1, 1);

        supercaps_volt = new QLCDNumber(Dialog);
        supercaps_volt->setObjectName(QStringLiteral("supercaps_volt"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        supercaps_volt->setPalette(palette5);
        supercaps_volt->setDigitCount(7);

        gridLayout->addWidget(supercaps_volt, 2, 1, 1, 1);

        supercaps_oh = new QLabel(Dialog);
        supercaps_oh->setObjectName(QStringLiteral("supercaps_oh"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        supercaps_oh->setPalette(palette6);
        supercaps_oh->setFont(font);

        gridLayout->addWidget(supercaps_oh, 3, 0, 1, 1);

        supercap_stat_oh = new QProgressBar(Dialog);
        supercap_stat_oh->setObjectName(QStringLiteral("supercap_stat_oh"));
        supercap_stat_oh->setValue(0);

        gridLayout->addWidget(supercap_stat_oh, 3, 1, 1, 1);

        supercaps_ov = new QLabel(Dialog);
        supercaps_ov->setObjectName(QStringLiteral("supercaps_ov"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        supercaps_ov->setPalette(palette7);
        supercaps_ov->setFont(font);

        gridLayout->addWidget(supercaps_ov, 4, 0, 1, 1);

        supercap_stat_ov = new QProgressBar(Dialog);
        supercap_stat_ov->setObjectName(QStringLiteral("supercap_stat_ov"));
        supercap_stat_ov->setValue(0);

        gridLayout->addWidget(supercap_stat_ov, 4, 1, 1, 1);

        ext_bat = new QLabel(Dialog);
        ext_bat->setObjectName(QStringLiteral("ext_bat"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        ext_bat->setPalette(palette8);
        ext_bat->setFont(font);

        gridLayout->addWidget(ext_bat, 5, 0, 1, 1);

        bat_stat = new QProgressBar(Dialog);
        bat_stat->setObjectName(QStringLiteral("bat_stat"));
        bat_stat->setValue(0);

        gridLayout->addWidget(bat_stat, 5, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        ardu_label->setText(QApplication::translate("Dialog", "IR val (RPM)", Q_NULLPTR));
        gen_i->setText(QApplication::translate("Dialog", "Generator Current", Q_NULLPTR));
        supercaps_v->setText(QApplication::translate("Dialog", "SuperCaps Voltage", Q_NULLPTR));
        supercaps_oh->setText(QApplication::translate("Dialog", "SuperCaps Overheating", Q_NULLPTR));
        supercap_stat_oh->setFormat(QString());
        supercaps_ov->setText(QApplication::translate("Dialog", "SuperCaps Overvoltage", Q_NULLPTR));
        supercap_stat_ov->setFormat(QString());
        ext_bat->setText(QApplication::translate("Dialog", "External Baterry", Q_NULLPTR));
        bat_stat->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
