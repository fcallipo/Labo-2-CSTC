#include <iostream>
#include <vector>
using namespace std;

// Realizar un programa donde el usuario ingrese varios números (la cantidad la define el usuario). Se deberá calcular si existe algún numero en el vector cuyo valor equivale a la suma del resto de números del vector. Mostrar por pantalla el número.

int encontrar_numero_suma_resto(vector<int> vector) {
    int sumaTotal = 0;
    for (int elemento : vector) {
        sumaTotal += elemento;
    }
    for (int num : vector) {
        if (num == sumaTotal - num) {
            return num;
        }
    }
    return -1;
}

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de números a ingresar: " <<endl;
    cin >> cantidad;
    
    vector<int> vector(cantidad);
    cout << "Ingrese los números: " << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> vector[i];
    }
    
    int numeroSumaResto = encontrar_numero_suma_resto(vector);
    if (numeroSumaResto != -1) {
        cout << "El número que equivale a la suma del resto de números es: " << numeroSumaResto << endl;
    } else {
        cout << "No hay ningún número que cumpla la condición." << endl;
    }
    
    return 0;
}
