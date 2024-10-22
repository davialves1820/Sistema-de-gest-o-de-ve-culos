#include "Car.h"

const char* Door_invalid_exception::what() const noexcept {
    return "Door quantity invalid";
}

Car::Car(const string& b, int y, double s, int n) : Vehicle(b, y, s), num_door(n) {
    if (n < 2 ) {
        throw Door_invalid_exception();
    }
    door = vector<bool>(num_door, false); // Inicializa todas as portas como false(fechadas)
}

Car::~Car() {}

int Car::get_num_door() const {
    return num_door;
}

void Car::open_door(int position) {
    // Verifica se o numero da porta é valido
    if (position >= num_door || position < 0) {
        cout << "Door invalid" << endl;
        return;
    }

    door[position] = true; // Abre a porta indicada;
}

void Car::close_door() {
    door = vector<bool>(num_door, false); // Fecha todas as portas
}

std::ostream& operator<<(std::ostream& out, const Car& c) {
    out << "Car" << endl;
    out << "Brand: " << c.get_brand() << endl;
    out << "Year: " << c.get_year() << endl;
    out << "Speed: " << c.get_speed() << endl;
    out << "Num doors: " << c.num_door << endl;

    return out;
}

void Car::show_info() const {
    cout << *this;
}