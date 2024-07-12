#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

// Transforma letras a numeros al orden deseado

int LetraANumero(char letra) {
    int aux = 0;
    letra = tolower(letra);
    switch (letra)
    {
    case 'a':
        aux=0;
        break;
    case 'b':
        aux=1;
        break;
    case 'c':
        aux=2;
        break;
    case 'd':
        aux=3;
        break;
    case 'e':
        aux=4;
        break;
    case 'f':
        aux=5;
        break;
    case 'g':
        aux=6;
        break;
    case 'h':
        aux=7;
        break;
    case 'i':
        aux=8;
        break;
    case 'j':
        aux=9;
        break;
    default:
        break;
    }
    return aux;
}

// Transformacion de numeros char a numeros int sin cambiar su valor

int NumeroString(char num){
    int numero;
    numero=num;
    switch (numero)
    {
    case 48:
        numero=1;
        break;
    case 49:
        numero=2;
        break;
    case 50:
        numero=3;
        break;
    case 51:
        numero=4;
        break;
    case 52:
        numero=5;
        break;
    case 53:
        numero=6;
        break;
    case 54:
        numero=7;
        break;
    case 55:
        numero=8;
        break;
    case 56:
        numero=9;
        break;
    case 57:
        numero=10;
        break;
    default:
        break;
    }
    return numero;
}

// Muestra el mapa que se le carga

void MostrarMapa(int map[10][10]){
    cout<<"---------------------"<<endl;
    cout<<"   |Batalla Naval|"<<endl;
    for (int i=0; i<10; i++){
        cout<<"---------------------";
        cout<<endl;
        cout<<"|";
        for(int ii=0; ii<10; ii++){
            if(map[i][ii]==1){
                cout<<BLUE<<map[i][ii]<<RESET;
            }
            else if(map[i][ii]==2){
                cout<<RED<<map[i][ii]<<RESET;
            }
            else{
                cout<<YELLOW<<map[i][ii]<<RESET;
            }
            cout<<"|";
        }
        cout<<endl;
    }
    cout<<"---------------------";
    cout<<endl;
}

// Pone los barcos en el mapa con barcos 

void PonerBarcos(int map[10][10], int fila, int columna, int numero, bool vertical, bool &error){
    if(vertical){
        for(int i=fila; i<fila + numero; i++){
            if(map[i][columna]==2){
                map[i][columna]=3;
                error=true;
            }
            else{
                map[i][columna]=2;
            }
        }
    }
    else{
        for(int i=columna; i<columna + numero; i++){
            if(map[fila][i]==2){
                map[fila][i]=3;
                error=true;
            }
            else{
                map[fila][i]=1;
            }
        }
    }
    MostrarMapa(map);
}

// Transforma y separa las cordenadas dadas en string a int. Tambien comprueba que sus valores sean los adecuados.

void TransformacionCordenadas(string barco, bool &vertical, bool &error2, int &barcox, int &ValorLetra){
    char letra = barco[0];
    barcox = NumeroString(barco[1]);
    ValorLetra = LetraANumero(letra);
    if(isupper(letra)){
        vertical=true;
    }
    ValorLetra = LetraANumero(letra);
    if(ValorLetra>=0 && ValorLetra<=9 && barcox>=0 && barcox <=9){}
    else{
        cout<<"Error de datos, repitiendo creacion de barco"<<endl;
        error2=true;
    }
}

void CrearMapaBase(int map[10][10]){
    for(int i = 0; i < 10; ++i){ // Mapa que no mue.stra ni agua ni los barcos para jugar
        for(int j = 0; j < 10; ++j){
            map[i][j] = 1;
        }
    }
}

// Crea el mapa con barcos 

void CrearMapa(int map[10][10]){
    string barco5x1="", barco4x1="", barco3x1="", barco2x1="", barco20x1="";
    int barco55x1, barco44x1, barco33x1, barco22x1, barco21x1;
    int ValorLetra5, ValorLetra4, ValorLetra3, ValorLetra2, ValorLetra1;
    bool vertical5=false, vertical4=false, vertical3=false, vertical2=false, vertical1=false, error=false, error2=false;
    CrearMapaBase(map);
    MostrarMapa(map);

    while(true){
        while(true){
            cout<<"Donde vas a querer el barco 5x1"<<endl;
            cin>>barco5x1;
            TransformacionCordenadas(barco5x1, vertical5, error2, barco55x1, ValorLetra5);
            if(error2){
                cout<<"Error de datos, repitiendo creacion de barco"<<endl;
                error2=false;
            }
            else{
                    PonerBarcos(map, ValorLetra5, barco55x1 - 1, 5, vertical5, error);
                    break;
                    }
            }

        while(true){
            cout<<"Donde vas a querer el barco 4x1"<<endl;
            cin>>barco4x1;
            TransformacionCordenadas(barco4x1, vertical4, error2, barco44x1, ValorLetra4);
            if(error2){
                cout<<"Error de datos, repitiendo creacion de barco"<<endl;
                error2=false;
            }
            else{
                    PonerBarcos(map, ValorLetra4, barco44x1 - 1, 4, vertical4, error);
                    break;
            }
        }

        while(true){
            cout<<"Donde vas a querer el barco 3x1"<<endl;
            cin>>barco3x1;
            TransformacionCordenadas(barco3x1, vertical3, error2, barco33x1, ValorLetra3);
            if(error2){
                cout<<"Error de datos, repitiendo creacion de barco"<<endl;
                error2=false;
            }
            else{
                
                    PonerBarcos(map, ValorLetra3, barco33x1 - 1, 3, vertical3, error);
                    break;
            }
        }

        while(true){
            cout<<"Donde vas a querer el barco 2x1"<<endl;
            cin>>barco2x1;
            TransformacionCordenadas(barco2x1, vertical2, error2, barco22x1, ValorLetra2);
            if(error2){
                cout<<"Error de datos, repitiendo creacion de barco"<<endl;
                error2=false;
            }
            else{
                    PonerBarcos(map, ValorLetra2, barco22x1 - 1, 2, vertical2, error);
                break;
            }
        }

        while(true){
            cout<<"Donde vas a querer el otro barco 2x1"<<endl;
            cin>>barco4x1;
            TransformacionCordenadas(barco20x1, vertical1, error2, barco21x1, ValorLetra1);
            if(error2){
                cout<<"Error de datos, repitiendo creacion de barco"<<endl;
                error2=false;
            }
            else{
                    PonerBarcos(map, ValorLetra1, barco21x1 - 1, 2, vertical1, error);
                break;
            }
        }
        if(error){
            cout<<"Superposicion de barcos repitiendo creacion, (3 = donde se superpucieron)";
        }
        else{
            break;
        }
    }
}


// Crea el mapa con el cual se va a jugar poniendo cordenadas para adivinar donde estan los barcos

void CrearMapaJ(int map[10][10]){
    for(int i = 0; i < 10; ++i){ // Mapa que no muestra ni agua ni los barcos para jugar
        for(int j = 0; j < 10; ++j){
            map[i][j] = 0;
        }
    }
}

int main(){
    bool Atk=true;
    string PosAtk="";
    int PosAtk1, PosAtk2, CantAtk1 = 0, CantAtk2 = 0, Barcos1=16, Barcos2=16;
    vector <string> AtkT1;
    vector <string> AtkT2;
    int Mapa1[10][10]; //Un mapa para cada jugador para poner sus barcos y para jugar
    int Mapa2[10][10];
    int JuegoMapa1[10][10];
    int JuegoMapa2[10][10];
    char SiNo;
    while(true){
        cout<<"Quieres  la introduccion? si(1)/no(0) "<<endl;
        cin>>SiNo;
        if(SiNo=='0' || SiNo=='1'){
            break;
        }
        else{
            cout<<"Opcion desconocida"<<endl;
        }
    }
    if(SiNo=='1'){
        cout<<
        "Bueno les comento un poco de este batalla naval, va a ser un mapa 10x10 con 5 barcos, unos mas largos   que otros\n "
        "Para poner los barcos se van a tener que usar cordenadas, Letras=Filas, Numeros=Columnas\n "
        "Los barcos van a ser 5x1, 4x1, 3x1, 2x1, 2x1\n "
        "Se van a poder poner tanto de forma horizontal y vertical\n "
        "Despues de poner los barcos, va a arrancar el juego donde de a 1 van a escribir una combinacion de     letras (columnas) y numeros (filas). De la 'a' a la 'j' y del 0 al 9\n "
        "Cada vez que un jugador golpee un barco se le va a marcar en el mapa con un '2' y cada vez que toque   agua se va a marcar un '1', si hay algun error en la creacion de los barcos por superposicion se va a poner un '3'\n "
        <<endl;
    }
    cout<<"Jugador 1"<<endl;
    CrearMapa(Mapa1);
    cout<<"Jugador 2"<<endl;
    CrearMapa(Mapa2);
    CrearMapaJ(JuegoMapa1);
    CrearMapaJ(JuegoMapa2);
    MostrarMapa(JuegoMapa1);
    while(true){
        while(true){
            while(true){
                cout<<"Jugador 1, donde quiere atacar?"<<endl;
                cin>>PosAtk;
                for(int i=0; i<CantAtk1; i++){
                    if(PosAtk==AtkT1[i]){
                        Atk=false;
                    }                
                }
                if(Atk){
                    break;
                }
                else{
                    cout<<"Casilla ya atacada"<<endl;
                    Atk=true;
                }
            }
            AtkT1.push_back(PosAtk); // guarda mal la letra y el numero
            CantAtk1+=1;
            PosAtk1=LetraANumero(PosAtk[0]);
            PosAtk2=NumeroString(PosAtk[1]);
            if(PosAtk1>=0 && PosAtk1<=9 && PosAtk2>=0 && PosAtk2<=9){
                break;
            }
        }
        if(Mapa2[PosAtk1][PosAtk2]==2){
            JuegoMapa2[PosAtk1][PosAtk2]=2;
            Barcos2-=1;
            MostrarMapa(JuegoMapa2);
        }
        else{
            JuegoMapa2[PosAtk1][PosAtk2]=1;
            MostrarMapa(JuegoMapa2);
            while(true){
                while(true){
                    while(true){
                        cout<<"Jugador 2, donde quiere atacar?"<<endl;
                        cin>>PosAtk;
                        for(int i=0; i<CantAtk1; i++){
                            if(PosAtk==AtkT2[i]){
                            Atk=false;
                            }
                        }
                        if(Atk){
                            break;
                        }
                        else{
                            cout<<"Casilla ya atacada"<<endl;
                        }
                    }
                    AtkT2.push_back(PosAtk);
                    Atk=true;
                    CantAtk2+=1;
                    PosAtk1=LetraANumero(PosAtk[0]);
                    PosAtk2=NumeroString(PosAtk[1]);
                    if(PosAtk1>=0 && PosAtk1<=9 && PosAtk2>=0 && PosAtk2<=9){
                        break;
                    }
                }
                if(Mapa1[PosAtk1][PosAtk2]==2){
                    JuegoMapa1[PosAtk1][PosAtk2]=2;
                    Barcos1-=1;
                    MostrarMapa(JuegoMapa1);
                    if(Barcos1==0 or Barcos2==0){
                        break;
                    }
                }
                else{
                    JuegoMapa1[PosAtk1][PosAtk2]=1;
                    MostrarMapa(JuegoMapa1);
                    break;
                }
            }
        }
        if(Barcos1==0 or Barcos2==0){
            break;
        }
    }
    if(Barcos1==0){
        cout<<"Gana la partida el jugador 2" <<endl;
        MostrarMapa(Mapa1);
        MostrarMapa(Mapa2);
    }
    if(Barcos2==0){
        cout<<"Gana la partida el jugador 1" <<endl;
        MostrarMapa(Mapa1);
        MostrarMapa(Mapa2);
    }
}