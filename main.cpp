#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Gato.h"
#include "Evaluador.h"
#include "NodoTrinario.h"

using namespace std;

//Escribe los datos del objeto gato (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios gatos en un solo archivo
void escribir(string nombre_archivo, Gato*gato, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*25);
    out.write((char*)&gato->edad,4);
    out.write((char*)gato->nombre.c_str(),10);
    out.write((char*)gato->raza.c_str(),10);
    out.write((char*)&gato->sexo,1);
    out.close();
}

//Devuelve un gato previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios gatos de un solo archivo
Gato* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*25);
    int edad;
    char nombre[10];
    char raza[10];
    char sexo;
    in.read((char*)&edad,4);
    in.read((char*)nombre,10);
    in.read((char*)raza,10);
    in.read((char*)&sexo,1);
    Gato *gato = new Gato(edad,sexo,nombre,raza);
    return gato;
}

//Devuelve el promedio de la edad de todos los gatos guardados en el archivo con nombre dado
double getPromedioDeEdad(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int cantidad_registros = in.tellg()/25;
    int acumulador_edades = 0;
    for(int i=0;i<cantidad_registros;i++)
    {
        acumulador_edades+=leer(nombre_archivo,i)->edad;
    }
    return (double)acumulador_edades/cantidad_registros;
}

//Devuelve el numero mayor almacenado en mi_set (dado)
int getMayor(set<int> mi_set)
{
    int mayor;
    for(set<int>::iterator i=mi_set.begin();
        i!=mi_set.end();
        i++)
        mayor=*i;
    return mayor;
}

//Mezcla el contenido de a y b (dados) y lo devuelve en un set ordenado alfabeticamente
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b)
{
    set<char> resultado;
    while(!a.empty())
    {
        resultado.insert(a.front());
        a.pop();
    }
    while(!b.empty())
    {
        resultado.insert(b.top());
        b.pop();
    }
    return resultado;
}

//Devuelve true si buscada (dada) existe en mi_mapa (dado), de lo contrario devuelve false
//Se debe de buscar en las llaves y en los valores almacenados en cada vector del mapa
bool existe(map<string,vector<string> >mi_mapa, string buscada)
{
    for(map<string,vector<string> >::iterator i=mi_mapa.begin();
        i!=mi_mapa.end();
        i++)
    {
        if(buscada==(*i).first)
            return true;
        for(int j=0;j<(*i).second.size();j++)
        {
            if(buscada==(*i).second[j])
                return true;
        }
    }
    return false;
}

//Devuelve el valor mayor almacenado en el arbol con raiz dada
int getMayor(NodoTrinario* raiz)
{
    if(raiz==NULL)
        return 0;
    return max(raiz->valor,
                max(getMayor(raiz->izquierdo),
                    max(getMayor(raiz->medio),
                        getMayor(raiz->derecho))
                   )
              );
}

//Busca y reemplaza dado los valores buscado y reemplazo en el arbol con raiz dada
void buscarYReemplazar(NodoTrinario* raiz,int buscado, int reemplazo)
{
    if(raiz==NULL)
        return;
    if(raiz->valor==buscado)
        raiz->valor=reemplazo;
    buscarYReemplazar(raiz->izquierdo,buscado,reemplazo);
    buscarYReemplazar(raiz->medio,buscado,reemplazo);
    buscarYReemplazar(raiz->derecho,buscado,reemplazo);
}

char retener3Bits(char byte)
{
    char mascara = 7;
    char resultado = byte&mascara;
    return resultado;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

