INCS =  -I"C:\libs\SFML\include" -I"C:\libs\TGUI\include" \
		-L"C:\libs\SFML\lib" -L"C:\libs\TGUI\lib" \

LIBS = -lm -ltgui-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s \
-lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-audio-s -lopenal32 \
-lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lsfml-network-s \
-lws2_32 -lwinmm

CPPS = src/*.cpp
CXX = g++
CXXFLAGS = -std=c++17
LINK_FLAGS = -DSFML_STATIC -DTGUI_STATIC

all:
	@ $(CXX) $(CXXFLAGS) main.cpp $(CPPS) -o main.exe $(LINK_FLAGS) $(INCS) $(LIBS)