#include "Mascota.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<shared_ptr<Item>> leerConfig(const string& nombreArchivo, string& nombreMascota) {
    ifstream archivo(nombreArchivo);
    string linea;
    vector<shared_ptr<Item>> items;

    if (archivo.is_open()) {
        getline(archivo, nombreMascota); // Leer el nombre de la mascota

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string idStr, tipoItem, nombreItem, cantidadStr, ubicacionImagen;
            getline(ss, idStr, ';');
            getline(ss, tipoItem, ';');
            getline(ss, nombreItem, ';');
            getline(ss, cantidadStr, ';');
            getline(ss, ubicacionImagen, ';'); // Este campo es opcional

            int id = stoi(idStr);
            int cantidad = stoi(cantidadStr);

            if (tipoItem == "Comida") {
                items.push_back(make_shared<Comida>(id, cantidad, nombreItem));
            } else if (tipoItem == "Medicina") {
                items.push_back(make_shared<Medicina>(id, cantidad, nombreItem));
            } else if (tipoItem == "Juguete") {
                items.push_back(make_shared<Juguete>(id, nombreItem));
            }
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo de configuración." << endl;
    }

    return items;
}

int main() {
    string nombreMascota;
    vector<shared_ptr<Item>> items = leerConfig("config.csv", nombreMascota);

    Mascota miMascota(nombreMascota, items);

    miMascota.imprimirEstado();
    miMascota.getInventario().imprimirInventario();

    // Usar ítems en la mascota
    miMascota.getInventario().usarItem(2, miMascota); // Usar comida
    miMascota.imprimirEstado();

    miMascota.getInventario().usarItem(4, miMascota); // Usar medicina
    miMascota.imprimirEstado();

    miMascota.getInventario().usarItem(1, miMascota); // Usar juguete
    miMascota.imprimirEstado();

    return 0;
}
