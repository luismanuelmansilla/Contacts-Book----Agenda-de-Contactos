#include "Contacto.h"
using namespace std;

Contacto::Contacto(string nombre, string apellido, string telefono)
{
    _nombre = nombre;
    _apellido = apellido;
    _telefono = telefono;
    _siguiente = NULL;

}

string Contacto::getNombre(){
    return _nombre;
}


string Contacto::getApellido(){
    return _apellido;
}

string Contacto::getTelefono()
{
    return _telefono;
}

Contacto* Contacto::getSiguiente(){
    return _siguiente;
}

string Contacto::datosContacto()
{
    string datos;
    char s[80];
    int i,j=0,k=0;

    for(i=0; i<80; i++)
        s[i]=' ';
    s[80]= '\n';
    for(i=0; i<_nombre.size(); i++)
        s[i]=_nombre[i];
    for(i=34; i<_apellido.size()+ 34; i++)
    {
        s[i]=_apellido[j];
        j++;
    }
    for(i=68; i<_telefono.size()+69; i++)
    {
        s[i]=_telefono[k];
        k++;
    }
    datos = string(s);

    return datos;
}



