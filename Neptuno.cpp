#include "Neptuno.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const float Neptuno::Gasolina_Requerida = 900000.0f;
const vector<int> Neptuno::Rutas = { 1, 2, 3 };
const float Neptuno::Probabilidad_Asteroides = 0.9f;
const int Neptuno::Dano_Asteroides = 40;
const int Neptuno::Ruta_Aleatoria = 3;

bool Neptuno::llegar(Cohete* cohete) {
    if (cohete->getGasolina() < Gasolina_Requerida) {
        std::cout << "El cohete " << cohete->getNombre() << " se quedó sin gasolina y no pudo llegar a Neptuno." << std::endl;
        return false;
    }

    float probabilidad = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    if (probabilidad < Probabilidad_Asteroides) {
        cohete->setAlaIzquierda(cohete->getAlaIzquierda() - Dano_Asteroides);
        cohete->setAlaDerecha(cohete->getAlaDerecha() - Dano_Asteroides);

        if (cohete->getAlaIzquierda() <= 0 && cohete->getAlaDerecha() <= 0) {
            cout << "El cohete " << cohete->getNombre() << " perdió ambas alas y no pudo llegar a Neptuno." << endl;
            return false;
        }
        else if (cohete->getAlaIzquierda() <= 0) {
            cout << "El cohete " << cohete->getNombre() << " perdió el ala izquierda y no pudo llegar a Neptuno." << endl;
            return false;
        }
        else if (cohete->getAlaDerecha() <= 0) {
            cout << "El cohete " << cohete->getNombre() << " perdió el ala derecha y no pudo llegar a Neptuno." << endl;
            return false;
        }
    }

    int ruta = rand() % Ruta_Aleatoria;
    cout << "El cohete " << cohete->getNombre() << " llegó con éxito a Neptuno a través de la ruta " << ruta << endl;
    return true;
}