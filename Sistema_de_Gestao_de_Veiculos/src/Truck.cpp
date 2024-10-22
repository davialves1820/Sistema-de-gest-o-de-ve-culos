#include "Truck.h"

const char* Charge_exceed_exception::what() const noexcept { return "Charge exceed"; }

const char* Charge_invalid_exception::what() const noexcept { return "Charge invalid"; }

Truck::Truck(const string& b, int y, double s, double c_h, double c_n) : Vehicle(b, y, s), charge_now(c_n) {
    if (c_h < 0) { // Verifica se a carga é valida
        throw Charge_invalid_exception();
    }
    charge_high = c_h;
    if (c_n > charge_high) { // Verifica se a carga a armazenar não é maior que a capacidade permitida
        throw Charge_exceed_exception();
    }
    if (c_n < 0) { // Verifica se a carga é valida
        throw Charge_invalid_exception();
    }
}

Truck::~Truck() {}

void Truck::store_charge(double value) {
    if (value < 0) { // Verifica se a carga a armazenar é valida
        throw Charge_invalid_exception();
    }
    charge_now += value;
    if (charge_now > charge_high) { // Verifica se a carga não ultrapassou o limite
        charge_now = charge_high;
    }
}

void Truck::unload_charge(double value) {
    if (value < 0) { // Verifica se a quantidade é valida
        throw Charge_invalid_exception();
    }
    if (value > charge_now) { // Verifica se o valor não é maior que a carga atual
        throw Charge_exceed_exception();
    }
}

std::ostream& operator<<(std::ostream& out, const Truck& t) {
    out << "Truck" << endl;
    out << "Brand: " << t.get_brand() << endl;
    out << "year: " << t.get_year() << endl;
    out << "Speed: " << t.get_speed() << endl;
    out << "Max charge: " << t.charge_high << endl;
    out << "Charge now: " << t.charge_now << endl;
    return out;
}

void Truck::show_info() const {
    cout << *this;
}