#include "ManagerVehicle.h"

/*
Manager_vehicle::~Manager_vehicle() {
    for (auto v : vehicles) {
        delete (v);
    }
    vehicles.clear();
}*/

void Manager_vehicle::add_vehicle(Vehicle* v) {
    vehicles.push_back(v);
}

void Manager_vehicle::remove_vehicle(size_t position) {
    if (position >= vehicles.size()) { // Verifica se a posição é valida
        cout << "Position invalid" << endl;
        return;
    }

    // Apagar o veículo na posição indicada
    delete vehicles[position]; // Deletar o objeto
    vehicles.erase(vehicles.begin() + position); // Remover do vetor
}

void Manager_vehicle::accelerate_all(double speed) {
    for (auto v = vehicles.begin(); v != vehicles.end(); v++) {
        (*v)->accelerate(speed);
    }
}

void Manager_vehicle::brake_all(double valor) {
    for (auto v = vehicles.begin(); v != vehicles.end(); v++) {
        (*v)->brake(valor);
    }
}

void Manager_vehicle::show_info() const {
    if (vehicles.size() == 0) { // Verifica se o vector esta vazio
        cout << "There aren't vehicles" << endl;
    }
    for (auto v = vehicles.begin(); v != vehicles.end(); ++v) {
        (*v)->show_info();
    }
}