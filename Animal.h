//
// Created by arcad on 30/03/2023.
//

#ifndef ZOOLOGICO_PROYECTO1_ANIMAL_H
#define ZOOLOGICO_PROYECTO1_ANIMAL_H

#include <iostream>

using namespace std;

class Animal {

private:
    string nombre;
    string especie;
    string habitat;
    int edad;
public:
    Animal()=default;
    Animal(const string &nombre, const string &especie, const string &habitat);

    virtual ~Animal();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getEspecie() const;

    void setEspecie(const string &especie);

    const string &getHabitat() const;

    void setHabitat(const string &habitat);

    int getEdad() const;

    void setEdad(int edad);


};


#endif //ZOOLOGICO_PROYECTO1_ANIMAL_H
