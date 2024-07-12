#include <experimental/random>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//TA TE TI

char tablero[3][3];
 
void inicializarTablero() {
for (int i = 0; i < 3; ++i) {
for (int j = 0; j < 3; ++j) {
            tablero[i][j] = ' ';
        }
    }
}
 
void imprimirTablero() {
    cout << "-------------" << endl;
for (int i = 0; i < 3; ++i) {
        cout << "| ";
for (int j = 0; j < 3; ++j) {
            cout << tablero[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}
 
char verificarGanador() {
for (int i = 0; i < 3; ++i) {
if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') {
return tablero[i][0];
        }
if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') {
return tablero[0][i];
        }
    }
 
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') {
return tablero[0][0];
    }
if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ') {
return tablero[0][2];
    }
 
    bool hayEspacio = false;
for (int i = 0; i < 3; ++i) {
for (int j = 0; j < 3; ++j) {
if (tablero[i][j] == ' ') {
                hayEspacio = true;
break;
            }
        }
if (hayEspacio) break;
    }
if (!hayEspacio) {
return'E';
    }
 
    return' ';
}

int tictactoe(){
    char jugador = 'X';
int fila, columna;
char resultado;
 
    inicializarTablero();
 
    do {
imprimirTablero();
 
        if (jugador == 'X') {
            cout << "Turno del jugador X. Ingrese la fila (1-3) y la columna (1-3): ";
        } else {
            cout << "Turno del jugador O. Ingrese la fila (1-3) y la columna (1-3): ";
        }
        cin >> fila >> columna;
 
        fila--;
        columna--;
 
        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
            cout << "Jugada inválida. Inténtelo de nuevo." << endl;
            cin.clear();
            cin.ignore();
continue;
        }
 
        tablero[fila][columna] = jugador;
        resultado = verificarGanador();
 
        if (jugador == 'X') {
            jugador = 'O';
        } else {
            jugador = 'X';
        }
 
    } while (resultado == ' ');
 
    imprimirTablero();
if (resultado == 'E') {
        cout << "¡Hubo un empate!" << endl;
    } else {
        cout << "¡El jugador " << resultado << " ha ganado!" << endl;
    }
 
    return 0;
}

//FIN TATETI

//AHORCADO

int ahorcado(){

    string ahorcado[7] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |"
};
    int rand = std::experimental::randint(0, 9);
    string pal;
    int selec;
    char let;
    int correctas=0;
    int fin=0;
    int mal=0;
    int act=0;
    vector<char> carac;
    vector<string> adiv;
    vector<char> letmal;
    vector<string> palabrasP = {"programacion", "procesador", "desarrollador", "computadora", "tecnologia", "juego", "codigo", "lenguaje", "biblioteca", "software"};
    vector<string> palabrasH = {"revolucion", "imperio", "colonizacion", "renacimiento", "guerra", "independencia", "civilizacion", "monarquia", "dictadura", "democracia"};
    cout<<"Bienvenido a ahorcado"<<endl<<"Elegir Tema"<<endl<<"1- Prgramación"<<endl<<"2- Historia"<<endl<<"3- Cualquiera"<<endl;
    cin>>selec;
    if (selec==1)
    {
        pal=palabrasP[rand];
    } else if(selec==2){
        pal=palabrasH[rand];
    }else if(selec==3){
        int xd=std::experimental::randint(1, 2);
        if (xd==1){
            pal=palabrasP[rand];
        } else {
            pal=palabrasH[rand];
        }
    } else{
        cout<<"No existe esa opcion"<<endl;
        exit(0);
    }
    
    for (char c : pal) {
        carac.push_back(c);
        adiv.push_back("__");
    }
    cout<<ahorcado[6];
    for (int i=0; i<pal.length(); i++){
        cout<<" __ ";
    }
    cout<<endl;
    while (fin==0){
        cout<<"Ingrese letra ";
        cin>>let;
        for (int i=0; i<pal.length(); i++){
            if (carac[i]==tolower(let)){
                act++;
            }
        }
        if(act==0){
            mal++;
            letmal.push_back(tolower(let));
        }
        act=0;
        cout<<ahorcado[6-mal];
        for (int i=0; i<pal.length(); i++){
            if (carac[i]==tolower(let)){
                cout<<" "<<carac[i]<<" ";
                carac[i]=' ';
                adiv[i]=tolower(let);
                correctas++;
            } else {
                cout<<" "<<adiv[i]<<" ";
            }
        }
        cout<<"Intentos fallidos: "<<mal<<"/6"<<endl;
        cout<<"Letras equivocadas y/o repetidas: ";
        for (int i=0; i<letmal.size(); i++){
            cout<<" "<<letmal[i]<<" ";
        }
        cout<<endl;
        if (correctas==pal.length()){
            cout<<"Ganaste!!!!!"<<endl;
            fin=1;
        } else if (mal==6){
            cout<<"Perdiste, la palabra era "<<pal<<endl;
            fin=1;
        }
    }
}

//FIN AHORCADO

//PIEDRAPAPELTIJERA

int pipati(){

    const char* rps_ascii[3] = {
    "    _______       \n"
    "---'   ____)____  \n"
    "          ______) \n"
    "       __________)\n"
    "      (____)      \n"
    "---.__(___)       \n",

    "     _______      \n"
    "---'    ____)____ \n"
    "           ______)\n"
    "          _______)\n"
    "         _______) \n"
    "---.__________)   \n",

    "    _______       \n"
    "---'   ____)      \n"
    "      (_____)     \n"
    "      (_____)     \n"
    "      (____)      \n"
    "---.__(___)       \n"
};
    int opcionCOMPU;
    int opcionUSUARIO;
 
    cout<< "Elegi Piedra(1) Papel(2) o Tijera(3)"<<endl;
    cin>>opcionUSUARIO;
    opcionCOMPU=experimental::randint(1,3);
 
    switch(opcionCOMPU){
        case 1:
        cout<<"La compu eligio Piedra"<<endl;
        cout<<rps_ascii[2]<<endl;
        break;
        case 2:
        cout<<"La compu eligio Papel"<<endl;
        cout<<rps_ascii[1]<<endl;
        break;
        case 3:
        cout<<"La compu eligio Tijera"<<endl;
        cout<<rps_ascii[0]<<endl;
        break;
    }
    if(opcionCOMPU==opcionUSUARIO){
        cout<<"EMPATE"<<endl;
    }
    else if ((opcionCOMPU==1 && opcionUSUARIO==2) ||
            (opcionCOMPU==2 && opcionUSUARIO==3) ||
            (opcionCOMPU==3 && opcionUSUARIO==1)){
        cout<<"GANO EL USUARIO"<<endl;
    } else {
        cout << "GANO LA COMPU" << endl;
    }    
}

//FIN PIPATI

//MATCHING

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void printBoard(int board[], int revealed[]) {
    int SIZE = 8;
    for (int i = 0; i < SIZE; i++) {
        if (revealed[i] == 1) {
            printf("%d ", board[i]);
        } else {
            printf("* ");
        }
    }
    printf("\n");
}

int matching() {
    int SIZE = 8;
    int cards[] = {1, 1, 2, 2, 3, 3, 4, 4};
    int revealed[SIZE] = {0};

    srand(time(NULL));
    shuffle(cards, SIZE);

    int pairsFound = 0;

    while (pairsFound < SIZE / 2) {
        printBoard(cards, revealed);

        int first, second;
        printf("Selecciona la primera carta (1-8): ");
        scanf("%d", &first);
        printf("Selecciona la segunda carta (1-8): ");
        scanf("%d", &second);

        first -= 1;
        second -= 1;

        if (first < 0 || first >= SIZE || second < 0 || second >= SIZE || first == second || revealed[first] || revealed[second]) {
            printf("Selección no válida. Inténtalo de nuevo.\n");
            continue;
        }

        revealed[first] = 1;
        revealed[second] = 1;
        printBoard(cards, revealed);

        if (cards[first] == cards[second]) {
            printf("¡Pareja encontrada!\n");
            pairsFound++;
        } else {
            printf("No es una pareja. Inténtalo de nuevo.\n");
            revealed[first] = 0;
            revealed[second] = 0;
        }
    }

    printf("¡Felicidades! Has encontrado todas las parejas.\n");

    return 0;
}

//FIN MATCHING

//ADIVINA EL NUMERO

int adivnum(){

    int numero = std::experimental::randint(0, 1000);
    int terminado=0;
    int resp=0;
    int inten=0;
    while (terminado==0){
        cout<<"Ingrese número: ";
        cin>>resp;
        inten++;
        if(resp==numero){
            terminado++;
            cout<<"Ganaste!!!! Intentos: "<<inten<<endl;
        } else if (resp<numero){
            cout<<"La respuesta es mayor. Intento N: "<<inten<<endl;
        } else {
            cout<<"La respuesta es menor. Intento N: "<<inten<<endl;
        }
    }
}

int main()
{
    int selec=0;
    int aux=0;
    while(aux==0){
    cout<<"-------JUEGOS-------"<<endl;
    cout<<"| 1- TIC TAC TOE   |"<<endl;
    cout<<"| 2- AHORCADO      |"<<endl;
    cout<<"| 3- PIE PAP o TIJ |"<<endl;
    cout<<"| 4- PAREJAS       |"<<endl;
    cout<<"| 5- ADIVINA el NUM|"<<endl;
    cout<<"Juego: ";
    cin>>selec;
    switch (selec){
        case 1:
        tictactoe();
        aux++;
        break;
        case 2:
        ahorcado();
        aux++;
        break;
        case 3:
        pipati();
        aux++;
        break;
        case 4:
        matching();
        aux++;
        break;
        case 5:
        adivnum();
        aux++;
        break;
        default:
        cout<<"Opción no válida"<<endl;
    }
    }
}