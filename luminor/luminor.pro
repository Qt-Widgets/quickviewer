include("../QVproject.pri")
QT       += core gui

CONFIG += c++11

TARGET = qluminor
TEMPLATE = lib
CONFIG += staticlib

win32 {
LIBS += -L$${LUMINOR_BIN_PATH} -lluminor -lluminor_rgba -lhalide_runtime
}

unix {
#OBJECTS_DIR += $${LUMINOR_BIN_PATH}
#OBJECTS += $${LUMINOR_BIN_PATH}/luminor.o $${LUMINOR_BIN_PATH}/luminor_rgba.o
LIBS += -L$${LUMINOR_BIN_PATH} -lhalide_runtime  $${LUMINOR_BIN_PATH}/luminor.o $${LUMINOR_BIN_PATH}/luminor_rgba.o
}
DESTDIR = ../lib

INCLUDEPATH += $${LUMINOR_BIN_PATH} luminor
HEADERS += \
    $${LUMINOR_BIN_PATH}/luminor.h \
    $${LUMINOR_BIN_PATH}/luminor_rgba.h \
    luminor/HalideBuffer.h \
    luminor/HalideRuntime.h \
    qluminor.h





# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qluminor.cpp
