QT       += core gui sql \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animals.cpp \
    barley.cpp \
    chicken.cpp \
    cow.cpp \
    farmer.cpp \
    gamepage.cpp \
    login_or_signup_page.cpp \
    main.cpp \
    mainwindow.cpp \
    seeds.cpp \
    sheep.cpp \
    wheat.cpp

HEADERS += \
    animals.h \
    barley.h \
    chicken.h \
    cow.h \
    farmer.h \
    gamepage.h \
    login_or_signup_page.h \
    mainwindow.h \
    seeds.h \
    sheep.h \
    wheat.h

FORMS += \
    gamepage.ui \
    login_or_signup_page.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
