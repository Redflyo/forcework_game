QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animation.cpp \
    block.cpp \
    bullet.cpp \
    camera.cpp \
    forcework.cpp \
    ia.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    personnage.cpp \
    physicalobject.cpp \
    player.cpp \
    settings.cpp

HEADERS += \
    animation.h \
    block.h \
    bullet.h \
    camera.h \
    forcework.h \
    ia.h \
    mainwindow.h \
    map.h \
    personnage.h \
    physicalobject.h \
    player.h \
    settings.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    mapTest.txt
