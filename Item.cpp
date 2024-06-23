#include "Item.h"
#include "Mascota.h"

void Comida::usar(Mascota& mascota) {
    cout << "Usando comida: " << nombre << " en la mascota\n";
    mascota.setSalud(mascota.getSalud() + 20);
    mascota.setEnergia(mascota.getEnergia() + 20);
    cantidad--;
}

void Medicina::usar(Mascota& mascota) {
    cout << "Usando medicina: " << nombre << " en la mascota\n";
    mascota.setSalud(mascota.getSalud() + 40);
    cantidad--;
}

void Juguete::usar(Mascota& mascota) {
    cout << "Usando juguete: " << nombre << " en la mascota\n";
    mascota.setFelicidad(mascota.getFelicidad() + 30);
}
