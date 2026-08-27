#include "funciones.h"
#include <string>
#include <map>
#include <iostream>

void add(std::string nombre, long long score, std::map<std::string,long long>& scoreboard) {
    scoreboard[nombre] += score;
    std::cout << "Scoreboard:" << scoreboard[nombre] << std::endl;}

void remove(std::string nombre, long long score, std::map<std::string,long long>& scoreboard) {
    scoreboard[nombre] -= score;
    std::cout << "Scoreboard:" << scoreboard[nombre] << std::endl;
}

void mostrarScoreboard(const std::map<std::string,long long>& scoreboard) {
    
    std::cout << "===========================" << std::endl;

    for (const auto& A : scoreboard) {
        std::cout << A.first << "\t:\t" << A.second << std::endl;
    }

    std::cout << "===========================" << std::endl;

}