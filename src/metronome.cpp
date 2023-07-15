#include "metronome.h"

Metronome::Metronome(int beatsPerMeasure, 
        int tempo, int downbeatPitch, int upbeatPitch){
    sf::Int16 raw[SAMPLES];
    double increment = (float)downbeatPitch / SAMPLES;
    double x = 0;
    for(unsigned i = 0; i < SAMPLES; i++){
        raw[i] = AMPLITUDE * sin(x * TWO_PI);
        x += increment;
    }

    if(!this->downbeatBuffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)){
        std::cout << "Loading failed!" << std::endl;
        return;
    }
    this->downbeatSound.setBuffer(this->downbeatBuffer);
    this->downbeatSound.setLoop(true);

    increment = (float)upbeatPitch / SAMPLES;
    x = 0;
    for(unsigned i = 0; i < SAMPLES; i++){
        raw[i] = AMPLITUDE * sin(x * TWO_PI);
        x += increment;
    }

    if(!this->upbeatBuffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)){
        std::cout << "Loading failed!" << std::endl;
        return;
    }
    this->upbeatSound.setBuffer(this->upbeatBuffer);
    this->upbeatSound.setLoop(true);

    this->tempo = tempo;
    this->beatsPerMeasure = beatsPerMeasure;
    std::cout << "INIT" << std::endl;
}

void Metronome::play(){
    int currBeat;
    double timePerBeat = 60.f / this->tempo;
    auto start = std::chrono::high_resolution_clock::now();
    int idx = 0;
    sf::Sound sounds[] = {upbeatSound, downbeatSound};
    while(true){
        auto curr = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = curr - start;
        double seconds = duration.count();
        if(seconds >= timePerBeat){
            start = curr;
            sounds[idx == 0].play();
            sf::sleep(sf::seconds(0.1));
            sounds[idx == 0].stop();
            std::cout << "Seconds: " << seconds << std::endl;
            idx++;
            idx = idx % beatsPerMeasure;
        }

//
//        this->downbeatSound.play();
//        sf::sleep(sf::seconds(0.1));
//        this->downbeatSound.stop();
//        sf::sleep(sf::seconds(pauseTime));
//        for(int i = 1; i < this->beatsPerMeasure; i++){
//            this->upbeatSound.play();
//            sf::sleep(sf::seconds(0.1));
//            this->upbeatSound.stop();
//            sf::sleep(sf::seconds(pauseTime));
//        }
    }
}



