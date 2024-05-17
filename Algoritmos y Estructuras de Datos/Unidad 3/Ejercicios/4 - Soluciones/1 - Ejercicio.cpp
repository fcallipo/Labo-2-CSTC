#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese dos palabras y que retorne si la ultima letra de ambas es igual o distinta.

int main() {
    string palabra1, palabra2;

    cout << "Ingrese 2 palabras" << endl;
    cin >> palabra1;
    cin >> palabra2;

    if(palabra1[palabra1.size()-1] == palabra2[palabra2.size()-1]){
        cout << "Ultimas 2 letras iguales." << endl;
    } 
    else{
        cout << "Ultimas 2 letras distintas." << endl;
    }
}