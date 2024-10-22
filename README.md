# Sistema de Gestão de Veículos

Este projeto é um sistema de gestão de veículos desenvolvido em C++. Ele permite o gerenciamento de diferentes tipos de veículos (carros, caminhões, motocicletas) por meio de uma interface simples. O sistema utiliza conceitos de Programação Orientada a Objetos (POO), como herança e polimorfismo.

## Funcionalidades

- **Gerenciamento de Veículos**: Adicione, remova e visualize veículos.
- **Aceleração e Desaceleração**: Controle a velocidade dos veículos.
- **Exibição de Informações**: Mostre informações detalhadas sobre os veículos cadastrados.

## Estrutura do Projeto

- **`src/: Contém os arquivos de implementação (.cpp).
- **`include/: Contém os arquivos de cabeçalho (.h).
- **`obj/: Diretório gerado pelo Makefile para armazenar arquivos objeto (.o).
- **`build/: Diretório gerado pelo Makefile para o executável final.
- **`Makefile: Script para automatizar o processo de compilação.

## Classes Principais

- **`Vehicle`**: Classe base abstrata para todos os tipos de veículos.
- **`Car`**, **`Truck`**, **`Motorcycle`**: Classes derivadas que implementam a funcionalidade específica de cada tipo de veículo.
- **`Manager_vehicle`**: Classe responsável por gerenciar uma coleção de veículos.

## Compilação e Execução

Para compilar o projeto, use o `Makefile`. No terminal, execute: 

```bash
make

./build/my_program
