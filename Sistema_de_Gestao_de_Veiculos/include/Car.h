#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

// Tratar exceção do numero de portas
class Door_invalid_exception : public exception {
public:
    const char* what() const noexcept override;
};

class Car : public Vehicle{
    int num_door;
    vector<bool> door;
public:
    // Construtor
    Car(const string& b, int y, double s, int n);

    ~Car() override;
    // Retorna o numero de portas
    int get_num_door() const;

    void open_door (int position); // Abre uma porta selecionada
    void close_door (); // Fecha todas as portas

    // Sobrecarga de <<
    friend std::ostream& operator<<(std::ostream& out, const Car& c);

    // Exibe as informações do carro
    void show_info() const override;
};

#endif