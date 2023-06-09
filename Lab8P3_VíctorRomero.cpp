#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Cohete.h"
#include "Marte.h"
#include "Saturno.h"
#include "Neptuno.h"
using namespace std;

// Leer el archivo
void crearCohetes(const string& archivo, vector<Cohete>& cohetes) {
	ifstream file(archivo);
	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo: " << archivo << endl;
		return;
	}

	string linea;
	while (getline(file, linea)) {
		string nombre;
		int alaIzquierda, alaDerecha;
		float gasolina;
		string lugar_destino;

		stringstream ss(linea);
		getline(ss, nombre, ',');
		ss >> alaIzquierda;
		ss.ignore();
		ss >> alaDerecha;
		ss.ignore();
		ss >> gasolina;
		ss.ignore();
		getline(ss, lugar_destino);

		Cohete cohete(nombre, alaIzquierda, alaDerecha, gasolina);
		cohetes.push_back(cohete);
	}

	file.close();
}

// Guardar la Bitacora (Ayudaaaaaaaaaaaaaaa)
void guardarBitacora(const vector<string>& bitacora, const string& archivo) {
	ofstream file(archivo);
	if (!file.is_open()) {
		cout << "No se pudo crear el archivo de la bitácora." << endl;
		return;
	}

	for (const string& mensaje : bitacora) {
		file << mensaje << endl;
	}

	file.close();

	cout << "Bitácora guardada correctamente." << endl;
}

// Eliminar Bitacora (Ya falta pocoooo)
void eliminarBitacora(const string& archivo) {
	if (remove(archivo.c_str()) != 0) {
		cout << "No se pudo eliminar la bitácora." << endl;
	}
	else {
		cout << "Bitácora eliminada correctamente." << endl;
	}
}

// Aparte por si las dudas... O como dice el inge POR SI LAS MOSCAS
void menu() {
	vector<Cohete> cohetes;
	vector<string> bitacora;

	int opcion = 0;
	string archivo = "bitacora.txt";

	while (opcion != 4) {
		cout << "----- Menú -----" << std::endl;
		cout << "1) Leer archivo" << std::endl;
		cout << "2) Guardar bitácora" << std::endl;
		cout << "3) Eliminar bitácora" << std::endl;
		cout << "4) Salir" << std::endl;
		cout << "Ingrese una opción: ";
		cin >> opcion;

		cout << "\n>La opcion ingresada es: " << opcion << endl << endl;

		switch (opcion) {
		case 1:
			crearCohetes("spaceZ.txt", cohetes);
			break;
		case 2:
			guardarBitacora(bitacora, archivo);
			cout << "Bitácora guardada correctamente." << std::endl;
			break;
		case 3:
			eliminarBitacora(archivo);
			break;
		case 4:
			cout << "Saliendo del programa..." << std::endl;
			break;
		default:
			cout << "Opción inválida. Intente nuevamente." << std::endl;
			break;
		}

		std::cout << std::endl;
	}
}

int main() {
	menu();
}
