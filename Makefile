OBJS = main.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I./include

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L./lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2_image -lmingw32 -lSDL2main -lSDL2
#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = ./bin/main

#This is the target that compiles our executable
all : compile_dll_window compile_main run
compile_dll_window:
	g++ -c -DBUILD_MY_DLL ./src/Window.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS)  $(LINKER_FLAGS) -o ./obj/window.o
	g++ -shared -o ./bin/window.dll ./obj/window.o -Wl,--out-implib,./lib/libwindow.a $(INCLUDE_PATHS) $(LIBRARY_PATHS)  $(LINKER_FLAGS) 
compile_main:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -lwindow $(LINKER_FLAGS) -o $(OBJ_NAME)
run:
	./bin/main