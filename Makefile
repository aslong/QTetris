#############################################################################
# Makefile for building: QTetris
# Generated by qmake (2.01a) (Qt 4.8.0) on: Tue Mar 20 23:36:57 2012
# Project:  QTetris.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile QTetris.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m32 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m32 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../work/staging/mkspecs/default -I. -I../../work/staging/include/QtCore -I../../work/staging/include/QtGui -I../../work/staging/include -I. -I.
LINK          = g++
LFLAGS        = -m32 -Wl,-rpath,/home/andrew/Documents/work/staging//lib
LIBS          = $(SUBLIBS)  -L/home/andrew/Documents/work/staging//lib -lQtGui -L/home/andrew/Documents/work/staging//lib -L/usr/X11R6/lib64 -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = TetrisGrid.cpp \
		TetrisScene.cpp \
		QTetrisWindow.cpp \
		Block.cpp \
		LineBlock.cpp \
		GameBorder.cpp \
		main.cpp moc_TetrisGrid.cpp \
		moc_QTetrisWindow.cpp
OBJECTS       = TetrisGrid.o \
		TetrisScene.o \
		QTetrisWindow.o \
		Block.o \
		LineBlock.o \
		GameBorder.o \
		main.o \
		moc_TetrisGrid.o \
		moc_QTetrisWindow.o
DIST          = ../../work/staging/mkspecs/common/unix.conf \
		../../work/staging/mkspecs/common/linux.conf \
		../../work/staging/mkspecs/common/gcc-base.conf \
		../../work/staging/mkspecs/common/gcc-base-unix.conf \
		../../work/staging/mkspecs/common/g++-base.conf \
		../../work/staging/mkspecs/common/g++-unix.conf \
		../../work/staging/mkspecs/qconfig.pri \
		../../work/staging/mkspecs/features/qt_functions.prf \
		../../work/staging/mkspecs/features/qt_config.prf \
		../../work/staging/mkspecs/features/exclusive_builds.prf \
		../../work/staging/mkspecs/features/default_pre.prf \
		../../work/staging/mkspecs/features/debug.prf \
		../../work/staging/mkspecs/features/default_post.prf \
		../../work/staging/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../work/staging/mkspecs/features/warn_on.prf \
		../../work/staging/mkspecs/features/qt.prf \
		../../work/staging/mkspecs/features/unix/thread.prf \
		../../work/staging/mkspecs/features/moc.prf \
		../../work/staging/mkspecs/features/resources.prf \
		../../work/staging/mkspecs/features/uic.prf \
		../../work/staging/mkspecs/features/yacc.prf \
		../../work/staging/mkspecs/features/lex.prf \
		../../work/staging/mkspecs/features/include_source_dir.prf \
		QTetris.pro
QMAKE_TARGET  = QTetris
DESTDIR       = 
TARGET        = QTetris

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -z "$(DESTDIR)" || cd "$(DESTDIR)"; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex 'save gdb-index .' -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: QTetris.pro  ../../work/staging/mkspecs/default/qmake.conf ../../work/staging/mkspecs/common/unix.conf \
		../../work/staging/mkspecs/common/linux.conf \
		../../work/staging/mkspecs/common/gcc-base.conf \
		../../work/staging/mkspecs/common/gcc-base-unix.conf \
		../../work/staging/mkspecs/common/g++-base.conf \
		../../work/staging/mkspecs/common/g++-unix.conf \
		../../work/staging/mkspecs/qconfig.pri \
		../../work/staging/mkspecs/features/qt_functions.prf \
		../../work/staging/mkspecs/features/qt_config.prf \
		../../work/staging/mkspecs/features/exclusive_builds.prf \
		../../work/staging/mkspecs/features/default_pre.prf \
		../../work/staging/mkspecs/features/debug.prf \
		../../work/staging/mkspecs/features/default_post.prf \
		../../work/staging/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../work/staging/mkspecs/features/warn_on.prf \
		../../work/staging/mkspecs/features/qt.prf \
		../../work/staging/mkspecs/features/unix/thread.prf \
		../../work/staging/mkspecs/features/moc.prf \
		../../work/staging/mkspecs/features/resources.prf \
		../../work/staging/mkspecs/features/uic.prf \
		../../work/staging/mkspecs/features/yacc.prf \
		../../work/staging/mkspecs/features/lex.prf \
		../../work/staging/mkspecs/features/include_source_dir.prf \
		/home/andrew/Documents/work/staging/lib/libQtGui.prl \
		/home/andrew/Documents/work/staging/lib/libQtCore.prl
	$(QMAKE) -o Makefile QTetris.pro
../../work/staging/mkspecs/common/unix.conf:
../../work/staging/mkspecs/common/linux.conf:
../../work/staging/mkspecs/common/gcc-base.conf:
../../work/staging/mkspecs/common/gcc-base-unix.conf:
../../work/staging/mkspecs/common/g++-base.conf:
../../work/staging/mkspecs/common/g++-unix.conf:
../../work/staging/mkspecs/qconfig.pri:
../../work/staging/mkspecs/features/qt_functions.prf:
../../work/staging/mkspecs/features/qt_config.prf:
../../work/staging/mkspecs/features/exclusive_builds.prf:
../../work/staging/mkspecs/features/default_pre.prf:
../../work/staging/mkspecs/features/debug.prf:
../../work/staging/mkspecs/features/default_post.prf:
../../work/staging/mkspecs/features/unix/gdb_dwarf_index.prf:
../../work/staging/mkspecs/features/warn_on.prf:
../../work/staging/mkspecs/features/qt.prf:
../../work/staging/mkspecs/features/unix/thread.prf:
../../work/staging/mkspecs/features/moc.prf:
../../work/staging/mkspecs/features/resources.prf:
../../work/staging/mkspecs/features/uic.prf:
../../work/staging/mkspecs/features/yacc.prf:
../../work/staging/mkspecs/features/lex.prf:
../../work/staging/mkspecs/features/include_source_dir.prf:
/home/andrew/Documents/work/staging/lib/libQtGui.prl:
/home/andrew/Documents/work/staging/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile QTetris.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/QTetris1.0.0 || $(MKDIR) .tmp/QTetris1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/QTetris1.0.0/ && $(COPY_FILE) --parents TetrisGrid.h TetrisScene.h QTetrisWindow.h Block.h LineBlock.h GameBorder.h .tmp/QTetris1.0.0/ && $(COPY_FILE) --parents TetrisGrid.cpp TetrisScene.cpp QTetrisWindow.cpp Block.cpp LineBlock.cpp GameBorder.cpp main.cpp .tmp/QTetris1.0.0/ && (cd `dirname .tmp/QTetris1.0.0` && $(TAR) QTetris1.0.0.tar QTetris1.0.0 && $(COMPRESS) QTetris1.0.0.tar) && $(MOVE) `dirname .tmp/QTetris1.0.0`/QTetris1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/QTetris1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_TetrisGrid.cpp moc_QTetrisWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_TetrisGrid.cpp moc_QTetrisWindow.cpp
moc_TetrisGrid.cpp: Block.h \
		GameBorder.h \
		TetrisGrid.h
	/home/andrew/Documents/work/staging//bin/moc-palm $(DEFINES) $(INCPATH) TetrisGrid.h -o moc_TetrisGrid.cpp

moc_QTetrisWindow.cpp: TetrisScene.h \
		TetrisGrid.h \
		Block.h \
		GameBorder.h \
		QTetrisWindow.h
	/home/andrew/Documents/work/staging//bin/moc-palm $(DEFINES) $(INCPATH) QTetrisWindow.h -o moc_QTetrisWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

TetrisGrid.o: TetrisGrid.cpp TetrisGrid.h \
		Block.h \
		GameBorder.h \
		LineBlock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TetrisGrid.o TetrisGrid.cpp

TetrisScene.o: TetrisScene.cpp TetrisScene.h \
		TetrisGrid.h \
		Block.h \
		GameBorder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TetrisScene.o TetrisScene.cpp

QTetrisWindow.o: QTetrisWindow.cpp QTetrisWindow.h \
		TetrisScene.h \
		TetrisGrid.h \
		Block.h \
		GameBorder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QTetrisWindow.o QTetrisWindow.cpp

Block.o: Block.cpp Block.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Block.o Block.cpp

LineBlock.o: LineBlock.cpp LineBlock.h \
		Block.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LineBlock.o LineBlock.cpp

GameBorder.o: GameBorder.cpp GameBorder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GameBorder.o GameBorder.cpp

main.o: main.cpp QTetrisWindow.h \
		TetrisScene.h \
		TetrisGrid.h \
		Block.h \
		GameBorder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

moc_TetrisGrid.o: moc_TetrisGrid.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_TetrisGrid.o moc_TetrisGrid.cpp

moc_QTetrisWindow.o: moc_QTetrisWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_QTetrisWindow.o moc_QTetrisWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

