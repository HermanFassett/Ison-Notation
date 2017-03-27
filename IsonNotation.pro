#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T11:16:25
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IsonNotation
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


SOURCES += main.cpp\
        mainwindow.cpp \
    DataModel/DataSet.cpp \
    DataModel/Parser.cpp

HEADERS  += mainwindow.h \
    DataModel/ISymbol.hpp \
    DataModel/DataSet.hpp \
    DataModel/IModifier.hpp \
    DataModel/IScale.hpp \
    DataModel/Symbols/Ison.hpp \
    DataModel/Symbols/Kentemata.hpp \
    DataModel/Symbols/Oligon.hpp \
    DataModel/Symbols/Petaste.hpp \
    DataModel/Symbols/Ypsele.hpp \
    DataModel/Symbols/Apostrophos.hpp \
    DataModel/Symbols/Elaphron.hpp \
    DataModel/Symbols/Kamele.hpp \
    DataModel/Symbols/Ypporoe.hpp \
    DataModel/Parser.hpp \
    DataModel/Modifiers/Martyria.hpp \
    DataModel/Modifiers/Fthora.hpp \
    DataModel/Symbols/SymbolGroup.hpp \
    DataModel/Symbols/Bar.hpp \
    DataModel/Modifiers/Digorgon.hpp \
    DataModel/Modifiers/Gorgon.hpp \
    DataModel/Modifiers/Klasma.hpp \
    DataModel/Modifiers/Trigorgon.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    fonts.qrc
