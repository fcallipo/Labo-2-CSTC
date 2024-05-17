#include <iostream>
using namespace std;

int main(){
    int num, suma = 0;

    cout << "Ingrese un número entre 1 y 99 (incluyendo los extremos): "<<endl;
    cin >> num;

    for (int i = 1; i <= 99; i++)
    {
        if (num * i <= 99){
            suma += (num * i);
        }
    }
    

    // for(int i = 1; i <= 99; i++){
    //     if(i % num == 0){
    //         suma += i;
    //     }
    // }

    cout << "La suma es: " << suma << endl;
}