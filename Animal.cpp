//
// Created by arcad on 30/03/2023.
//

#include "Animal.h"



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

const string &Animal::getComer() const {
    return comer;
}

void Animal::setComer(const string &comer) {
    Animal::comer = comer;
}

const string &Animal::getJuego() const {
    return juego;
}

void Animal::setJuego(const string &juego) {
    Animal::juego = juego;
}

int Animal::getDormir() const {
    return dormir;
}

void Animal::setDormir(int dormir) {
    Animal::dormir = dormir;
}

Animal::Animal(const string &nombre, const string &especie, const string &habitat, const string &comer,
               const string &juego, int edad, int dormir) : nombre(nombre), especie(especie), habitat(habitat),
                                                            comer(comer), juego(juego), edad(edad), dormir(dormir) {}




