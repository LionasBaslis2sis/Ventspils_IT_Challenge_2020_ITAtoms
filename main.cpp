#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <bits/stdc++.h>

#include "simulation.hpp"

int main(const int argc, const char** argv) {
	// set random seed
	srand(time(NULL));
	/// window setup	
	sf::VideoMode mode(768, 512);
	const char* name = "Simulation";
	int style = sf::Style::Titlebar | sf::Style::Close;
	sf::RenderWindow window(mode, name, style);
	sf::Event event;
	/// resources
	tgui::Font font("res/consolas.ttf");
	tgui::Theme theme("res/Black.txt");
	tgui::Theme::setDefault(&theme);
	// simulation
	bool update = false;
	Simulation sim(mode);
	/// gui
	tgui::Gui gui(window);
	// info label
	std::stringstream sstream;
	auto info = tgui::Label::create();
	info->setPosition(mode.width - info->getSize().x - 10, 10);
	gui.add(info);
	// team info label
	auto team_info = tgui::Label::create();
    team_info->setText("Developed within Ventspils IT challange 2020\nITAtoms: Arnas Vaicekauskas, Justas Komza and Elijus Zemgulis. Mentor: Ramune Simkuviene");
    team_info->setPosition(10, mode.height - team_info->getSize().y - 10);
    gui.add(team_info);
	// start button
	auto start = tgui::Button::create();
    start->setPosition(10, 10);
    start->setText("Start");
    start->setSize(72, 32);
    start->connect("pressed", [&](){update = true;});
    gui.add(start);
	// stop button
	auto stop = tgui::Button::create();
    stop->setPosition(92, 10);
    stop->setText("Stop");
    stop->setSize(72, 32);
    stop->connect("pressed", [&](){update = false;});
    gui.add(stop);
	// exit button
	auto exit = tgui::Button::create();
    exit->setPosition(174, 10);
    exit->setText("Exit");
    exit->setSize(72, 32);
    exit->connect("pressed", [&](){ window.close(); });
    gui.add(exit);
	/// loop setup
	sf::Clock clock;
	long now = 0, last = 0, dt = 0;
	// accumulated time
	long t = 0;
	/// loop
	while(window.isOpen()) {
		last = now;
		now = clock.getElapsedTime().asMilliseconds();
		if(update) {
			dt = now - last;
			t += dt;
			sim.iterate(dt, t);
		}
		sstream << std::fixed << std::setprecision(2) << t / 1000.0f;
		info->setText("time: " + sstream.str());
		sstream.str("");
		info->setPosition(mode.width - info->getSize().x - 10, 10);
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) window.close();
			gui.handleEvent(event);
		}
		window.clear();
		window.draw(sim);
		gui.draw();
		window.display();
	}
	return EXIT_SUCCESS;
}
