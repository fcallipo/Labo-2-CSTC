#include <iostream>
using namespace std;

// Realizar un programa ídem al anterior pero sin el número 5 en el rango.
int main() {
    float num;

    cout<<"Ingrese un número"<<endl;
    cin>>num;

    if (num>0 && num<10 && num != 5) {
        cout << "El número es: " << num << endl;
    }
    else {
        cout << "No esta dentro del rango." << endl; 
    }
}
