#include "funciones.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

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

void leerScoreboard(std::map<std::string,long long>& scoreboard) {
    std::ifstream archivo("scoreboard.txt");

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }
    std::string nombre;
    long long score;

    while (archivo >> nombre >> score) {
        scoreboard[nombre] = score;
    }

    archivo.close();
}

void escribirScoreboard(const std::map<std::string,long long>& scoreboard) {
    std::ofstream archivo("scoreboard.txt");

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }

    for (const auto& A : scoreboard) {
        archivo << A.first << " " << A.second << std::endl;
    }

    archivo.close();
}