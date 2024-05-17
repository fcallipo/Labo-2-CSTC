#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese dos palabras y que retorne si la 1° palabra se encuentra dentro de la 2° palabra.

int main(){
    int contador = 0, contador_p1 = 1, contador_p2;
    bool esta = false, es_diferente = false;
    string p1, p2;

    cout << "Ingresar 2 palabras." << endl;
    cin >> p1;
    cin >> p2;
    
    while((contador < p2.length()) && !esta){

        if(p1[0] == p2[contador]){
            contador_p2 = contador;

            while(contador_p1 < p1.length() && !es_diferente){
                contador_p2 ++;
                if(p2[contador_p2] == p1[contador_p1]){
                    contador_p1 ++;
                }
                else{
                    es_diferente = true;
                }
            }

            if(contador_p1 == p1.length() && !es_diferente){
                esta = true;
            }
            else{
                es_diferente = false;
            }
        }

        contador ++;
    }
    
    cout << esta << endl;
}