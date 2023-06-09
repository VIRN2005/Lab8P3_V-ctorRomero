#include "Marte.h"
#include <iostream>

const float Marte::Gasolina_Requerida = 400000.0f;

bool Marte::llegar(Cohete& cohete) {
	if (cohete.getGasolina() < Gasolina_Requerida) {
		cout << "El cohete " << cohete.getNombre() << " se quedó sin gasolina y no pudo llegar a Marte." << endl;
		return false;
	}

	cout << "El cohete " << cohete.getNombre() << " llegó con éxito a Marte." << endl;
	return true;
}
