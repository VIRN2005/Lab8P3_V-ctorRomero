#ifndef NEPTUNO_H
#define NEPTUNO_H

#include <iostream>
#include <string>
#include "Cohete.h"
#include <vector>
using namespace std;

class Neptuno {
public:
    static const float Gasolina_Requerida;
    static const vector<int> Rutas;
    static const float Probabilidad_Asteroides;
    static const int Dano_Asteroides;
    static const int Ruta_Aleatoria;

    static bool llegar(Cohete* cohete);
};

#endif 

