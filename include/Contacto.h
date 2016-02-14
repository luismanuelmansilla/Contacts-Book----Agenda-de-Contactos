#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <string>
using namespace std;

class Contacto
{
    public:
        Contacto(string nombre, string apellido, string telefono);
        string getNombre();
        string getApellido();
        string getTelefono();
        Contacto* getSiguiente();
        string datosContacto ();

    private:
        string  _nombre;
        string _apellido;
        string _telefono;
        Contacto* _siguiente;
    friend class Lista;
    friend class Diccionario;
};

#endif // ELEMENTO_H
