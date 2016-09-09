#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T13:21:06
#
#-------------------------------------------------

QT       += core gui widgets

TARGET   = QPDFView
TEMPLATE = app

SOURCES  += main.cpp       \
            mainwindow.cpp \
            page.cpp

HEADERS  += mainwindow.h  \
            page.hpp

FORMS    += mainwindow.ui

INCLUDEPATH += ../3rdparty/lib/Linux-x64/include
DEPENDPATH  += ../3rdparty/lib/Linux-x64

unix:!macx: LIBS += -L../3rdparty/lib/Linux-x64/ -lmupdf-qt -lmupdf -lz -lfreetype -ljpeg -ljbig2dec -lopenjpeg  -lmujs
unix:!macx: LIBS += -L/usr/lib -lssl -lcrypto


