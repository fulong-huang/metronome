#include "circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(sf::Color color, sf::Vector2i pos, int radius):
	color(color), radius(radius), pos(pos)
{
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->pos.x, this->pos.y);
};

Circle::~Circle(){

};

Circle::Circle(const Circle& c):
	color(c.color), radius(c.radius), pos(c.pos)
{
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->pos.x, this->pos.y);
};

Circle Circle::operator=(const Circle& c){
	this->color = c.color;
	this->radius = c.radius;
	this->pos = c.pos;
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(this->color);
	this->shape.setPosition(this->pos.x, this->pos.y);
	return *this;
};

sf::Drawable* Circle::get(){
	return &this->shape;
};

void Circle::setColor(sf::Color color){
	this->color = color;
	this->shape.setFillColor(color);
};

void Circle::setPosition(sf::Vector2i pos) {
	this->pos = pos;
	this->shape.setPosition(this->pos.x, this->pos.y);
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
sf::Vector2i Circle::getPosition() {
	return this->pos;
};
sf::Vector2i Circle::getSize() {
	return {this->radius * 2, this->radius * 2};
};

bool Circle::boundCheck(sf::Vector2i pos) {
	int distX = pos.x - this->pos.x - this->radius;
	int distY = pos.y - this->pos.y - this->radius;
	float dist = std::sqrt(distX * distX + distY * distY);
	return dist <= this->radius;
};

