QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    igro_blocco.cpp \
    igrometro.cpp \
    lux_blocco.cpp \
    luxometro.cpp \
    main.cpp \
    mainwindow.cpp \
    sens_blocco.cpp \
    sens_info.cpp \
    sens_widget.cpp \
    sensore.cpp \
    sensorinfovisitor.cpp \
    serra.cpp \
    serra_widget.cpp \
    term_blocco.cpp \
    termometro.cpp \
    vista.cpp

HEADERS += \
    igro_blocco.h \
    igrometro.h \
    lux_blocco.h \
    luxometro.h \
    mainwindow.h \
    sens_blocco.h \
    sens_info.h \
    sens_widget.h \
    sensore.h \
    sensorinfovisitor.h \
    sensorvisitorinterface.h \
    serra.h \
    serra_widget.h \
    term_blocco.h \
    termometro.h \
    vista.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
