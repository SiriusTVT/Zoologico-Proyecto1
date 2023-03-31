//
// Created by arcad on 30/03/2023.
//

#include "Zoologico.h"

void agHabitat(Zoologico *AgregarH){
    string habitat;

    cout<<"Lista de Habitats Disponibles:"<<endl;
    for (auto const& elemento : AgregarH->listaHabitats) {
        cout<<" - "<<elemento<<"";
    }
    cout<<endl;

    cin.ignore();
    cout<<"Habitat:"<<endl;
    getline(cin, habitat, '\n');

    AgregarH->agregarHabitat(habitat);
}


void menu(Zoologico *Inicio){
    int entrada;
    do {
        cout<<"1. Agregar habitat"<<endl;

        cin>>entrada;

        switch (entrada) {
            case 1:
                agHabitat(Inicio);
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