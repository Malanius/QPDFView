#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T13:21:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPDFView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    page.cpp

HEADERS  += mainwindow.h \
    page.hpp

FORMS    += mainwindow.ui


INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64/include

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -lmupdf-qt

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64/include
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libmupdf-qt.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -lmupdf

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libmupdf.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -lz

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libz.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -lfreetype

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libfreetype.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -ljpeg

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libjpeg.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -ljbig2dec

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libjbig2dec.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -lopenjpeg

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libopenjpeg.a

unix:!macx: LIBS += -L$$PWD/../3rdparty/lib/Linux-x64/ -lmujs

INCLUDEPATH += $$PWD/../3rdparty/lib/Linux-x64
DEPENDPATH += $$PWD/../3rdparty/lib/Linux-x64

unix:!macx: PRE_TARGETDEPS += $$PWD/../3rdparty/lib/Linux-x64/libmujs.a


unix:!macx: LIBS += -L$$PWD/../usr/lib -lssl -lcrypto

INCLUDEPATH += $$PWD/../usr/lib
DEPENDPATH += $$PWD/../usr/lib

