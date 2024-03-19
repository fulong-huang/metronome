#include "SFML/Graphics.hpp"
#include "shape.h"

class Rectangle : public Shape{
public:
	Rectangle(sf::Color color, int width, int height, int x=0, int y=0);
	~Rectangle() override;
	Rectangle(const Rectangle& c);
	Rectangle operator=(const Rectangle& c);

	sf::Shape* get() override;
	void setColor(sf::Color color) override;
	void setPosition(int x, int y) override;
	void setSize(int r, int diff) override;

	sf::Color getColor() override;
	std::pair<int, int> getPosition() override;
	sf::Vector2i getSize() override;

	bool boundCheck(sf::Vector2i pos) override;
private:
	sf::RectangleShape shape;
	sf::Color color;
	int width;
	int height;
	int posX;
	int posY;

};


