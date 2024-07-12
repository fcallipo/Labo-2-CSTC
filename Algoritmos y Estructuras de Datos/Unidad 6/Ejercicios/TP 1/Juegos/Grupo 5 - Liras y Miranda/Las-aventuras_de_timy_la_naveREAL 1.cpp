#include <iostream>
#include <iomanip>
#include <unistd.h> 
#include <termios.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
using namespace std;

bool game_over = false;
int nave_x = 3, nave_y = 5;
int asteroide_x, asteroide_y;
int score = 0;
const int width = 54;
const int height = 13;

struct Asteroide {
    int x, y;
};

vector<Asteroide> asteroides;
// ======================Movimiento======================


void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

// ======================Mapa======================

void limites(){
    for (int i = 0; i < 55; i++)
    {
        gotoxy(i, 13); cout<< "─";

    for (int i = 0; i <= 13; i++) {
        gotoxy(0, i); cout << "│";
        gotoxy(56, i); cout << "│";
    }
    gotoxy(0, 13); cout<<"└";    // esquina inferior izquierda
    gotoxy(56, 13); cout <<"┘";  // esquina inferior derecha
    }
    
}

// ======================Dificultad======================

void elegirdificultad(int &dificultad){
    int RESniveles;
            cout <<"Elige tu nivel: " << endl;
            cout << "1. Fácil" <<endl;
            cout << "2. Medio" <<endl;
            cout << "3. Difícil"<<endl;
            while (RESniveles != 1 && RESniveles != 2 && RESniveles != 3)
            {
            cin >> RESniveles;
            switch (RESniveles)
            {
            case 1:
                dificultad = 5;
                break;
            case 2:
                dificultad = 100;
                break;
            case 3:
                dificultad = 500;
                break;
            default:
                cout << "Escribe uno de los numeros en pantalla" <<endl;
            }
            }
}

// ======================Skin======================

void elegirskin(string &skin){
int opcion;
            cout<<"=================================OPCIONES================================="<<endl<<endl;
            cout <<"Elige tu skin: "<<endl<<endl;
            cout <<"1. ↑"<<endl;
            cout <<"2. ⇈"<<endl;
            cout <<"3. ↥"<<endl;
            cout <<"4. ⇑"<<endl;
            cout <<"5. ⇡"<<endl;
            cout <<"6. ⬆"<<endl;
            cout <<"7. ⬿"<<endl;
            cout <<"8. ↟"<<endl;
            cout <<"9. &"<<endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                skin = "↑";
                break;
            case 2:
                skin = "⇈";
                break;
            case 3:
                skin = "↥";
                break;
            case 4:
                skin = "⇑";
                break;
            case 5:
                skin = "⇡";
                break;
            case 6:
                skin = "⬆";
                break;
            case 7:
                skin = "⬿";
                break;
            case 8:
                skin = "↟";
                break;
            case 9:
                skin = "&";
                break;
            
            default:
                skin = "↑";
                break;
            }
}

// ======================Borrar rastro nave======================

void borrar(int &x, int &y){
    gotoxy(x,y); cout <<" ";
}


// ======================Cod. para que ande en LINUX======================
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





// Función para dibujar el campo de juego
void dibujar_campo(string &skin, int &corazones) {
    system("clear");
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 54; j++) {
            if (i == nave_y && j == nave_x)
                cout << skin; // Dibuja la nave
            else {
                bool dibujado = false;
                for (int k = 0; k < asteroides.size(); k++) {
                    if (i == asteroides[k].y && j == asteroides[k].x) {
                        cout << "*"; // Dibuja el asteroide
                        dibujado = true;
                        break;
                    }
                }
                if (!dibujado) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    if(corazones < 1){
        return;
    }

    gotoxy(58, 1); cout<<"Vidas";
    gotoxy(62, 2); cout<<"      ";
    //  Imprime los corazones
    for (int i = 0; i < corazones; i++)
    {
        gotoxy(62+i, 2); cout<<"♥️";
    }
        gotoxy(62, 4); cout<<"Score: "<<score;

}
// Función para generar un nuevo asteroide
void generar_asteroide(int &dificultad) {
    if (asteroides.size() < dificultad) { // Puedes ajustar el número máximo de asteroides aquí
        Asteroide nuevo;
        nuevo.x = rand() % (width - 2) + 1;
        nuevo.y = 0;
        asteroides.push_back(nuevo);
    }
}
// Función para mover todos los asteroides
void mover_asteroides() {
    for (int i = 0; i < asteroides.size(); i++) {
        if (asteroides[i].y >= height - 1) {
            asteroides.erase(asteroides.begin() + i); // Eliminar asteroides que salieron del mapa
        } else {
            asteroides[i].y++;
        }
    }
}// Función para verificar colisiones
void logica_juego(int &corazones) {
    for (int i = 0; i < asteroides.size(); i++) {
        if (nave_x == asteroides[i].x && nave_y == asteroides[i].y) {
            corazones--;
            usleep(1000000);
            if (corazones == 0) {
                game_over = true;
            }
        }
    }
    // Aumentar puntuación cuando el asteroide llega al borde inferior
    for (int i = 0; i < asteroides.size(); i++) {
        if (asteroides[i].y == height - 1) {
            score++;
        }
    }
}



void mover_nave(int &corazones, int &nave_x, int &nave_y) {
    if (kbhit()) {
        char tecla = getch(); // Con la función getch() no hace falta tocar enter 
        switch (tecla) {
            case 'a':
                if (nave_x > 1)
                    nave_x--;
                break;
            case 'd':
                if (nave_x < width - 1)
                    nave_x++;
                break;
            case 'w':
                if (nave_y > 1)
                    nave_y--;
                break;
            case 's':
                if (nave_y < height - 1)
                    nave_y++;
                break;
            case 'e':
                corazones--;
                break;
            case 'k':
                game_over = true;
                break;
        }
    }
}

// ======================Explosion======================
void explosion(int x, int y){
        char nashe;
        borrar(x, y);
        gotoxy(x, y-1); cout<<"  *  ";
        gotoxy(x, y);   cout<<" *** ";
        gotoxy(x, y+1); cout<<"  *  ";
        cout.flush(); // Vacía el buffer de salida
        usleep(1000000);
        gotoxy(x, y-1); cout<<" *** ";
        gotoxy(x, y);   cout<<"*****";
        gotoxy(x, y+1); cout<<" *** ";
        cout.flush(); // Vacía el buffer de salida
        usleep(50000);
        cout<< "FIN";
        usleep(50000);
        cout<<"Tu puntaje fue: "<<score<<endl;
        cout<<"PRESIONAR K PARA VOLVER AL MENÚ"<<endl;

        while (true)
        {
            cin>>nashe;
            if (nashe == 'k')
            {
            return;
            }
        }
}
void velocidad_meteoritos(){
    if (score < 50){ 
            usleep(100000);
            }
            else if(score < 100){
            usleep(95000);
            }
            else if(score < 200)
            {
            usleep(90000);
            }
                else if (score < 300)
            {
            usleep(80000);
                    }else if (score < 400)
                {
                    usleep(65000);
                }
                else if (score < 500)
                {
                    usleep(50000);
                }
                else if (score < 650)
                {
                    usleep(40000);
                }    
                else if (score < 850)
                {
                    usleep(20000);
                }         
}




// ======================Main======================

void juego(string skin, int &dificulty) {
        // Codigo para que el movimiento sea fluido
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

        // Posicion inicial
    int i = 0;
    int corazones= 3;
    game_over = false;
    score = 0;
    while (!game_over) {
        mover_nave(corazones, nave_x, nave_y);
        generar_asteroide(dificulty);
        mover_asteroides();
        dibujar_campo(skin, corazones);
        limites();
        logica_juego(corazones);
        velocidad_meteoritos();  
        i++;
    }
    // Llamar a la función de explosión cuando el juego termine
    explosion(nave_x, nave_y);
}


// ======================Menu======================

void menu (int decision, string &skin, int &dificulty){
    cout<<endl;
    switch (decision){
        case 1:
                system("clear");
                juego(skin, dificulty);
            break;

        case 2:
                system("clear");
                elegirdificultad(dificulty);
            break;
        case 3:
                system("clear");
                elegirskin(skin);
            break;

        case 4:
            system("clear");
            cout<<"=================================CREDITOS================================="<<endl<<endl;
            cout <<"Los desarrolladores principales son Thiago Mirinda Liotto y Benjamin Liras Putarich"<<endl<<endl;
            cout <<"Agradecimientos Especiales: "<<endl<<"A nuestro profesor por su orientación y apoyo durante este año."<<endl<<"A nuestros amigos y compañeros por sus comentarios y sugerencias valiosas."<<endl<<"A nuestras familias por su inquebrantable apoyo y paciencia durante largas horas de desarrollo."<<endl;
            break;

        default: 
            cout << "Que tengas un hermoso dia :3" <<endl;
            break;
    
    }
    
}
int main(){
    system("clear");

    int respuesta;
    string skining = "O";
    int dificultad = 5;
    while (respuesta != 5)
    {
            cout << endl<< "=================================Aventuras De Timmy La Nave=================================" <<endl<<endl;
    
    cout << "1. JUGAR" << endl;
    cout << "2. NIVELES" << endl;
    cout << "3. OPCIONES" << endl;
    cout << "4. CREDITOS" << endl;
    cout << "5. SALIR" << endl;
    cin >> respuesta;
    menu(respuesta, skining, dificultad);
    }

}
