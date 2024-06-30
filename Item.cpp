#include "Item.h"

Item::Item(int id, const std::string& nombre, int cantidad)
    : id(id), nombre(nombre), cantidad(cantidad) {}

int Item::getId() const {
    return id;
}

const std::string& Item::getNombre() const {
    return nombre;
}

int Item::getCantidad() const {
    return cantidad;
}

void Item::usar() {
    if (cantidad > 0) {
        --cantidad;
    }
}

Comida::Comida(int id, const std::string& nombre, int cantidad)
    : Item(id, nombre, cantidad) {}

Medicina::Medicina(int id, const std::string& nombre, int cantidad)
    : Item(id, nombre, cantidad) {}

Juguete::Juguete(int id, const std::string& nombre, int cantidad)
    : Item(id, nombre, cantidad) {}
