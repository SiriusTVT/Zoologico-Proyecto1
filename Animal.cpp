//
// Created by arcad on 30/03/2023.
//

#include "Animal.h"

Animal::Animal(const string &nombre, const string &especie, const string &habitat, int edad)
: nombre(nombre), especie(especie), habitat(habitat), edad(edad) {}

const string &Animal::getNombre() const {
    return nombre;
}

void Animal::setNombre(const string &nombre) {
    Animal::nombre = nombre;
}

const string &Animal::getEspecie() const {
    return especie;
}

void Animal::setEspecie(const string &especie) {
    Animal::especie = especie;
}

const string &Animal::getHabitat() const {
    return habitat;
}

void Animal::setHabitat(const string &habitat) {
    Animal::habitat = habitat;
}

Animal::~Animal() {

}

int Animal::getEdad() const {
    return edad;
}

void Animal::setEdad(int edad) {
    Animal::edad = edad;
}


