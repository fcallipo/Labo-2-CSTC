#include <iostream>
using namespace std;

// Realizar un programa donde se le muestre al usuario cuanto falta para irse de la clase, sabiendo que la hora de salida es a las 12:05 hs. Se deberá crear una función que retorne el tiempo faltante.

string calcular(int hora_actual, int minutos_actuales){
    int hora_salida = 12, minuto_salida = 05, horas_restantes, minutos_restantes;
    
    if(minutos_actuales > minuto_salida){
        hora_salida -= 1;
        minuto_salida += 60;
    }

    horas_restantes = hora_salida - hora_actual;
    minutos_restantes = minuto_salida - minutos_actuales;

    return to_string(horas_restantes) + ":" + to_string(minutos_restantes);

    // cout << "Faltan: "<<horas_restantes << " horas y "<< minutos_restantes << " minutos para irnos." << endl;
}         
int main(){
    int hora_actual, minutos_actuales;
    
    cout << "Ingrese la hora y minutos actuales." << endl;
    cin >> hora_actual;
    cin >> minutos_actuales;

    
    cout << "Faltan: "<<calcular(hora_actual, minutos_actuales) << "hs para irnos." << endl;
}