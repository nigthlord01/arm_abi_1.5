#-------------------------------------------------
#
# Project created by QtCreator 2022-07-14T08:36:31
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport

MOC_DIR = .moc
OBJECTS_DIR = .obj
UI_DIR = .ui
RCC_DIR = .rcc
DESTDIR  =$$PWD/bin
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arm_abi
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


SOURCES += \
    src/main.cpp \
    src/abi.cpp \
    src/authenticator.cpp \
    src/list_password.cpp \
    src/form_dev.cpp \
    src/user_bt.cpp \
    src/chpass.cpp \
    src/settings.cpp \
    src/kc_bt.cpp \
    src/access_to_resources.cpp \
    src/mand_seiting.cpp \
    src/audit.cpp \
    src/audit_settings.cpp \
    src/filesystem.cpp \
    src/object_anti.cpp \
    src/object_kc.cpp


HEADERS += \
    src/abi.h \
    src/authenticator.h \
    src/list_password.h \
    src/form_dev.h \
    src/user_bt.h \
    src/chpass.h \
    src/settings.h \
    src/kc_bt.h \
    src/access_to_resources.h \
    src/mand_seiting.h \
    src/audit.h \
    src/audit_settings.h \
    src/filesystem.h \
    src/object_anti.h \
    src/object_kc.h


FORMS += \
    src/abi.ui \
    src/authenticator.ui \
    src/list_password.ui \
    src/form_dev.ui \
    src/user_bt.ui \
    src/chpass.ui \
    src/settings.ui \
    src/kc_bt.ui \
    src/access_to_resources.ui \
    src/mand_seiting.ui \
    src/audit.ui \
    src/audit_settings.ui \
    src/filesystem.ui \
    src/object_anti.ui \
    src/object_kc.ui

