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

    comprobante=Zoologico::Comprobante(habitatM);
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

    comprobante = Zoologico::ComprobanteListaHabitat(habitat1);
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
            cout << elemento.first << " : " << "Habitat: " << elemento.second->getHabitat() << ", Especie: "
                 << elemento.second->getEspecie()<< ", Edad: "<< elemento.second->getEdad()<< ", Tipo de alimento: "
                 << elemento.second->getComer()<< ", Duerme en horas: "<< elemento.second->getDormir()<< ", A jugado: "
                 << elemento.second ->getJuego()<< endl;
        }
        cout << endl;
    }
}

void Zoologico::Acciones() {
    if (mapaAnimal.empty()){cout<<"No hay animales Disponible"<<endl;}
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
    int entrada;
    string alimento;

    mostrarDatosAnimal();
    cout<<"A quien desea alimentar:"<<endl;
    cin>>entrada;

    cin.ignore();
    cout<<"Tipo de Alimento:"<<endl;
    getline(cin, alimento, '\n');

    try
    {
        auto iter = mapaAnimal.find(entrada);
        if (iter->second->getComer()==alimento)
        {
            cout<<"Se dio de comer correctamente al "<<iter->second->getEspecie()<<endl;
        }
        else
        {
            cout<<"El tipo de alimento: "<<alimento<<" No es adecuado para el animal escogido"<<endl;
        }
    }
    catch (const out_of_range& e)
    {
        cout<<"No se Encontro el Animal"<<endl;
    }


}
void Zoologico::DormirAnimales() {
    int entrada, valor, valor1;

    cin.ignore();
    mostrarDatosAnimal();
    cout<<"Escoja un animal:"<<endl;
    cin>>entrada;

    cout<<"Que horas de sueno Estima para el animal:"<<endl;
    cin>>valor;
    try
    {
        auto iter = mapaAnimal.find(entrada);
        valor1=iter->second->getDormir()*2;
        if (iter->second->getDormir()<=valor and valor1>=valor) //Se estima un Minimo y un Maximo permitido
        {
            iter->second->setDormir(valor);
            cout<<"Se cuadro correctamente las horas, ahora el "<<iter->second->getEspecie()
            <<", Duerme: "<<iter->second->getDormir()<<" Horas"<<endl;
        }
        else
        {
            cout<<"Las horas, No son suficientes o sobre-pasan maximo permitido"<<endl;
        }
    }
    catch (const out_of_range e)
    {
        cout<<"No se Encontro el Animal"<<endl;
    }
}
void Zoologico::JugarAnimales() {
    int entrada;

    cin.ignore();
    mostrarDatosAnimal();
    cout<<"Con quien desea jugar:"<<endl;
    cin>>entrada;
    try
    {
        auto iter = mapaAnimal.find(entrada);
        if (iter->second->getJuego()=="no")
        {
            iter->second->setJuego("si");
            cout<<"El "<<iter->second->getEspecie()<<" a jugado"<<endl;
        }
        else
        {
            cout<<"El "<<iter->second->getEspecie()<<" ya jugo"<<endl;
        }

    }
    catch (const out_of_range e)
    {
        cout<<"No se Encontro el Animal"<<endl;
    }
}

