#include "funciones.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

void add(std::string jugador, long long score, std::map<std::string,long long>& scoreboard) {
    scoreboard[jugador] += score;
    std::cout << "Se agrego " << score << " puntos a " << jugador << ". Puntaje total: " << scoreboard[jugador] << std::endl;
}

void remove(std::string jugador, long long score, std::map<std::string,long long>& scoreboard) {
    scoreboard[jugador] -= score;
    std::cout << "Se removieron " << score << " puntos de " << jugador << ". Puntaje total: " << scoreboard[jugador] << std::endl;
}

void listScoreboard(const std::map<std::string,long long>& scoreboard) {
    
    std::cout << "===========================" << std::endl;

    for (const auto& A : scoreboard) {
        std::cout << A.first << "\t:\t" << A.second << std::endl;
    }

    std::cout << "===========================" << std::endl;

}

bool leerScoreboard(std::map<std::string,long long>& scoreboard, std::string filename) {
    filename += ".txt";
    std::ifstream archivo(filename);

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo.\n";
        return false;
    }

    scoreboard.clear();

    std::string nombre;
    long long score;

    while (archivo >> nombre >> score) {
        scoreboard[nombre] = score;
    }

    std::cout << "Archivo "<< filename << " leído correctamente." << std::endl;
    archivo.close();
    return true;
}

void escribirScoreboard(const std::map<std::string,long long>& scoreboard, std::string filename) {
    filename += ".txt";
    std::ofstream archivo(filename);

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo.\n";
        return;
    }

    for (const auto& A : scoreboard) {
        archivo << A.first << " " << A.second << std::endl;
    }

    std::cout << "Archivo "<< filename << " escrito correctamente." << std::endl;
    archivo.close();
}

void getScoreboard(const std::map<std::string,long long>& scoreboard, std::string jugador) {
    auto it = scoreboard.find(jugador);
    if (it != scoreboard.end()) {
        std::cout << "Scoreboard de " << jugador << ": " << it->second << std::endl;
    } else {
        std::cout << "Jugador no encontrado en el scoreboard." << std::endl;
    }
}

void setScoreboard(std::map<std::string,long long>& scoreboard, std::string jugador, long long score) {
    scoreboard[jugador] = score;
    std::cout << "Scoreboard de " << jugador << " actualizado a: " << score << std::endl;
}

void resetScoreboard(std::map<std::string,long long>& scoreboard, std::string jugador) {
   size_t borrado = scoreboard.erase(jugador);
    if (borrado == 1) {
        std::cout << "Scoreboard de " << jugador << " reiniciado." << std::endl;
    } else {
        std::cout << "Jugador no encontrado en el scoreboard." << std::endl;
    }
}

