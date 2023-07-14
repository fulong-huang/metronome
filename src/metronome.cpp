#include "metronome.h"

void playSound(int pitch, float duration, float volumn = 0.5){
    volumn = volumn > 1? 1 : volumn;
    sf::Int16 raw[SAMPLES];
    const double increment = (float)pitch/SAMPLES;
    double x = 0;
    for(unsigned i = 0; i < SAMPLES; i++){
        raw[i] = (volumn * AMPLITUDE) * sin(x * TWO_PI);
        x += increment;
    }

    sf::SoundBuffer Buffer;
    if(!Buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)){
        std::cerr << "Loading failed!" << std::endl;
        return;
    }
    
    sf::Sound Sound;
    Sound.setBuffer(Buffer);
    Sound.setLoop(true);
    Sound.play();
    sf::sleep(sf::seconds(duration));
    Sound.stop();
}

int doSomething() {

    for(int _ = 0; _ < 2; _++){
    for(int i : {880, 440, 440, 440}){
        std::thread s(playSound, i, 0.1, 0.8);
        s.join();
        sf::sleep(sf::seconds(0.4));
    }
    }

	return 0;
}



