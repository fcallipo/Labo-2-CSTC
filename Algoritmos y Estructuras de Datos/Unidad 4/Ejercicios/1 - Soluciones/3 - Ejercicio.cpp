#include <iostream>
using namespace std;

// Realizar un programa que pida al usuario una cadena de palabras que contenga comas y muestre por pantalla cada palabra que esta entre comas. Ejemplo: Siendo el string: “hola,como,estas” se deberá mostrar por consola: hola como estas.

int main(){
    string oracion;

    cout << "Ingrese una cadena de palabras separadas por comas: " << endl;
    cin >> oracion;

    for(int i = 0; i < oracion.size(); i++){
        if(oracion[i]!=','){
            cout<<oracion[i];
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;

}