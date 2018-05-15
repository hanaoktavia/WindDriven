#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicFunctionality/sensorfactory.h"

#include <iostream>
#include <fstream>
#include "tokenizer.hpp"

const int gaugeTab = 0;
const int graphTab = 1;
const int settingsTab = 2;
//QVector<double> MainWindow::x2;
//QVector<double> MainWindow::y2;

MainWindow::MainWindow(SensorContainer &sensorContainer, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sensorCollection(sensorContainer)
{
    LOG(INFO)<<"constructor called";
    ui->setupUi(this);
    this->showFullScreen();
    this->move(0,0);
    ui->GraphButton->hide();
    ui->tabWidget->setCurrentIndex(gaugeTab);

    QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
    tabBar->hide();
    //    setupGraph();
    //    threadRunning = false;
    //    LOGsettings::toCout = true;

    //    prio = QCustomPlot::rpImmediateRefresh;

    ui->numberOfSamples->setValue(10);

    // Initalizing the recorder widget its style
    ui->stopRecording->setDisabled(true);
    ui->stopRecording->setDown(true);
    ui->startRecording->setDisabled(false);
    ui->startRecording->setDown(false);
    // -----------------------------------------

    // Initializing the recorderFileSettings widget
    ui->recorderTable->setRowCount(maxSensorValuesOnDisplay);
    ui->recorderTable->setColumnCount(3);
    ui->recorderTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList horizontalHeaders;
    horizontalHeaders << "Time (ms)" << "Sensor" << "Value";
    ui->recorderTable->setHorizontalHeaderLabels(horizontalHeaders);
    ui->recorderTable->verticalHeader()->setVisible(false);
    // -----------------------------------------

    // GUI update thread
    guiUpdateThread = new std::thread(&MainWindow::guiUpdateThreadFunction,this);


    LOG(INFO)<<"constructor ended";
}

MainWindow::~MainWindow()
{
    // Terminate the guiUpdateThread
    updateGUI = false;
    guiUpdateThread->join();
    delete guiUpdateThread;

    delete ui;
}

void MainWindow::on_GaugeButton_clicked()
{
    ui->tabWidget->setCurrentIndex(gaugeTab);
}

void MainWindow::on_GraphButton_clicked()
{
    ui->tabWidget->setCurrentIndex(graphTab);
}

void MainWindow::on_settingsButton_clicked()
{
    ui->tabWidget->setCurrentIndex(settingsTab);
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    LOG(INFO)<<"Function resizeEvent called";
    resize(this->width(),this->width()*9/16);
    QSize size;
    size.setHeight(ui->sensorShowerTopLeft->height());
    size.setWidth(ui->sensorShowerTopLeft->height());

    ui->sensorShowerTopLeft->resize(size);
    ui->sensorShowerTopMiddle->resize(size);
    ui->sensorShowerTopRight->resize(size);
    ui->recorderWidget_2->resize(size);
    ui->sensorShowerBottomMiddle->resize(size);
    ui->sensorShowerBottomRight->resize(size);
    //size.setWidth(ui->widget_tl->height()*2);
    //ui->widget_bc->resize(size);
    //ui->widget_tc->resize(size);

    //ui->label_tl->setText(QString::number(ui->widget_tl->width())+" "+QString::number(ui->widget_tl->height()));
    //ui->label_tc->setText(QString::number(ui->widget_tc->width())+" "+QString::number(ui->widget_tc->height()));
    //ui->sensorLabel->setText(QString::number(ui->sensorShowerTopRight->width())+" "+QString::number(ui->sensorShowerTopRight->height()));
    // ui->recorderWidget_2->setText(QString::number(ui->recorderWidget_2->width())+" "+QString::number(ui->recorderWidget_2->height()));
    //ui->label_bc->setText(QString::number(ui->widget_bc->width())+" "+QString::number(ui->widget_bc->height()));
    //ui->label_br->setText(QString::number(ui->->width())+" "+QString::number(ui->->height()));

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    LOG(INFO)<<"Function resizeEvent stopped";
}

//void MainWindow::demoThread()
//{
//    LOG(INFO)<<"Thread started";
//    int i = 0;
//    const std::chrono::milliseconds sleep {500};
//    while(threadRunning)
//    {
//        MainWindow::x2.push_back(i/(double)(100-1)*10);
//        MainWindow::y2.push_back(qCos(MainWindow::x2[i]*0.85+qSin(MainWindow::x2[i]*0.165+1.1))*qSin(MainWindow::x2[i]*0.50)+1.7);
//        setGraphData(MainWindow::x2,MainWindow::y2);
//        plotGraph();
//
//        ++i;

//        std::this_thread::sleep_for(sleep);
//    }
//    LOG(INFO)<<"Thread closed";
//}

//void MainWindow::setGraphData(QVector<double>&x, QVector<double>&y)
//{
//    LOG(INFO)<<"Function setGraphData started";
//    graph1->setData(x, y);
//    LOG(INFO)<<"Function setGraphData ended";
//}

//void MainWindow::plotGraph()
//{
//    LOG(DEBUG)<<"Function plotGraph started";
//    ui->customPlot->rescaleAxes();
//    LOG(DEBUG)<<"Axes rescaled";
//    ui->customPlot->yAxis->setRange(*std::min_element(y2.begin(),y2.end()),*std::max_element(y2.begin(),y2.end()));
//    LOG(DEBUG)<<"Y-axle set";
//    ui->customPlot->xAxis->setRange((*std::max_element(x2.begin(),x2.end()))-(graphSamples),*std::max_element(x2.begin(),x2.end()));
//    LOG(DEBUG)<<"X-axle set";
//    ui->customPlot->replot(prio);
//    LOG(DEBUG)<<"graph replotted";
//    //ui->customPlot->repaint();
//    LOG(INFO)<<"Function plotGraph ended";
//}


//void MainWindow::setupGraph()
//{
//    LOG(INFO)<<"Function setupGraph started";
//    // set some pens, brushes and backgrounds:
//    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
//    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
//    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1)); //big steps axis
//    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
//    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1)); //small steps axis
//    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
//    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
//    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
//    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
//    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    QLinearGradient plotGradient;
//    plotGradient.setStart(0, 0);
//    plotGradient.setFinalStop(0, 350);
//    plotGradient.setColorAt(0, QColor(80, 80, 80));
//    plotGradient.setColorAt(1, QColor(50, 50, 50));
//    ui->customPlot->setBackground(plotGradient);
//    QLinearGradient axisRectGradient;
//    axisRectGradient.setStart(0, 0);
//    axisRectGradient.setFinalStop(0, 350);
//    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
//    ui->customPlot->axisRect()->setBackground(axisRectGradient);

//    graph1 = ui->customPlot->addGraph();

//    // move bars above graphs and grid below bars:
//    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
//    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
//    graph1->setLayer("abovemain");
//    ui->customPlot->xAxis->grid()->setLayer("belowmain");
//    ui->customPlot->yAxis->grid()->setLayer("belowmain");
//    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::green), 9));
//    graph1->setPen(QPen(QColor(120, 120, 120), 2));
//    LOG(INFO)<<"Function setupGraph ended";
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    LOG(INFO)<<"Function windspeedbutton clicked";
//    WindspeedUI * wind = new WindspeedUI;
//    wind->show();
//}

//void MainWindow::on_numberOfSamples_valueChanged(int arg1)
//{
//    graphSamples = arg1;
//}

void MainWindow::on_startRecording_clicked()
{
    recorderThread = new std::thread(&MainWindow::recorderThreadFunction,this);
    ui->startRecording->setDisabled(true);
    ui->startRecording->setDown(true);
    ui->stopRecording->setEnabled(true);
    ui->stopRecording->setDown(false);
    ui->settingsButton->setDisabled(true);
    ui->settingsButton->setVisible(false);
}

void MainWindow::on_stopRecording_clicked()
{
    recordingParameters = false;
    ui->stopRecording->setDisabled(true);
    ui->stopRecording->setDown(true);
    ui->startRecording->setDisabled(false);
    ui->startRecording->setDown(false);
    ui->settingsButton->setDisabled(false);
    ui->settingsButton->setVisible(true);
    recorderThread->join();
    delete recorderThread;
}

void MainWindow::recorderThreadFunction(void)
{
    std::ofstream recorderFile;
    recorderFile.open( ui->recorderFileName->displayText().toStdString()+".csv" );
    if(recorderFile.is_open())
    {
        recorderFile << "time from start(ms),sensor,latest sample value" << std::endl;
        recordingParameters = true;
        timerStartPoint = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        while(recordingParameters)
        {
            {
                //auto sensorList = SensorFactory::theSensorFactory().getSensorList();

                auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - timerStartPoint).count();
                ui->recordingSinceLabel->setText(QString::fromStdString(std::to_string(elapsedTime)));
                // For all sensors
                for( auto aSensor: SensorFactory::theSensorFactory().getSensorList())
                {
                    const auto sensor = SensorFactory::theSensorFactory().getSensorObject(aSensor);
                    //int waarde = SensorFactory::theSensorFactory().getSensorObject(aSensor)->getLastSample();
                    recorderFile << elapsedTime << "," << aSensor << "," //<< "dummy"
                                 << sensor.getLastSample() << std::endl;
                    //                                 << waarde
                    //<<std::endl;
                    //std::cout <<"blabla test haha: "<< waarde << std::endl;
                }

            }
            std::this_thread::sleep_until(now + std::chrono::milliseconds(100));
            now = std::chrono::steady_clock::now();

        }
        recorderFile.close();
    }
    else
    {
        LOG(ERROR) << "Unable to open the parameter logfile: "<< ui->recorderFileName->displayText().toStdString() +".csv";
    }
}

void MainWindow::guiUpdateThreadFunction(void)
{
    while(updateGUI)
    {
        updateSensorWidget(ui->sensorLabelTopRight, ui->sensorSelectorTopRight);
        updateSensorWidget(ui->sensorLabelTopMiddle, ui->sensorSelectorTopMiddle);
        updateSensorWidget(ui->sensorLabelTopLeft, ui->sensorSelectorTopLeft);
        updateSensorWidget(ui->sensorLabelBottomMiddle, ui->sensorSelectorBottomMiddle);
        updateSensorWidget(ui->sensorLabelBottomRight, ui->sensorSelectorBottomRight);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void MainWindow::updateSensorWidget(QLabel*& labelToAdapt, QComboBox*& boxToAdapt)
{
    std::vector<std::string> sensorList = sensorCollection.getSensorList();
    QString comboboxText = boxToAdapt->currentText();
    boxToAdapt->clear();
    for(auto i = sensorList.begin(); i != sensorList.end(); ++i)
    {
        boxToAdapt->addItem(QString::fromStdString(*i));
    }
    boxToAdapt->setCurrentText(comboboxText);
    if(comboboxText.length())
    {
        const auto sensor = SensorFactory::theSensorFactory().getSensorObject(comboboxText.toStdString());
        // Car
        if(comboboxText == QString("car " + QString::fromStdString(MQTTSettings::drivenDistane)))
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()) + " m");
        }
        else if(comboboxText == QString("car " + QString::fromStdString(MQTTSettings::pedometer)))
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()) + " km/h");
        }
        else if(comboboxText == QString("car " + QString::fromStdString(MQTTSettings::carDirection)))
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()) + " degrees");
        }
        else if(comboboxText == QString("car " + QString::fromStdString(MQTTSettings::correctionVector)))
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()) + " degrees");
        }
        else if(comboboxText == QString("car " + QString::fromStdString(MQTTSettings::carCondensorVolatage)))
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()) + " V");
        }
        else if(comboboxText == QString("car " + QString::fromStdString( MQTTSettings::carPowerConsumed)))
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()) + " kWh");
        }
        // Nodes
        // if this is a node then
        if(comboboxText.toStdString().find("node") != std::string::npos)
        {
            if(comboboxText.toStdString().find(MQTTSettings::windspeed) != std::string::npos)
            {
                labelToAdapt->setText(QString::number(sensor.getLastSample()) + " bft");
            }
            else if(comboboxText == QString("node 1 " + QString::fromStdString( MQTTSettings::correctionVector)))
            {
                labelToAdapt->setText(QString::number(sensor.getLastSample()) + " degrees");
            }
            else
            {
                labelToAdapt->setText(QString::number(sensor.getLastSample()));
            }
        }
        else
        {
            labelToAdapt->setText(QString::number(sensor.getLastSample()));
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void MainWindow::on_displayRecorderFile_clicked()
{
    // Initializing code
    //  ui->recorderTable->setItem(0, 1, new QTableWidgetItem("Hello"));

    // Read log file
    std::ifstream logFile(ui->recorderFileName->displayText().toStdString() +".csv");

    std::string theLine;
    // First read contains table headers, but they are already known.
    if( std::getline(logFile, theLine) )
    {
        int rowCounter = 0;
        while(std::getline(logFile, theLine))
        {
            auto tokenizedString = split(theLine, isComma);
            //-------------------------------------------------------------
            ui->recorderTable->setItem(rowCounter, 0, new QTableWidgetItem(QString::fromStdString(tokenizedString[0])));
            ui->recorderTable->setItem(rowCounter, 1, new QTableWidgetItem(QString::fromStdString(tokenizedString[1])));
            ui->recorderTable->setItem(rowCounter, 2, new QTableWidgetItem(QString::fromStdString(tokenizedString[2])));
            rowCounter++;
        }
    }
}

void MainWindow::on_openRecorderFile_clicked()
{
    QString path = QDir::toNativeSeparators(QApplication::applicationDirPath());
    path = path + "/" + ui->recorderFileName->displayText() + ".csv";
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    MainWindow::setWindowState(Qt::WindowMinimized);
}
