QT       += core gui sql charts printsupport serialport network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    client.cpp \
    commande.cpp \
    employe.cpp \
    entrepot.cpp \
    factures.cpp \
    fournisseur.cpp \
    globales.cpp \
    login.cpp \
    machine.cpp \
    main.cpp \
    mainwindow.cpp \
    matiere_p.cpp \
    produit.cpp \
    revenues.cpp \
    smtp.cpp \
    user.cpp

HEADERS += \
    arduino.h \
    client.h \
    commande.h \
    employe.h \
    entrepot.h \
    factures.h \
    fournisseur.h \
    globales.h \
    login.h \
    machine.h \
    mainwindow.h \
    matiere_p.h \
    produit.h \
    revenues.h \
    smtp.h \
    user.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    libeay32.dll \
    ssleay32.dll
