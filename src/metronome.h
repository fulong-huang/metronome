#include <cmath>
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <chrono>

const unsigned SAMPLES = 44100;
const unsigned SAMPLE_RATE = 44100;
const unsigned AMPLITUDE = 30000;
const double TWO_PI = 6.28318;

int doSomething();

class Metronome{
    sf::Sound downbeatSound;
    sf::Sound upbeatSound;
    int tempo;
    int beatsPerMeasure;
    sf::SoundBuffer downbeatBuffer, upbeatBuffer;

public:
    Metronome(
                int beatsPerMeasure = 4,
                int tempo           = 80,
                int downbeatPitch   = 880,
                int upbeatPitch     = 440
            );

    void play();

};

