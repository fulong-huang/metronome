#include "manager.h"

#include "circle.h"
#include "rectangle.h"

Manager::Manager(){
	this->setup();
};

Manager::~Manager(){
	for(Shape* s : buttons){
		delete s;
	};
};

void Manager::setup(){
	Rectangle* playButton = new Rectangle(sf::Color::Red, 200, 120, 20, 50);
	buttons.push_back(playButton);
	display.addShape(playButton->get());

	Circle* nextButton = new Circle(sf::Color::Red, 200, 200, 100);
	buttons.push_back(nextButton);
	display.addShape(nextButton->get());

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
	for(int i = 0; i < this->buttons.size(); i++){
		if(this->buttons[i]->boundCheck(mousePos)){
			std::cout << "FOUND" << std::endl;
			return static_cast<Button>(i);
		};
	};
	return SPACE;
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
		case NEXT:
			if(this->buttons[NEXT]->getColor() == sf::Color::Green){
				this->buttons[NEXT]->setColor(sf::Color::Red);
			}
			else{
				this->buttons[NEXT]->setColor(sf::Color::Green);
			};
			break;
		case SPACE:
			// IGNORED
			break;
	};
};


