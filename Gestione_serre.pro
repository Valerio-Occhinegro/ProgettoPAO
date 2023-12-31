QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    igrometro.cpp \
    luxometro.cpp \
    main.cpp \
    mainwindow.cpp \
    sens_info.cpp \
    sensore.cpp \
    serra.cpp \
    termometro.cpp

HEADERS += \
    igrometro.h \
    luxometro.h \
    mainwindow.h \
    sens_info.h \
    sensore.h \
    serra.h \
    termometro.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
