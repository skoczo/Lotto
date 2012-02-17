# -------------------------------------------------
# Project created by QtCreator 2011-06-09T20:30:09
# -------------------------------------------------
TEMPLATE = app
QT += core \
    gui
TARGET = parserTest
CONFIG += console \
    qt
SOURCES += Generator.cpp \
    main.cpp \
    parsertest.cpp \
    Trojka.cpp \
    TableWindow.cpp \
    sample.cpp \
    Para.cpp \
    lotto.cpp \
    loader.cpp \
    Exceptions.cpp \
    Dodaj.cpp 
HEADERS += Generator.h \
    parsertest.h \
    Trojka.h \
    TableWindow.h \
    sample.h \
    Para.h \
    lotto.h \
    loader.h \
    Exceptions.h \
    Dodaj.h
FORMS += lottoMain.ui \
    lotto.ui \
    dodaj.ui
RESOURCES += 
QMAKE_CXXFLAGS += -g \
    -rdynamic
QMAKE_CXXFLAGS_DEBUG += -g \
    -rdynamic
