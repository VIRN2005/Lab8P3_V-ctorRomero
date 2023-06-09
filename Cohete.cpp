#include "Cohete.h"

Cohete::Cohete( string& nombre, int alaIzquierda, int alaDerecha, float gasolina)
	: nombre(nombre), alaIzquierda(alaIzquierda), alaDerecha(alaDerecha), gasolina(gasolina) {}


void Cohete::setAlaIzquierda(int resistencia) {
	alaIzquierda = resistencia;
}

void Cohete::setAlaDerecha(int resistencia) {
	alaDerecha = resistencia;
}


const string& Cohete::getNombre() {
	return nombre;
}

int Cohete::getAlaIzquierda() {
	return alaIzquierda;
}

int Cohete::getAlaDerecha() {
	return alaDerecha;
}

float Cohete::getGasolina()  {
	return gasolina;
}

void Cohete::setGasolina(float valor) {
	gasolina = valor;
}
