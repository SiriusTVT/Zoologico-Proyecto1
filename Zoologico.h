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

using namespace std;

class Zoologico {

private:
    vector<Habitat*> AdHabitat;
    unordered_map<int, Animal*> mapaAnimal;
    int contadorAnimal=0;

public:
    Zoologico()=default;
    void agregarHabitat(string habitat);
    void agDatosHabitat();
    vector<string> listaHabitats = {"desertico", "selvatico", "polar", "acuatico"};

    unordered_map<string, vector<string>> alimentos = {
            {"herbivoro", {"hierbas", "hojas", "frutas"}},
            {"carnivoro", {"carne", "pescado", "insectos"}},
            {"omnivoro", {"verduras", "carne", "huevos"}}
    };


    void agregarAnimal(string nombre, string especie, string habitat, int edad, string comida, string juego, int dormir);
    void agDatosAnimal();

    void mostrarDatosAnimal();
    void mostrarDatosAlimento();

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
