#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasicFunctionality/sensorcontainer.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QTabBar>
#include <QResizeEvent>
#include <QSize>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iostream>
#include <atomic>
#include <windspeedui.h>
#include "qcustomplot.h"
#include "log.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SensorContainer &sensorContainer, QWidget *parent = 0);
//    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_GaugeButton_clicked();

    void on_GraphButton_clicked();

    void on_settingsButton_clicked();

//    void on_pushButton_2_clicked();

//    void on_numberOfSamples_valueChanged(int arg1);

    void on_startRecording_clicked();

    void on_stopRecording_clicked();

    void on_displayRecorderFile_clicked();

    void on_openRecorderFile_clicked();

    void updateSensorWidget(QLabel*& labelToAdapt, QComboBox*& boxToAdapt);

private:
    Ui::MainWindow *ui;

    SensorContainer& sensorCollection;

    // For recorder functionality
    std::chrono::steady_clock::time_point timerStartPoint;
    std::thread * recorderThread;
    void recorderThreadFunction(void);
    std::atomic<bool> recordingParameters {false};
    // Recorder display functionality
    const int maxSensorValuesOnDisplay = 100000;

    // --------------------------

    std::thread * guiUpdateThread;
    void guiUpdateThreadFunction(void);
    std::atomic<bool> updateGUI {true};

//    void setupGraph();
//    void plotGraph();
//    void demoThread();
//    void setGraphData(QVector<double> &x, QVector<double> &y);
    //int graphSamples = 10;
//    std::atomic<int> graphSamples;

//    QCPGraph *graph1;
//    static QVector<double> x2, y2;
//    std::thread * threadje;
//    QCustomPlot::RefreshPriority prio ;

protected:
    void resizeEvent(QResizeEvent *);
//    std::atomic<bool> threadRunning;
};



#endif // MAINWINDOW_H
