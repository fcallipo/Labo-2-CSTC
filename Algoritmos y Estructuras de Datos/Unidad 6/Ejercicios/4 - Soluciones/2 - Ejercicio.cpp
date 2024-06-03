#include <iostream>
#include <vector>
using namespace std;

// Realizar un programa donde el usuario defina un vector de enteros (el largo lo define el usuario). Se deberán ingresar los elementos en el vector y se deberá realizar una función que elimine los elementos duplicados. Mostrar por pantalla el vector sin elementos duplicados.

vector<int> limpiar_duplicados (vector <int> v){
    vector <int> sinduplicados;
    int cant_veces=0;

    for(int i=0; i<v.size(); i++){
        bool hayqueagregar=true;
        for (int j=0; j<sinduplicados.size(); j++){
            if(v[i]==sinduplicados[j]){
                hayqueagregar = false;
            }
        }
        if(hayqueagregar){
            sinduplicados.push_back(v[i]);
        }
    }
    return sinduplicados;
    
}

int main() {
    int n;
    cout << "Ingrese la longitud del vector: " <<endl;
    cin >> n;
    
    vector<int> vector(n);
    cout << "Ingrese los elementos del vector: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> vector[i];
    }
    
    vector = limpiar_duplicados(vector);
    
    cout << "Vector sin elementos duplicados: " << endl;
    for (int elemento : vector) {
        cout << elemento << " ";
    }
    cout << endl;
}
