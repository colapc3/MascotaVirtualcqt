#include "Inventario.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Inventario::agregarItem(Item* item) {
    items.push_back(item);
}

void Inventario::eliminarItem(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getId() == id) {
            items.erase(it);
            break;
        }
    }
}

Item* Inventario::obtenerItem(int id) {
    for (auto& item : items) {
        if (item->getId() == id) {
            return item;
        }
    }
    return nullptr;
}

void Inventario::mostrarInventario() const {
    for (const auto& item : items) {
        std::cout << "ID: " << item->getId() << ", Nombre: " << item->getNombre() << ", Cantidad: " << item->getCantidad() << std::endl;
    }
}

const std::vector<Item*>& Inventario::getItems() const {
    return items;
}

void Inventario::cargarDesdeCSV(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    bool primeraLinea = true;
    while (std::getline(archivo, linea)) {
        if (primeraLinea) {
            primeraLinea = false; // Ignorar la primera línea (nombre de la mascota)
            continue;
        }

        std::istringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;
        while (std::getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        if (campos.size() >= 4) {
            int id = std::stoi(campos[0]);
            std::string tipo = campos[1];
            std::string nombre = campos[2];
            int cantidad = std::stoi(campos[3]);
            Item* item = nullptr;

            if (tipo == "Comida") {
                item = new Comida(id, nombre, cantidad);
            } else if (tipo == "Medicina") {
                item = new Medicina(id, nombre, cantidad);
            } else if (tipo == "Juguete") {
                item = new Juguete(id, nombre, cantidad);
            }

            if (item) {
                agregarItem(item);
            }
        }
    }

    archivo.close();
}
