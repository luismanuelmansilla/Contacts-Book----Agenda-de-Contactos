#include "Diccionario.h"
#include <iostream>
using namespace std;

Diccionario::Diccionario()
{
    _tamano = 100;
    _cantidad = 0;
    _listas = new Lista[_tamano];
}

void Diccionario::agregar(Contacto* contacto)
{
    _listas[codificar(contacto -> _nombre)].agregar(contacto);
    _cantidad++;
}

Contacto* Diccionario::extraer(string llave)
{
    Contacto* contacto;
    if(llave=="")
        return NULL;
    if(!obtener(llave))
    {
        return NULL;
    }
    contacto =_listas[codificar(llave)].borrar(obtener(llave));
    _cantidad--;
    return contacto;

}

int Diccionario::codificar(string llave)
{
    int codigo=0;
    for(int i=0; i<llave.size(); i++)
    {
        codigo +=llave[i];
    }
    return codigo % _tamano;
}

void Diccionario::modificar(string nombre, string llave, std::string nuevo)
{
    if(!obtener(nombre))
    {
        cout << "Contacto no existe!" << endl;
        return;
    }
    if(llave == "nombre")
    {
        Contacto* contacto = obtener(nombre);
        Contacto* temp = new Contacto(nuevo,contacto -> _apellido, contacto-> _telefono);
        agregar(temp);
        extraer(contacto -> _nombre);
        return;
    }
    _listas[codificar(nombre)].modificar(obtener(nombre),llave,nuevo);

}

Contacto* Diccionario::obtener(string llave)
{
    Contacto* item= _listas[codificar(llave)]._primer;
    if(!item){
        return NULL;
    }
    do{
        if(item->_nombre == llave)
        {
            return item;
        }
        item = item->_siguiente;
    }while(item !=NULL);
    return NULL;
}

string Diccionario::datos(int iterador)
{
    if( !_listas[iterador].getPrimer())
        return  "";
    return _listas[iterador].getPrimer()->getNombre();

}

int Diccionario::getCantidad()
{
    return _cantidad;
}

int Diccionario::getTamano()
{
    return _tamano;
}

void Diccionario::listarDiccionario()
{
    for(int i=0; i<_tamano; i++)
        _listas[i].listarContactos();
}
