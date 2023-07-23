#include "display.h"

int main(){

    Display display;
    display.runGame();
    
//    Metronome m;
//    m.start();
//    std::string command;
//    while(true){
//        std::getline(std::cin, command);
//        if(command.compare("p") == 0){
//            if(m.isPlaying()){
//                std::cout << "Pause" << std::endl;
//                m.pause();
//            }
//            else{
//                std::cout << "Play" << std::endl;
//                m.start();
//            }
//            continue;
//        }
//        if(command.size() <= 2){
//            continue;
//        }
//        if(command.compare("exit") == 0){
//            break;
//        }
//        char type = command[0];
//        command = command.substr(2);
//        if(type == 't'){
//            m.setTempo(std::stoi(command));
//        }
//        else if(type == 'b'){
//            m.setBeatsPerMeasure(std::stoi(command));
//        }
//    }
//    m.stop();
    return 0;
}

