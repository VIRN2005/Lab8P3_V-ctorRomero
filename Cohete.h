#ifndef COHETE_H
#define COHETE_H

#include <iostream>
#include <string>
using namespace std;

class Cohete {
public:
	Cohete(string& nombre, int alaIzquierda, int alaDerecha, float gasolina);

	const string& getNombre();
	int getAlaIzquierda();
	int getAlaDerecha();
	float getGasolina();
	void setAlaIzquierda(int);
	void setAlaDerecha(int);
	void setGasolina(float valor);

private:
	string nombre;
	int alaIzquierda;
	int alaDerecha;
	float gasolina;
};

#endif




