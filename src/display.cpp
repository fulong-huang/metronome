#include <iostream>
#include "display.h"

Display::Display(){
}
void Display::setup(){
};

Display::~Display(){};

void Display::draw(sf::RenderWindow& window){
	
	window.clear();

	for(sf::Drawable* s : drawables){
		window.draw(*s);
	};
	window.display();
}

void Display::handleMouseClick(sf::Vector2i mousePos){
}

void Display::addShape(sf::Drawable* s){
	this->drawables.push_back(s);
};




