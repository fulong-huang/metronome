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

    this->playing = false;
    std::cout << "INIT" << std::endl;
}

int math__(){
    return 1;
}

void Metronome::start(){
    if(this->playing){
        return;
    }
    this->playing = true;
    std::cout << "IS PLAYING: " << this->playing << std::endl;
    this->t = std::thread(&Metronome::play, this);
    this->t.detach();
}

void Metronome::stop(){
    this->playing = false;
}

void Metronome::pause(){
    this->playing = false;
}

bool Metronome::isPlaying(){
    return this->playing;
}

void Metronome::play(){
    auto start = std::chrono::high_resolution_clock::now();
    int idx = 0;
    sf::Sound sounds[] = {upbeatSound, downbeatSound};
    while(this->playing){
        auto curr = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = curr - start;
        double seconds = duration.count();
        double timePerBeat = 60.f / this->tempo;
        if(seconds >= timePerBeat){
            start = curr;
            sounds[idx == 0].play();
            sf::sleep(sf::seconds(0.1));
            sounds[idx == 0].stop();
            idx++;
            idx = idx % beatsPerMeasure;
        }
    }
}


void Metronome::setTempo(int tempo){
    this->tempo = tempo;
}
void Metronome::setBeatsPerMeasure(int beats){
    this->beatsPerMeasure = beats;
}


