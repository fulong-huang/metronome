#include "drawable.h"

void Drawable::setup(){
	this->shape.setPointCount(this->points.size());
	for(int i = 0; i < this->points.size(); i++){
		this->shape.setPoint(i, sf::Vector2f(this->points[i] + this->pos));
	};
	this->shape.setFillColor(this->color);
};

Drawable::Drawable(sf::Color color, sf::Vector2i pos, std::vector<sf::Vector2i> points):
	color(color), pos(pos), points(points)
{
	this->setup();
};

Drawable::~Drawable(){

};

Drawable::Drawable(const Drawable& d){
	this->pos = d.pos;
	this->color = d.color;
	this->points = d.points;
	this->setup();
};

Drawable Drawable::operator=(const Drawable& d){
	this->pos = d.pos;
	this->color = d.color;
	this->points = d.points;
	this->setup();
	return *this;
};

sf::Drawable* Drawable::get(){
	return &this->shape;
};


