#include "SFML/Graphics.hpp"
#include "shape.h"

class Circle : public Shape{
public:
	Circle(sf::Color color, int radius, int x=0, int y=0);
	~Circle();
	Circle(const Circle& c);
	Circle operator=(const Circle& c);

	sf::Shape& get() override;
	void setColor(sf::Color color) override;
	void setPosition(int x, int y) override;
	void setSize(int r, int diff) override;

	sf::Color getColor() override;
	std::pair<int, int> getPosition() override;
	int getSize() override;

	bool boundCheck(sf::Vector2i pos) override;
private:
	sf::CircleShape circle;
	sf::Color color;
	int radius;
	int posX;
	int posY;

};


