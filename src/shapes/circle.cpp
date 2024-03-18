#include "circle.h"
#include <iostream>

Circle::Circle(sf::Color color, int radius, int x, int y):
	color(color), radius(radius), posX(x), posY(y)
{
	this->circle.setRadius(this->radius);
	this->circle.setFillColor(this->color);
	this->circle.setPosition(this->posX, this->posY);
};

Circle::~Circle(){

};

Circle::Circle(const Circle& c):
	color(c.color), radius(c.radius), posX(c.posX), posY(c.posY)
{
	this->circle.setRadius(this->radius);
	this->circle.setFillColor(this->color);
	this->circle.setPosition(this->posX, this->posY);
};

Circle Circle::operator=(const Circle& c){
	this->color = c.color;
	this->radius = c.radius;
	this->posX = c.posX;
	this->posY = c.posY;
	this->circle.setRadius(this->radius);
	this->circle.setFillColor(this->color);
	this->circle.setPosition(this->posX, this->posY);
	return *this;
};

sf::Shape& Circle::get(){
	return this->circle;
};

void Circle::setColor(sf::Color color){
	this->color = color;
	this->circle.setFillColor(color);
};

void Circle::setPosition(int x, int y) {
	this->posX = x;
	this->posY = y;
	this->circle.setPosition(this->posX, this->posY);
};

void Circle::setSize(int r, int c){
	if(r == -1){
		this->radius += c;
		if(this->radius < 0){
			this->radius = 0;
		};
	}
	else{
		this->radius = r;
	};
	this->circle.setRadius(this->radius);
};

sf::Color Circle::getColor() {
	return this->color;
};
std::pair<int, int> Circle::getPosition() {
	return {this->posX, this->posY};
};
int Circle::getSize() {
	return this->radius;
};

bool Circle::boundCheck(sf::Vector2i pos) {
	return true;
};

