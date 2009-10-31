#############################################################################
# Makefile for building: bin/Casual_processes
# Generated by qmake (2.01a) (Qt 4.5.2) on: ?? ???. 31 19:04:03 2009
# Project:  Casual_processes.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile Casual_processes.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Ibuild
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib /usr/lib/libqwt-qt4.so -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/mainwindowimpl.cpp \
		src/main.cpp \
		src/histogram_item.cpp \
		src/lab1_1.cpp \
		src/lab1_2.cpp \
		src/lab1_3.cpp build/moc_mainwindowimpl.cpp \
		build/moc_lab1_1.cpp \
		build/moc_lab1_2.cpp \
		build/moc_lab1_3.cpp \
		qrc_windowrc.cpp
OBJECTS       = build/mainwindowimpl.o \
		build/main.o \
		build/histogram_item.o \
		build/lab1_1.o \
		build/lab1_2.o \
		build/lab1_3.o \
		build/moc_mainwindowimpl.o \
		build/moc_lab1_1.o \
		build/moc_lab1_2.o \
		build/moc_lab1_3.o \
		build/qrc_windowrc.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Casual_processes.pro
QMAKE_TARGET  = Casual_processes
DESTDIR       = bin/
TARGET        = bin/Casual_processes

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
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Casual_processes.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile Casual_processes.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile Casual_processes.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Casual_processes1.0.0 || $(MKDIR) build/Casual_processes1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Casual_processes1.0.0/ && $(COPY_FILE) --parents src/mainwindowimpl.h src/histogram_item.h src/lab1_1.h src/lab1_2.h src/lab1_3.h build/Casual_processes1.0.0/ && $(COPY_FILE) --parents windowrc.qrc build/Casual_processes1.0.0/ && $(COPY_FILE) --parents src/mainwindowimpl.cpp src/main.cpp src/histogram_item.cpp src/lab1_1.cpp src/lab1_2.cpp src/lab1_3.cpp build/Casual_processes1.0.0/ && (cd `dirname build/Casual_processes1.0.0` && $(TAR) Casual_processes1.0.0.tar Casual_processes1.0.0 && $(COMPRESS) Casual_processes1.0.0.tar) && $(MOVE) `dirname build/Casual_processes1.0.0`/Casual_processes1.0.0.tar.gz . && $(DEL_FILE) -r build/Casual_processes1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_mainwindowimpl.cpp build/moc_lab1_1.cpp build/moc_lab1_2.cpp build/moc_lab1_3.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_mainwindowimpl.cpp build/moc_lab1_1.cpp build/moc_lab1_2.cpp build/moc_lab1_3.cpp
build/moc_mainwindowimpl.cpp: src/lab1_1.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		src/histogram_item.h \
		src/lab1_2.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		src/lab1_3.h \
		/usr/include/qwt-qt4/qwt_scale_engine.h \
		src/mainwindowimpl.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/mainwindowimpl.h -o build/moc_mainwindowimpl.cpp

build/moc_lab1_1.cpp: /usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		src/histogram_item.h \
		src/lab1_1.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/lab1_1.h -o build/moc_lab1_1.cpp

build/moc_lab1_2.cpp: /usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		src/lab1_2.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/lab1_2.h -o build/moc_lab1_2.cpp

build/moc_lab1_3.cpp: /usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		/usr/include/qwt-qt4/qwt_scale_engine.h \
		src/lab1_3.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/lab1_3.h -o build/moc_lab1_3.cpp

compiler_rcc_make_all: qrc_windowrc.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_windowrc.cpp
qrc_windowrc.cpp: windowrc.qrc \
		images/new.png \
		images/find.png \
		images/exit.png \
		images/start.png \
		images/cut.png \
		images/copy.png \
		images/icon.png \
		images/gotocell.png \
		images/save.png \
		images/paste.png \
		images/clear.png \
		images/open.png
	/usr/bin/rcc -name windowrc windowrc.qrc -o qrc_windowrc.cpp

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
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

build/mainwindowimpl.o: src/mainwindowimpl.cpp src/mainwindowimpl.h \
		src/lab1_1.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		src/histogram_item.h \
		src/lab1_2.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		src/lab1_3.h \
		/usr/include/qwt-qt4/qwt_scale_engine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/mainwindowimpl.o src/mainwindowimpl.cpp

build/main.o: src/main.cpp src/mainwindowimpl.h \
		src/lab1_1.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		src/histogram_item.h \
		src/lab1_2.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		src/lab1_3.h \
		/usr/include/qwt-qt4/qwt_scale_engine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/histogram_item.o: src/histogram_item.cpp /usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_interval_data.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		/usr/include/qwt-qt4/qwt_painter.h \
		/usr/include/qwt-qt4/qwt_layout_metrics.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		src/histogram_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/histogram_item.o src/histogram_item.cpp

build/lab1_1.o: src/lab1_1.cpp src/lab1_1.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		src/histogram_item.h \
		/usr/include/qwt-qt4/qwt_interval_data.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/lab1_1.o src/lab1_1.cpp

build/lab1_2.o: src/lab1_2.cpp src/lab1_2.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		/usr/include/qwt-qt4/qwt_symbol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/lab1_2.o src/lab1_2.cpp

build/lab1_3.o: src/lab1_3.cpp src/lab1_3.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		/usr/include/qwt-qt4/qwt_scale_engine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/lab1_3.o src/lab1_3.cpp

build/moc_mainwindowimpl.o: build/moc_mainwindowimpl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_mainwindowimpl.o build/moc_mainwindowimpl.cpp

build/moc_lab1_1.o: build/moc_lab1_1.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_lab1_1.o build/moc_lab1_1.cpp

build/moc_lab1_2.o: build/moc_lab1_2.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_lab1_2.o build/moc_lab1_2.cpp

build/moc_lab1_3.o: build/moc_lab1_3.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_lab1_3.o build/moc_lab1_3.cpp

build/qrc_windowrc.o: qrc_windowrc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_windowrc.o qrc_windowrc.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

