TEMPLATE = app
TARGET = Lotto
QT += core \
    gui
HEADERS += TableWindow.h \
    Exceptions.h \
    sample.h \
    loader.h \
    lotto.h
SOURCES += TableWindow.cpp \
    Exceptions.cpp \
    sample.cpp \
    loader.cpp \
    main.cpp \
    lotto.cpp
FORMS += lotto.ui
RESOURCES += 
QMAKE_CXXFLAGS += -g -rdynamic
QMAKE_CXXFLAGS_DEBUG += -g -rdynamic