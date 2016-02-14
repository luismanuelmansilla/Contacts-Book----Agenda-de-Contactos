#ifndef LISTA_H
#define LISTA_H
#include "Contacto.h"
using namespace std;

class Lista
{
    public:
        Lista();
        void listarContactos();
        void agregar(Contacto* contacto);
        Contacto* borrar(Contacto* contacto);
        void modificar(Contacto* contacto, string llave, string nuevo);
        Contacto* getPrimer();
        bool estaVacia();
    private:
        Contacto* _primer;
        Contacto* _ultimo;
    friend class Diccionario;

};

#endif // LISTA_H
