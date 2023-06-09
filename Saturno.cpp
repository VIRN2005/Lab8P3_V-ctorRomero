#include "Saturno.h"
#include <iostream>

const float Saturno::Gasolina_Requerida = 700000.0f;
const int Saturno::Dano_Asteroides = 30;
const float Saturno::Probabilidad_Asteroides = 0.5f;


string Saturno::llegar(Cohete* cohete) {
    if (cohete->getGasolina() < Gasolina_Requerida) {
        return "El cohete " + cohete->getNombre() + " se quedó sin gasolina y no pudo llegar a Saturno.\n";
    }

    float probabilidad = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    if (probabilidad < Probabilidad_Asteroides) {
        cohete->setAlaIzquierda(cohete->getAlaIzquierda() - Dano_Asteroides);
        cohete->setAlaDerecha(cohete->getAlaDerecha() - Dano_Asteroides);

        if (cohete->getAlaIzquierda() <= 0 && cohete->getAlaDerecha() <= 0) {
            return "El cohete " + cohete->getNombre() + " perdió ambas alas y no pudo llegar a Saturno.";
        }
        else if (cohete->getAlaIzquierda() <= 0) {
            return "El cohete " + cohete->getNombre() + " perdió el ala izquierda y no pudo llegar a Saturno.";
        }
        else if (cohete->getAlaDerecha() <= 0) {
            return "El cohete " + cohete->getNombre() + " perdió el ala derecha y no pudo llegar a Saturno.";
        }
    }

    return "El cohete " + cohete->getNombre() + " llegó con éxito a Saturno.";
}
