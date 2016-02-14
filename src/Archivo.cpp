#include "Archivo.h"
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

Archivo::Archivo()
{
    //ctor
}



void Archivo::leerArchivo(Diccionario* diccionario)
{
    ifstream leer;
    leer.open("Contactos.txt");
    char nombre[34],apellido[34], telefono[11];
    int i,j,k;
    string linea;
    string nom,ape,tel,nomr,aper;

    while(getline(leer,linea)){
        j=0,k=0;

        for(i=0; i<34; i++)
        {
            nombre[i] = linea[i];
        }
        nom = string(nombre);
        nomr = nom.substr(0,nom.find(", "));
        for(i=34; i<68; i++)
        {
            apellido[j]=linea[i];
            j++;
        }

        ape=std::string(apellido);
        aper=ape.substr(0,ape.find("  "));
        for(i=68; i<79; i++)
        {
            telefono[k]=linea[i];
            k++;
        }
        tel = string(telefono);
        Contacto* contacto = new Contacto(nomr,aper,tel);
        diccionario -> agregar(contacto);
    }
    leer.close();
}
void Archivo::escribirArchivo(Diccionario* diccionario)
{
    ofstream escribir("Contactos.txt");
    Contacto* contacto;
    int i=0,f=0;
    while(i < diccionario -> getTamano()){
        if(diccionario -> datos(i)!= ""){
            contacto = diccionario -> extraer(diccionario -> datos(i));
            escribir << contacto -> datosContacto()<< endl;
            f=1;
        }
        i++;
        if(i == diccionario -> getTamano()){
            if(f==1){
                i=0;
                f=0;
            }
            else
                return;
        }
    }
}
