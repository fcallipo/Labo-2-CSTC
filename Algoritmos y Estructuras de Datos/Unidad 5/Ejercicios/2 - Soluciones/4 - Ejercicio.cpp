#include <iostream>
using namespace std;

// Realizar un programa que le pida al usuario ingresar 2 números. La función tiene recibir, por referencia, el primer número ingresado y recibir por valor el segundo número. Se deberá calcular el primer número elevado por el segundo y en el main se mostrará el resultado obtenido.

void calcular_potencia(int &num1, int num2){
    int indice = 0;
    int num_aux = num1;
    while (indice < num2){
        num1 *= num_aux;
        indice ++;
    }
}

int main(){
    int num1, num2;
    
    cout << "Ingrese 2 números: " << endl;
    cin >> num1;
    cin >> num2;

    cout << num1 << " elevado a la " << num2 << " es: ";
    calcular_potencia(num1, num2);
    cout << num1 << endl;
}