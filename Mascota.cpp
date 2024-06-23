#include "Mascota.h"
#include <iostream>
#include <algorithm>

using namespace std;

Mascota::Mascota(string nombreMascota)
    : nombre(nombreMascota), edad(0), salud(100), energia(100), felicidad(50), estadoActual(Estado::Neutro) {}

Mascota::Mascota(string nombreMascota, const vector<shared_ptr<Item>>& items)
    : nombre(nombreMascota), edad(0), salud(100), energia(100), felicidad(50), estadoActual(Estado::Neutro) {
    for (auto& item : items) {
        inventario.agregarItem(item);
    }
}

void Mascota::actualizarEstado() {
    if (salud <= 0 || energia <= 0 || edad >= 15) {
        estadoActual = Estado::Muerto;
    } else if (edad > 5 && salud <= 30 && energia <= 30) {
        estadoActual = Estado::Enojado;
    } else if (energia <= 15) {
        estadoActual = Estado::Cansado;
    } else if ((edad <= 5 && salud <= 20) || (edad > 5 && edad <= 10 && salud <= 50)) {
        estadoActual = Estado::Hambriento;
    } else if (felicidad <= 20) {
        estadoActual = Estado::Triste;
    } else if (felicidad >= 60) {
        estadoActual = Estado::Feliz;
    } else {
        estadoActual = Estado::Neutro;
    }
}

void Mascota::verificarLimites() {
    salud = max(0, min(100, salud));
    energia = max(0, min(100, energia));
    felicidad = max(0, min(100, felicidad));
}

void Mascota::imprimirEstado() {
    cout << "Nombre: " << nombre << "\n";
    cout << "Edad: " << edad << "\n";
    cout << "Salud: " << salud << "\n";
    cout << "Energía: " << energia << "\n";
    cout << "Felicidad: " << felicidad << "\n";
    cout << "Estado: ";
    switch (estadoActual) {
    case Estado::Neutro:
        cout << "Neutro\n";
        break;
    case Estado::Feliz:
        cout << "Feliz\n";
        break;
    case Estado::Triste:
        cout << "Triste\n";
        break;
    case Estado::Hambriento:
        cout << "Hambriento\n";
        break;
    case Estado::Enojado:
        cout << "Enojado\n";
        break;
    case Estado::Cansado:
        cout << "Cansado\n";
        break;
    case Estado::Muerto:
        cout << "Muerto\n";
        break;
    }
}

void Mascota::setSalud(int s) {
    salud = s;
    verificarLimites();
    actualizarEstado();
}

void Mascota::setEnergia(int e) {
    energia = e;
    verificarLimites();
    actualizarEstado();
}

void Mascota::setFelicidad(int f) {
    felicidad = f;
    verificarLimites();
    actualizarEstado();
}
