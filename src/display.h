#include "SFML/Graphics.hpp"
#include "metronome.h"
#include <unistd.h>

class Display{
public:
    Display();
    void runGame();
    void handleMouseClick();

private:
    sf::RenderWindow window;
    sf::CircleShape shape;

    Metronome metronome;

};


