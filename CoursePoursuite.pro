#-------------------------------------------------
#
# Project created by QtCreator 2015-02-14T11:31:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoursePoursuite
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    notaire.cpp \
    position.cpp \
    Exception/notaireexception.cpp \
    Exception/notaireexceptiondecisiondejavue.cpp \
    Exception/notaireexceptionaucunedecision.cpp

HEADERS  += mainwindow.h \
    notaire.h \
    position.h \
    Exception/notaireexception.h \
    Exception/notaireexceptiondecisiondejavue.h \
    Exception/notaireexceptionaucunedecision.h

FORMS    += mainwindow.ui

RESOURCES +=
