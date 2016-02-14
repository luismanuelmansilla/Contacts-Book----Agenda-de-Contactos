#ifndef MENU_H
#define MENU_H
#include "Lista.h"
#include "Contacto.h"
#include "Menu.h"
#include "string"

class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void menuListar();
        void menuInsertar();
        void menuEliminar();
        void menuModificar();
        bool verificarTelefono(string telefono);
        bool verificarTipoTelefono(string tipoTelefono);
    friend class Lista;
};

#endif // MENU_H
