#ifndef NODOTRINARIO_H
#define NODOTRINARIO_H


class NodoTrinario
{
    public:
        NodoTrinario* izquierdo;
        NodoTrinario* medio;
        NodoTrinario* derecho;
        int valor;

        NodoTrinario(int valor);
        virtual ~NodoTrinario();
    protected:
    private:
};

#endif // NODOTRINARIO_H
