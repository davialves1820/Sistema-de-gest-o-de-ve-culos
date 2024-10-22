#ifndef MANAGERVEHICLE_H
#define MANAGERVEHICLE_H

#include "Vehicle.h"

class Manager_vehicle {
    vector<Vehicle*> vehicles; 
public:
    // Destrutor
    //~Manager_vehicle();

    // Adiciona um veiculo no vector
    void add_vehicle(Vehicle* v);

    // Remove um veiculo no vector
    void remove_vehicle(size_t position);

    // Acelera todos os veiculos de acordo com a velocidade indicada pelo usuario
    void accelerate_all(double s);

    // Desacelera todos os veiculos de acordo com a quantidade indicada pelo usuario
    void brake_all(double valor);
    
    // Exibe as informações de todos os veiculos
    void show_info() const;
};

#endif