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
    Exception/notaireexceptionaucunedecision.cpp \
    strategie.cpp \
    Exception/strategieexception.cpp \
    Exception/strategieexceptionmauvaisrayonaction.cpp \
    joueur.cpp \
    poursuivant.cpp \
    Exception/poursuivantexception.cpp \
    Exception/poursuivantexceptionaucunestrategiefuyard.cpp \
    Exception/poursuivantexceptionmauvaisrayonaction.cpp \
    Exception/poursuivantexceptionmauvaiseprofondeurhisto.cpp \
    historique.cpp \
    Exception/historiqueexception.cpp \
    Exception/historiqueexceptionhorslimites.cpp \
    Exception/historiqueexceptionhistoriquevide.cpp

HEADERS  += mainwindow.h \
    notaire.h \
    position.h \
    Exception/notaireexception.h \
    Exception/notaireexceptiondecisiondejavue.h \
    Exception/notaireexceptionaucunedecision.h \
    strategie.h \
    Exception/strategieexception.h \
    Exception/strategieexceptionmauvaisrayonaction.h \
    joueur.h \
    poursuivant.h \
    Exception/poursuivantexception.h \
    Exception/poursuivantexceptionaucunestrategiefuyard.h \
    Exception/poursuivantexceptionmauvaisrayonaction.h \
    Exception/poursuivantexceptionmauvaiseprofondeurhisto.h \
    historique.h \
    Exception/historiqueexception.h \
    Exception/historiqueexceptionhorslimites.h \
    Exception/historiqueexceptionhistoriquevide.h

FORMS    += mainwindow.ui

RESOURCES +=
