#-------------------------------------------------
#
# Project created by QtCreator 2018-03-13T12:02:14
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tmp
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    BasicFunctionality/absolutewinddirection.cpp \
    BasicFunctionality/condensorvoltage.cpp \
    BasicFunctionality/correctionvector.cpp \
    BasicFunctionality/drivendistance.cpp \
    BasicFunctionality/motordata.cpp \
    BasicFunctionality/pedometer.cpp \
    BasicFunctionality/powerconsumed.cpp \
    BasicFunctionality/sensorfactory.cpp \
    BasicFunctionality/sensors.cpp \
    BasicFunctionality/topicsimulator.cpp \
    BasicFunctionality/uartclass.cpp \
    BasicFunctionality/uarttranslator.cpp \
    BasicFunctionality/windspeed.cpp \
    qcustomplot.cpp \
    tokenizer.cpp \
    windspeedui.cpp

HEADERS  += mainwindow.h \
    BasicFunctionality/absolutewinddirection.h \
    BasicFunctionality/condensorvoltage.h \
    BasicFunctionality/correctionvector.h \
    BasicFunctionality/drivendistance.h \
    BasicFunctionality/motordata.h \
    BasicFunctionality/pedometer.h \
    BasicFunctionality/powerconsumed.h \
    BasicFunctionality/sensorcontainer.h \
    BasicFunctionality/sensorfactory.h \
    BasicFunctionality/sensors.h \
    BasicFunctionality/topicreceiver.h \
    BasicFunctionality/topicsimulator.h \
    BasicFunctionality/uartclass.h \
    BasicFunctionality/uarttranslator.h \
    BasicFunctionality/windspeed.h \
    log.h \
    qcustomplot.h \
    settings.h \
    tokenizer.hpp \
    windspeedui.h

FORMS    += mainwindow.ui \
    windspeedui.ui

DISTFILES += \
    topicsimulation.txt \
    mylog.log
