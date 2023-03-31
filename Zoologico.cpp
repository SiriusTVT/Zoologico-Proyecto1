//
// Created by arcad on 30/03/2023.
//

#include "Zoologico.h"

void Zoologico::agregarHabitat(string habitat) { //Se agrega Habitat: desértico, selvático, polar y acuático.
    string habitatM = habitat;
    transform(habitatM.begin(), habitatM.end(), habitatM.begin(), [](unsigned char c){return ::tolower(c);});

    for (auto const& elemento:listaHabitats) {

        if (elemento==habitatM) {
            Habitat *pAgregarHabitat = new Habitat(habitatM);
            this->AdHabitat.push_back(pAgregarHabitat);
            cout<<"Se agregado el Habitat Correctamente"<<endl;
            goto Inicio;

        }
    }
    cout<<"Valor, esta mal escrito o Incorrecto"<<endl;
    Inicio:
    cout<<endl;
}

