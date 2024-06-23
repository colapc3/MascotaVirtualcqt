#ifndef MASCOTA_H
#define MASCOTA_H

#include "Inventario.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Mascota {
public:
    enum class Estado { Neutro, Feliz, Triste, Hambriento, Enojado, Cansado, Muerto };

    Mascota(string nombreMascota);
    Mascota(string nombreMascota, const vector<shared_ptr<Item>>& items);

    void actualizarEstado();
    void verificarLimites();
    void imprimirEstado();

    void setSalud(int s);
    int getSalud() const { return salud; }
    void setEnergia(int e);
    int getEnergia() const { return energia; }
    void setFelicidad(int f);
    int getFelicidad() const { return felicidad; }

    Inventario& getInventario() { return inventario; }

private:
    string nombre;
    double edad;
    int salud;
    int energia;
    int felicidad;
    Estado estadoActual;

    void disminuirFelicidad(int cantidad);
    Inventario inventario;
};

#endif // MASCOTA_H
