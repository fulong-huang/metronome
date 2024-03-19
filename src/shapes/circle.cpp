#include "circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(sf::Color color, int radius, int x, int y):
	color(color), radius(radius), posX(x), posY(y)
{
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->posX, this->posY);
};

Circle::~Circle(){

};

Circle::Circle(const Circle& c):
	color(c.color), radius(c.radius), posX(c.posX), posY(c.posY)
{
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->posX, this->posY);
};

Circle Circle::operator=(const Circle& c){
	this->color = c.color;
	this->radius = c.radius;
	this->posX = c.posX;
	this->posY = c.posY;
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->posX, this->posY);
	return *this;
};

sf::Shape* Circle::get(){
	return &this->shape;
};

void Circle::setColor(sf::Color color){
	this->color = color;
	this->shape.setFillColor(color);
};

void Circle::setPosition(int x, int y) {
	this->posX = x;
	this->posY = y;
	this->shape.setPosition(this->posX, this->posY);
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
	this->shape.setRadius(this->radius);
};

sf::Color Circle::getColor() {
	return this->color;
};
std::pair<int, int> Circle::getPosition() {
	return {this->posX, this->posY};
};
sf::Vector2i Circle::getSize() {
	return {this->radius * 2, this->radius * 2};
};

bool Circle::boundCheck(sf::Vector2i pos) {
	int distX = pos.x - this->posX - this->radius;
	int distY = pos.y - this->posY - this->radius;
	float dist = std::sqrt(distX * distX + distY * distY);
	return dist <= this->radius;
};

