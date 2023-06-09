#ifndef MARTE_H
#define MARTE_H

#include <iostream>
#include <string>
#include "Cohete.h"
using namespace std;

class Marte {
public:
    static const float Gasolina_Requerida;
    static const float Probabilidad_Asteroides;
    static const int Dano_Asteroides;
    static string llegar(Cohete* cohete);
};

#endif


