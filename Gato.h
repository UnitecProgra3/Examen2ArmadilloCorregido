#ifndef GATO_H
#define GATO_H

#include<iostream>
using namespace std;

class Gato
{
    public:
        int edad;
        char sexo;
        string nombre;
        string raza;

        Gato(int edad, char sexo, string nombre, string raza);
        virtual ~Gato();
    protected:
    private:
};

#endif // GATO_H
