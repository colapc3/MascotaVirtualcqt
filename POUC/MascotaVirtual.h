#ifndef MASCOTAVIRTUAL_H
#define MASCOTAVIRTUAL_H

#include <string>

enum class Estado {
    Neutro,
    Feliz,
    Triste,
    Hambriento,
    Enojado,
    Cansado,
    Muerto
};

class MascotaVirtual {
private:
    std::string nombre;
    int edad; // en segundos
    int salud;
    int energia;
    int felicidad;
    Estado estadoActual;

    void actualizarEstado();
    void verificarLimites();

public:
    MascotaVirtual(std::string nombreMascota);
    void simularTiempo(double segundos);
    void imprimirEstado();
    void setSalud(int s);
    void setEnergia(int e);
    void setFelicidad(int f);
};

#endif
