#include <iostream>
using namespace std;

// Realizar un programa que desplace los caracteres de una palabra sobre sí misma N veces y luego la muestre por pantalla. Por ejemplo : si se ingresa “programación” 5, se debe mostrar “aciónprogram”.

int main(){
    string palabra, palabra_aux;
    int n, largo, indice;

    cout << "Ingresar una palabra: " << endl;
    cin >> palabra;

    cout << "Ingrese la cantidad de caracteres a desplazar: " << endl;
    cin >> n;

    largo = palabra.size();
    indice = largo - n;

    while (indice < largo){
        palabra_aux += palabra[indice];
        indice ++;
    }

    for(int i = 0; i < largo - n; i++){
        palabra_aux += palabra[i];
    }

    cout << "La palabra era: " << palabra << endl;
    cout << "Y ahora la palabra es: " << palabra_aux << endl;
}