#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T14:06:12
#
#-------------------------------------------------

QT       += core gui
CONFIG  += c++11
LIBS    += -lpthread -pthread

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=  main.cpp\
            mainwindow.cpp \
            qcustomplot.cpp \
    windspeedui.cpp \
    BasicFunctionality/absolutewinddirection.cpp \
    BasicFunctionality/correctionvector.cpp \
    BasicFunctionality/drivendistance.cpp \
    BasicFunctionality/motordata.cpp \
    BasicFunctionality/topicsimulator.cpp \
    BasicFunctionality/pedometer.cpp \
    BasicFunctionality/sensorfactory.cpp \
    BasicFunctionality/sensors.cpp \
    BasicFunctionality/windspeed.cpp \
    BasicFunctionality/uartclass.cpp \
    BasicFunctionality/uarttranslator.cpp \
    tokenizer.cpp \
    BasicFunctionality/condensorvoltage.cpp \
    BasicFunctionality/powerconsumed.cpp

HEADERS  += mainwindow.h \
            qcustomplot.h \
    windspeedui.h \
    log.h \
    BasicFunctionality/absolutewinddirection.h \
    BasicFunctionality/correctionvector.h \
    BasicFunctionality/drivendistance.h \
    BasicFunctionality/motordata.h \
    BasicFunctionality/topicsimulator.h \
    BasicFunctionality/pedometer.h \
    BasicFunctionality/sensorfactory.h \
    BasicFunctionality/sensors.h \
    BasicFunctionality/topicreceiver.h \
    BasicFunctionality/windspeed.h \
    settings.h \
    BasicFunctionality/sensorcontainer.h \
    BasicFunctionality/uartclass.h \
    BasicFunctionality/uarttranslator.h \
    tokenizer.hpp \
    BasicFunctionality/condensorvoltage.h \
    BasicFunctionality/powerconsumed.h

FORMS    += mainwindow.ui \
    windspeedui.ui

DISTFILES += \
    topicsimulation.txt
