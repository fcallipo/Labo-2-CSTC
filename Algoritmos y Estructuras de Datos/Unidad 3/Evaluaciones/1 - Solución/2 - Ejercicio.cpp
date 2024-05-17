#include <iostream>
using namespace std;

int main(){
    const int mes = 30;
    float monto_maximo, gasto_diario, gasto_total = 0;

    cout << "Ingresar el monto maximo: "<<endl;
    cin >> monto_maximo;

    for(int i = 0; i < mes; i++){
        cout << "Ingresar gasto del dia " << i+1 << " :" << endl;
        cin >> gasto_diario;

        gasto_total += gasto_diario;
    }

    cout << "El gasto total fue de: $" << gasto_total << endl;

    if(gasto_total <= monto_maximo){
        cout << "El gasto total fue menor al monto maximo, se ahorró: $" << monto_maximo - gasto_total << endl;
    }
    else{
        cout << "El gasto total fue mayor al monto maximo, se perdió: $" << gasto_total - monto_maximo << endl;
    }
}