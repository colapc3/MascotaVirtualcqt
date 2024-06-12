#include "MascotaVirtual.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

MascotaVirtual::MascotaVirtual(string nombreMascota)
    : nombre(nombreMascota), edad(0), salud(100), energia(100), felicidad(100), estadoActual(Estado::Neutro) {}

void MascotaVirtual::actualizarEstado() {
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

void MascotaVirtual::verificarLimites() {
    salud = max(0, min(100, salud));
    energia = max(0, min(100, energia));
    felicidad = max(0, min(100, felicidad));
}

void MascotaVirtual::disminuirFelicidad(int cantidad) {
    felicidad = max(0, felicidad - cantidad);
}

void MascotaVirtual::simularTiempo(double segundos) {
    for (int t = 0; t < segundos * 2; ++t) {
        edad += 0.5;

        if (edad <= 5 && salud <= 10) {
            disminuirFelicidad(20);
        } else if (edad > 5 && edad <= 10 && salud <= 50) {
            disminuirFelicidad(20);
            energia = max(0, energia - 10);
        } else if (edad > 10 && salud <= 50) {
            disminuirFelicidad(30);
            energia = max(0, energia - 20);
        }

        verificarLimites();
        actualizarEstado();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void MascotaVirtual::imprimirEstado() {
    cout << "Nombre: " << nombre << "\n";
    cout << "Edad: " << edad << " segundos\n";
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

void MascotaVirtual::setSalud(int s) {
    salud = s;
    verificarLimites();
    actualizarEstado();
}

void MascotaVirtual::setEnergia(int e) {
    energia = e;
    verificarLimites();
    actualizarEstado();
}

void MascotaVirtual::setFelicidad(int f) {
    felicidad = f;
    verificarLimites();
    actualizarEstado();
}
