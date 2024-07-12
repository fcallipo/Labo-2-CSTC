#include <iostream>
#include <termios.h>
#include <unistd.h>

#include <limits>
#include "the_button.h"
#include "super_tateti.h"
using namespace std;

#define RED "\033[31m"
#define RESET "\033[0m"

int menu_global(int seleccion){
    //Hace la selección del menu
    while (true){
        cout<<"Seleccione un juego \n 1-Super TaTeTi \n 2-The Button"<<endl;
        cin>>seleccion;
        //Verifica si se manda una letra
        if(cin.fail()){
            cout << "Error: Ingrese un número válido." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
        }
        else if (seleccion!=1 and seleccion!=2){cout<<"Elija una opcion correcta"<<endl;}
        else {break;}
    }
    return seleccion;
}

int main(){
    int seleccion=0;
    if(menu_global(seleccion)==1){
        cout<<"Turno del jugador 1 ("<<RED<<"X"<<RESET<<")"<<endl;
        main_super_tateti_juego();
    }
    else{
        cout<<"Bienvenido a The Button, aprete \"o\" o \"i\" para empezar a jugar"<<endl;
        main_boton();
    }
}