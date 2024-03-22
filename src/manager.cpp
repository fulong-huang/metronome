#include "manager.h"

#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

Manager::Manager(){
	this->setup();
};

Manager::~Manager(){
	for(int i = 0; i < END; i++){
		if(this->buttons[i]){
			delete this->buttons[i];
		};
	};
	for(int i = 0; i < this->drawables.size(); i++){
		delete this->drawables[i];
	};
};

void Manager::setup(){
	Rectangle* playButton = new Rectangle(sf::Color::Red, {50, 50}, 700, 50);
	buttons[PLAY] = playButton;
	display.addShape(playButton->get());

	Triangle* speedUp = new Triangle(sf::Color::Red, 
			{500, 200},
			{100, 50}, {0, 0}, {0, 100});
	buttons[SPEED_UP] = speedUp;
	display.addShape(speedUp->get());

	Triangle* speedDown = new Triangle(sf::Color::Red, 
			{200, 200},
			{0, 50}, {100, 0}, {100, 100});
	buttons[SPEED_DOWN] = speedDown;
	display.addShape(speedDown->get());

	tempo = new Text(sf::Color(100, 100, 100), {340, 200}, "80", 
			80, "Doesn't matter, it's fine", sf::Text::Bold);
	buttons[TEMPO] = tempo;
	display.addShape(tempo->get());
	
	this->createDrawables();
	this->window.create(sf::VideoMode(800, 600), "Metronome");
};

void Manager::createDrawables(){
	Drawable* minusSign = new Drawable(
			sf::Color::White, this->buttons[SPEED_DOWN]->getPosition(), 
			{{20, 50}, {35, 45}, {50, 45}, {97, 50},
			 {50, 55}, {35, 55}});
	this->drawables.push_back(minusSign);
	this->display.addShape(minusSign->get());

	Drawable* plusSign = new Drawable(
			sf::Color::White, this->buttons[SPEED_UP]->getPosition(), 
			{{80, 50}, {65, 45}, 
			 {45, 45}, {3, 50},
			 {45, 55}, {65, 55}});
	this->drawables.push_back(plusSign);
	this->display.addShape(plusSign->get());
	Drawable* plusSign2 = new Drawable(
			sf::Color::White, this->buttons[SPEED_UP]->getPosition(), 
			{{60, 45}, {53, 33}, {43, 25}, {49, 35}, {50, 45}});
	this->drawables.push_back(plusSign2);
	this->display.addShape(plusSign2->get());
	Drawable* plusSign3 = new Drawable(
			sf::Color::White, this->buttons[SPEED_UP]->getPosition(), 
			{{60, 55}, {53, 67}, {43, 75}, {49, 65}, {50, 55}});
	this->drawables.push_back(plusSign3);
	this->display.addShape(plusSign3->get());
};

void Manager::run(){
	sf::Event event;
	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			else if(event.type == sf::Event::MouseButtonPressed){
				sf::Vector2i mousePos = sf::Mouse::getPosition(this->window);
				Button clickedButton = this->findButtonClicked(mousePos);
				this->handleClickEvent(clickedButton);
			}
		};
		display.draw(this->window);
	};
	if (metronome.isPlaying()){
		metronome.stop();
	};
};

Button Manager::findButtonClicked(sf::Vector2i mousePos){
	for(int i = 0; i < END; i++){
		if(this->buttons[i]->boundCheck(mousePos)){
			return static_cast<Button>(i);
		};
	};
	return END;
};

void Manager::handleClickEvent(Button button){
	switch(button){
		case PLAY:{
			if(metronome.isPlaying()){
				this->buttons[PLAY]->setColor(sf::Color::Red);
				this->buttons[TEMPO]->setColor(sf::Color(100, 100, 100));
				metronome.stop();
			}
			else{
				this->buttons[PLAY]->setColor(sf::Color::Green);
				this->buttons[TEMPO]->setColor(sf::Color(200, 200, 200));
				metronome.start();
			};
			break;
		}
		case SPEED_UP:{
			std::string currTempoStr = this->tempo->getText();
			int currTempo;
			try{
				currTempo = std::stoi(currTempoStr);
			}
			catch(std::exception e){
				std::cout << "EXCEPTION OCCURED!!!!!!" << std::endl;
				std::cout << e.what() << std::endl;
				break;
			};
			currTempo++;
			this->tempo->setText(std::to_string(currTempo));
			this->metronome.setTempo(currTempo);
			
			break;
		}
		case SPEED_DOWN:{
			std::string currTempoStr = this->tempo->getText();
			int currTempo;
			try{
				currTempo = std::stoi(currTempoStr);
			}
			catch(std::exception e){
				std::cout << "EXCEPTION OCCURED!!!!!!" << std::endl;
				std::cout << e.what() << std::endl;
				break;
			};
			if(currTempo > 20){
				currTempo--;
				this->metronome.setTempo(currTempo);
			};
			this->tempo->setText(std::to_string(currTempo));
			
			break;
		}
		case END:{
			// IGNORED
			break;
		}
		default:
			std::cout << "OOB" << std::endl;
	};
};


