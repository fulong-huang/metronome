#include "SFML/Graphics.hpp"

class Drawable{
public:
	Drawable(sf::Color, sf::Vector2i pos, std::vector<sf::Vector2i> points);
	~Drawable();
	Drawable(const Drawable& d);
	Drawable operator=(const Drawable& d);
	
	sf::Drawable* get();


private:
	void setup();

	sf::ConvexShape shape;
	sf::Vector2i pos;
	sf::Color color;
	std::vector<sf::Vector2i> points;

};

