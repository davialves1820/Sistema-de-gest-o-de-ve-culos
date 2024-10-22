#include "ManagerVehicle.h"

// Função para exibir o menu
void display_menu() {
    cout << "MENU" << endl;
    cout << "1- Adicionar carro" << endl;
    cout << "2- Adicionar moto" << endl;
    cout << "3- Adicionar caminhao" << endl;
    cout << "4- Remover carro" << endl;
    cout << "5- Remover moto" << endl;
    cout << "6- Remover caminhao" << endl;
    cout << "7- Acelerar todos os veiculos" << endl;
    cout << "8- Desacelerar todos os veiculos" << endl;
    cout << "9- Exibir todos os veiculos" << endl;
    cout << "0- Sair" << endl;
}

// Funções de entrada para cada tipo de veículo
Car* input_car() { 
    string brand;
    int year, num_door;
    double speed;
    
    cout << "Marca: ";
    std::getline(std::cin, brand);
    
    cout << "Ano: ";
    std::cin >> year;
    
    cout << "Velocidade: ";
    std::cin >> speed;

    cout << "Numero de portas: ";
    std::cin >> num_door;
    
    return new Car(brand, year, speed, num_door);
}

Motorcycle* input_motorcycle() {
    string brand;
    int year;
    double speed;
    char sidecar;

    cout << "Marca: ";
    std::getline(std::cin, brand);
    
    cout << "Ano: ";
    std::cin >> year;

    cout << "Velocidade: ";
    std::cin >> speed;

    cout << "Tem sidecar (y/n): ";
    std::cin >> sidecar;

    return new Motorcycle(brand, year, speed, (sidecar == 'y'));
}

Truck* input_truck() {
    string brand;
    int year;
    double speed, charge;

    cout << "Marca: ";
    std::getline(std::cin, brand);
    
    cout << "Ano: ";
    std::cin >> year;

    cout << "Velocidade: ";
    std::cin >> speed;

    cout << "Carga: ";
    std::cin >> charge;

    return new Truck(brand, year, speed, charge);
}

int main(void) {

    Manager_vehicle m_v;

    cout << "Bem vindo ao sistema de gerenciamento de veiculos" << endl;
    int op;
    do {
        display_menu(); // Exibe o menu
        cout << "Opcao: "; 
        std::cin >> op; // ler a opção selecionada pelo usuario
        std::cin.ignore();

        switch (op) {
            case 1: {
                try {
                    m_v.add_vehicle(input_car());
                } catch (const std::exception& e) { // Trata as exceções
                    cout << e.what() << endl;
                }
                break;
            }

            case 2: {
                try {
                    m_v.add_vehicle(input_motorcycle());
                } catch (const std::exception& e) { // Trata as exceções
                    cout << e.what() << endl;
                }
                break;
            }

            case 3: {
                try {
                    m_v.add_vehicle(input_truck());
                } catch (const std::exception& e) { // Trata as exceções
                    cout << e.what() << endl;
                }
                break;
            }

            case 4: {
                int index;
                cout << "Indice do carro a remover: ";
                std::cin >> index;
                m_v.remove_vehicle(index);
                break;
            }

            case 5: {
                int index;
                cout << "Indice da moto a remover: ";
                std::cin >> index;
                m_v.remove_vehicle(index);
                break;
            }

            case 6: {
                int index;
                cout << "Indice do caminhao a remover: ";
                std::cin >> index;
                m_v.remove_vehicle(index);
                break;
            }

            case 7: {
                try {
                    double speed;
                    cout << "Valor de aceleracao: ";
                    std::cin >> speed;
                    m_v.accelerate_all(speed);
                } catch (const Speed_invalid_exception& e) { // Trata a exceção de velocidade
                    cout << e.what() << endl;
                }
                break;
            }

            case 8: {
                try {
                    double speed;
                    cout << "Valor de desaceleracao: ";
                    std::cin >> speed;
                    m_v.brake_all(speed);
                } catch (const Speed_invalid_exception& e) { // Trata a exceção de velocidade
                    cout << e.what() << endl;
                }
                break;
            }

            case 9: {
                m_v.show_info();
                break;
            }

            case 0:
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (op != 0);

    return 0;
}