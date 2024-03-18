#include "display.h"
#include <iostream>

Display::Display(){
	this->setup();
}

Display::~Display(){};

void Display::draw(sf::RenderWindow& window){
	
	window.clear();

	for(Shape* s : shapes){
		window.draw(s->get());
	};
	//window.draw(c);
	window.display();
}

void Display::handleMouseClick(sf::Vector2i mousePos){
	if(shapes[0]->getColor() == sf::Color::Red){
		shapes[0]->setColor(sf::Color::Green);
	}
	else{
		shapes[0]->setColor(sf::Color::Red);
	};
}

void Display::setup(){
	Circle* circle = new Circle(sf::Color::Red, 300);
	shapes.push_back(circle);
};


