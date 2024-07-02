#include <iostream>
#include <fstream>
using namespace std;

// Realizar un programa donde el usuario deberá ingresar un nombre y posteriormente se deberá buscar en el archivo anterior la existencia del mismo. Mostrar por pantalla la cantidad de veces que aparece ese nombre en el archivo.

int main() {
    ifstream archivo;
    int contador = 0;
    string archivo_leer, nombre;

    cout << "Ingrese el nombre del archivo que quiere leer: ";
    cin >> archivo_leer;
    cout << "Ingrese el nombre de una persona: ";
    cin >> nombre;

    archivo.open(archivo_leer, ios::in);
    if (archivo.is_open()) {
        string palabra;
        while (getline(archivo, palabra, ',')) {
            if (palabra == nombre) {
                contador++;
            }
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    archivo.close();

    if (contador > 0) {
        cout << "El nombre " << nombre << " aparece " << contador << " veces en el archivo." << endl;
    } else {
        cout << "El nombre " << nombre << " no se encuentra en el archivo." << endl;
    }
}

