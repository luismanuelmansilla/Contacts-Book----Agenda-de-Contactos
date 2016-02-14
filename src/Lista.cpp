#include "Lista.h"
#include "iostream"
#include<string>
using namespace std;

Lista::Lista() : _primer(NULL), _ultimo(NULL)
{
    //ctor
}

void Lista::agregar(Contacto* contacto)
{
    if(!_primer)
    {
        _primer = _ultimo =contacto;
        return;
    }
    _ultimo ->_siguiente = contacto;
    _ultimo = contacto;
}
void Lista::modificar(Contacto* contacto, string llave, string nuevo)
{
    if(llave == "nombre" || llave== "Nombre")
        contacto -> _nombre = nuevo;
    else if(llave =="apellido" || llave == "Apellido")
        contacto -> _apellido = nuevo;
    else
        contacto -> _telefono = nuevo;
}

Contacto* Lista::borrar(Contacto* contacto)
{
    Contacto* pPrev= NULL;
    Contacto* pBorrar=NULL;
    Contacto* c=NULL;

    if(contacto==_primer){
        pBorrar =_primer;
        _primer = pBorrar-> getSiguiente();
        c = pBorrar;
        return c;
    }
    pPrev=_primer;
    pBorrar=_primer->getSiguiente();
    while(pBorrar!=NULL){
        if(pBorrar==contacto){
            pPrev->_siguiente = pBorrar->_siguiente;
            if(pBorrar=_ultimo){
                _ultimo=pPrev;
            }
            c=pBorrar;
            return c;
        }
        pPrev=pBorrar;
        pBorrar=pBorrar->getSiguiente();
    }
}

void Lista::listarContactos()
{
    Contacto* contacto = _primer;
    while(contacto != NULL){
        cout << contacto -> datosContacto() << endl;
        contacto = contacto-> _siguiente;
    }
}

Contacto* Lista::getPrimer()
{
    return _primer;
}

bool Lista::estaVacia()
{
    return !_primer;
}
