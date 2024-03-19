#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(sf::Color color, int width, int height, int x, int y):
	color(color), width(width), height(height), posX(x), posY(y)
{
	this->shape.setSize({float(this->width), float(this->height)});
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->posX, this->posY);
};

Rectangle::~Rectangle(){

};

Rectangle::Rectangle(const Rectangle& c):
	color(c.color), width(c.width), height(c.height), posX(c.posX), posY(c.posY)
{
	this->shape.setSize({float(this->width), float(this->height)});
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->posX, this->posY);
};

Rectangle Rectangle::operator=(const Rectangle
	& c){
	this->color = c.color;
	this->width = c.width;
	this->height = c.height;
	this->posX = c.posX;
	this->posY = c.posY;
	this->shape.setSize({float(this->width), float(this->height)});
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->posX, this->posY);
	return *this;
};

sf::Shape* Rectangle::get(){
	return &this->shape;
};

void Rectangle::setColor(sf::Color color){
	this->color = color;
	this->shape.setFillColor(color);
};

void Rectangle::setPosition(int x, int y) {
	this->posX = x;
	this->posY = y;
	this->shape.setPosition(this->posX, this->posY);
};

void Rectangle::setSize(int width, int height){
	this->width = width;
	this->height = height;
	this->shape.setSize({float(this->width), float(this->height)});
};

sf::Color Rectangle::getColor() {
	return this->color;
};
std::pair<int, int> Rectangle::getPosition() {
	return {this->posX, this->posY};
};
sf::Vector2i Rectangle::getSize() {
	return {this->width, this->height};
};

bool Rectangle::boundCheck(sf::Vector2i pos) {
	bool inBound = 
		this->posX <= pos.x &&
		this->posY <= pos.y &&
		this->posX + this->width >= pos.x &&
		this->posY + this->height >= pos.y;
	return inBound;
};

