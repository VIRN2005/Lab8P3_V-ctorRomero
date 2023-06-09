#ifndef SATURNO_H
#define SATURNO_H

#include <iostream>
#include <string>
#include "Cohete.h"
using namespace std;

class Saturno {
public:
    static const float Gasolina_Requerida;
    static const int Dano_Asteroides;
    static const float Probabilidad_Asteroides;
    static string llegar(Cohete* cohete);
};

#endif

