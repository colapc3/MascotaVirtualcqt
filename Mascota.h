#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

class Mascota {
public:
    enum Estado { Neutro, Feliz, Triste, Hambriento, Enojado, Cansado, Muerto };

    Mascota(const std::string& nombre);

    void mostrarEstado() const;
    void usarComida();
    void usarMedicina();
    void usarJuguete();
    void avanzarTiempo(double segundos);

    const std::string& getNombre() const;
    double getEdad() const;
    int getSalud() const;
    int getEnergia() const;
    int getFelicidad() const;
    Estado getEstado() const;

private:
    std::string nombre;
    double edad; // En días
    int salud; // 0-100
    int energia; // 0-100
    int felicidad; // 0-100
    Estado estado;

    void actualizarEstado();
};

#endif // MASCOTA_H
