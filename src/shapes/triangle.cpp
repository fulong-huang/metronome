#include "triangle.h"

#include <iostream>

Triangle::Triangle(sf::Color color, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2i pos):
	color(color), p1(p1), p2(p2), p3(p3), pos(pos)
{
	this->setup();
};

Triangle::~Triangle(){

};

Triangle::Triangle(const Triangle& c):
	color(c.color), p1(c.p1), p2(c.p2), p3(c.p3), pos(c.pos)
{
	this->setup();
};

Triangle Triangle::operator=(const Triangle& c){
	this->color = c.color;
	this->p1 = c.p1;
	this->p2 = c.p2;
	this->p3 = c.p3;
	this->pos = c.pos;

	this->setup();

	return *this;
};

void Triangle::setup(){
	this->shape.setPointCount(3);
	sf::Vector2f thisPos = sf::Vector2f(this->pos);
	this->shape.setPoint(0, this->p1 + thisPos);
	this->shape.setPoint(1, this->p2 + thisPos);
	this->shape.setPoint(2, this->p3 + thisPos);

	this->shape.setFillColor(this->color);
	//this->shape.setPosition(this->pos.x, this->pos.y);
	this->findDimensions();
};

void Triangle::findDimensions(){
	int width = p1.x;
	int height = p1.y;
	if(p2.x > width){
		width = p2.x;
	};
	if(p3.x > width){
		width = p3.x;
	};
	if(p2.y > height){
		height = p2.y;
	};
	if(p3.y > height){
		height = p3.y;
	};
	this->width = width;
	this->height = height;
};

sf::Shape* Triangle::get(){
	return &this->shape;
};

void Triangle::setColor(sf::Color color){
	this->color = color;
	this->shape.setFillColor(color);
};

void Triangle::setPosition(sf::Vector2i pos) {
	this->pos = pos;

	sf::Vector2f thisPos = sf::Vector2f(this->pos);
	this->shape.setPoint(0, this->p1 + thisPos);
	this->shape.setPoint(1, this->p2 + thisPos);
	this->shape.setPoint(2, this->p3 + thisPos);
	// this->shape.setPosition(this->pos.x, this->pos.y);
	// this->findDimensions();
};

void Triangle::setSize(int width, int height){
	float widthRatio = float(width) / this->width;
	float heightRatio = float(height) / this->height;
	p1.x *= widthRatio;
	p2.x *= widthRatio;
	p3.x *= widthRatio;
	p1.y *= heightRatio;
	p2.y *= heightRatio;
	p3.y *= heightRatio;

	sf::Vector2f thisPos = sf::Vector2f(this->pos);
	this->shape.setPoint(0, this->p1 + thisPos);
	this->shape.setPoint(1, this->p2 + thisPos);
	this->shape.setPoint(2, this->p3 + thisPos);

	this->shape.setFillColor(this->color);
	this->width = width;
	this->height = height;
	//this->shape.setPosition(this->pos.x, this->pos.y);
};

sf::Color Triangle::getColor() {
	return this->color;
};
sf::Vector2i Triangle::getPosition() {
	return this->pos;
};
sf::Vector2i Triangle::getSize() {
	return {this->width, this->height};
};

bool Triangle::boundCheck(sf::Vector2i pos) {
	// TODO
	bool inBound = 
		this->pos.x <= pos.x &&
		this->pos.y <= pos.y &&
		this->pos.x + this->width >= pos.x &&
		this->pos.y + this->height >= pos.y;
	return inBound;
};

