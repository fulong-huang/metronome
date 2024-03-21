#include "SFML/Graphics.hpp"
#include "shape.h"

class Text : public Shape{
public:
	Text(sf::Color color, sf::Vector2i pos, std::string str, 
			int fontSize, std::string fontName, sf::Uint32 style);
	~Text() override;
	Text(const Text& t);
	Text operator=(const Text& t);

	sf::Drawable* get() override;
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2i pos) override;
	void setSize(int width, int height) override;

	sf::Color getColor() override;
	sf::Vector2i getPosition() override;
	sf::Vector2i getSize() override;

	bool boundCheck(sf::Vector2i pos) override;
	
	void setText(std::string str);
	std::string getText();
private:
	void findDimensions();
	void setup();
	
	sf::Text text;
	sf::Font font;
	sf::Color color;
	sf::Vector2i pos;
	sf::Uint32 style;
	std::string str;
	std::string fontName;
	int fontSize;

};


