#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "funciones.h"

std::map<std::string,long long> scoreboard;
std::string filename;
bool modificado = false;

int main() {

    std::cout << "Bienvenido al simulador de scoreboards de Minecraft." << std::endl;
    std::cout << "Este programa permite simular un scoreboard de Minecraft, permitiendo agregar, eliminar y listar jugadores y sus puntajes." << std::endl;
    std::cout << "El programa utiliza un archivo de texto para almacenar los puntajes de los jugadores." << std::endl;
    std::cout << "Puedes tener varios archivos de scoreboard y cambiar entre ellos." << std::endl;
    std::cout << "Deseas leer un scoreboard desde archivo o crear uno nuevo? (leer/crear): " << std::endl;

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
        switch(comando) {
            case '1': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                std::cout << "Ingrese el puntaje a agregar del jugador: ";
                long long score;
                std::cin >> score;
                add(jugador, score, scoreboard);
                modificado = true;
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
                modificado = true;
                break;
            }
            case '3':
                std::cout << "Scoreboard de " << filename << ":" << std::endl;
                listScoreboard(scoreboard);
                break;
            case '4':
                leerScoreboard(scoreboard, filename);
                modificado = false;
                break;
            case '5':
                escribirScoreboard(scoreboard, filename);
                modificado = false;
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
                modificado = true;
                break;
            }
            case '8': {
                std::cout << "Ingrese el nombre del jugador: ";
                std::string jugador;
                std::cin >> jugador;
                resetScoreboard(scoreboard, jugador);
                modificado = true;
                break;
            }
            case '9':
                if (modificado) {
                    std::cout << "Hay cambios sin guardar. ¿Desea guardar antes de salir? (s/n): ";
                    char guardar;
                    std::cin >> guardar;
                    if (guardar == 's' || guardar == 'S') {
                        escribirScoreboard(scoreboard, filename);
                    }
                }
                std::cout << "Saliendo del programa." << std::endl;
                salir = true;
                break;
            case 'c':
                if(modificado) {
                    std::cout << "Hay cambios sin guardar. ¿Desea guardar antes de cambiar de scoreboard? (s/n): ";
                    char guardar;
                    std::cin >> guardar;
                    if (guardar == 's' || guardar == 'S') {
                        escribirScoreboard(scoreboard, filename);
                    }
                }
                std::cout << "Ingrese el nombre del scoreboard a cambiar: ";
                std::cin >> filename;
                if(!leerScoreboard(scoreboard, filename)) {
                    std::cout << "Se creará uno nuevo." << std::endl;
                    scoreboard.clear();
                    escribirScoreboard(scoreboard, filename);
                }
                modificado = false;
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
                std::cout << "c. Cambiar de scoreboard." << std::endl;
                std::cout << "0. Mostrar lista de comandos." << std::endl;
                break;
            default:
                std::cout << "Comando no reconocido. Ingrese 0 para ver la lista de comandos." << std::endl;
                break;
        }

        if (!salir) std::cin >> comando;

    } while (!salir);
}