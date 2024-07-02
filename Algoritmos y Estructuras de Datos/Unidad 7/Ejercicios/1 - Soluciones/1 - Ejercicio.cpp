#include <iostream>
#include <fstream>
using namespace std;

// Realizar un programa donde el usuario deberá ingresar 10 nombres a un archivo separados por coma (,).

int main() {
    ofstream archivo("nombres.txt");
    string nombre;

    archivo.open("nombres.txt", ios::out);
    if (archivo.is_open()) {
        for (int i = 0; i < 10; ++i) {
            cout << "Ingrese el nombre " << i + 1 << ": ";
            cin >> nombre;

            archivo << nombre;
            if (i < 9) {
                archivo << ",";
            }
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    archivo.close();
    cout << "Los nombres han sido guardados en 'nombres.txt'." << endl;
}
