#include "Inventario.h"
#include "Mascota.h"

void Inventario::agregarItem(shared_ptr<Item> item) {
    items.push_back(item);
}

void Inventario::usarItem(int id, Mascota& mascota) {
    auto it = find_if(items.begin(), items.end(), [id](const shared_ptr<Item>& item) { return item->getId() == id; });
    if (it != items.end() && (*it)->getCantidad() != 0) {
        (*it)->usar(mascota);
    } else {
        cout << "Item no disponible o cantidad agotada.\n";
    }
}

void Inventario::mostrarInventario() {
    for (const auto& item : items) {
        item->mostrarItem();
    }
}
