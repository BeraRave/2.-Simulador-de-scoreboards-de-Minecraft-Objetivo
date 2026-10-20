#ifndef FUNCIONES_SCOREBOARD_H
#define FUNCIONES_SCOREBOARD_H

#include <map>
#include <string>

void add(const std::string& jugador, long long score, std::map<std::string, long long>& scoreboard);
void remove(const std::string& jugador, long long score, std::map<std::string, long long>& scoreboard);
void listScoreboard(const std::map<std::string, long long>& scoreboard);
bool leerScoreboard(std::map<std::string, long long>& scoreboard, std::string filename);
bool escribirScoreboard(const std::map<std::string, long long>& scoreboard, std::string filename);
void getScoreboard(const std::map<std::string, long long>& scoreboard, std::string jugador);
void setScoreboard(std::map<std::string, long long>& scoreboard, std::string jugador, long long score);
void resetScoreboard(std::map<std::string, long long>& scoreboard, std::string jugador);

#endif