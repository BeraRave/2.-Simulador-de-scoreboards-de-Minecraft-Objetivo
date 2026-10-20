#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "funciones_main.h"
#include "funciones_scoreboard.h"

int main() {

    std::map<std::string,long long> scoreboard;
    std::string filename;
    bool modificado = false;

    imprimirPresentacion();

    std::string opcion;
    std::cin >> opcion;

    if (opcion == "leer") {
        std::cout << "Ingrese el nombre del scoreboard: ";
        std::cin >> filename;
        leerScoreboard(scoreboard, filename);
    } else if (opcion == "crear") {
        std::cout << "Ingrese el nombre del scoreboard: ";
        std::cin >> filename;
        escribirScoreboard(scoreboard, filename);
    }

    bool salir = false;

    char comando = '0';

    do {

        selecionarOpcion(comando, scoreboard, filename, modificado, salir);

        if (!salir) std::cin >> comando;

    } while (!salir);
}