#include "display.h"
#include "metronome.h"
#include "shape.h"
#include "text.h"

enum Button{
	PLAY,
	SPEED_UP,
	SPEED_DOWN,
	TEMPO,
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
	
	// NOTE: might add display to keep track of unclickables. 
	Shape* buttons[END];

	Text* tempo;

	void setup();
	Button findButtonClicked(sf::Vector2i mousePos);
	void handleClickEvent(Button button);

};

