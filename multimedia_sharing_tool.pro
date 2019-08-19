#-------------------------------------------------
#
# Project created by QtCreator 2019-06-27T16:06:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = multimedia_sharing_tool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

CONFIG(release, debug|release){
    DESTDIR = ./build/release/bin
    OBJECTS_DIR = ./build/release/obj
    MOC_DIR = ./build/release/moc
    RCC_DIR = ./build/release/rcc
    UI_DIR = ./build/release/ui
}

CONFIG(debug, debug|release){
    DESTDIR = ./build/debug/bin
    UI_DIR = ./build/debug/ui
    OBJECTS_DIR = ./build/debug/obj
    MOC_DIR = ./build/debug/moc
    RCC_DIR = ./build/debug/rcc
}

SOURCES += \
        src/camerathread.cpp \
        src/clientstreamthread.cpp \
        src/configurations.cpp \
        src/connectivity.cpp \
        src/cudadetectionthread.cpp \
        src/dictionary.cpp \
        src/feedaudiopipethread.cpp \
        src/feedvideopipethread.cpp \
        src/frmclient.cpp \
        src/frmconnected.cpp \
        src/frmrunning.cpp \
        src/frmserver.cpp \
        src/main.cpp \
        src/frmmain.cpp \
        src/serverstreamthread.cpp \
        src/tcpclientthread.cpp \
        src/tcpserverthread.cpp

HEADERS += \
        include/camerathread.h \
        include/clientstreamthread.h \
        include/configurations.h \
        include/connectivity.h \
    include/cudadetectionthread.h \
        include/dictionary.h \
    include/feedaudiopipethread.h \
    include/feedvideopipethread.h \
        include/frmclient.h \
        include/frmconnected.h \
        include/frmmain.h \
        include/frmrunning.h \
        include/frmserver.h \
        include/serverstreamthread.h \
        include/tcpclientthread.h \
        include/tcpserverthread.h

FORMS += \
        ui/frmclient.ui \
        ui/frmconnected.ui \
        ui/frmmain.ui \
        ui/frmrunning.ui \
        ui/frmserver.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Used to make the build version of this qt application an executable that can be launched
# without the use of a command prompt.
QMAKE_LFLAGS += -no-pie

INCLUDEPATH += /usr/include/curl
INCLUDEPATH += include/
INCLUDEPATH += "/usr/local/include/"
LIBS += -L/usr/local/lib -lcurl
LIBS += -lX11
LIBS += `pkg-config --libs opencv`
LIBS += -ljetson-inference
LIBS += -ljetson-utils

# Path to cuda toolkit install
CUDA_DIR      = /usr/local/cuda
# Path to header and libs files
INCLUDEPATH  += $$CUDA_DIR/include
QMAKE_LIBDIR += $$CUDA_DIR/lib64     # Note I'm using a 64 bits Operating system
# libs used in your code
LIBS += -lcudart -lcuda
# GPU architecture
#CUDA_ARCH     = sm_20
# NVCC flags always used by default.
NVCCFLAGS     = --compiler-options -fno-strict-aliasing -use_fast_math --ptxas-options=-v


DISTFILES += \
    media/eye.png \
    media/eyegray.png \
    media/eyegrey.png \
    media/green_state.ico \
    media/green_state.png \
    media/grey_state.png \
    media/mst_logo.ico \
    media/mst_logo.png \
    media/mst_logo2.png \
    media/mst_logo3.png \
    media/stream_active.png \
    media/stream_inactive.png \
    media/yellow_state.ico

RESOURCES += \
    resource.qrc
