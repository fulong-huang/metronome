#include "metronome.h"
#include <cmath>
#include <chrono>

Metronome::Metronome(int beatsPerMeasure, 
        int tempo, std::string downbeatNote, std::string upbeatNote):
	beatsPerMeasure(beatsPerMeasure), tempo(tempo),
	downbeatNote(downbeatNote), upbeatNote(upbeatNote)
{
	this->setDownbeatPitch(downbeatNote);
	this->setUpbeatPitch(upbeatNote);
    this->playing = false;
}

void Metronome::setDownbeatPitch(std::string noteName){
	int pitch = this->parseNote(noteName);
	sf::Int16 raw[SAMPLES];
	double increment = (float)pitch/SAMPLES;
	double x = 0;
	for(unsigned i = 0; i < SAMPLES; i++){
		raw[i] = AMPLITUDE * sin(x * TWO_PI);
		x += increment;
	};
	if(!this->downbeatBuffer.loadFromSamples(raw,SAMPLES, 1, SAMPLE_RATE)){
		std::cout << "DOWNBEAT LOAD FAILED!!!" << std::endl;
		return;
	};
	this->downbeatSound.setBuffer(this->downbeatBuffer);
	this->downbeatSound.setLoop(true);
};

void Metronome::setUpbeatPitch(std::string noteName){
	int pitch = this->parseNote(noteName);
	sf::Int16 raw[SAMPLES];
	double increment = (float)pitch/SAMPLES;
	double x = 0;
	for(unsigned i = 0; i < SAMPLES; i++){
		raw[i] = AMPLITUDE * sin(x * TWO_PI);
		x += increment;
	};
	if(!this->upbeatBuffer.loadFromSamples(raw,SAMPLES, 1, SAMPLE_RATE)){
		std::cout << "UPBEAT LOAD FAILED!!!" << std::endl;
		return;
	};
	this->upbeatSound.setBuffer(this->upbeatBuffer);
	this->upbeatSound.setLoop(true);
};

std::string Metronome::getDownbeatNote(){
	return this->downbeatNote;
};

std::string Metronome::getUpbeatNote(){
	return this->upbeatNote;
};

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
void Metronome::increaseBPM(){
	this->beatsPerMeasure++;
};
void Metronome::decreaseBPM(){
	this->beatsPerMeasure--;
	if(this->beatsPerMeasure < 0){
		this->beatsPerMeasure = 0;
	};
};
int Metronome::getBPM(){
	return this->beatsPerMeasure;
};

int Metronome::parseNote(std::string strName){
	// ASSUME INPUT ARE CORRECT!!!
	int octave = strName[strName.size() - 1] - '0';
	
	int idx = strName[0] - 'A';
	if(strName.size() == 3){
		switch(strName[0]){
			case 'A':
				idx += 7;
				break;
			case 'C':
			case 'D':
				idx += 6;
				break;
			default: 
				idx += 5;
		};
	};
	
	NoteName noteName = static_cast<NoteName>(idx);
	float pitch = notes.at(noteName);
	while(octave > 0){
		pitch *= 2;
		octave--;
	};
	std::cout << pitch << std::endl;
	return pitch;
};

void Metronome::increaseDownbeatPitch(){
	char noteName = this->downbeatNote[0];
	char octave = this->downbeatNote[1];
	if(this->downbeatNote.size() == 3){
		octave = this->downbeatNote[2];
		if(noteName == 'G'){
			this->downbeatNote = "";
			this->downbeatNote += 'A';
			this->downbeatNote += octave;
		}
		else{
			this->downbeatNote = "";
			this->downbeatNote += (noteName + 1);
			this->downbeatNote += octave;
		};
	}
	else if(noteName == 'A' || noteName == 'C' || noteName == 'D' ||
		   noteName == 'F' || noteName == 'G'){
		this->downbeatNote = "";
		this->downbeatNote += noteName;
		this->downbeatNote += "#";
		this->downbeatNote += octave;
	}
	else if(noteName == 'B'){
		this->downbeatNote = "";
		this->downbeatNote += (noteName + 1);
		this->downbeatNote += (octave + 1);
	}
	else{
		this->downbeatNote = "";
		this->downbeatNote += (noteName + 1);
		this->downbeatNote += octave;
	};
	std::cout << this->downbeatNote << std::endl;
	this->setDownbeatPitch(this->downbeatNote);
};

void Metronome::increaseUpbeatPitch(){
	char noteName = this->upbeatNote[0];
	char octave = this->upbeatNote[1];
	if(this->upbeatNote.size() == 3){
		octave = this->upbeatNote[2];
		if(noteName == 'G'){
			this->upbeatNote = "";
			this->upbeatNote += 'A';
			this->upbeatNote += octave;
		}
		else{
			this->upbeatNote = "";
			this->upbeatNote += (noteName + 1);
			this->upbeatNote += octave;
		};
	}
	else if(noteName == 'A' || noteName == 'C' || noteName == 'D' ||
		   noteName == 'F' || noteName == 'G'){
		this->upbeatNote = "";
		this->upbeatNote += noteName;
		this->upbeatNote += "#";
		this->upbeatNote += octave;
	}
	else if(noteName == 'B'){
		this->upbeatNote = "";
		this->upbeatNote += (noteName + 1);
		this->upbeatNote += (octave + 1);
	}
	else{
		this->upbeatNote = "";
		this->upbeatNote += (noteName + 1);
		this->upbeatNote += octave;
	};
	std::cout << this->upbeatNote << std::endl;
	this->setUpbeatPitch(this->upbeatNote);
};

void Metronome::decreaseDownbeatPitch(){
	char noteName = this->downbeatNote[0];
	char octave = this->downbeatNote[1];
	if(this->downbeatNote.size() >= 3){
		octave = this->downbeatNote[2];
		this->downbeatNote = "";
		this->downbeatNote += noteName;
		this->downbeatNote += octave;
	}
	else if(noteName == 'B' || noteName == 'G' ||
			noteName == 'E' || noteName == 'D'){
		this->downbeatNote = "";
		this->downbeatNote += (noteName - 1);
		this->downbeatNote += "#";
		this->downbeatNote += octave;
	}
	else if(noteName == 'A'){
		this->downbeatNote = "Gs";
		this->downbeatNote += octave;
	}
	else if(noteName == 'C'){
		if(octave == '0'){
			std::cout << "REACH LOWEST NOTE" << std::endl;
			return;
		};
		this->downbeatNote = "B";
		this->downbeatNote += (octave - 1);
	}
	else{
		this->downbeatNote = "";
		this->downbeatNote += (noteName - 1);
		this->downbeatNote += octave;
	};
	std::cout << "END, call setPitch: " << this->downbeatNote << std::endl;
	this->setDownbeatPitch(this->downbeatNote);
};


void Metronome::decreaseUpbeatPitch(){
	char noteName = this->upbeatNote[0];
	char octave = this->upbeatNote[1];
	if(this->upbeatNote.size() >= 3){
		octave = this->upbeatNote[2];
		this->upbeatNote = "";
		this->upbeatNote += noteName;
		this->upbeatNote += octave;
	}
	else if(noteName == 'B' || noteName == 'G' ||
			noteName == 'E' || noteName == 'D'){
		this->upbeatNote = "";
		this->upbeatNote += (noteName - 1);
		this->upbeatNote += "#";
		this->upbeatNote += octave;
	}
	else if(noteName == 'A'){
		this->upbeatNote = "Gs";
		this->upbeatNote += octave;
	}
	else if(noteName == 'C'){
		if(octave == '0'){
			std::cout << "REACH LOWEST NOTE" << std::endl;
			return;
		};
		this->upbeatNote = "B";
		this->upbeatNote += (octave - 1);
	}
	else{
		this->upbeatNote = "";
		this->upbeatNote += (noteName - 1);
		this->upbeatNote += octave;
	};
	std::cout << "END, call setPitch: " << this->upbeatNote << std::endl;
	this->setUpbeatPitch(this->upbeatNote);
};




