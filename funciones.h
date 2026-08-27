#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <map>
#include <string>

void add(std::string nombre, long long score, std::map<std::string,long long>& scoreboard);
void remove(std::string nombre, long long score, std::map<std::string,long long>& scoreboard);
void mostrarScoreboard(const std::map<std::string,long long>& scoreboard);

#endif