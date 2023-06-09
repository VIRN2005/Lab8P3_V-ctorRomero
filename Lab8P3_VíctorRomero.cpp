#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Cohete.h"
#include "Marte.h"
#include "Saturno.h"
#include "Neptuno.h"
using namespace std;

static vector<Cohete*> cohetesV;

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

		Cohete* cohete = new Cohete(nombre, alaIzquierda, alaDerecha, gasolina, lugar_destino);
		cohetesV.push_back(cohete);
	}

	file.close();
}

// Guardar la Bitacora (Ayudaaaaaaaaaaaaaaa)
void guardarBitacora(const string& archivo) {
	vector<string> bitacora;

	Marte marte;
	Saturno saturno;
	Neptuno neptuno;

	ofstream file(archivo);
	if (!file.is_open()) {
		cout << "No se pudo crear el archivo de la bitácora." << endl;
		return;
	}

	for (size_t i = 0; i < cohetesV.size(); i++) {
		string aux;
		if (cohetesV[i]->getLugarDestino() == "Marte") {
			aux = marte.llegar(cohetesV[i]);
			bitacora.push_back(aux);
		}
		else if (cohetesV[i]->getLugarDestino() == "Neptuno") {
			aux = neptuno.llegar(cohetesV[i]);
			bitacora.push_back(aux);
		}
		else if (cohetesV[i]->getLugarDestino() == "Saturno") {
			aux = saturno.llegar(cohetesV[i]);
			bitacora.push_back(aux);
		}
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
			guardarBitacora(archivo);
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

		cout << endl;
	}
	for (Cohete* cohete : cohetesV) {
		delete cohete;
	}
	cohetesV.clear();
}

int main() {
	menu();
}
