#ifndef COHETE_H
#define COHETE_H

#include <iostream>
#include <string>
using namespace std;

class Cohete {
public:
	Cohete(const string& nombre, int alaIzquierda, int alaDerecha, float gasolina);

	const string& getNombre() const;
	int getAlaIzquierda() const;
	int getAlaDerecha() const;
	float getGasolina() const;

private:
	string nombre;
	int alaIzquierda;
	int alaDerecha;
	float gasolina;
};

#endif




