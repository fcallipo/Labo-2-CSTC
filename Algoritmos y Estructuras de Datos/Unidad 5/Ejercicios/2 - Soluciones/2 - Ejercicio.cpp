#include <iostream>
using namespace std;

// Realizar un programa que le pida al usuario ingresar 2 números. La función tiene que recibir, por referencia, ambos números ingresados y se deberán intercambiar mutuamente. En el main se mostrará el cambio obtenido.

void intercambiar_numeros(int &num1, int &num2){
    int num_aux = num1;
    num1 = num2;
    num2 = num_aux;
}

int main(){
    int num1, num2;
    
    cout << "Ingrese 2 numeros: " << endl;
    cin >> num1;
    cin >> num2;

    cout << "Antes de intercambiar los números: " << num1 << ", " << num2 << endl;
    intercambiar_numeros(num1, num2);
    cout << "Despues de intercambiar los números: " << num1 << ", " << num2 << endl;
}