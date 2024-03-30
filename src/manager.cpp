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
	for(int i = 0; i < positions.size(); i++){
		delete this->positions[i];
	};
	for(int i = 0; i < shapes.size(); i++){
		delete shapes[i];
	};
};

void Manager::setup(){
	Circle* playButton = new Circle(sf::Color::Red, {350, 350}, 50);
	buttons[PLAY] = playButton;
	display.addShape(playButton->get());

	Rectangle* pauseButton = new Rectangle(sf::Color(200, 200, 200), {350, 350}, 100, 100, true);
	buttons[PAUSE] = pauseButton;
	display.addShape(pauseButton->get());

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
	

	// PITCHES
	Triangle* upbeatInc = new Triangle(sf::Color::Cyan,
			{250, 350},
			{25, 0}, {50, 47}, {0, 47});
	buttons[UPBEAT_INC] = upbeatInc;
	display.addShape(upbeatInc->get());

	Triangle* downbeatInc = new Triangle(sf::Color::Cyan,
			{500, 350},
			{25, 0}, {50, 47}, {0, 47});
	buttons[DOWNBEAT_INC] = downbeatInc;
	display.addShape(downbeatInc->get());


	Triangle* upbeatDec = new Triangle(sf::Color::Cyan,
			{250, 403},
			{0, 0}, {25, 47}, {50, 0});
	buttons[UPBEAT_DEC] = upbeatDec;
	display.addShape(upbeatDec->get());

	Triangle* downbeatDec = new Triangle(sf::Color::Cyan,
			{500, 403},
			{0, 0}, {25, 47}, {50, 0});
	buttons[DOWNBEAT_DEC] = downbeatDec;
	display.addShape(downbeatDec->get());

	tempo = new Text(sf::Color(100, 100, 100), {400, 225}, "80", 80);
	buttons[TEMPO] = tempo;
	display.addShape(tempo->get());
	
	this->createDrawables();
	this->window.create(sf::VideoMode(800, 600), "Metronome");

	this->createPositions();
	this->createShapes();
};

void Manager::createPositions(){
	for(int i = 0; i < END; i++){
		sf::Vector2i pos = this->buttons[i]->getPosition();
		Text* txt = new Text(
				sf::Color::Magenta, 
				pos,
				std::to_string(pos.x) + "," + std::to_string(pos.y),
				20, false
				);
		this->positions.push_back(txt);
		this->display.addShape(txt->get());
	};
};

void Manager::createShapes(){
	Text* upbeatText = new Text(
				sf::Color::White,
				{275, 455},
				"Upbeat pitch",
				10
			);
	Text* downbeatText = new Text(
				sf::Color::White,
				{525, 455},
				"Downbeat pitch",
				10
			);

	this->display.addShape(upbeatText->get());
	this->display.addShape(downbeatText->get());
	this->shapes.push_back(upbeatText);
	this->shapes.push_back(downbeatText);
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
			this->buttons[PLAY]->setColor(sf::Color::Green);
			this->buttons[TEMPO]->setColor(sf::Color(200, 200, 200));
			this->buttons[PLAY]->setTransparency(true);
			this->buttons[PAUSE]->setTransparency(false);
			metronome.start();
			break;
		}
		case PAUSE:{
			this->buttons[PLAY]->setColor(sf::Color::Red);
			this->buttons[TEMPO]->setColor(sf::Color(100, 100, 100));
			this->buttons[PLAY]->setTransparency(false);
			this->buttons[PAUSE]->setTransparency(true);
			metronome.stop();
			break;
		};
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
		case UPBEAT_INC:{
			this->metronome.increaseUpbeatPitch();
			break;
		}
		case UPBEAT_DEC:{
			this->metronome.decreaseUpbeatPitch();
			break;
		}
		case DOWNBEAT_INC:{
			this->metronome.increaseDownbeatPitch();
			break;
		}
		case DOWNBEAT_DEC:{
			this->metronome.decreaseDownbeatPitch();
			break;
		}
		case TEMPO:{
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


