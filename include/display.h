#include "SFML/Graphics.hpp"
#include "circle.h"

class Display{
public:
    Display();
	~Display();
	
    void draw(sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2i mousePos);

private:
	Display(const Display& d);
	Display operator=(const Display& d);
    // sf::RenderWindow window;
	std::vector<Shape *> shapes;


	void setup();
};


