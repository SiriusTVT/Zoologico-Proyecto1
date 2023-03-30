//
// Created by arcad on 30/03/2023.
//

#include "Habitat.h"

Habitat::Habitat(const string &habitat) : habitat(habitat) {}

const string &Habitat::getHabitat() const {
    return habitat;
}

void Habitat::setHabitat(const string &habitat) {
    Habitat::habitat = habitat;
}


