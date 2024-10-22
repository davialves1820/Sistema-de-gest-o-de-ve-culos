#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::exception;

// Classe para tratar exceções de velocidade
class Speed_invalid_exception : public exception {
public:
    const char* what() const noexcept override;
};

// Classe veiculo
class Vehicle {
    string brand;
    int year;
    double speed;
public:
    // Construtor
    Vehicle(const string& b, int y, double s);
    
    // Destrutor
    virtual ~Vehicle();
    
    // Sets and Gets
    void set_brand(const string& b);

    string get_brand() const;

    void set_year(int y);

    int get_year() const;

    void set_speed(double s);

    double get_speed() const;

    virtual void accelerate(double valor); // Aumenta a velocidade do veiculo

    void brake(double valor); // Diminui a velocidade do veiculo

    virtual void show_info() const = 0; // Metodo abstrato que exibe as informações do veiculo
};

#endif