#include "SFML/Graphics.hpp"
class Shape{
public:
	Shape(){}
	virtual ~Shape(){}

	virtual sf::Shape& get() = 0;
	virtual void setColor(sf::Color c) = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual void setSize(int w = 0, int h = 0) = 0;

	virtual sf::Color getColor() = 0;
	virtual std::pair<int, int> getPosition() = 0;
	virtual int getSize() = 0;

	virtual bool boundCheck(sf::Vector2i pos) = 0;
};


