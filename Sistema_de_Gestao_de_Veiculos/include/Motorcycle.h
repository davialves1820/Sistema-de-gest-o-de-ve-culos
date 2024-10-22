#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
    bool has_sidecar;
public: 
    // Construtor
    Motorcycle(const string& b, int y, double s, bool h);

    ~Motorcycle() override;
    // Sobreescrita do metodo accelerate
    void accelerate(double value) override;

    // Remover o sidecar da moto
    void remove_sidecar();

    // Colocar o sidecar na moto
    void add_sidecar();

    // Sobrecarga de <<
    friend std::ostream& operator<<(std::ostream& out, const Motorcycle& m);

    // Exibe informações da moto
    void show_info() const override;
};

#endif