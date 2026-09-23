#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "config.h"
#include "funciones.h"

int main() {

    leerScoreboard(scoreboard);

    std::string nombre;
    long long score;

    std::cin >> nombre >> score;

    add(nombre, score, scoreboard);

    std::cin >> nombre >> score;

    remove(nombre, score, scoreboard);

    mostrarScoreboard(scoreboard);

    escribirScoreboard(scoreboard);

}