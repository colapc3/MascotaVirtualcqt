#include "MascotaVirtual.h"
#include <iostream>

using namespace std;

int main() {
    MascotaVirtual mascota("Pelusa");

    mascota.imprimirEstado();
    mascota.simularTiempo(5); // Simular 5 segundos
    mascota.imprimirEstado();

    return 0;
}
