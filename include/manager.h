#include "display.h"
#include "metronome.h"
#include "shape.h"
#include "text.h"
#include "drawable.h"

enum Txt{
	UP_T,
	DOWN_T,
	UP_PITCH_T,
	DOWN_PITCH_T,
	END_T,
	
};
enum Button{
	PLAY,
	PAUSE,
	SPEED_UP,
	SPEED_DOWN,
	UPBEAT_INC,
	UPBEAT_DEC,
	DOWNBEAT_INC,
	DOWNBEAT_DEC,
	BPM_INC,
	BPM_DEC,
	TEMPO,
	BPM,
	END_B,
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
	std::vector<Text*> texts;
	Shape* buttons[END_B];

	Text* tempo;
	Text* timeSig;


	void setup();
	void createDrawables();
	void createText();

	void createPositions();
	std::vector<Text*> positions;

	Button findButtonClicked(sf::Vector2i mousePos);
	void handleClickEvent(Button button);

};

