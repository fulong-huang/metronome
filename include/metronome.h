//#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <thread>
#include <map>

enum NoteName{
	A, B, C, D, E, F, G, As, Cs, Ds, Fs, Gs,
};
const std::map<NoteName, float> notes{
		{C, 16.35},
		{Cs, 17.32},
		{D, 18.35},
		{Ds, 19.45}, 
		{E, 20.60}, 
		{F, 21.83},
		{Fs, 23.12},
		{G, 24.50},
		{Gs, 25.96},
		{A, 27.50},
		{As, 29.14},
		{B, 30.87},
};

class Metronome{
public:
    Metronome(
                int beatsPerMeasure = 4,
                int tempo           = 80,
                std::string downbeatNote   = "A5",
                std::string upbeatNote     = "A4"
            );
	~Metronome(){};

    void start();
    void stop();

    bool isPlaying();

    void setTempo(int tempo);
    void setBeatsPerMeasure(int beats);
	
	void setDownbeatPitch(std::string noteName);
	void setUpbeatPitch(std::string noteName);
	
	void increaseDownbeatPitch();
	void increaseUpbeatPitch();
	void decreaseDownbeatPitch();
	void decreaseUpbeatPitch();

private:

	static const unsigned SAMPLES = 44100;
	static const unsigned SAMPLE_RATE = 44100;
	static const unsigned AMPLITUDE = 30000 / 10.f;
	constexpr static const double TWO_PI = 6.28318;

	Metronome(const Metronome& m);
	Metronome operator=(const Metronome& m);
    sf::Sound downbeatSound;
    sf::Sound upbeatSound;
    int tempo;
    int beatsPerMeasure;
	std::string downbeatNote;
	std::string upbeatNote;
    sf::SoundBuffer downbeatBuffer, upbeatBuffer;

    bool playing;
    std::thread t;
    void play();

	int parseNote(std::string strName);

};

