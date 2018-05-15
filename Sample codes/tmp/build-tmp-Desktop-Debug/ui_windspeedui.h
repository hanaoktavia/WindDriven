/********************************************************************************
** Form generated from reading UI file 'windspeedui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDSPEEDUI_H
#define UI_WINDSPEEDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindspeedUI
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget__;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *WindspeedUI)
    {
        if (WindspeedUI->objectName().isEmpty())
            WindspeedUI->setObjectName(QStringLiteral("WindspeedUI"));
        WindspeedUI->resize(1033, 540);
        WindspeedUI->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0.655 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        horizontalLayout = new QHBoxLayout(WindspeedUI);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_3 = new QWidget(WindspeedUI);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget__ = new QWidget(widget_3);
        widget__->setObjectName(QStringLiteral("widget__"));
        widget__->setStyleSheet(QStringLiteral("background-color: rgba(191, 64, 64, 0);"));
        horizontalLayout_3 = new QHBoxLayout(widget__);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(widget__);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(191, 64, 64, 0);"));

        horizontalLayout_3->addWidget(label, 0, Qt::AlignHCenter);


        horizontalLayout_2->addWidget(widget__);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgba(191, 64, 64, 0);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QLatin1String("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        lcdNumber = new QLCDNumber(widget_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(14);
        sizePolicy1.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy1);
        lcdNumber->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"background-color: rgba(191, 64, 64, 0);"));
        lcdNumber->setDigitCount(2);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(lcdNumber);


        horizontalLayout_2->addWidget(widget_2);


        horizontalLayout->addWidget(widget_3);


        retranslateUi(WindspeedUI);

        QMetaObject::connectSlotsByName(WindspeedUI);
    } // setupUi

    void retranslateUi(QWidget *WindspeedUI)
    {
        WindspeedUI->setWindowTitle(QApplication::translate("WindspeedUI", "Form", 0));
        label->setText(QApplication::translate("WindspeedUI", "Richting indicator", 0));
        label_2->setText(QApplication::translate("WindspeedUI", "Speed", 0));
    } // retranslateUi

};

namespace Ui {
    class WindspeedUI: public Ui_WindspeedUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDSPEEDUI_H
