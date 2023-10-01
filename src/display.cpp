#include "display.h"

Display::Display(){
    this->window.create(sf::VideoMode(800, 600), "Metronome");
    this->shape.setRadius(300.f);
    this->shape.setFillColor(sf::Color::Red);
}

void Display::runGame(){
    std::cout << this->metronome.isPlaying() << std::endl;
    while(this->window.isOpen()){
        sf::Event event;
        while(this->window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                this->window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                this->handleMouseClick();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
	if(this->metronome.isPlaying()){
		this->metronome.pause();
	}
}

void Display::handleMouseClick(){
    std::cout << "HANDLE MOUSE CLICK" << std::endl;
    if(this->metronome.isPlaying()){
        this->shape.setFillColor(sf::Color::Red);
        this->metronome.pause();
    }
    else{
        this->shape.setFillColor(sf::Color::Green);
        this->metronome.start();
    }
}



