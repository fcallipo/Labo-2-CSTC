#include <iostream>
using namespace std;

// Realizar un programa que pida al usuario un número natural n y calcule la suma de todos los números naturales impares menores que n.

int main(){
    int num = 0, suma = 0;

    while (num <= 0){
        cout << "Ingrese un número natural: " << endl;
        cin >> num;
    }

    for(int i = 0; i <= num; i++){
        if (i % 2 != 0){
            suma += i;
        }
    }

    // for (int i = 1; i < num; i += 2) {
    //     suma += i;
    // }

    cout << "La suma de todos los numeros impares menores que " << num << " es: " << suma << endl;
    
}