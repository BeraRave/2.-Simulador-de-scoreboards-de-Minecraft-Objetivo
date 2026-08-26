#include <iostream>
#include <map>
#include <string>
#include "config.h"

int main() {

    std::map <std::string,long long> scoreboard;

    std::string nombre;
    long long score;

    std::cin >> nombre >> score;

    scoreboard[nombre] += score;

    std::cout << "Scoreboard:" << scoreboard[nombre] << std::endl;

    std::cin >> nombre >> score;

    scoreboard[nombre] += score;

    std::cout << "Scoreboard:" << scoreboard[nombre] << std::endl;

    std::cout << "===========================" << std::endl;

    for(const auto& A : scoreboard){
        std::cout << A.first << "\t:\t" << A.second << std::endl;
    }

    std::cout << "===========================" << std::endl;

}