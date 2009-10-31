TEMPLATE = app
QT = gui \
    core
# sql
CONFIG += qt \
    qwt \
    warn_on \
    console \
    debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
HEADERS = src/mainwindowimpl.h \
    src/histogram_item.h \
    src/lab1_1.h \
    src/lab1_2.h \
    src/lab1_3.h
SOURCES = src/mainwindowimpl.cpp \
    src/main.cpp \
    src/histogram_item.cpp \
    src/lab1_1.cpp \
    src/lab1_2.cpp \
    src/lab1_3.cpp
LIBS += /usr/lib/libqwt-qt4.so
#INCLUDEPATH += /usr/include/qwt-qt4/
RESOURCES = windowrc.qrc
