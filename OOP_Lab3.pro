QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game/Enemies/beagle.cpp \
    Game/Enemies/enemy.cpp \
    Game/Enemies/skeleton.cpp \
    Game/Enemies/troll.cpp \
    Game/Field/field.cpp \
    Game/Field/point.cpp \
    Game/Hero/hero.cpp \
    Game/Interfaces/interfaceforpoint.cpp \
    Game/Items/boots.cpp \
    Game/Items/healingpotion.cpp \
    Game/Items/item.cpp \
    Game/Items/sword.cpp \
    Game/Logic/builder.cpp \
    Game/Logic/interacter.cpp \
    Game/Logic/levelbuilder.cpp \
    Game/Logic/mover.cpp \
    Game/Logic/moverhero.cpp \
    Game/Paint/levelpainter.cpp \
    Game/Paint/painter.cpp \
    Game/Paint/palette.cpp \
    Game/game.cpp \
    Game/loader.cpp \
    Game/logger.cpp \
    Game/loggerconsole.cpp \
    Game/loggerfile.cpp \
    Game/main.cpp \
    Game/mainwindow.cpp \
    Game/reader.cpp \
    Game/saver.cpp \
    rules.cpp

HEADERS += \
    Game/Enemies/beagle.h \
    Game/Enemies/enemy.h \
    Game/Enemies/skeleton.h \
    Game/Enemies/troll.h \
    Game/Field/field.h \
    Game/Field/point.h \
    Game/Hero/hero.h \
    Game/Interfaces/interfaceforpoint.h \
    Game/Items/boots.h \
    Game/Items/healingpotion.h \
    Game/Items/item.h \
    Game/Items/sword.h \
    Game/KeysName.h \
    Game/Logic/builder.h \
    Game/Logic/interacter.h \
    Game/Logic/levelbuilder.h \
    Game/Logic/mover.h \
    Game/Logic/moverhero.h \
    Game/Paint/levelpainter.h \
    Game/Paint/painter.h \
    Game/Paint/palette.h \
    Game/game.h \
    Game/loader.h \
    Game/logger.h \
    Game/loggerconsole.h \
    Game/loggerfile.h \
    Game/mainwindow.h \
    Game/reader.h \
    Game/saver.h \
    rules.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
