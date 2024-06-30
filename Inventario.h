#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include <vector>
#include <string>

class Inventario {
public:
    void agregarItem(Item* item);
    void eliminarItem(int id);
    Item* obtenerItem(int id);
    void mostrarInventario() const;
    const std::vector<Item*>& getItems() const;
    void cargarDesdeCSV(const std::string& nombreArchivo);

private:
    std::vector<Item*> items;
};

#endif // INVENTARIO_H
