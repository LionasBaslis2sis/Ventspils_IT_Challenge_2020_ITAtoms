INCS =  -I"C:\libs\SFML\include" -I"C:\libs\TGUI\include" \
		-L"C:\libs\SFML\lib" -L"C:\libs\TGUI\lib" \

LIBS = -lm -ltgui-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s \
-lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-audio-s -lopenal32 \
-lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lsfml-network-s \
-lws2_32 -lwinmm

all:
	@ g++ -std=c++17 main.cpp simulation.cpp -o main.exe -DSFML_STATIC -DTGUI_STATIC $(INCS) $(LIBS)