TEMPLATE = app
TARGET = Lotto
QT += core \
    gui
HEADERS += Generator.h \
    Trojka.h \
    Dodaj.h \
    Para.h \
    TableWindow.h \
    Exceptions.h \
    sample.h \
    loader.h \
    lotto.h
SOURCES += Generator.cpp \
    Trojka.cpp \
    Dodaj.cpp \
    Para.cpp \
    TableWindow.cpp \
    Exceptions.cpp \
    sample.cpp \
    loader.cpp \
    main.cpp \
    lotto.cpp
FORMS += lottoMain.ui \
    dodaj.ui \
    lotto.ui
RESOURCES += 
QMAKE_CXXFLAGS += -g \
    -rdynamic
QMAKE_CXXFLAGS_DEBUG += -g \
    -rdynamic
