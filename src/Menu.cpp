#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "Menu.h"
#include "Lista.h"
#include "Archivo.h"

using namespace std;

Archivo* archivo = new Archivo();
Diccionario* diccionario = new Diccionario();

Menu::Menu()
{
    archivo -> leerArchivo(diccionario);
}

void Menu::menuPrincipal()
{
    char opcionMenu;

    do {
        cout << "\n\n\t\t\t      Agenda de Contactos\n\n";
        cout << " 1. Listar contactos.\n";
        cout << " 2. Insertar contacto.\n";
        cout << " 3. Modificar contacto.\n";
        cout << " 4. Eliminar contacto.\n";
        cout << " 5. Salir.\n";
        cout << " \n Elija una opci\242n => ";
        opcionMenu=_getch();
        cin.clear();
        fflush(stdin);
        cout << "\n";

        switch (opcionMenu) {
            case '1':
                system("cls");
                cout << "\n\n\t\t\t      Listado de Contactos\n\n";
                menuListar();
                cout << "\n --Presione Cualquier tecla para regresar al men\243 principal --\n";
            break;
            case '2': menuInsertar();
            break;
            case '3': menuModificar();
            break;
            case '4': menuEliminar();
            break;
            case '5':
                system("cls");
                archivo -> escribirArchivo(diccionario);
                cout << "\n Informaci\242n guardada...";
                cout << "\n\n\n Gracias por usar el programa, hasta la pr\242xima!\n";
                break;
            default: cout << "\n" <<"\n Opci\242n Invalida! Presione cualquier tecla para continuar...\n";
        }
        system("PAUSE>null");
        system("cls");
    }while(opcionMenu != '5');

}

void Menu::menuListar()
{
    if(diccionario -> getCantidad()==0){
        cout<<" No hay contactos agregados!"<<endl;
    }else{
        cout << "\n";
        cout << "NOMBRE:";
        cout << "\t\t\t          APELLIDO:";
        cout << "\t\t            TELEFONO:" << endl;
        cout << "\n";
        diccionario ->listarDiccionario();
    }
}

void Menu::menuInsertar()
{
    system("cls");
    string nombre, apellido, telefono;

    cin.clear();
    fflush(stdin);

    cout << "\n\n\t\t\t      Insertar Contacto\n\n" << endl;
    cout << " Introduzca el nombre: ";
    do{
        getline(cin, nombre);
        if(nombre.empty() || nombre.size()>33)
            cout<<" Nombre invalido!"<<endl;
    }while (nombre.empty() || nombre.size()>33);

    cout << " Introduza el apellido: ";
   do{
        getline(cin, apellido);
        if(apellido.empty() || apellido.size()>33)
            cout<<" Apellido invalido!"<<endl;
    }while (apellido.empty() || apellido.size()>33);

    cout << " Introduzca el telefono: ";
    do{
        cin >> telefono;
        if(!verificarTelefono(telefono))
            cout<<" Telefono invalido!"<<endl;
    }while (!verificarTelefono(telefono));

    Contacto* contacto = new Contacto(nombre, apellido, telefono);
    diccionario -> agregar(contacto);

    cout << "\n--Contacto Agregado. Presione cualquier tecla para regresar al men\243 principal--\n";
}

void Menu::menuModificar()
{
    system("cls");
    cout << "\n\n\t\t\t      Modificar Contacto\n\n";

    if(diccionario -> getCantidad()==0)
        cout<<" No hay contactos agregados!"<<endl;
    else
    {
        menuListar();
        string nombre,clave,nuevo;
        cout<<"\n Escriba el contacto a modificar (Nombre): ";
        getline(cin,nombre);
        do{
            cout<<" Escriba lo que quiere modificar (Nombre, Apellido, Telefono)";
            getline(cin,clave);
            if(clave!= "Nombre" && clave!= "Apellido" && clave!= "Telefono")
                cout<<"Opci\242 invalida!"<<endl;
        }while(clave!= "Nombre" && clave!="Apellido" && clave!= "Telefono");
        if(clave == "Telefono" || clave == "telefono"){
            do{
                cout<< " Nuevo telefono: ";
                getline(cin,nuevo);
                if(!verificarTelefono(nuevo))
                    cout<<" N\243mero invalido!"<<endl;
            }while(!verificarTelefono(nuevo));
        }
        else{
            cout<< " Nuevo dato:";
            do{
                getline(cin,nuevo);
                if(nuevo=="" || nuevo.size()>33)
                    cout<<" Dato invalido!"<<endl;
            }while(nuevo=="" || nuevo.size()>33);
        }
        diccionario -> modificar(nombre,clave,nuevo);
    }
    cout << "\n --Presione Cualquier tecla para regresar el men\243 principal --\n";
}

void Menu::menuEliminar()
{
    system("cls");
    string nombre,apellido;

    cout << "\n\n\t\t\t      Eliminar Contacto.\n\n";

    if(diccionario->getCantidad()==0){
        cout<<" No hay contactos agregados!"<<endl;
        cout << "\n --Presione cualquier tecla para regresar al men\243 principal--\n";
    }else{
        menuListar();
        cout<<"\n Escriba el nombre del contacto a borrar:";
        getline(cin,nombre);
        if( (diccionario -> extraer(nombre)) == NULL ){
            cout << " Contacto no existe!" << endl;

        }else{
            diccionario -> extraer(nombre);
            cout << "\n--Contacto Eliminado. Presione cualquier tecla para regresar al men\243 principal--\n";
        }
    }
}

bool Menu::verificarTelefono(string telefono)
{
    int i;
    bool f=true;
    if(telefono.length()!=10)
        f=false;
    for(i=0; i<telefono.length(); i++){
        if(! (telefono[i] >= '0' && telefono[i] <= '9' || telefono[i] == ' ') )
            f= false;
    }
    return f;
}
