#include <iostream>
using namespace std;

// Realizar un programa que le pida al usuario ingresar una palabra y una letra. La función tiene recibir, por referencia, la palabra ingresada y recibir por valor la letra. Se le agregara la letra al final de la palabra, mostrando en el main la nueva palabra obtenida.

void unificar(string &palabra, char letra){
    palabra += letra;
}

int main(){
    string palabra;
    char letra;
    
    cout << "Ingrese una palabra y despues una letra: " << endl;
    cin >> palabra;
    cin >> letra;

    cout << "Palabra: " << palabra << endl;
    cout << "Letra: " << letra << endl;

    unificar(palabra, letra);
    cout << "Palabra final: " << palabra << endl;
}