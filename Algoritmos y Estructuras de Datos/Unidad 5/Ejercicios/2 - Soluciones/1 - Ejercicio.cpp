#include <iostream>
using namespace std;

// Realizar un programa que le pida al usuario ingresar un número. La función tiene recibir, por referencia, el número ingresado y se deberá multiplicar por 2. En el main se mostrará el resultado obtenido.

void multiplicar_por_2(int &num){
    num *= 2;
}

int main(){
    int num;
    
    cout << "Ingrese un numero: " << endl;
    cin >> num;

    multiplicar_por_2(num);

    cout << "El resultado es: " << num << endl;
}