#include "Vehicle.h"

const char* Speed_invalid_exception::what() const noexcept {
    return "Speed invalid";
}

Vehicle::Vehicle(const string& b, int y, double s) : brand(b), year(y){
    if (s < 0) { // Verifica se a velocidade é valida
        throw Speed_invalid_exception();
    } 
    speed = s;
}

Vehicle::~Vehicle() {}

void Vehicle::set_brand(const string& b) { brand = b; }

string Vehicle::get_brand() const { return brand; }

void Vehicle::set_speed(double s) { speed = s; }

double Vehicle::get_speed() const { return speed; }

void Vehicle::set_year(int y) { year = y; }

int Vehicle::get_year() const { return year; }

void Vehicle::accelerate(double a) {
    if (a < 0) { // Verifica se a velocidade é valida
        throw Speed_invalid_exception();
    } 
    speed += a;
}

void Vehicle::brake(double b) {
    if (b < 0) { // Verifica se a velocidade é valida
        throw Speed_invalid_exception();
    }
    if (b > speed) { // Verifica se a desaleração é maior q a velocidade atual
        speed = 0;
    } else {
        speed -= b;
    }
}