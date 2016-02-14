#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Diccionario.h"

class Archivo
{
    public:
        Archivo();
        void leerArchivo(Diccionario* diccionario);
        void escribirArchivo(Diccionario* diccionario);
    protected:
    private:
};

#endif // ARCHIVO_H
