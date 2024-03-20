#include "display.h"
#include "metronome.h"
#include "shape.h"

enum Button{
	PLAY,
	SPEED_UP,
	SPEED_DOWN,
	END,
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
	Shape* buttons[END];

	void setup();
	Button findButtonClicked(sf::Vector2i mousePos);
	void handleClickEvent(Button button);

};

