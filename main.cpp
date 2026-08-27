#include <iostream>
#include <map>
#include <string>
#include "config.h"
#include "funciones.h"

int main() {

    std::string nombre;
    long long score;

    std::cin >> nombre >> score;

    add(nombre, score, scoreboard);

    std::cin >> nombre >> score;

    remove(nombre, score, scoreboard);

    mostrarScoreboard(scoreboard);


}