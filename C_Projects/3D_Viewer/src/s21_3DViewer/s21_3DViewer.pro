
QT += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets
#=======
QT       += core gui
QT += core widgets

CONFIG += c++11 -O2


#INCLUDEPATH += /opt/homebrew/Cellar/imagemagick/7.1.1-14/include/ImageMagick-7
#INCLUDEPATH += /usr/include/ImageMagick-6
INCLUDEPATH += /usr/local/include/ImageMagick-7
#LIBS += -L/opt/homebrew/Cellar/imagemagick/7.1.1-14/lib -lMagick++-7.Q16HDRI.5 -lMagickCore-7.Q16HDRI.10 -lMagickWand-7.Q16HDRI.10
LIBS += -L/usr/local/lib -lMagick++-7.Q16HDRI.5 -lMagickCore-7.Q16HDRI.10 -lMagickWand-7.Q16HDRI.10
#LIBS += -L/usr/lib/x86_64-linux-gnu -lMagick++-6.Q16 -lMagickCore-6.Q16 -lMagickWand-6.Q16
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
FORMS += \
    mainwindow.ui \

SOURCES += \
    DynamicBuffer/DynamicBuffer.c \
    MainWindow/MainWindow.cpp \
    ModelViewerWidget/MVWidget_DrawModel.cpp \
    AffineTransform/AffineTransform.c \
    ModelViewerWidget/MVWidget_Setters.cpp \
    ModelViewerWidget/MVWidget_Setup.cpp \
    ModelViewerWidget/ModelViewerWidget.cpp \
    OBJLoader/OBJLoader.c \
    OBJLoader/OBJLoader_Create.c \
    OBJLoader/OBJLoader_Destroy.c \
    OBJLoader/OBJLoader_Getline.c \
    OBJLoader/OBJLoader_InvalidData.c \
    OBJLoader/OBJLoader_IsValid.c \
    OBJLoader/OBJLoader_LineManipulation.c \
    OBJLoader/OBJLoader_Load.c \
    OBJLoader/OBJLoader_ParseFormat.c \
    main.cpp

HEADERS += \
    Headers/DynamicBuffer.h \
    Headers/MainWindow.h \
    Headers/ModelViewerWidget.h \
    Headers/OBJLoader.h \
    OBJLoader/OBJLoader_Util.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

