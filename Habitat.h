//
// Created by arcad on 30/03/2023.
//

#ifndef ZOOLOGICO_PROYECTO1_HABITAT_H
#define ZOOLOGICO_PROYECTO1_HABITAT_H

#include <iostream>

using namespace std;

class Habitat {

private:
    string habitat;

public:
    Habitat()=default;

    explicit Habitat(const string &habitat);

    const string &getHabitat() const;

    void setHabitat(const string &habitat);

};


#endif //ZOOLOGICO_PROYECTO1_HABITAT_H
