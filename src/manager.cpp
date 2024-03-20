#include "manager.h"

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

Manager::Manager(){
	this->setup();
};

Manager::~Manager(){
	for(int i = 0; i < END; i++){
		if(buttons[i]){
			delete buttons[i];
		};
	};
};

void Manager::setup(){
	Rectangle* playButton = new Rectangle(sf::Color::Red, {50, 50}, 700, 50);
	buttons[PLAY] = playButton;
	display.addShape(playButton->get());

	Circle* speedUp = new Circle(sf::Color::Red, {300, 150}, 50);
	buttons[SPEED_UP] = speedUp;
	display.addShape(speedUp->get());

	Triangle* speedDown = new Triangle(sf::Color::Red, 
			{0, 50}, {100, 0}, {100, 100}, 
			{100, 150});
	buttons[SPEED_DOWN] = speedDown;
	display.addShape(speedDown->get());

	this->window.create(sf::VideoMode(800, 600), "Metronome");
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
		case PLAY:
			if(metronome.isPlaying()){
				this->buttons[PLAY]->setColor(sf::Color::Red);
				metronome.stop();
			}
			else{
				this->buttons[PLAY]->setColor(sf::Color::Green);
				metronome.start();
			};
			break;
		case SPEED_UP:
			if(this->buttons[SPEED_UP]->getColor() == sf::Color::Green){
				this->buttons[SPEED_UP]->setColor(sf::Color::Red);
			}
			else{
				this->buttons[SPEED_UP]->setColor(sf::Color::Green);
			};
			break;
		case SPEED_DOWN:
			if(this->buttons[SPEED_DOWN]->getColor() == sf::Color::Green){
				this->buttons[SPEED_DOWN]->setColor(sf::Color::Red);
			}
			else{
				this->buttons[SPEED_DOWN]->setColor(sf::Color::Green);
			};
			break;
		case END:
			// IGNORED
			break;
		default:
			std::cout << "OOB" << std::endl;
	};
};


