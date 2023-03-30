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
    string nombre;

public:
    Zoologico()=default;
    void agregarHabitat(string habitat);
};


#endif //ZOOLOGICO_PROYECTO1_ZOOLOGICO_H
