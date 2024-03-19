#include "display.h"
#include "metronome.h"
#include "shape.h"

enum Button{
	PLAY,
	NEXT,
	SPACE,
};

class Manager{
public:
	Manager();
	~Manager();

	void run();

private:
	Manager(const Manager&);
	Manager operator=(const Manager&);

	sf::RenderWindow window;
	Display display;
	Metronome metronome;
	std::vector<Shape *> buttons;

	void setup();
	Button findButtonClicked(sf::Vector2i mousePos);
	void handleClickEvent(Button button);

};

