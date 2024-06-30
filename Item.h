#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(int id, const std::string& nombre, int cantidad);
    virtual ~Item() = default; // Destructor virtual

    int getId() const;
    const std::string& getNombre() const;
    int getCantidad() const;
    void usar();

protected:
    int id;
    std::string nombre;
    int cantidad;
};

class Comida : public Item {
public:
    Comida(int id, const std::string& nombre, int cantidad);
};

class Medicina : public Item {
public:
    Medicina(int id, const std::string& nombre, int cantidad);
};

class Juguete : public Item {
public:
    Juguete(int id, const std::string& nombre, int cantidad);
};

#endif // ITEM_H
