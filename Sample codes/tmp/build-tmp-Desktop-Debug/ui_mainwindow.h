/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *Gauges;
    QGridLayout *gridLayout_2;
    QWidget *planes;
    QGridLayout *gridLayout;
    QWidget *sensorShowerTopRight;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QComboBox *sensorSelectorTopRight;
    QLabel *sensorLabelTopRight;
    QWidget *recorderWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *RecorderLabel;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *startRecording;
    QPushButton *stopRecording;
    QLabel *recordingSince;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *recordingSinceLabel;
    QLabel *label_4;
    QWidget *sensorShowerBottomRight;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QComboBox *sensorSelectorBottomRight;
    QLabel *sensorLabelBottomRight;
    QWidget *sensorShowerBottomMiddle;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_8;
    QComboBox *sensorSelectorBottomMiddle;
    QLabel *sensorLabelBottomMiddle;
    QWidget *sensorShowerTopMiddle;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_9;
    QComboBox *sensorSelectorTopMiddle;
    QLabel *sensorLabelTopMiddle;
    QWidget *sensorShowerTopLeft;
    QHBoxLayout *horizontalLayout_12;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_10;
    QComboBox *sensorSelectorTopLeft;
    QLabel *sensorLabelTopLeft;
    QWidget *Graph;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *numberOfSamples;
    QCustomPlot *customPlot;
    QWidget *Settings;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *RecorderSettingsLabel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *recorderFileNameLabel;
    QLineEdit *recorderFileName;
    QHBoxLayout *recorderFileSettings;
    QPushButton *openRecorderFile;
    QPushButton *displayRecorderFile;
    QTableWidget *recorderTable;
    QWidget *tabBar;
    QHBoxLayout *horizontalLayout;
    QWidget *tabButtons;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *GaugeButton;
    QPushButton *GraphButton;
    QPushButton *settingsButton;
    QWidget *widget_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1037, 647);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(16);
        sizePolicy.setVerticalStretch(9);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setCursor(QCursor(Qt::CrossCursor));
        MainWindow->setMouseTracking(true);
        MainWindow->setWindowOpacity(1);
        MainWindow->setStyleSheet(QStringLiteral("background: rgb(54, 69, 79);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(15);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        tabWidget->setElideMode(Qt::ElideNone);
        Gauges = new QWidget();
        Gauges->setObjectName(QStringLiteral("Gauges"));
        gridLayout_2 = new QGridLayout(Gauges);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        planes = new QWidget(Gauges);
        planes->setObjectName(QStringLiteral("planes"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(14);
        sizePolicy2.setHeightForWidth(planes->sizePolicy().hasHeightForWidth());
        planes->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(planes);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sensorShowerTopRight = new QWidget(planes);
        sensorShowerTopRight->setObjectName(QStringLiteral("sensorShowerTopRight"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(sensorShowerTopRight->sizePolicy().hasHeightForWidth());
        sensorShowerTopRight->setSizePolicy(sizePolicy3);
        sensorShowerTopRight->setStyleSheet(QStringLiteral("background: rgb(83,104,114);"));
        horizontalLayout_5 = new QHBoxLayout(sensorShowerTopRight);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget = new QWidget(sensorShowerTopRight);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        sensorSelectorTopRight = new QComboBox(widget);
        sensorSelectorTopRight->setObjectName(QStringLiteral("sensorSelectorTopRight"));

        verticalLayout_4->addWidget(sensorSelectorTopRight);

        sensorLabelTopRight = new QLabel(widget);
        sensorLabelTopRight->setObjectName(QStringLiteral("sensorLabelTopRight"));
        sensorLabelTopRight->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_4->addWidget(sensorLabelTopRight, 0, Qt::AlignHCenter);


        horizontalLayout_5->addWidget(widget);


        gridLayout->addWidget(sensorShowerTopRight, 0, 2, 1, 1);

        recorderWidget_2 = new QWidget(planes);
        recorderWidget_2->setObjectName(QStringLiteral("recorderWidget_2"));
        recorderWidget_2->setEnabled(true);
        sizePolicy3.setHeightForWidth(recorderWidget_2->sizePolicy().hasHeightForWidth());
        recorderWidget_2->setSizePolicy(sizePolicy3);
        recorderWidget_2->setStyleSheet(QStringLiteral("background: rgb(83,104,114);"));
        verticalLayout_5 = new QVBoxLayout(recorderWidget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        RecorderLabel = new QLabel(recorderWidget_2);
        RecorderLabel->setObjectName(QStringLiteral("RecorderLabel"));
        RecorderLabel->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_5->addWidget(RecorderLabel);

        widget_4 = new QWidget(recorderWidget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_9 = new QHBoxLayout(widget_4);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        startRecording = new QPushButton(widget_4);
        startRecording->setObjectName(QStringLiteral("startRecording"));
        startRecording->setStyleSheet(QStringLiteral("font: 14pt \"Ubuntu Condensed\";"));

        horizontalLayout_9->addWidget(startRecording);

        stopRecording = new QPushButton(widget_4);
        stopRecording->setObjectName(QStringLiteral("stopRecording"));
        stopRecording->setStyleSheet(QStringLiteral("font: 14pt \"Ubuntu Condensed\";"));

        horizontalLayout_9->addWidget(stopRecording);


        verticalLayout_5->addWidget(widget_4);

        recordingSince = new QLabel(recorderWidget_2);
        recordingSince->setObjectName(QStringLiteral("recordingSince"));
        recordingSince->setStyleSheet(QStringLiteral("font: 14pt \"Ubuntu Condensed\";"));

        verticalLayout_5->addWidget(recordingSince);

        widget_5 = new QWidget(recorderWidget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        recordingSinceLabel = new QLabel(widget_5);
        recordingSinceLabel->setObjectName(QStringLiteral("recordingSinceLabel"));
        recordingSinceLabel->setStyleSheet(QStringLiteral("font: 14pt \"Ubuntu Condensed\";"));
        recordingSinceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(recordingSinceLabel);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 14pt \"Ubuntu Condensed\";"));

        horizontalLayout_6->addWidget(label_4);


        verticalLayout_5->addWidget(widget_5);


        gridLayout->addWidget(recorderWidget_2, 1, 0, 1, 1);

        sensorShowerBottomRight = new QWidget(planes);
        sensorShowerBottomRight->setObjectName(QStringLiteral("sensorShowerBottomRight"));
        sizePolicy3.setHeightForWidth(sensorShowerBottomRight->sizePolicy().hasHeightForWidth());
        sensorShowerBottomRight->setSizePolicy(sizePolicy3);
        sensorShowerBottomRight->setStyleSheet(QStringLiteral("background: rgb(83,104,114);"));
        horizontalLayout_8 = new QHBoxLayout(sensorShowerBottomRight);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        widget_2 = new QWidget(sensorShowerBottomRight);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        sensorSelectorBottomRight = new QComboBox(widget_2);
        sensorSelectorBottomRight->setObjectName(QStringLiteral("sensorSelectorBottomRight"));

        verticalLayout_7->addWidget(sensorSelectorBottomRight);

        sensorLabelBottomRight = new QLabel(widget_2);
        sensorLabelBottomRight->setObjectName(QStringLiteral("sensorLabelBottomRight"));
        sensorLabelBottomRight->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_7->addWidget(sensorLabelBottomRight, 0, Qt::AlignHCenter);


        horizontalLayout_8->addWidget(widget_2);


        gridLayout->addWidget(sensorShowerBottomRight, 1, 2, 1, 1);

        sensorShowerBottomMiddle = new QWidget(planes);
        sensorShowerBottomMiddle->setObjectName(QStringLiteral("sensorShowerBottomMiddle"));
        sizePolicy3.setHeightForWidth(sensorShowerBottomMiddle->sizePolicy().hasHeightForWidth());
        sensorShowerBottomMiddle->setSizePolicy(sizePolicy3);
        sensorShowerBottomMiddle->setStyleSheet(QStringLiteral("background: rgb(83,104,114);"));
        horizontalLayout_7 = new QHBoxLayout(sensorShowerBottomMiddle);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        widget_6 = new QWidget(sensorShowerBottomMiddle);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_8 = new QVBoxLayout(widget_6);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        sensorSelectorBottomMiddle = new QComboBox(widget_6);
        sensorSelectorBottomMiddle->setObjectName(QStringLiteral("sensorSelectorBottomMiddle"));

        verticalLayout_8->addWidget(sensorSelectorBottomMiddle);

        sensorLabelBottomMiddle = new QLabel(widget_6);
        sensorLabelBottomMiddle->setObjectName(QStringLiteral("sensorLabelBottomMiddle"));
        sensorLabelBottomMiddle->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_8->addWidget(sensorLabelBottomMiddle, 0, Qt::AlignHCenter);


        horizontalLayout_7->addWidget(widget_6);


        gridLayout->addWidget(sensorShowerBottomMiddle, 1, 1, 1, 1);

        sensorShowerTopMiddle = new QWidget(planes);
        sensorShowerTopMiddle->setObjectName(QStringLiteral("sensorShowerTopMiddle"));
        sizePolicy3.setHeightForWidth(sensorShowerTopMiddle->sizePolicy().hasHeightForWidth());
        sensorShowerTopMiddle->setSizePolicy(sizePolicy3);
        sensorShowerTopMiddle->setStyleSheet(QStringLiteral("background: rgb(83,104,114);"));
        horizontalLayout_11 = new QHBoxLayout(sensorShowerTopMiddle);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        widget_7 = new QWidget(sensorShowerTopMiddle);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        verticalLayout_9 = new QVBoxLayout(widget_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        sensorSelectorTopMiddle = new QComboBox(widget_7);
        sensorSelectorTopMiddle->setObjectName(QStringLiteral("sensorSelectorTopMiddle"));

        verticalLayout_9->addWidget(sensorSelectorTopMiddle);

        sensorLabelTopMiddle = new QLabel(widget_7);
        sensorLabelTopMiddle->setObjectName(QStringLiteral("sensorLabelTopMiddle"));
        sensorLabelTopMiddle->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_9->addWidget(sensorLabelTopMiddle, 0, Qt::AlignHCenter);


        horizontalLayout_11->addWidget(widget_7);


        gridLayout->addWidget(sensorShowerTopMiddle, 0, 1, 1, 1);

        sensorShowerTopLeft = new QWidget(planes);
        sensorShowerTopLeft->setObjectName(QStringLiteral("sensorShowerTopLeft"));
        sizePolicy3.setHeightForWidth(sensorShowerTopLeft->sizePolicy().hasHeightForWidth());
        sensorShowerTopLeft->setSizePolicy(sizePolicy3);
        sensorShowerTopLeft->setStyleSheet(QStringLiteral("background: rgb(83,104,114);"));
        horizontalLayout_12 = new QHBoxLayout(sensorShowerTopLeft);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        widget_8 = new QWidget(sensorShowerTopLeft);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        verticalLayout_10 = new QVBoxLayout(widget_8);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        sensorSelectorTopLeft = new QComboBox(widget_8);
        sensorSelectorTopLeft->setObjectName(QStringLiteral("sensorSelectorTopLeft"));

        verticalLayout_10->addWidget(sensorSelectorTopLeft);

        sensorLabelTopLeft = new QLabel(widget_8);
        sensorLabelTopLeft->setObjectName(QStringLiteral("sensorLabelTopLeft"));
        sensorLabelTopLeft->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_10->addWidget(sensorLabelTopLeft, 0, Qt::AlignHCenter);


        horizontalLayout_12->addWidget(widget_8);


        gridLayout->addWidget(sensorShowerTopLeft, 0, 0, 1, 1);


        gridLayout_2->addWidget(planes, 0, 0, 1, 1);

        tabWidget->addTab(Gauges, QString());
        Graph = new QWidget();
        Graph->setObjectName(QStringLiteral("Graph"));
        verticalLayout_3 = new QVBoxLayout(Graph);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame = new QFrame(Graph);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        numberOfSamples = new QSpinBox(frame);
        numberOfSamples->setObjectName(QStringLiteral("numberOfSamples"));
        numberOfSamples->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(numberOfSamples);


        verticalLayout_3->addWidget(frame);

        customPlot = new QCustomPlot(Graph);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(10);
        sizePolicy5.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy5);
        customPlot->setStyleSheet(QStringLiteral("color: rgb(186, 189, 182);"));

        verticalLayout_3->addWidget(customPlot);

        tabWidget->addTab(Graph, QString());
        Settings = new QWidget();
        Settings->setObjectName(QStringLiteral("Settings"));
        verticalWidget = new QWidget(Settings);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setGeometry(QRect(0, 0, 371, 501));
        verticalLayout_6 = new QVBoxLayout(verticalWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        RecorderSettingsLabel = new QLabel(verticalWidget);
        RecorderSettingsLabel->setObjectName(QStringLiteral("RecorderSettingsLabel"));
        RecorderSettingsLabel->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu Condensed\";"));

        verticalLayout_6->addWidget(RecorderSettingsLabel);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        recorderFileNameLabel = new QLabel(verticalWidget);
        recorderFileNameLabel->setObjectName(QStringLiteral("recorderFileNameLabel"));
        recorderFileNameLabel->setStyleSheet(QStringLiteral("font: 14pt \"Ubuntu Condensed\";"));

        horizontalLayout_10->addWidget(recorderFileNameLabel);

        recorderFileName = new QLineEdit(verticalWidget);
        recorderFileName->setObjectName(QStringLiteral("recorderFileName"));
        recorderFileName->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Ubuntu Condensed\";"));

        horizontalLayout_10->addWidget(recorderFileName);


        verticalLayout_6->addLayout(horizontalLayout_10);

        recorderFileSettings = new QHBoxLayout();
        recorderFileSettings->setSpacing(6);
        recorderFileSettings->setObjectName(QStringLiteral("recorderFileSettings"));
        openRecorderFile = new QPushButton(verticalWidget);
        openRecorderFile->setObjectName(QStringLiteral("openRecorderFile"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(openRecorderFile->sizePolicy().hasHeightForWidth());
        openRecorderFile->setSizePolicy(sizePolicy6);
        openRecorderFile->setStyleSheet(QLatin1String("background: rgb(83,104,114);\n"
"font: 14pt \"Ubuntu Condensed\";"));

        recorderFileSettings->addWidget(openRecorderFile);

        displayRecorderFile = new QPushButton(verticalWidget);
        displayRecorderFile->setObjectName(QStringLiteral("displayRecorderFile"));
        sizePolicy6.setHeightForWidth(displayRecorderFile->sizePolicy().hasHeightForWidth());
        displayRecorderFile->setSizePolicy(sizePolicy6);
        displayRecorderFile->setStyleSheet(QLatin1String("background: rgb(83,104,114);\n"
"font: 14pt \"Ubuntu Condensed\";"));

        recorderFileSettings->addWidget(displayRecorderFile);


        verticalLayout_6->addLayout(recorderFileSettings);

        recorderTable = new QTableWidget(verticalWidget);
        recorderTable->setObjectName(QStringLiteral("recorderTable"));
        recorderTable->setEnabled(true);

        verticalLayout_6->addWidget(recorderTable);

        tabWidget->addTab(Settings, QString());

        verticalLayout->addWidget(tabWidget);

        tabBar = new QWidget(centralWidget);
        tabBar->setObjectName(QStringLiteral("tabBar"));
        tabBar->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(2);
        sizePolicy7.setHeightForWidth(tabBar->sizePolicy().hasHeightForWidth());
        tabBar->setSizePolicy(sizePolicy7);
        tabBar->setMinimumSize(QSize(0, 0));
        tabBar->setMaximumSize(QSize(16777215, 100));
        horizontalLayout = new QHBoxLayout(tabBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tabButtons = new QWidget(tabBar);
        tabButtons->setObjectName(QStringLiteral("tabButtons"));
        horizontalLayout_2 = new QHBoxLayout(tabButtons);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        GaugeButton = new QPushButton(tabButtons);
        GaugeButton->setObjectName(QStringLiteral("GaugeButton"));
        sizePolicy6.setHeightForWidth(GaugeButton->sizePolicy().hasHeightForWidth());
        GaugeButton->setSizePolicy(sizePolicy6);
        GaugeButton->setStyleSheet(QLatin1String("background: rgb(83,104,114);\n"
"font: 20pt \"Ubuntu Condensed\";"));
        GaugeButton->setAutoDefault(false);
        GaugeButton->setFlat(false);

        horizontalLayout_2->addWidget(GaugeButton);

        GraphButton = new QPushButton(tabButtons);
        GraphButton->setObjectName(QStringLiteral("GraphButton"));
        GraphButton->setEnabled(false);
        sizePolicy6.setHeightForWidth(GraphButton->sizePolicy().hasHeightForWidth());
        GraphButton->setSizePolicy(sizePolicy6);
        GraphButton->setStyleSheet(QLatin1String("background: rgb(83,104,114);\n"
"font: 20pt \"Ubuntu Condensed\";"));

        horizontalLayout_2->addWidget(GraphButton);

        settingsButton = new QPushButton(tabButtons);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        sizePolicy6.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy6);
        settingsButton->setStyleSheet(QLatin1String("background: rgb(83,104,114);\n"
"font: 20pt \"Ubuntu Condensed\";"));

        horizontalLayout_2->addWidget(settingsButton);


        horizontalLayout->addWidget(tabButtons);

        widget_3 = new QWidget(tabBar);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout->addWidget(widget_3);


        verticalLayout->addWidget(tabBar);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        GaugeButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Windauto", 0));
        sensorLabelTopRight->setText(QApplication::translate("MainWindow", "No valid data available", 0));
        RecorderLabel->setText(QApplication::translate("MainWindow", "Recorder", 0));
        startRecording->setText(QApplication::translate("MainWindow", "Start", 0));
        stopRecording->setText(QApplication::translate("MainWindow", "Stop", 0));
        recordingSince->setText(QApplication::translate("MainWindow", "Recording since:", 0));
        recordingSinceLabel->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "milliseconds", 0));
        sensorLabelBottomRight->setText(QApplication::translate("MainWindow", "No valid data available", 0));
        sensorLabelBottomMiddle->setText(QApplication::translate("MainWindow", "No valid data available", 0));
        sensorLabelTopMiddle->setText(QApplication::translate("MainWindow", "No valid data available", 0));
        sensorLabelTopLeft->setText(QApplication::translate("MainWindow", "No valid data available", 0));
        tabWidget->setTabText(tabWidget->indexOf(Gauges), QApplication::translate("MainWindow", "Tab 1", 0));
        label->setText(QApplication::translate("MainWindow", "Number of Samples", 0));
        tabWidget->setTabText(tabWidget->indexOf(Graph), QApplication::translate("MainWindow", "Page", 0));
        RecorderSettingsLabel->setText(QApplication::translate("MainWindow", "Recorder Settings", 0));
        recorderFileNameLabel->setText(QApplication::translate("MainWindow", "Change recorder file name:", 0));
        recorderFileName->setText(QApplication::translate("MainWindow", "sensorlogfile", 0));
        openRecorderFile->setText(QApplication::translate("MainWindow", "Open Recorder File", 0));
        displayRecorderFile->setText(QApplication::translate("MainWindow", "Display Last Recorder File", 0));
        tabWidget->setTabText(tabWidget->indexOf(Settings), QApplication::translate("MainWindow", "Page", 0));
        GaugeButton->setText(QApplication::translate("MainWindow", "Gauges", 0));
        GraphButton->setText(QApplication::translate("MainWindow", "Graph", 0));
        settingsButton->setText(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
