#include <iostream>
#include <fstream>
using namespace std;

// Realizar un programa donde el usuario deberá ingresar 2 números para realizar una suma, se deberá escribir en un archivo la suma de la siguiente manera: num1 + num2 = suma. El programa no va a frenar hasta que ambos números ingresados sean 0.

int main() {
    ofstream archivo;
    int num1 = 1, num2 = 1;

    archivo.open("creado.txt", ios::out);
    if (archivo.is_open()) {
        cout << "Ingrese dos números para sumar. El programa terminará cuando ambos números sean 0." << endl;

        while (num1 != 0 && num2 != 0) {
            cout << "Ingrese el primer número: ";
            cin >> num1;
            cout << "Ingrese el segundo número: ";
            cin >> num2;

            int suma = num1 + num2;
            archivo << num1 << " + " << num2 << " = " << suma << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    archivo.close();
    cout << "Los resultados se han guardado en el archivo creado.txt" << endl;
}


