#include "display.h"
#include "metronome.h"

int main(){

    Display display;
	Metronome metronome;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Metronome");

	sf::Event event;
	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			else if(event.type == sf::Event::MouseButtonPressed){
				sf::Vector2i mousePos = sf::Mouse::getPosition();
				display.handleMouseClick(mousePos);
				if(metronome.isPlaying()){
					metronome.stop();
				}
				else{
					metronome.start();
				};
			}
		}

		display.draw(window);
	};

	if (metronome.isPlaying()){
		metronome.stop();
	};
	// while loop
	// 		check mouse click
	// 			metronome handle mouse click
	// 			display object handle mouse click
	// 		update display
	//
    
    return 0;
}

