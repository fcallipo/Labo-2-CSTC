#include <iostream>
using namespace std;

// Realizar un programa donde se ingresen números que el usuario quiera sumar y cuando se escriba el número cero, se le mostrará la suma de todos los números ingresados.

int main(){
    int suma = 0, num;

    cout << "Ingrese los números que quiera sumar y cuando escriba 0 se retornara la suma." << endl;
    cin >> num;
    
    while(num != 0){
        suma += num;
        cin >> num;
    }

    cout << "La suma total es: " << suma << endl;
}