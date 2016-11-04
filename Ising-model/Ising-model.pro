TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    isingmodel.cpp \
    examples.cpp \
    main.cpp

HEADERS += \
    isingmodel.h \
    examples.h

#MPI settings

#QMAKE_CXX = C:\Users\Username\AppData\Local\Lxss\rootfs\usr\bin\mpic++
#QMAKE_CXX_RELEASE = $$QMAKE_CXX
#QMAKE_CXX_DEBUG = $$QMAKE_CXX
#QMAKE_LINK = $$QMAKE_CXX
#QMAKE_CC = mpicc

#QMAKE_CFLAGS += $system(C:\Users\Username\AppData\Local\Lxss\rootfs\usr\bin\mpicc --showme:compile)
#QMAKE_LFLAGS += $$system(C:\Users\Username\AppData\Local\Lxss\rootfs\usr\bin\mpicxx --showme:link)
#QMAKE_CXXFLAGS += $$system(C:\Users\Username\AppData\Local\Lxss\rootfs\usr\bin\mpicxx --showme:compile) -DMPICH_IGNORE_CXX_SEEK
#QMAKE_CXXFLAGS_RELEASE += $$system(C:\Users\Username\AppData\Local\Lxss\rootfs\usr\bin\mpicxx --showme:compile) -DMPICH_IGNORE_CXX_SEEK /*

