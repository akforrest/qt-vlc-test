#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T15:13:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-vlc-test
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

VLC_QT_PATH = ../vlc-qt/vlc-qt-build

TARGET_OS = win

android {
    TARGET_OS = android
}

INCLUDEPATH += $${VLC_QT_PATH}/include

android {
    # static link vlc-qt, dynamic link libvlc
    LIBS += $${VLC_QT_PATH}/$${TARGET_OS}/libVLCQtCore.a
    LIBS += $${VLC_QT_PATH}/$${TARGET_OS}/libVLCQtWidgets.a

    LIBS += -L$$PWD/android/libs/armeabi-v7a -lvlcjni

    DISTFILES += \
        android/AndroidManifest.xml \
        android/gradle/wrapper/gradle-wrapper.jar \
        android/gradlew \
        android/res/values/libs.xml \
        android/build.gradle \
        android/gradle/wrapper/gradle-wrapper.properties \
        android/gradlew.bat

    ANDROID_PACKAGE_SOURCE_DIR = $${PWD}/android
}
else {

    LIBS += -L$${VLC_QT_PATH}/$${TARGET_OS}

    VLC_LIB = -lVLCQtCore -lVLCQtWidgets

    CONFIG(debug, debug|release) {
        win32 {
            VLC_LIB = -lVLCQtCored -lVLCQtWidgetsd
        }
    }

    LIBS += $${VLC_LIB}
}
