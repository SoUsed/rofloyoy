TEMPLATE = app

QT += qml quick widgets websockets network multimedia

SOURCES += main.cpp \
    mainrofl.cpp \
    multiplayer_server.cpp \
    multiplayer_client.cpp

RESOURCES += qml.qrc \
    resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainrofl.h \
    multiplayer_server.h \
    multiplayer_client.h

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    androdid/AndroidManifest.xml \
    android/AndroidManifest.xml

