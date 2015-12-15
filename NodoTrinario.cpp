#include "NodoTrinario.h"

NodoTrinario::NodoTrinario(int valor)
{
    this->valor = valor;
    this->izquierdo = 0;
    this->medio = 0;
    this->derecho = 0;
}

NodoTrinario::~NodoTrinario()
{
    //dtor
}
