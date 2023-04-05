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
    string comer;
    string juego;
    int edad;
    int dormir;
public:
    Animal()=default;

    Animal(const string &nombre, const string &especie, const string &habitat, const string &comer, const string &juego,
           int edad, int dormir);

    virtual ~Animal();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getEspecie() const;

    void setEspecie(const string &especie);

    const string &getHabitat() const;

    void setHabitat(const string &habitat);

    int getEdad() const;

    void setEdad(int edad);

    const string &getComer() const;

    void setComer(const string &comer);

    const string &getJuego() const;

    void setJuego(const string &juego);

    int getDormir() const;

    void setDormir(int dormir);
};


#endif //ZOOLOGICO_PROYECTO1_ANIMAL_H
