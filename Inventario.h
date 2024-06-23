#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Inventario {
public:
    void agregarItem(shared_ptr<Item> item) {
        items.push_back(item);
    }

    void usarItem(int id, Mascota& mascota) {
        for (auto& item : items) {
            if (item->getId() == id) {
                item->usar(mascota);
                if (item->getCantidad() == 0) {
                    items.erase(remove(items.begin(), items.end(), item), items.end());
                }
                break;
            }
        }
    }

    void imprimirInventario() const {
        for (const auto& item : items) {
            cout << "ID: " << item->getId() << "\n";
            cout << "Nombre: " << item->getNombre() << "\n";
            cout << "Cantidad: " << item->getCantidad() << "\n";
        }
    }

private:
    vector<shared_ptr<Item>> items;
};

#endif // INVENTARIO_H
