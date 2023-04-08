//
// Created by arcad on 30/03/2023.
//

#include "Zoologico.h"

bool Zoologico::Comprobante(string habitat) { //Comprobante inicial de los habitats disponibles a agregar
    for (auto const& elemento:listaHabitats)
    {
        if (elemento==habitat)
        {
            return true;
        }
    }
    return false;
}

bool Zoologico::ComprobanteListaHabitat(string habitat) { //Comprobante despues de a ver agregado un habitat al vector
    for (auto const& elemento:AdHabitat)
    {
        if (elemento->getHabitat() ==  habitat)
        {
            return true;
        }
    }
    return false;
}

string Zoologico::transformarMinuscula(string especie) { //Pone las entradas en minuscula para evitar errores
    string cambiarDato = especie;
    transform(cambiarDato.begin(), cambiarDato.end(), cambiarDato.begin(), [](unsigned char c){return ::tolower(c);});
    return cambiarDato;
}

void Zoologico::agregarHabitat(string habitat) { //Se agrega Habitat: desértico, selvático, polar y acuático.
    bool comprobante;

    string habitatM = transformarMinuscula(habitat);

    comprobante = Comprobante(habitatM); //Comprueba si el habitat agregada coincide con la lista de habitats disponibles
    if (comprobante == true)
    {
        Habitat *pAgregarHabitat = new Habitat(habitatM);
        this->AdHabitat.push_back(pAgregarHabitat);
        cout << "Se agregado el Habitat Correctamente" << endl;
    }
    else
    {
        cout<<"El dato no coincide con los habitas disponibles"<<endl;
        cout<<endl;
    }
}

void Zoologico::agregarAnimal(string nombre, string especie, string habitat, int edad, string comida, string juego, int dormir) {
    Animal *pAgregarAnimal = new Animal(nombre, especie, habitat, comida, juego, edad, dormir);
    bool comprobante;

    string habitat1 = transformarMinuscula(habitat);

    comprobante = ComprobanteListaHabitat(habitat1); //Comprueba si el habitat del animal coincide con la lista habitat
    if (comprobante == false)
    {
        cout << "El Habitat del animal no coincide con los datos disponibles" << endl;
    }
    else
    {
        this->contadorAnimal += 1;
        this->mapaAnimal.insert(make_pair(Zoologico::contadorAnimal, pAgregarAnimal)); //Datos de animal
        cout<<"Se agrego Correctamente"<<endl;
    }
}

void Zoologico::agDatosAnimal() {
    string nombre, especie, habitat, comida, juego;
    int edad, dormir;

    string valor;

    if (AdHabitat.empty())
    {
        cout<<"No hay Habitat Existente"<<endl;
    }
    else
    {
        cin.ignore();
        cout << "Nombre:" << endl;
        getline(cin, nombre, '\n');
        cout << "Especie:" << endl;
        getline(cin, especie, '\n');
        cout << "Habitat:" << endl;
        getline(cin, habitat, '\n');

        cout << "Tipo alimentacion:" << endl;
        getline(cin, comida, '\n');
        cout << "El animal a jugado ?" << endl;
        getline(cin, juego, '\n');

        valor = transformarMinuscula(juego);
        juego = valor;

        cout << "Edad:" << endl;
        cin >> edad;
        cout << "Cuanto duerme en el dia:" << endl;
        cin >> dormir;

        agregarAnimal(nombre, especie, habitat, edad, comida, juego, dormir);
    }
}

void Zoologico::mostrarDatosAnimal() {
    if (mapaAnimal.empty())
    {
        cout<<"No hay Animales Diponibles"<<endl;
    }
    else
    {
        for (auto const &elemento: mapaAnimal) {
            cout << elemento.first << " : " << "Habitat: " << elemento.second->getHabitat()
            << ", Nombre: " << elemento.second->getNombre() << ", Especie: " << elemento.second->getEspecie()
            << ", Edad: "<< elemento.second->getEdad()<< ", Tipo de alimento: " << elemento.second->getComer()
            << ", Duerme en horas: "<< elemento.second->getDormir()<< ", A jugado: " << elemento.second ->getJuego()
            << endl;
        }
        cout << endl;
    }
}

void Zoologico::Acciones() {
    if (mapaAnimal.empty()){cout<<"No hay animales Disponibles"<<endl;}
    else {
        int entrada;
        do {
            cout << "1. Alimentar Animal" << endl;
            cout << "2. Dormir Animal" << endl;
            cout << "3. Dar juego al Animal" << endl;
            cout << "0. Salir al menu inicial" << endl;

            cin >> entrada;

            switch (entrada) {
                case 1:
                    AlimentarAnimales();
                    break;
                case 2:
                    DormirAnimales();
                    break;
                case 3:
                    JugarAnimales();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        } while (entrada != 0);
    }
}

void Zoologico::AlimentarAnimales() {
    int entrada, entrada2, entrada3;
    string alimento, validacion, entrada1;

    cin.ignore();

    mostrarDatosAnimal();
    cout<<"A quien desea alimentar:"<<endl;
    getline(cin, entrada1, '\n');
    entrada = validarInt(entrada1);
    if (entrada==0){cout<<"Entrada no Valida"<<endl;}
    else
    {
        cout << "Tipo de Alimento:" << endl;
        getline(cin, alimento, '\n');
        entrada2 = ValidarString(alimento);
        if (entrada2==0){cout<<"Entrada no Valida"<<endl;}
        else
        {

            auto iter = mapaAnimal.find(entrada);
            if (iter != mapaAnimal.end() and iter->second->getComer() == alimento) {
                cout << "Se dio de comer correctamente al " << iter->second->getEspecie() << endl;

                cout << "Se desea cambiar la alimentacion del " << iter->second->getEspecie() << ":" << endl;
                getline(cin, validacion, '\n');
                entrada3 = ValidarString(validacion);
                if (entrada3==0){cout<<"Entrada no Valida"<<endl;}
                else {
                    validacion = transformarMinuscula(validacion);
                    if (validacion == "si") {
                        cout << "Ingrese nueva alimentacion:" << endl;
                        getline(cin, alimento, '\n');
                        iter->second->setComer(alimento);
                        cout << "Se actualizo Correctamente" << endl;
                    }
                }
            } else if (iter != mapaAnimal.end()) {
                cout << "El tipo de alimento: " << alimento << " No es adecuado para el animal escogido" << endl;
            } else {
                cerr << "No se encontro el animal" << endl;
            }
        }
    }
}
void Zoologico::DormirAnimales() {
    int entrada, valor, valor1;
    string entrada1, valor2;

    cin.ignore();
    mostrarDatosAnimal();
    cout<<"Escoja un animal:"<<endl;
    getline(cin, entrada1, '\n');
    entrada = validarInt(entrada1);
    if (entrada==0){cout<<"Entrada no Valida"<<endl;}
    else {

        cout << "Cuantas horas Estima para el animal:" << endl;
        getline(cin, valor2, '\n');
        valor = validarInt(valor2);
        if (valor==0){cout<<"Entrada no Valida"<<endl;}
        else {

            auto iter = mapaAnimal.find(entrada);

            if (iter != mapaAnimal.end()) {
                valor1 = iter->second->getDormir() * 2;
            }
            if (iter != mapaAnimal.end() and iter->second->getDormir() <= valor and
                valor1 >= valor) //Se estima un Minimo y un Maximo permitido
            {
                iter->second->setDormir(valor);
                cout << "Se cuadro correctamente las horas, ahora el " << iter->second->getEspecie()
                     << ", Duerme: " << iter->second->getDormir() << " Horas" << endl;
            } else if (iter != mapaAnimal.end()) {
                cout << "El numero de horas debe estar entre " << iter->second->getDormir() << " y " << valor1 << endl;
            } else {
                cerr << "No se encontro el animal" << endl;
            }
        }
    }
}

void Zoologico::JugarAnimales() {
    int entrada;
    string entrada1;

    cin.ignore();
    mostrarDatosAnimal();
    cout<<"Con quien desea jugar:"<<endl;
    getline(cin, entrada1, '\n');
    entrada = validarInt(entrada1);
    if (entrada==0){cout<<"Entrada no Valida"<<endl;}
    else {

        auto iter = mapaAnimal.find(entrada);
        if (iter != mapaAnimal.end() && iter->second->getJuego() == "no") {
            iter->second->setJuego("si");
            cout << "El " << iter->second->getEspecie() << " ha jugado" << endl;
        } else if (iter != mapaAnimal.end()) {
            cout << "El " << iter->second->getEspecie() << " ya jugo" << endl;
        } else {
            cerr << "No se encontro el animal" << endl;
        }
    }
}

int Zoologico::validarInt(string entrada) {
    int entrada1;
    for (char c: entrada)
    {
        if (!isdigit(c)) //Cuando la entrada es diferente a un Dijito
        {
            return 0;
        }
    }
    entrada1 = stoi(entrada);
    return entrada1;
}

int Zoologico::ValidarString(string entrada) {
    for (char c: entrada)
    {
        if (isdigit(c)) //Cuando la entrada es un Digito
        {
            return 0;
        }
    }
    return 1;
}
