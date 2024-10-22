#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

// Lançada se o valor for invalido
class Charge_invalid_exception : public exception {
public:
    const char* what() const noexcept override;
};

// Lançada quando a carga excede a capacidade permitida
class Charge_exceed_exception : public exception {
public:
    const char* what() const noexcept override;
};

class Truck : public Vehicle {
    double charge_high;
    double charge_now;
public:
    // Construtor
    Truck(const string& b, int y, double s, double c_h, double c_n = 0);

    ~Truck() override;

    void store_charge(double c); // Adicionar carga ao caminhão

    void unload_charge(double c); // Descarregar carga do caminhão

    // Sobrecarga de <<
    friend std::ostream& operator<<(std::ostream& out, const Truck& t);

    // Exibe as informações do caminhão
    void show_info() const;
};

#endif