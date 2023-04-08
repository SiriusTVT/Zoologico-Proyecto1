//
// Created by arcad on 30/03/2023.
//

#include "Zoologico.h"

void menu(Zoologico *Inicio){
    int entrada;
    do {
        cout<<"1. Agregar habitat"<<endl;
        cout<<"2. Agregar Animal"<<endl;
        cout<<"3. Mostrar Dato Animal"<<endl;
        cout<<"4. Acciones"<<endl;

        cin>>entrada;

        switch (entrada) {
            case 1:
                Inicio->agDatosHabitat(); //Agregar Nueva Habitat
                break;
            case 2:
                Inicio->agDatosAnimal(); //Agregar un animal aun habitat
                break;
            case 3:
                Inicio->mostrarDatosAnimal(); //Mostrar Datos Animal
                break;
            case 4:
                Inicio->Acciones(); //Menu emergente para realizar acciones
                break;
            default:
                break;
        }
    } while (entrada!=0);
}

int main(){
    Zoologico *pZologico = new Zoologico();
    cout<<"Bienvenido al Zoologico"<<endl;
    menu(pZologico);
    return 0;
}