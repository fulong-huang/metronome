#pragma once
#include "SFML/Graphics.hpp"
class Shape{
public:
	Shape(){}
	virtual ~Shape(){}

	virtual sf::Shape* get() = 0;
	virtual void setColor(sf::Color c) = 0;
	virtual void setPosition(sf::Vector2i pos) = 0;
	virtual void setSize(int w = 0, int h = 0) = 0;

	virtual sf::Color getColor() = 0;
	virtual sf::Vector2i getPosition() = 0;
	virtual sf::Vector2i getSize() = 0;

	virtual bool boundCheck(sf::Vector2i pos) = 0;
};


