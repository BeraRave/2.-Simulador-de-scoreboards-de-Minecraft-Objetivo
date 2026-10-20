#ifndef FUNCIONES_MAIN_H
#define FUNCIONES_MAIN_H

#include <map>
#include <string>

void imprimirPresentacion();
void imprimirMenu();
void selecionarOpcion(char opcion, std::map<std::string, long long>& scoreboard, std::string& filename, bool& modificado, bool& salir);

#endif