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
public:
    Zoologico()=default;
    void agregarHabitat(string habitat);
    vector<string> listaHabitats = {"desertico", "selvatico", "polar", "acuatico"};
};


#endif //ZOOLOGICO_PROYECTO1_ZOOLOGICO_H
