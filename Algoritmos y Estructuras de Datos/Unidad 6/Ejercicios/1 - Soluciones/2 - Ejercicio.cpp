#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese 10 palabras. Se deberá invertir los elementos, del arreglo donde se almacenan, y mostrar por pantalla el nuevo orden de las palabras.

int main() {
    const int largo = 10;
    string palabras[largo];

    cout << "Ingrese 10 palabras:" << endl;
    for (int i = 0; i < largo; i++) {
        cout << "Palabra " << i + 1 << ": ";
        cin >> palabras[i];
    }

    cout << "El nuevo orden de las palabras es: " << endl;
    for (int i = largo - 1; i >= 0; i--) {
        if(i != 0){
            cout << palabras[i] << ", ";
        }
        else{
            cout << palabras[i] << ". " << endl;
        }
    }
}
