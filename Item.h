#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

class Mascota;

class Item {
public:
    Item(int id, int cantidad, string nombre) 
        : id(id), cantidad(cantidad), nombre(nombre) {}
    virtual ~Item() = default;

    virtual void usar(Mascota& mascota) = 0;

    int getId() const { return id; }
    int getCantidad() const { return cantidad; }
    const string& getNombre() const { return nombre; }

protected:
    int id;
    int cantidad;
    string nombre;
};

class Comida : public Item {
public:
    Comida(int id, int cantidad, string nombre) 
        : Item(id, cantidad, nombre) {}

    void usar(Mascota& mascota) override;
};

class Medicina : public Item {
public:
    Medicina(int id, int cantidad, string nombre) 
        : Item(id, cantidad, nombre) {}

    void usar(Mascota& mascota) override;
};

class Juguete : public Item {
public:
    Juguete(int id, string nombre) 
        : Item(id, -1, nombre) {}

    void usar(Mascota& mascota) override;
};

#endif // ITEM_H
