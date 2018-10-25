#-------------------------------------------------
#
# Project created by QtCreator 2018-10-25T11:47:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH+=/usr/local/include\
/usr/local/include/opencv\
/usr/local/include/opencv2
LIBS+=/usr/local/lib/libopencv_highgui.so\
/usr/local/lib/libopencv_core.so\
/usr/local/lib/libopencv_imgproc.so\
/usr/local/lib/libopencv_imgcodecs.so

TARGET = pcl_cloud_read
TEMPLATE = app


SOURCES += main.cpp\
        pcl_visualizer.cpp

HEADERS  += pcl_visualizer.h

FORMS    += pcl_visualizer.ui

DISTFILES += \
    CMakeLists.txt
