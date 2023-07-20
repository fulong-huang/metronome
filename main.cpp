#include "SFML/System/Sleep.hpp"
#include "metronome.h"

int main(){
    Metronome m;
    m.start();
    std::string command;
    while(true){
        std::getline(std::cin, command);
        if(command.size() <= 2){
            continue;
        }
        if(command.compare("exit") == 0){
            break;
        }
        char type = command[0];
        command = command.substr(2);
        if(type == 't'){
            m.setTempo(std::stoi(command));
        }
        else if(type == 'b'){
            m.setBeatsPerMeasure(std::stoi(command));
        }
    }
    m.stop();
    sf::sleep(sf::seconds(0.1));
    return 0;
}

