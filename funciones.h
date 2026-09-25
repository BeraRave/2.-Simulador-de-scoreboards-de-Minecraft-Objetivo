#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <map>
#include <string>

void add(std::string jugador, long long score, std::map<std::string,long long>& scoreboard);
void remove(std::string jugador, long long score, std::map<std::string,long long>& scoreboard);
void listScoreboard(const std::map<std::string,long long>& scoreboard);
bool leerScoreboard(std::map<std::string,long long>& scoreboard, std::string filename);
void escribirScoreboard(const std::map<std::string,long long>& scoreboard, std::string filename);
void getScoreboard(const std::map<std::string,long long>& scoreboard, std::string jugador);
void setScoreboard(std::map<std::string,long long>& scoreboard, std::string jugador, long long score);
void resetScoreboard(std::map<std::string,long long>& scoreboard, std::string jugador);

#endif