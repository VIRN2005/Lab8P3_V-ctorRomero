#include "Cohete.h"

Cohete::Cohete(const std::string& nombre, int alaIzquierda, int alaDerecha, float gasolina, const std::string& destino)
	: nombre(nombre), alaIzquierda(alaIzquierda), alaDerecha(alaDerecha), gasolina(gasolina), lugarDestino(destino) {}


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

string Cohete::getLugarDestino() const {
	return lugarDestino;
}
