#include "Cohete.h"

Cohete::Cohete(const string& nombre, int alaIzquierda, int alaDerecha, float gasolina)
	: nombre(nombre), alaIzquierda(alaIzquierda), alaDerecha(alaDerecha), gasolina(gasolina) {}

const string& Cohete::getNombre() const {
	return nombre;
}

int Cohete::getAlaIzquierda() const {
	return alaIzquierda;
}

int Cohete::getAlaDerecha() const {
	return alaDerecha;
}

float Cohete::getGasolina() const {
	return gasolina;
}
