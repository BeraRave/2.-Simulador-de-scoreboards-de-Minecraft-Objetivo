#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "config.h"
#include "funciones.h"

int main() {

    std::cout << "Bienvenido al simulador de scoreboards de Minecraft." << std::endl;
    std::cout << "Este programa permite simular un scoreboard de Minecraft, permitiendo agregar, eliminar y listar jugadores y sus puntajes." << std::endl;
    std::cout << "El programa utiliza un archivo de texto para almacenar los puntajes de los jugadores." << std::endl;
    std::cout << "Leyendo archivo de scoreboard..." << std::endl << std::endl;

    leerScoreboard(scoreboard);

    std::string salida = "holi";

    char comando = '0';

    do {
        switch(comando) {
            case '1': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                std::cout << "Ingrese el puntaje a agregar del jugador: ";
                long long score;
                std::cin >> score;
                add(jugador, score, scoreboard);
                break;
            }
            case '2': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                std::cout << "Ingrese el puntaje a remover del jugador: ";
                long long score;
                std::cin >> score;
                remove(jugador, score, scoreboard);
                break;
            }
            case '3':
                listScoreboard(scoreboard);
                break;
            case '4':
                leerScoreboard(scoreboard);
                break;
            case '5':
                escribirScoreboard(scoreboard);
                break;
            case '6': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                getScoreboard(scoreboard, jugador);
                break;
            }
            case '7': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                std::cout << "Ingrese el puntaje a establecer del jugador: ";
                long long score;
                std::cin >> score;
                setScoreboard(scoreboard, jugador, score);
                break;
            }
            case '8': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                resetScoreboard(scoreboard, jugador);
                break;
            }
            case '9':
                std::cout << "Saliendo del programa." << std::endl;
                salida = "salir";
                break;
            case '0':
                std::cout << "Que comando desea ejecutar?" << std::endl;
                std::cout << "1. Agregar puntos a un jugador." << std::endl;
                std::cout << "2. Remover puntos de un jugador." << std::endl;
                std::cout << "3. Listar puntajes de jugadores." << std::endl;
                std::cout << "4. Leer scoreboard desde archivo." << std::endl;
                std::cout << "5. Escribir scoreboard a archivo." << std::endl;
                std::cout << "6. Obtener puntaje de un jugador." << std::endl;
                std::cout << "7. Establecer puntaje de un jugador." << std::endl;
                std::cout << "8. Reiniciar puntaje de un jugador." << std::endl;
                std::cout << "9. Salir del programa." << std::endl;
                std::cout << "0. Mostrar lista de comandos." << std::endl;
                break;
            default:
                std::cout << "Comando no reconocido. Ingrese 0 para ver la lista de comandos." << std::endl;
                break;
        }

        if (salida != "salir") std::cin >> comando;

    } while (salida != "salir");
}