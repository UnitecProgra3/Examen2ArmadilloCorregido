#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "Gato.h"
#include "NodoTrinario.h"
#include <iostream>       // std::cin, std::cout
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

void evaluar();
void escribir(string nombre_archivo, Gato*gato, int posicion);
Gato* leer(string nombre_archivo, int posicion);
double getPromedioDeEdad(string nombre_archivo);
int getMayor(set<int> mi_cola);
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b);
bool existe(map<string,vector<string> >mi_mapa, string buscada);
int getMayor(NodoTrinario* raiz);
void buscarYReemplazar(NodoTrinario* raiz,int buscado, int reemplazo);
char retener3Bits(char byte);

#endif // EVALUADOR_H
