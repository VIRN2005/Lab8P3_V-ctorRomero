#include "Marte.h"
#include <iostream>

const float Marte::Gasolina_Requerida = 400000.0f; 
const float Marte::Probabilidad_Asteroides = 0.2f;
const int Marte::Dano_Asteroides = 40;

string Marte::llegar(Cohete* cohete) {
    if (cohete->getGasolina() < Gasolina_Requerida) {
        return "El cohete " + cohete->getNombre() + " se qued� sin gasolina y no pudo llegar a Marte.\n";
    }

    float probabilidad = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    if (probabilidad < Probabilidad_Asteroides) {
        cohete->setAlaIzquierda(cohete->getAlaIzquierda() - Dano_Asteroides);
        cohete->setAlaDerecha(cohete->getAlaDerecha() - Dano_Asteroides);

        if (cohete->getAlaIzquierda() <= 0 && cohete->getAlaDerecha() <= 0) {
            return "El cohete " + cohete->getNombre() + " perdi� ambas alas y no pudo llegar a Marte.";
        }
        else if (cohete->getAlaIzquierda() <= 0) {
            return "El cohete " + cohete->getNombre() + " perdi� el ala izquierda y no pudo llegar a Marte.";
        }
        else if (cohete->getAlaDerecha() <= 0) {
            return "El cohete " + cohete->getNombre() + " perdi� el ala derecha y no pudo llegar a Marte.";
        }
    }

    return "El cohete " + cohete->getNombre() + " lleg� con �xito a Marte.";
}

