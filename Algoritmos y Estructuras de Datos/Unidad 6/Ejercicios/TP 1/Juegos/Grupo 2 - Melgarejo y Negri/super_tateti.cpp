#include <iostream>
#include <string>
#include <limits>
#include "super_tateti.h"
using namespace std;

const int TAMANIO = 9;
//Creo matrices de cada tateti chiquito
    int tateti_1[TAMANIO];
    int tateti_2[TAMANIO];
    int tateti_3[TAMANIO];
    int tateti_4[TAMANIO];
    int tateti_5[TAMANIO];
    int tateti_6[TAMANIO];
    int tateti_7[TAMANIO];
    int tateti_8[TAMANIO];
    int tateti_9[TAMANIO];
//Creo al tateti grande
    int main_tateti[TAMANIO];
//Creo un registro de los movimientos
    int espacio_elegido;
    int tablero_elegido;

//Defino los colores
#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define PURPLE  "\033[35m"      /*Purple*/

//Funcion para pintar el tablero en el que se juega de amarillo
string tablero_jugando(int tateti){
    if(tateti==espacio_elegido){return YELLOW;}
    else{return GREEN;}
}

//Funcion para definir si tiene que ir una "X" o un "0"
string Xo0(int espacio, int tablero, int lugar){
    if(espacio==0){return " ";}
    else if(espacio==1 && tablero==tablero_elegido && lugar==espacio_elegido){return PURPLE + string(1 , 'X');}
    else if(espacio==2 && tablero==tablero_elegido && lugar==espacio_elegido){return PURPLE + string(1 , '0') + RESET;}
    else if(espacio==1){return RED + string(1 , 'X') + RESET;}
    else if(espacio==2){return BLUE + string(1 , '0') + RESET;}
    else if(espacio==3){return "E";}
}

//Funcion que imprime el tablero
void tablero(){
    string lineaHorizontal = "-------------";

    for (int n = 0; n < 3; ++n) {
        cout <<GREEN<< lineaHorizontal << " ";
    }
    cout<<tablero_jugando(1)<<"\n| "<<Xo0(tateti_1[0],1,1)<<tablero_jugando(1)<<" | "<<Xo0(tateti_1[1],1,2)<<tablero_jugando(1)<<" | "<<Xo0(tateti_1[2],1,3)<<tablero_jugando(1)<<" |"<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[0],2,1)<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[1],2,2)<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[2],2,3)<<tablero_jugando(2)<<" |"<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[0],3,1)<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[1],3,2)<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[2],3,3)<<tablero_jugando(3)<<" |";
    cout<<endl;
    cout<<tablero_jugando(1)<<"| "<<Xo0(tateti_1[3],1,4)<<tablero_jugando(1)<<" | "<<Xo0(tateti_1[4],1,5)<<tablero_jugando(1)<<" | "<<Xo0(tateti_1[5],1,6)<<tablero_jugando(1)<<" |"<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[3],2,4)<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[4],2,5)<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[5],2,6)<<tablero_jugando(2)<<" |"<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[3],3,4)<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[4],3,5)<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[5],3,6)<<tablero_jugando(3)<<" |";
    cout<<endl;
    cout<<tablero_jugando(1)<<"| "<<Xo0(tateti_1[6],1,7)<<tablero_jugando(1)<<" | "<<Xo0(tateti_1[7],1,8)<<tablero_jugando(1)<<" | "<<Xo0(tateti_1[8],1,9)<<tablero_jugando(1)<<" |"<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[6],2,7)<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[7],2,8)<<tablero_jugando(2)<<" | "<<Xo0(tateti_2[8],2,9)<<tablero_jugando(2)<<" |"<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[6],3,7)<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[7],3,8)<<tablero_jugando(3)<<" | "<<Xo0(tateti_3[8],3,9)<<tablero_jugando(3)<<" |";
    cout<<RESET<<endl;
    for (int n = 0; n < 3; ++n) {cout <<GREEN<< lineaHorizontal << " ";}
    cout<<tablero_jugando(4)<<"\n| "<<Xo0(tateti_4[0],4,1)<<tablero_jugando(4)<<" | "<<Xo0(tateti_4[1],4,2)<<tablero_jugando(4)<<" | "<<Xo0(tateti_4[2],4,3)<<tablero_jugando(4)<<" |"<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[0],5,1)<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[1],5,2)<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[2],5,3)<<tablero_jugando(5)<<" |"<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[0],6,1)<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[1],6,2)<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[2],6,3)<<tablero_jugando(6)<<" |";
    cout<<endl;
    cout<<tablero_jugando(4)<<"| "<<Xo0(tateti_4[3],4,4)<<tablero_jugando(4)<<" | "<<Xo0(tateti_4[4],4,5)<<tablero_jugando(4)<<" | "<<Xo0(tateti_4[5],4,6)<<tablero_jugando(4)<<" |"<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[3],5,4)<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[4],5,5)<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[5],5,6)<<tablero_jugando(5)<<" |"<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[3],6,4)<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[4],6,5)<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[5],6,6)<<tablero_jugando(6)<<" |";
    cout<<endl;
    cout<<tablero_jugando(4)<<"| "<<Xo0(tateti_4[6],4,7)<<tablero_jugando(4)<<" | "<<Xo0(tateti_4[7],4,8)<<tablero_jugando(4)<<" | "<<Xo0(tateti_4[8],4,9)<<tablero_jugando(4)<<" |"<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[6],5,7)<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[7],5,8)<<tablero_jugando(5)<<" | "<<Xo0(tateti_5[8],5,9)<<tablero_jugando(5)<<" |"<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[6],6,7)<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[7],6,8)<<tablero_jugando(6)<<" | "<<Xo0(tateti_6[8],6,9)<<tablero_jugando(6)<<" |";
    cout<<RESET<<endl;
    for (int n = 0; n < 3; ++n) {cout <<GREEN<< lineaHorizontal << " ";}
    cout<<tablero_jugando(7)<<"\n| "<<Xo0(tateti_7[0],7,1)<<tablero_jugando(7)<<" | "<<Xo0(tateti_7[1],7,2)<<tablero_jugando(7)<<" | "<<Xo0(tateti_7[2],7,3)<<tablero_jugando(7)<<" |"<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[0],8,1)<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[1],8,2)<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[2],8,3)<<tablero_jugando(8)<<" |"<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[0],9,1)<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[1],9,2)<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[2],9,3)<<tablero_jugando(9)<<" |";
    cout<<endl;
    cout<<tablero_jugando(7)<<"| "<<Xo0(tateti_7[3],7,4)<<tablero_jugando(7)<<" | "<<Xo0(tateti_7[4],7,5)<<tablero_jugando(7)<<" | "<<Xo0(tateti_7[5],7,6)<<tablero_jugando(7)<<" |"<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[3],8,4)<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[4],8,5)<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[5],8,6)<<tablero_jugando(8)<<" |"<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[3],9,4)<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[4],9,5)<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[5],9,6)<<tablero_jugando(9)<<" |";
    cout<<endl;
    cout<<tablero_jugando(7)<<"| "<<Xo0(tateti_7[6],7,7)<<tablero_jugando(7)<<" | "<<Xo0(tateti_7[7],7,8)<<tablero_jugando(7)<<" | "<<Xo0(tateti_7[8],7,9)<<tablero_jugando(7)<<" |"<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[6],8,7)<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[7],8,8)<<tablero_jugando(8)<<" | "<<Xo0(tateti_8[8],8,9)<<tablero_jugando(8)<<" |"<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[6],9,7)<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[7],9,8)<<tablero_jugando(9)<<" | "<<Xo0(tateti_9[8],9,9)<<tablero_jugando(9)<<" |";
    cout<<RESET<<endl;
    for (int n = 0; n < 3; ++n) {cout<<GREEN<< lineaHorizontal <<RESET<< " ";}
    cout<<"\n";
}

//Funcion que rellena un tablero completado con el simbolo del jugador correspondiente
void rellenar_tablero(int tateti[TAMANIO], int jugador){
    for(int i=0; i<9; i++){tateti[i]=jugador;}
}

string tab_habilitado(int tablero){
    if(main_tateti[tablero-1]!=0){return RED;}
    else{return GREEN;}
}

string lugar_habilitado(int lugar){
    switch (tablero_elegido){
        case 1:
            if(tateti_1[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 2:
            if(tateti_2[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 3:
            if(tateti_3[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 4:
            if(tateti_4[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 5:
            if(tateti_5[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 6:
            if(tateti_6[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 7:
            if(tateti_7[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 8:
            if(tateti_8[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        case 9:
            if(tateti_9[lugar-1]!=0){return RED;}
            else{return GREEN;}
            break;
        default:
            break;
    }
}

//Funcion que verifica si se completo el tateti grande
void verificar_main(int jugador){
    if((main_tateti[0]==jugador and main_tateti[1]==jugador and main_tateti[2]==jugador)||
        (main_tateti[0]==jugador and main_tateti[3]==jugador and main_tateti[6]==jugador)||
        (main_tateti[0]==jugador and main_tateti[4]==jugador and main_tateti[8]==jugador)||
        (main_tateti[1]==jugador and main_tateti[4]==jugador and main_tateti[7]==jugador)||
        (main_tateti[3]==jugador and main_tateti[4]==jugador and main_tateti[5]==jugador)||
        (main_tateti[6]==jugador and main_tateti[7]==jugador and main_tateti[8]==jugador)||
        (main_tateti[2]==jugador and main_tateti[5]==jugador and main_tateti[8]==jugador)||
        (main_tateti[2]==jugador and main_tateti[4]==jugador and main_tateti[6]==jugador))
        {
            cout<<"Gano el jugador "<<jugador<<" ("<<Xo0(jugador,0,0)<<") "<<endl;
            tablero();
            exit(0);
        }
    else if((main_tateti[0] and main_tateti[1] and main_tateti[2])and
            (main_tateti[3] and main_tateti[4] and main_tateti[5])and
            (main_tateti[6] and main_tateti[7] and main_tateti[8]))
            {
                cout<<"Empate"<<endl;
                exit(0);
            }
}

//Funcion que verifica si se completo un mini tateti
void verificar(int tateti[TAMANIO], int jugador, int tablero, int &restriccion){
    if((tateti[0]==jugador and tateti[1]==jugador and tateti[2]==jugador)||
        (tateti[0]==jugador and tateti[3]==jugador and tateti[6]==jugador)||
        (tateti[0]==jugador and tateti[4]==jugador and tateti[8]==jugador)||
        (tateti[1]==jugador and tateti[4]==jugador and tateti[7]==jugador)||
        (tateti[3]==jugador and tateti[4]==jugador and tateti[5]==jugador)||
        (tateti[6]==jugador and tateti[7]==jugador and tateti[8]==jugador)||
        (tateti[2]==jugador and tateti[5]==jugador and tateti[8]==jugador)||
        (tateti[2]==jugador and tateti[4]==jugador and tateti[6]==jugador))
        {
            cout<<"El tablero "<<tablero<<" lo ganó el jugador "<<jugador<<" ("<<Xo0(jugador,0,0)<<")"<<endl;
            main_tateti[tablero-1]=jugador;
            rellenar_tablero(tateti, jugador);
            verificar_main(jugador);
        }
    else if((tateti[0] and tateti[1] and tateti[2])and
            (tateti[3] and tateti[4] and tateti[5])and
            (tateti[6] and tateti[7] and tateti[8]))
            {
                cout<<RESET<<"El tablero "<<tablero<<" terminó en empate."<<endl;
                main_tateti[tablero-1]=3;
                rellenar_tablero(tateti, 3);
                verificar_main(jugador);
                
            }
}
    
//Funcion para poner una ficha
void poner_ficha(int &jugador, int &restriccion){
    if (restriccion==0){
        while(true){
            cout<<"Seleccione uno de los 9 TaTeTi \n "<<tab_habilitado(1)<<"1"<<RESET<<" |"<<tab_habilitado(2)<<" 2"<<RESET<<" | "<<tab_habilitado(3)<<"3"<<RESET<<"\n --------- \n "<<tab_habilitado(4)<<"4 "<<RESET<<"| "<<tab_habilitado(5)<<"5 "<<RESET<<"| "<<tab_habilitado(6)<<"6 "<<RESET<<"\n --------- \n "<<tab_habilitado(7)<<"7 "<<RESET<<"| "<<tab_habilitado(8)<<"8 "<<RESET<<"| "<<tab_habilitado(9)<<"9 "<<RESET<<endl;
            cin>>tablero_elegido;
            //Verifica si se manda una letra
            if(cin.fail()){
                cout << "Error: Ingrese un número válido." << endl;
                tablero();
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            }
            //Verifica si se manda un numero fuera de rango
            else if(tablero_elegido<1 || tablero_elegido>9){cout<<"Ingrese un valor dentro del rango"<<endl;}
            //Verifica si se manda un tablero completado
            else if(main_tateti[tablero_elegido-1]!=0){cout<<"Este tablero ya fue completado, seleccione otro."<<endl;}
                //Salgo del while
                else{break;}
        }
    }
    else{tablero_elegido=restriccion;}
    cout<<"Elija donde quiere poner su ficha en ese TaTeTi \n " <<lugar_habilitado(1)<<"1"<<RESET<<" |"<<lugar_habilitado(2)<<" 2"<<RESET<<" | "<<lugar_habilitado(3)<<"3"<<RESET<<"\n --------- \n "<<lugar_habilitado(4)<<"4 "<<RESET<<"| "<<lugar_habilitado(5)<<"5 "<<RESET<<"| "<<lugar_habilitado(6)<<"6 "<<RESET<<"\n --------- \n "<<lugar_habilitado(7)<<"7 "<<RESET<<"| "<<lugar_habilitado(8)<<"8 "<<RESET<<"| "<<lugar_habilitado(9)<<"9 "<<RESET<<endl;
    bool check_lugar=true;

    while(check_lugar){
        while(true){
            cin>>espacio_elegido;
            //Verifica si se manda una letra
            if(cin.fail()){
                cout << "\nError: Ingrese un número válido." << endl;
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            }
            //Verifica si se manda un numero fuera de rango
            else if(espacio_elegido<=0 or espacio_elegido>=10){cout<<"\nPor favor, elija un número del 1 al 9 \n " <<lugar_habilitado(1)<<"1"<<RESET<<" |"<<lugar_habilitado(2)<<" 2"<<RESET<<" | "<<lugar_habilitado(3)<<"3"<<RESET<<"\n --------- \n "<<lugar_habilitado(4)<<"4 "<<RESET<<"| "<<lugar_habilitado(5)<<"5 "<<RESET<<"| "<<lugar_habilitado(6)<<"6 "<<RESET<<"\n --------- \n "<<lugar_habilitado(7)<<"7 "<<RESET<<"| "<<lugar_habilitado(8)<<"8 "<<RESET<<"| "<<lugar_habilitado(9)<<"9 "<<RESET<<endl;}
            else{break;}
        }
        switch (tablero_elegido)
        {
            case 1:
                //Verifica si se uso este espacio
                if(tateti_1[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_1[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_1, jugador, tablero_elegido, restriccion);
                }
                break;
            case 2:
                //Verifica si se uso este espacio
                if(tateti_2[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_2[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_2, jugador, tablero_elegido, restriccion);
                }
                break;
            case 3:
                //Verifica si se uso este espacio
                if(tateti_3[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_3[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_3, jugador, tablero_elegido, restriccion);
                }
                break;
            case 4:
                //Verifica si se uso este espacio
                if(tateti_4[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_4[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_4, jugador, tablero_elegido, restriccion);
                }
                break;
            case 5:
                //Verifica si se uso este espacio
                if(tateti_5[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_5[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_5, jugador, tablero_elegido, restriccion);
                }
                break;
            case 6:
                //Verifica si se uso este espacio
                if(tateti_6[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_6[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_6, jugador, tablero_elegido, restriccion);
                }
                break;
            case 7:
                //Verifica si se uso este espacio
                if(tateti_7[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_7[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_7, jugador, tablero_elegido, restriccion);
                }
                break;
            case 8:
                //Verifica si se uso este espacio
                if(tateti_8[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_8[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_8, jugador, tablero_elegido, restriccion);
                }
                break;
            case 9:
                //Verifica si se uso este espacio
                if(tateti_9[espacio_elegido-1]!=0){cout<<"Ese espacio ya está ocupado. Ingrese otro espacio."<<endl;}
                else{
                tateti_9[espacio_elegido-1]=jugador;
                check_lugar=false;
                verificar(tateti_9, jugador, tablero_elegido, restriccion);
                }
                break;
            default:
                break;
        }
    }

    //Verifica si te tiene que dejar elegir un tablero o no
    if(main_tateti[espacio_elegido-1]!=0){restriccion=0;}
    else{restriccion=espacio_elegido;}
    //Cambia el jugador
    if (jugador==1){jugador=2;}
    else{jugador=1;}

    cout<<RESET<<"\nTurno del jugador "<<jugador<<" ("<<Xo0(jugador,0,0)<<")"<<endl;
    if (restriccion==0){
        cout<<"\nElija cualquier tablero\n";
    }
    else{
        cout<<"\nEstamos en el tablero "<<restriccion<<endl;
    }
}

int main_super_tateti_juego(){
    int restriccion=0;
    int jugador=1;
    while(true){
        tablero();
        poner_ficha(jugador, restriccion);
    }  
}


