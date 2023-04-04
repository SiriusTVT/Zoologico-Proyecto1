//
// Created by arcad on 30/03/2023.
//

#include "Zoologico.h"

bool Zoologico::Comprobante(string habitat) {
    for (auto const& elemento:listaHabitats)
    {
        if (elemento==habitat)
        {
            return true;
        }
    }
    return false;
}

void Zoologico::agregarHabitat(string habitat) { //Se agrega Habitat: desértico, selvático, polar y acuático.
    string habitatM = habitat;
    bool comprobante;
    transform(habitatM.begin(), habitatM.end(), habitatM.begin(), [](unsigned char c){return ::tolower(c);});

    comprobante=Zoologico::Comprobante(habitatM);
    if (comprobante == true)
    {
        Habitat *pAgregarHabitat = new Habitat(habitatM);
        this->AdHabitat.push_back(pAgregarHabitat);
        cout << "Se agregado el Habitat Correctamente" << endl;
    }
    else
    {
        cout<<"El dato no coincide con los habitas disponibles"<<endl;
        cout<<endl;
    }
}

void Zoologico::agregarAnimal(string nombre, string especie, string habitat, int edad) {
    Animal *pAgregarAnimal = new Animal(nombre, especie, habitat, edad);
    bool comprobante;

    comprobante = Zoologico::Comprobante(habitat);
    if (comprobante == false)
    {
        cout << "El Habitat del animal no coincide con los datos disponibles" << endl;
    }
    else
    {
        this->contadorAnimal += 1;
        this->mapaAnimal.insert(make_pair(Zoologico::contadorAnimal, pAgregarAnimal)); //Datos de Cada animal
        this->mapaAnimalHabitat.insert(make_pair(especie, habitat)); //Datos de Especie y Habitat
    }
}

void Zoologico::agDatosAnimal() {
    string nombre, especie, habitat;
    int edad;

    if (AdHabitat.empty())
    {
        cout<<"No hay Habitat Existente"<<endl;
    }
    else {

        cin.ignore();
        cout << "Nombre:" << endl;
        getline(cin, nombre, '\n');
        cout << "Especie:" << endl;
        getline(cin, especie, '\n');
        cout << "Habitat:" << endl;
        getline(cin, habitat, '\n');

        cout << "Edad:" << endl;
        cin >> edad;

        agregarAnimal(nombre, especie, habitat, edad);
    }
}

