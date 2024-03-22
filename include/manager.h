#include "display.h"
#include "metronome.h"
#include "shape.h"
#include "text.h"
#include "drawable.h"

enum Button{
	PLAY,
	PAUSE,
	SPEED_UP,
	SPEED_DOWN,
	UPBEAT_INC,
	UPBEAT_DEC,
	DOWNBEAT_INC,
	DOWNBEAT_DEC,
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
	
	std::vector<Drawable*> drawables;
	Shape* buttons[END];

	Text* tempo;

	void setup();
	void createDrawables();

	Button findButtonClicked(sf::Vector2i mousePos);
	void handleClickEvent(Button button);

};

