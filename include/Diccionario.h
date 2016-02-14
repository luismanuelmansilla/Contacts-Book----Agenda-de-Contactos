#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <string>
#include "Lista.h"
using namespace std;
class Diccionario
{
    public:
        Diccionario();
        void agregar(Contacto* elemento);
        Contacto* extraer(string llave);
        void modificar(string nombre, string llave, string nuevo);
        Contacto* obtener(string llave);
        string datos(int iterador);
        int getCantidad();
        int getTamano();
        void listarDiccionario();
    private:
        int codificar(string llave);
        int _tamano;
        int _cantidad;
        Lista* _listas;
};

#endif // DICCIONARIO_H
