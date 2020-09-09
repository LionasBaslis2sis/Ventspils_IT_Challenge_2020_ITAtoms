#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <bits/stdc++.h>

int main(const int argc, const char** argv) {
	// window setup	
	sf::VideoMode mode(1024, 768);
	const char* name = "Simulation";
	int style = sf::Style::Titlebar | sf::Style::Close;
	sf::RenderWindow window(mode, name, style);
	sf::Event event;
	// loop
	while(window.isOpen()) {
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) window.close();
		}
		window.clear();
		window.display();
	}
	return EXIT_SUCCESS;
}