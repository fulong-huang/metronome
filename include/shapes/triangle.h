#include "SFML/Graphics.hpp"
#include "shape.h"

class Triangle : public Shape{
public:
	Triangle(sf::Color color, 
			sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3,
			sf::Vector2i pos);
	~Triangle() override;
	Triangle(const Triangle& c);
	Triangle operator=(const Triangle& c);

	sf::Drawable* get() override;
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2i pos) override;
	void setSize(int r, int diff) override;

	sf::Color getColor() override;
	sf::Vector2i getPosition() override;
	sf::Vector2i getSize() override;

	bool boundCheck(sf::Vector2i pos) override;
private:
	void setup();
	void findDimensions();
	//sf::TriangleShape shape;
	sf::ConvexShape shape;
	sf::Color color;
	sf::Vector2f p1, p2, p3;
	sf::Vector2i pos;
	int width, height;

};


