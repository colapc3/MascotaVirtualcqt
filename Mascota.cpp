#include "Mascota.h"
#include <iostream>
#include <algorithm>

Mascota::Mascota(const std::string& nombre)
    : nombre(nombre), edad(0), salud(100), energia(100), felicidad(50), estado(Neutro) {}

void Mascota::mostrarEstado() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Salud: " << salud << std::endl;
    std::cout << "Energía: " << energia << std::endl;
    std::cout << "Felicidad: " << felicidad << std::endl;
    std::cout << "Estado: " << estado << std::endl;
}

void Mascota::usarComida() {
    salud = std::min(100, salud + 20);
    energia = std::min(100, energia + 20);
    avanzarTiempo(0.5); // Avanzar el tiempo en 0.5 segundos
    actualizarEstado();
}

void Mascota::usarMedicina() {
    salud = std::min(100, salud + 40);
    avanzarTiempo(0.5); // Avanzar el tiempo en 0.5 segundos
    actualizarEstado();
}

void Mascota::usarJuguete() {
    felicidad = std::min(100, felicidad + 30);
    avanzarTiempo(0.5); // Avanzar el tiempo en 0.5 segundos
    actualizarEstado();
}

void Mascota::avanzarTiempo(double segundos) {
    // Incrementar la edad en días (1 día = 86400 segundos)
    edad += segundos / 86400.0;

    // Afectar indicadores entre sí
    if (edad <= 5 && salud <= 10) {
        felicidad = std::max(0, static_cast<int>(felicidad - 20));
    } else if (edad > 5 && edad <= 10 && salud <= 50) {
        felicidad = std::max(0, static_cast<int>(felicidad - 20));
        energia = std::max(0, static_cast<int>(energia - 10));
    } else if (edad > 10 && salud <= 50) {
        felicidad = std::max(0, static_cast<int>(felicidad - 30));
        energia = std::max(0, static_cast<int>(energia - 20));
    }

    // Disminuir salud, energía y felicidad con el tiempo
    salud = std::max(0, salud - static_cast<int>(segundos / 86400.0)); // Disminuir salud cada día
    energia = std::max(0, energia - static_cast<int>(segundos / 3600.0)); // Disminuir energía cada hora
    felicidad = std::max(0, felicidad - static_cast<int>(segundos / 86400.0)); // Disminuir felicidad cada día

    actualizarEstado();
}

void Mascota::actualizarEstado() {
    if (salud <= 0 || energia <= 0) {
        estado = Muerto;
    } else if (felicidad >= 60) {
        estado = Feliz;
    } else if (felicidad <= 20) {
        estado = Triste;
    } else if (edad <= 5 && salud <= 20) {
        estado = Hambriento;
    } else if (edad > 5 && salud <= 50) {
        estado = Enojado;
    } else if (energia <= 15) {
        estado = Cansado;
    } else {
        estado = Neutro;
    }
}

const std::string& Mascota::getNombre() const {
    return nombre;
}

double Mascota::getEdad() const {
    return edad;
}

int Mascota::getSalud() const {
    return salud;
}

int Mascota::getEnergia() const {
    return energia;
}

int Mascota::getFelicidad() const {
    return felicidad;
}

Mascota::Estado Mascota::getEstado() const {
    return estado;
}
