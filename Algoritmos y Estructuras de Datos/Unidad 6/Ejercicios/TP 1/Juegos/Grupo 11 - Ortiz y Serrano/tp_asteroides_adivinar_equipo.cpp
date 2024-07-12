/*
Este programa esta diseñado para linux, no funciona en todos
los sistemas operativos, en windows la inclusion de la libreria
conio.h nos facilitaba no tener que hacer las funciones getch() y kbhit() 
ya que venian endicha libreria pero investigando encontramos
como realizar las funciones en linux y unas librerias que si estaban 
disponibles en linux pero no en windows, por esto probablemente tire error 
al ejecutar este programa en windows por las librerias y sus respectivas funciones


*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

using namespace std;


//variables y funciones para el juego de adivinar
const int maximo=5;
 
 
string equipo;
string apodo; 
string campo_sin_rellenar[50];
string equipo_ingresado;
int cantidad_de_letras;
const int tamanio=28;
string lista_de_equipos[tamanio];
string lista_de_apodos[tamanio];
int num;
 
 
void apodo_aleatorio(int numero,string apodos[],string &apodo){
    apodo=apodos[numero];
}
void equipo_aleatorio(int numerito,string equipos[],string &equipo){
    equipo=equipos[numerito];
}
void cual_es_la_cantidad_de_letras(int &cantidad_de_letras,string equipitos[],int numeritito){
    cantidad_de_letras=equipitos[numeritito].size();
}


//hasta aca 

//variables y funciones para el juego de esquivar asteroidees

bool game_over = false;
int nave_x = 5, nave_y = 5;
int asteroide_x, asteroide_y;
int score = 0;
const int width = 12;
const int height = 7;
int frecuencia_asteroides=50;

int kbhit() {//funcion para poder usar kbhit en linux ya que no viene como en windows en la libreria conio.h que no esta disponible en linux 
    termios term;
    tcgetattr(0, &term);

    termios term_nuevo = term;
    term_nuevo.c_lflag &= ~ICANON;
    term_nuevo.c_cc[VMIN] = 0;
    term_nuevo.c_cc[VTIME] = 0;

    tcsetattr(0, TCSANOW, &term_nuevo);

    int bytesWaiting;
    ioctl(0, FIONREAD, &bytesWaiting);

    tcsetattr(0, TCSANOW, &term);

    return bytesWaiting;
}

char getch() {// sucede lo mismo que con el kbhit, es la funcion para la entrada de datos sin tocar el enter
    char buf = 0;
    struct termios term;
    tcgetattr(0, &term);

    struct termios term_nuevo = term;
    term_nuevo.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term_nuevo);

    read(0, &buf, 1);

    tcsetattr(0, TCSANOW, &term);
    return buf;
}

void mover_nave(int &nave_x, int &nave_y, int width, int height, bool &game_over) {//esta es la funcion para la entrada de datos del movimiento de la nave  
    if (kbhit()) {
        char tecla = getch();//la variable tecla almacena la tecla que se presiono, con el getch() no hace falta tocar enter 
        switch (tecla) {
            case 'a':
                if (nave_x > 0)
                
                    nave_x--;
                break;
            case 'd':
                if (nave_x < width - 1)
                    nave_x++;
                break;
            case 'w':
                if (nave_y > 0)
                    nave_y--;
                break;
            case 's':
                if (nave_y < height - 1)
                    nave_y++;
                break;
            case 'q':
                game_over = true;
                break;
        }
    }
}
void generar_asteroide(int &asteroide_y, int &asteroide_x, int height, int width) {//funcion para generar asteroides 

    if (asteroide_y >= height - 1) {
        asteroide_x = rand() % (width - 2) + 1;
        asteroide_y = 0;
    } else {
        asteroide_y++;
    }
    
    
    
    
}

void dibujar_campo(int &nave_x, int &nave_y, int &asteroide_y, int &asteroide_x, int width, int height, int &score) {
    //system("cls"); esto es para windows
    system("clear");//para linux
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout << "|";
            else if (i == nave_y && j == nave_x)
                cout << "V"; // Dibuja la nave
            else if (i == asteroide_y && j == asteroide_x)
                cout << "T"; // Dibuja el asteroide
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;

    cout << "Score: " << score << endl;
    }

void logica_juego(int &nave_x, int &nave_y, int &asteroide_y, int &asteroide_x, int width, int height, int &score) {
    // Verificar colisión
    
    if (nave_x == asteroide_x && nave_y == asteroide_y) {
        game_over = true;
    }
    if(asteroide_y== height-1){

        score++;
    }
   




}

//hasta aca variables y funciones para el juego de esquivar asteroides

int main() {
    int choice;
    string username;
    cout<<"ingrese un username"<<endl;    
    cin>>username;
    cout<<"bienvenido "<<username<<" espero que disfrutes el juego"<<endl;

    cout<<"para este programa diseñamos 2 juegos el primero trata sobre adivinar un equipo argentino sabiendo su apodo y el otro sobre esquivar asteroides que caen "<<endl;
    
    cout<<"eliga que juego desea jugar:ingrese 1 para jugar al juego de adivinar equipos y ingrese 2 para el juego de esquivar asteroides"<<endl;
    cin>>choice;
    if (choice==2){

        srand(time(NULL));//inicializamos 
        char start;
        cout<<"hola! "<<username<<" elegiste el juego de esquivar asteroides para mover la nave utiliza las teclas WASD si un asteroide te choca vas a perder"<<endl;

        cout<<"Aclaracion: no mantener las teclas de movimiento apretadas, apretar de a una para no saturar el programa "<<endl;
        cout << "Ingrese 'c' para comenzar el juego: ";
        cin >> start;
        int i=0;
     if (start == 'c') {

        asteroide_x = rand() % (width - 2) + 1;
        asteroide_y = 0;
        while (!game_over) {
            mover_nave(nave_x, nave_y, width, height, game_over);
            generar_asteroide(asteroide_y, asteroide_x, height, width);
            dibujar_campo(nave_x, nave_y, asteroide_y, asteroide_x, width, height, score);
            logica_juego(nave_x, nave_y, asteroide_y, asteroide_x, width, height, score);
            usleep(100000);
            i++;
        }

        cout <<"bien jugado "<<username<<" tu puntaje final es: "<<score << endl;
    }   else {
            cout << "una lastima, estaria bueno que lo probaras" << endl;
    }
        return 0;
}
    if (choice==1){
        //codigo
        srand(time(0));
        num = rand() % 28;
        lista_de_equipos[0]="defensa y justicia";
        lista_de_equipos[1]="atletico tucuman";
        lista_de_equipos[2]="huracan";
        lista_de_equipos[3]="union";
        lista_de_equipos[4]="river";
        lista_de_equipos[5]="boca";
        lista_de_equipos[6]="racing";
        lista_de_equipos[7]="independiente";
        lista_de_equipos[8]="san lorenzo";
        lista_de_equipos[9]="velez";
        lista_de_equipos[10]="riestra";
        lista_de_equipos[11]="independiente rivadavia";
        lista_de_equipos[12]="sarmiento";
        lista_de_equipos[13]="estudiantes";
        lista_de_equipos[14]="belgrano";
        lista_de_equipos[15]="talleres";
        lista_de_equipos[16]="tigre";
        lista_de_equipos[17]="lanus";
        lista_de_equipos[18]="newells";
        lista_de_equipos[19]="instituto";
        lista_de_equipos[20]="godoy cruz";
        lista_de_equipos[21]="rosario cental";
        lista_de_equipos[22]="argentinos juniors";
        lista_de_equipos[23]="central cordoba";
        lista_de_equipos[24]="gimnasia";
        lista_de_equipos[25]="barracas central";
        lista_de_equipos[26]="banfield";
        lista_de_equipos[27]="platense";
        lista_de_apodos[0]="halcon";
        lista_de_apodos[1]="decano";
        lista_de_apodos[2]="globo";
        lista_de_apodos[3]="tatengue";
        lista_de_apodos[4]="millonario";
        lista_de_apodos[5]="xeneizes";
        lista_de_apodos[6]="academia";
        lista_de_apodos[7]="rojo";
        lista_de_apodos[8]="cuervo";
        lista_de_apodos[9]="fortin";
        lista_de_apodos[10]="albinegro";
        lista_de_apodos[11]="lepra mendocina";
        lista_de_apodos[12]="guerrero";
        lista_de_apodos[13]="pincharrata";
        lista_de_apodos[14]="pirata";
        lista_de_apodos[15]="  T ";
        lista_de_apodos[16]="matador";
        lista_de_apodos[17]="granate";
        lista_de_apodos[18]="lepra";
        lista_de_apodos[19]="gloria";
        lista_de_apodos[20]="tomba";
        lista_de_apodos[21]="canalla";
        lista_de_apodos[22]="bicho";
        lista_de_apodos[23]="ferroviario";
        lista_de_apodos[24]="lobo";
        lista_de_apodos[25]="camionero";
        lista_de_apodos[26]="taladro";
        lista_de_apodos[27]="calamar";
 
        apodo_aleatorio(num,lista_de_apodos,apodo);
 
        equipo_aleatorio(num,lista_de_equipos,equipo);
        cual_es_la_cantidad_de_letras(cantidad_de_letras,lista_de_equipos,num);
        for (int i=0; i<cantidad_de_letras;i++){
            campo_sin_rellenar[i]="_";
        
        }
    
        cout<<"este es el apodo del equipo: "<<apodo<<endl;
        cout<<"IMPORTANTE:PARA EL NOMBRE DEL EQUIPO NO SE PUEDE INGRESAR NI MAYUSCULAS NI ARTICULOS"<<endl;
        cout<<"Tienes 6 intentos"<<endl;
        cout<<"ingrese el nombre del equipo: ";
        for(int i=0;i<cantidad_de_letras;i++){
            cout<<campo_sin_rellenar[i];
            
            }
        cin>>equipo_ingresado;
        for(int intent=0;intent<maximo;intent++){
            int restantes=maximo-intent;
            if(equipo_ingresado!=equipo){
                cout<<"incorrecto"<<endl;
                cout<<"intentos restantes: "<<restantes<<endl;
                cout<<"ingrese el nombre del equipo: ";
                for(int i=0;i<cantidad_de_letras;i++){
                    cout<<campo_sin_rellenar[i];
            
                }
                cin>>equipo_ingresado;
            if(intent==maximo-1){
                cout<<"perdiste, no eres un cruk. El equipo era: "<<equipo<<endl;
                break;
            }
 
        }
        if(equipo_ingresado==equipo){
            cout<<"felicidades, eres un cruck";
            break;
        } 
        
    }   




    }
}