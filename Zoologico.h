//
// Created by arcad on 30/03/2023.
//

#ifndef ZOOLOGICO_PROYECTO1_ZOOLOGICO_H
#define ZOOLOGICO_PROYECTO1_ZOOLOGICO_H

#include <iostream>
#include "Habitat.h"
#include "Animal.h"
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stdexcept>

using namespace std;

class Zoologico {

private:
    vector<Habitat*> AdHabitat;
    unordered_map<int, Animal*> mapaAnimal;
    int contadorAnimal=0;

public:
    Zoologico()=default;
    void agregarHabitat(string habitat);
    vector<string> listaHabitats = {"desertico", "selvatico", "polar", "acuatico"};

    void agregarAnimal(string nombre, string especie, string habitat, int edad, string comida, string juego, int dormir);
    void agDatosAnimal();

    void mostrarDatosAnimal();

    bool Comprobante(string habitat);
    bool ComprobanteListaHabitat(string habitat);
    string transformarMinuscula(string especie);

    void AlimentarAnimales();
    void DormirAnimales();
    void JugarAnimales();

    void Acciones();

    int validarInt(string entrada);
    int ValidarString(string entrada);
};


#endif //ZOOLOGICO_PROYECTO1_ZOOLOGICO_H
