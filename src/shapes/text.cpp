#include "text.h"
#include <iostream>
#include <filesystem>

Text::Text(sf::Color color, sf::Vector2i pos, std::string str, int fontSize,
		bool centered, bool transparent, std::string fontName, sf::Uint32 style):
	color(color), pos(pos), str(str), fontSize(fontSize), style(style), transparent(transparent), centered(centered)
{
	this->setup();
};


Text::~Text(){

};

Text::Text(const Text& t){
	this->color = t.color;
	this->pos = t.pos;
	this->style = t.style;
	this->str = t.str;
	this->fontName = t.fontName;
	this->fontSize = t.fontSize;
	this->transparent = t.transparent;
	this->centered = t.centered;

	this->setup();
};

Text Text::operator=(const Text& t){
	this->color = t.color;
	this->pos = t.pos;
	this->style = t.style;
	this->str = t.str;
	this->transparent = t.transparent;
	this->fontName = t.fontName;
	this->fontSize = t.fontSize;

	this->setup();
	return *this;
};

void Text::setup(){
    std::string srcDir = std::__fs::filesystem::path(__FILE__).parent_path();
	srcDir += "/../../resources/";
	if(!this->font.loadFromFile(srcDir + "Silkscreen/slkscr.ttf")){
		std::cout << "Font " << fontName  << " Failed to Load" << std::endl;
		return;
	};
	this->text.setFont(this->font);
	this->text.setString(this->str);
	this->text.setCharacterSize(this->fontSize);
	if(this->transparent){
		this->text.setFillColor(sf::Color::Transparent);
	}
	else{
		this->text.setFillColor(this->color);
	};
	this->text.setStyle(style);
	if(centered){
		float width = this->text.getLocalBounds().width;
		float height = this->text.getLocalBounds().height;
		this->text.setPosition(
				this->pos.x - width/2,
				this->pos.y - height/2);
	}
	else{
		this->text.setPosition(this->pos.x, this->pos.y);
	};
};

sf::Drawable* Text::get(){
	return &this->text;
};

void Text::setColor(sf::Color color){
	this->color = color;
	this->text.setFillColor(this->color);
};

void Text::setPosition(sf::Vector2i pos){
	this->pos = pos;
	this->text.setPosition(this->pos.x, this->pos.y);
};

void Text::setTransparency(bool transparent){
	this->transparent = transparent;
	if(this->transparent){
		this->text.setFillColor(sf::Color::Transparent);
	}
	else{
		this->text.setFillColor(this->color);
	}
};

void Text::setSize(int width, int height){
	// TODO
};

sf::Color Text::getColor(){
	return this->color;
};

sf::Vector2i Text::getPosition(){
	return this->pos;
};

sf::Vector2i Text::getSize(){
	// TODO
	return this->pos;
};

bool Text::boundCheck(sf::Vector2i pos){
	// TODO
	return true;
};

void Text::setText(std::string str){
	this->str = str;
	this->text.setString(this->str);
}

void Text::recenter(){
	if(centered){
		float width = this->text.getLocalBounds().width;
		float height = this->text.getLocalBounds().height;
		this->text.setPosition(
				this->pos.x - width/2,
				this->pos.y - height/2);
	}
	else{
		this->text.setPosition(this->pos.x, this->pos.y);
	};
};

std::string Text::getText(){
	return this->str;
};




