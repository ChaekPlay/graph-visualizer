QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/dijkstraalgorithm.cpp \
    src/edge.cpp \
    src/graphview.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/setnumberdialog.cpp \
    src/vertex.cpp

HEADERS += \
    include/dijkstraalgorithm.h \
    include/edge.h \
    include/graphview.h \
    include/mainwindow.h \
    include/setnumberdialog.h \
    include/styles.h \
    include/vertex.h

FORMS += \
    ui/mainwindow.ui \
    ui/setnumberdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md \
    icon.ico

RC_ICONS = icon.ico
