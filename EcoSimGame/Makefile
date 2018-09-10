
all:
	c++ -o GameRoot/EcoSimGame -I/usr/include/SDL2 Source/Font.cpp \
		Source/Font_Subsystem.cpp Source/Game.cpp \
		Source/Image_Subsystem.cpp Source/main.cpp \
		Source/SDL_Subsystem.cpp Source/Subsystems.cpp \
		-lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	rm GameRoot/EcoSimGame Font.o Font_Subsystem.o Game.o \
		Image_Subsystem.o main.o SDL_Subsystem.o Subsystems.o


