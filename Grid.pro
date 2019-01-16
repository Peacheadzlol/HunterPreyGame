TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11

#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\..\SFML-2.3.2\lib"
#LIBS += -L"..\..\SFML-2.3.2\bin"

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "..\..\SFML-2.3.2\include"
#DEPENDPATH += "..\..\SFML-2.3.2\include"

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"


SOURCES += main.cpp \
    grid.cpp \
    creature.cpp \
    wall.cpp \
    hunter.cpp \
    prey.cpp \
    balancer.cpp


HEADERS += \
    grid.h \
    creature.h \
    constant.h \
    wall.h \
    hunter.h \
    prey.h \
    balancer.h
