QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                                   charts

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/igrometro.cpp \
    model/luxometro.cpp \
    model/sensore.cpp \
    model/sensorinfovisitor.cpp \
    model/serra.cpp \
    model/termometro.cpp \
    model/persistenza.cpp \
    view/igro_blocco.cpp \
    view/lux_blocco.cpp \
    view/mainwindow.cpp \
    view/sens_blocco.cpp \
    view/sens_info.cpp \
    view/sens_widget.cpp \
    view/serra_widget.cpp \
    view/term_blocco.cpp \
    view/vista.cpp


HEADERS += \
    model/igrometro.h \
    model/luxometro.h \
    model/sensore.h \
    model/sensorinfovisitor.h \
    model/sensorobserverinterface.h \
    model/sensorvisitorinterface.h \
    model/serra.h \
    model/termometro.h \
    model/persistenza.h \
    view/igro_blocco.h \
    view/lux_blocco.h \
    view/mainwindow.h \
    view/sens_blocco.h \
    view/sens_info.h \
    view/sens_widget.h \
    view/serra_widget.h \
    view/term_blocco.h \
    view/vista.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc


