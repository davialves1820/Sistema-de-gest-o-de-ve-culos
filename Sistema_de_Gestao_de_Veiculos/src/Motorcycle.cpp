#include "Motorcycle.h"

Motorcycle::Motorcycle(const string& b, int y, double s, bool h) : Vehicle(b, y, s), has_sidecar(h) {}

Motorcycle::~Motorcycle() {}

void Motorcycle::accelerate(double value) {
    if (value < 0) { // Verifica se a velocidade é valida
        throw Speed_invalid_exception();
    }
    double speed = has_sidecar ? 10.0 : 20.0; // Limita a aceleração dependendo se tem ou nao o sidecar
    if (value > speed) { 
        value = speed;
    }
    Vehicle::accelerate(value);
}

void Motorcycle::remove_sidecar() { has_sidecar = false; }

void Motorcycle::add_sidecar() { has_sidecar = true; }

std::ostream& operator<<(std::ostream& out, const Motorcycle& m) {
    out << "Motorcycle" << endl;
    out << "Brand: " << m.get_brand() << endl;
    out << "Year: " << m.get_year() << endl;
    out << "Speed: " << m.get_speed() << endl;
    out << "Has sidecar: " << (m.has_sidecar ? "Yes" : "No") << endl;
    return out;
}

void Motorcycle::show_info() const { cout << *this; }