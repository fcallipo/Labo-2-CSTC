#include <iostream>
using namespace std;

// Realizar un programa para mostrar en pantalla el % de hombres y el % de mujeres que integran un grupo. La cantidad de hombres y mujeres son valores ingresados por el usuario.

int main() {
    float hombres, mujeres, total, porcentaje_hombres, porcentaje_mujeres;
    
    cout << "Ingrese cantidad de hombres" << endl;
    cin >> hombres;

    cout << "Ingrese cantidad de mujeres" << endl;
    cin >> mujeres;

    total = hombres + mujeres;

    porcentaje_hombres = (hombres*100/total);
    cout << "El porcentaje de hombres es: " << porcentaje_hombres << endl;

    porcentaje_mujeres = (mujeres*100/total);
    cout << "El porcentaje de mujeres es: " << porcentaje_mujeres << endl;
    

}
