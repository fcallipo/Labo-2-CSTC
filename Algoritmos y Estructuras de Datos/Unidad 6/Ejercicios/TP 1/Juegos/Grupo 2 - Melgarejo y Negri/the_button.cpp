#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <chrono>   
#include <thread>  
#include "the_button.h" 
using namespace std;

struct termios original_termios;

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"

void setup_terminal() {
    // Guardar la configuración original de la terminal
    tcgetattr(STDIN_FILENO, &original_termios);
    
    // Configurar nuevas opciones para la terminal
    struct termios newSettings;
    newSettings = original_termios;
    
    // Deshabilitar modo canónico y eco de caracteres
    newSettings.c_lflag &= ~(ICANON | ECHO);

    // Establecer el modo no canónico para la lectura
    newSettings.c_cc[VTIME] = 0;    // Tiempo de espera (decisegundos) antes de retornar
    newSettings.c_cc[VMIN] = 1;     // Número mínimo de caracteres para retornar desde read()

    // Aplicar las nuevas configuraciones a la terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

int main_boton() {
    int leaderboard1=0;
    int leaderboard2=0;
    int leaderboard3=0;
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1, 100);
    setup_terminal();
    int contador=0;
    while(true){
        char input;
        cin>>input;
        if(input=='o' or input=='i'){
            int a=dist(rng);
            if(a>=contador){
                system("clear");
                contador=contador+1;
                cout<<GREEN<<contador<<" veces presionado el botón con éxito"<<RESET<<endl;
                if(contador>leaderboard3){
                    if(contador>leaderboard2){
                        if(contador>leaderboard1){
                            leaderboard1=contador;
                        }
                        else{leaderboard2=contador;}
                    }
                    else{leaderboard3=contador;}
                }
            }
            else{
                system("clear");
                contador=0;
                cout<<RED<<":/"<<RESET<<endl;
                
            }
        }
        else if(input=='l'){
            system("clear");
            cout<<BLUE<<"Su top 1 ha sido "<<leaderboard1<<RESET<<endl;
            cout<<BLUE<<"Su top 2 ha sido "<<leaderboard2<<RESET<<endl;
            cout<<BLUE<<"Su top 3 ha sido "<<leaderboard3<<RESET<<endl;

        }
        else if(input=='e'){
            exit(0);
        }
    }
    // Restaurar la configuración original de la terminal antes de salir
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
    

}
