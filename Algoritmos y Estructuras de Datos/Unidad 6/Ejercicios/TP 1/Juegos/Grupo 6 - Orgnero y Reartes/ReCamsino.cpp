#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <ctime>
#include <random>
using namespace std;


struct termios original_termios;

void setup_terminal(){
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
}



const int map_x = 60;
const int map_y = 10;

string map[map_x][map_y];



// Espaciado
void clean() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

// Mas espaciado
void clear(){
    for(int i = 0; i < 100; i++){
        cout<<" "<<endl;
    }
}

// Numero random
int rand_range(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<> dis(min, max);

    int random = dis(gen);

    return random;
}


int numRandom(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(min, max);
    int numero_aleatorio = dis(gen);
    return numero_aleatorio;
}

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define GRAY    "\033[90m"      /* Gray */

//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK// Numero Random


//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK





// Barajas
const char baraja[4][13] ={
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, // Trebor    Negro
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, // Pica      Negro
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, // Corazon   Rojo
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}  // Rombo     Rojo
};

bool barajaUsada[4][13] ={
    {false, false, false, false, false, false, false, false, false, false, false, false, false}, // Trebor    Negro
    {false, false, false, false, false, false, false, false, false, false, false, false, false}, // Pica      Negro
    {false, false, false, false, false, false, false, false, false, false, false, false, false}, // Corazon   Rojo
    {false, false, false, false, false, false, false, false, false, false, false, false, false}  // Rombo     Rojo
};

void ascii(string palabra){
    if (palabra == "blackjack") {
        cout << endl;
        cout << BLUE << "black jack" << endl;
    } else if (palabra == "ganaste") {
        cout << endl;
        cout << GREEN << "   ____    _    _   _    _    ____ _____ _____ " << endl;
        cout << GREEN << "  / ___|  / \\  | \\ | |  / \\  / ___|_   _| ____|" << endl;
        cout << GREEN << " | |  _  / _ \\ |  \\| | / _ \\ \\___ \\ | | |  _|  " << endl;
        cout << GREEN << " | |_| |/ ___ \\| |\\  |/ ___ \\ ___) || | | |___ " << endl;
        cout << GREEN << "  \\____/_/   \\_\\_| \\_/_/   \\_\\____/ |_| |_____|" << endl;
    } else if (palabra == "perdiste") {
        cout << endl;
        cout << RED << "  ____  _____ ____  ____ ___ ____ _____ _____ " << endl;
        cout << RED << " |  _ \\| ____|  _ \\|  _ \\_ _/ ___|_   _| ____|" << endl;
        cout << RED << " | |_) |  _| | |_) | | | | |\\___ \\ | | |  _|  " << endl;
        cout << RED << " |  __/| |___|  _ <| |_| | | ___) || | | |___ " << endl;
        cout << RED << " |_|   |_____|_| \\_\\____/___|____/ |_| |_____|" << endl;
    } else if (palabra == "empate") {
        cout << endl;
        cout << YELLOW << "  _____ __  __ ____   _  _____ _____ " << endl;
        cout << YELLOW << " | ____|  \\/  |  _ \\ / \\|_   _| ____|" << endl;
        cout << YELLOW << " |  _| | |\\/| | |_) / _ \\ | | |  _|  " << endl;
        cout << YELLOW << " | |___| |  | |  __/ ___ \\| | | |___ " << endl;
        cout << YELLOW << " |_____|_|  |_|_| /_/   \\_\\_| |_____|" << endl;     
    }
}


// Cartas random
string repartirCarta(){
    int cartita, palo;

    // while(barajaUsada[palo][cartita]){
    //     cartita = numRandom(0, 12);
    //     palo = numRandom(0, 3);
    // }

    cartita = numRandom(0, 12);
    palo = numRandom(0, 3);

    barajaUsada[palo][cartita] = true;

    string palito;
    if(palo == 0){
        palito = "♣";
    } else if(palo == 1){
        palito = "♠";
    } else if(palo == 2){
        palito = "❤";
    } else if(palo == 3){
        palito = "◆";
    }
    return palito + baraja[palo][cartita];
}

void imprimir_cartas(vector<string> mano){
    string palos[4] = {"♣", "♠", "❤", "◆"};

    for(int ii = 0; ii < 5; ii++){
        for(int i = 0; i < mano.size(); i++){

            // Colores
            int palo = 0;
            int cualPalo;
            for(int ii = 0; ii < 4; ii++){
                for(int iii = 0; iii < 3; iii++){
                    if(mano[i][iii] == palos[ii][iii]) {
                        palo++;
                    }
                }
                if(palo == 3){
                    cualPalo = ii;
                    break;
                } else {
                    palo = 0;
                }
            }
            switch (cualPalo){
            case 0:
            case 1:
                // Imprimir
                switch (ii){
                case 0:
                    cout << RESET << ".----. " << RESET;
                    break;
                case 1:
                    cout << RESET << "|    | " << RESET;
                    break;
                case 2:
                    if(mano[i][3] == '0'){
                        cout << RESET << "| "<< mano[i][0] << mano[i][1] << mano[i][2] <<"10| " << RESET;
                    } else {
                        cout << RESET << "| "<< mano[i] <<" | " << RESET;
                    }
                    break;
                case 3:
                    cout << RESET << "|    | " << RESET;
                    break;
                case 4:
                    cout << RESET << "'----' " << RESET;
                    break;
                default:
                    break;
                }
                break;

            case 2:
            case 3:
                // Imprimir
                switch (ii){
                case 0:
                    cout << RED << ".----. " << RESET;
                    break;
                case 1:
                    cout << RED << "|    | " << RESET;
                    break;
                case 2:
                    if(mano[i][3] == '0'){
                        cout << RED << "| "<< mano[i][0] << mano[i][1] << mano[i][2] <<"10| " << RESET;
                    } else {
                        cout << RED << "| "<< mano[i] <<" | " << RESET;
                    }
                    break;
                case 3:
                    cout << RED << "|    | " << RESET;
                    break;
                case 4:
                    cout << RED << "'----' " << RESET;
                    break;
                default:
                    break;
                }
                break;
            }

        }
        cout<<endl;
    }
}

// Devuelve el valor de la carta ingresada
int valorCarta(string carta){
    int valor;
    switch (carta[3])
    {
    case '2':
        valor = 2;
        break;
    case '3':
        valor = 3;
        break;
    case '4':
        valor = 4;
        break;
    case '5':
        valor = 5;
        break;
    case '6':
        valor = 6;
        break;
    case '7':
        valor = 7;
        break;
    case '8':
        valor = 8;
        break;
    case '9':
        valor = 9;
        break;
    case '0':
    case 'J':
    case 'Q':
    case 'K':
        valor = 10;
        break;
    default:
        valor = 0;
        break;
    }
    return valor;
}

// Cuenta el valor de la mano
int contarCartas(vector<string> mano){
    int valor = 0;
    for(string carta:mano){
        valor += valorCarta(carta);
    }
    for(string carta:mano){
        if(carta[3] == 'A'){
            if(valor <= 10){
                valor += 11;
            } else {
                valor += 1;
            }
        }
    }
    return valor;
}

void dealer(vector<string> manoCasa, vector<string> manoJugador, int &resultado, int &apuesta, int &coin, bool &bucleMano){
    if(contarCartas(manoCasa) >= 17){
        clean();
        ascii("blackjack");

        cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
        imprimir_cartas(manoCasa);
        cout << endl;

        cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
        imprimir_cartas(manoJugador);
        cout << endl;

        cout << GREEN << "(P) PEDIR " << RED << "(Q) QUEDARSE " << YELLOW << "(D) DOBLAR" << RESET << endl;
        cout << "--> ";
        usleep(2000000);
    }

    if(contarCartas(manoJugador) > 21){
        clean();

        ascii("blackjack");

        cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
        imprimir_cartas(manoCasa);
        cout << endl;

        cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
        imprimir_cartas(manoJugador);
        cout << endl;

        cout << GREEN << "(P) PEDIR " << RED << "(Q) QUEDARSE " << YELLOW << "(D) DOBLAR" << RESET << endl;
        cout << "--> ";
        resultado = 2;
        bucleMano = false;
        usleep(2000000);

    } else {

        usleep(2000000);
        while (contarCartas(manoCasa) < 17){
            manoCasa.push_back(repartirCarta());
            clean();

            ascii("blackjack");

            cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
            imprimir_cartas(manoCasa);
            cout << endl;

            cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
            imprimir_cartas(manoJugador);
            cout << endl;

            cout << GREEN << "(P) PEDIR " << RED << "(Q) QUEDARSE " << YELLOW << "(D) DOBLAR" << RESET << endl;
            cout << "--> ";
            usleep(2000000);
        }

        usleep(1000000);
        if(contarCartas(manoCasa) > 21){
            resultado = 1;
            coin += apuesta*2;
            bucleMano = false;
        } else if(contarCartas(manoJugador) > 21){
            resultado = 2;
            bucleMano = false;
        } else {
            if(contarCartas(manoCasa) > contarCartas(manoJugador)){
                resultado = 2;
                bucleMano = false;
            } else if (contarCartas(manoCasa) == contarCartas(manoJugador)) {
                resultado = 3;
                coin += apuesta;
                bucleMano = false;
            } else {
                resultado = 1;
                coin += apuesta*2;
                bucleMano = false;
            }
        }

    }

    
}

void rondas(int &coin){

    int apuesta = 0;

    vector<string> manoJugador;
    vector<string> manoCasa;

    // Apuestas
    while (true){
        clean();
        cout << BLUE << "Valor a apostar --> " << RESET;
        cin >> apuesta;
        if (apuesta > coin){
            cout << RED << "FONDOS INSUFICIENTES!" << RESET << endl;
            usleep(3000000);
        } else if(apuesta > 0) {
            coin -= apuesta;
            break;
        } else {
            cout << RED << "INGRESE UN NUMERO VALIDO!" << RESET << endl;
            usleep(3000000);
        }
    }
    clean();
    
    // Contador de cartas
    int valorJugador = 0;
    int valorCasa = 0;

    // Animacion inicio
    manoCasa.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    usleep(600000);
    clean();
    manoCasa.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    usleep(600000);
    clean();
    manoJugador.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
    imprimir_cartas(manoJugador);
    usleep(600000);
    clean();
    manoJugador.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
    imprimir_cartas(manoJugador);
    usleep(600000);
    clean();

    // Un bucle
    char opcion;
    int resultado = 0;
    bool bucleMano = true;

    if(contarCartas(manoCasa) == 21){
        if(contarCartas(manoJugador) == 21){
            bucleMano = false;
            resultado = 3;
            usleep(1300000);
        }
        bucleMano = false;
        resultado = 1;
        usleep(1300000);
    }

    if(contarCartas(manoJugador) == 21){
        bucleMano = false;
        resultado = 1;
        usleep(1300000);
    }

    // Partidas
    while (bucleMano){
        clean();

        ascii("blackjack");

        cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
        imprimir_cartas(manoCasa);
        cout << endl;

        cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
        imprimir_cartas(manoJugador);
        cout << endl;

        cout << GREEN << "(P) PEDIR " << RED << "(Q) QUEDARSE " << YELLOW << "(D) DOBLAR" << RESET << endl;
        cout << "--> ";
        cin >> opcion;

        switch (opcion)
        {
        case 'p':
        case 'P':
            manoJugador.push_back(repartirCarta());
            if(contarCartas(manoJugador) > 21){
                clean();

                ascii("blackjack");

                cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
                imprimir_cartas(manoCasa);
                cout << endl;

                cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
                imprimir_cartas(manoJugador);
                cout << endl;

                cout << GREEN << "(P) PEDIR " << RED << "(Q) QUEDARSE " << YELLOW << "(D) DOBLAR" << RESET << endl;
                cout << "--> ";

                bucleMano = false;
                resultado = 2;
                usleep(1300000);
            }
            break;

        case 'q':
        case 'Q':
            dealer(manoCasa, manoJugador, resultado, apuesta, coin, bucleMano);
            break;

        case 'd':
        case 'D':
            clean();
            manoJugador.push_back(repartirCarta());
            dealer(manoCasa, manoJugador, resultado, apuesta, coin, bucleMano);
            break;

        default:
            break;
        }
    }


    // RESULTADO
    if(resultado == 1){
        ascii("ganaste");
        cout << GREEN << "GANASTE --> $" << apuesta*2 << endl;
        usleep(5000000);
    } else if (resultado == 2) {
        ascii("perdiste");
        usleep(5000000);
    } else if (resultado == 3) {
        ascii("empate");
        cout << GRAY << "TE DEVOLVIERON --> $" << apuesta << endl;
        usleep(5000000);
    } else {
        clean();
        int asd;
        cout << "ERROR INESPERADO!" << endl;
        cin >> asd;
    }


}

// El juego
void juego(int &coin){
    // Juego
    int respuesta;
    int bucle = true;
    while (bucle){
        clean();
        ascii("blackjack");
        cout <<"  .-------------------------------------------------------."<< endl;
        cout <<"  |                                                       |"<< endl;
        cout <<"  |         OPCIONES - TOCAR UN NUM Y LUEGO ENTER.        |"<< endl;
        cout <<"  |                                                       |"<< endl;
        cout <<"  |                      1 - Jugar                        |"<< endl;
         cout <<" |                      2 - Salir                        |"<< endl;
         cout <<" |                                                       |)" << endl;
        cout << "          |                     saldo: "<< coin <<"                       |" << endl;
        cout << "          '-------------------------------------------------------'" << endl;
        cout << "--> ";
        cin >> respuesta;
        if(respuesta == 1){
            rondas(coin);
        } else if (respuesta == 2) {
            bucle = false;
        } else {
            cout << RED << "Elija una de las siguientes opciones!" << RESET << endl;
            usleep(2000000);
        }

    }

}



//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA
//RULETA


#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <string>
#include <random>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

// Instalar en ubuntu o reemplazarla
// #include <conio.h>


// Mapeado
int mapp(int valor, int fromLow, int fromHigh, int toLow, int toHigh) {
    if (valor < fromLow)
        valor = fromLow;
    else if (valor > fromHigh)
        valor = fromHigh;

    float porcentaje = (float)(valor - fromLow) / (float)(fromHigh - fromLow);

    int calculo = toLow + (porcentaje * (toHigh - toLow));

    return calculo;
}

//
//
//
//  _  _________   __  ____  ____  _____ ____ ____  
// | |/ / ____\ \ / / |  _ \|  _ \| ____/ ___/ ___| 
// | ' /|  _|  \ V /  | |_) | |_) |  _| \___ \___ \ 
// | . \| |___  | |   |  __/|  _ <| |___ ___) |__) |
// |_|\_\_____| |_|   |_|   |_| \_\_____|____/____/ 
//
//
//
//
                                                


enum Key {
    UP_ARROW = 0,
    DOWN_ARROW,
    RIGHT_ARROW,
    LEFT_ARROW,
    OTHER_KEY
};

char keyPress(){
    char c;
    while (true) {
        cin.get(c);
        if (c == 27) {
            char arrow1, arrow2;
            cin.get(arrow1);
            cin.get(arrow2);
            if (arrow1 == '[') {
                switch (arrow2) {
                    case 'A':
                        return UP_ARROW;
                    case 'B':
                        return DOWN_ARROW;
                    case 'C':
                        return RIGHT_ARROW;
                    case 'D':
                        return LEFT_ARROW;
                }
            }
        } else {
            return c;
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////    ____ ___  ____ ___ ____  ___     //////////////////////////
//////////////////////////   / ___/ _ \|  _ \_ _/ ___|/ _ \    //////////////////////////
//////////////////////////  | |  | | | | | | | | |  _| | | |   //////////////////////////
//////////////////////////  | |__| |_| | |_| | | |_| | |_| |   /////////////////s/////////
//////////////////////////   \____\___/|____/___\____|\___/    //////////////////////////
//////////////////////////                                     //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


void animacion(const string &text) {
    for (char caracter : text) {
        cout << caracter;
        usleep(5000);
    }
    usleep(10000);
}


//
//
//
//  __     _______ ____       _    ____  _   _ _____ ____ _____  _    ____  
//  \ \   / / ____|  _ \     / \  |  _ \| | | | ____/ ___|_   _|/ \  / ___| 
//   \ \ / /|  _| | |_) |   / _ \ | |_) | | | |  _| \___ \ | | / _ \ \___ \ 
//    \ V / | |___|  _ <   / ___ \|  __/| |_| | |___ ___) || |/ ___ \ ___) |
//     \_/  |_____|_| \_\ /_/   \_\_|    \___/|_____|____/ |_/_/   \_\____/                                                                                                 
//
//
//
//

void apuestasVer(int apuestas[], int valores){
    // Imprimir las apuestas realizadas
    cout << "ruleta" << endl;
    cout << endl << "Apuestas: " << endl;
    string opciones[14] = {
        "Par",
        "Impar",
        "Rojo",
        "Negro",
        "1 a 18",
        "19 a 36",
        "1ra Docena",
        "2nda Docena",
        "3era Docena",
        "1 Linea",
        "2 Linea",
        "3 Linea",
        "Multiples numeros",
        "Numero unico"
    };

    cout << endl;
    for (int i = 0; i < 14; i++) {
        if (apuestas[i] > 0) {
            cout << opciones[i] << ": " << apuestas[i] << " monedas" << endl;
        }
    }
    cout << "----------------------" << endl;
    cout << endl;
}

//
//
//
//   _____  _    ____  _     _____ ____   ___  
//  |_   _|/ \  | __ )| |   | ____|  _ \ / _ \ 
//    | | / _ \ |  _ \| |   |  _| | |_) | | | |
//    | |/ ___ \| |_) | |___| |___|  _ <| |_| |
//    |_/_/   \_\____/|_____|_____|_| \_\\___/                             
//
//
//
//

void ruletaVer() {
    // Limpia la consola e imprime el tablero
    clean();
    cout << "Ruleta" << endl;
    cout << endl;
    cout << " _________________________________________________________________________" << endl;
    cout << " |    |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
    cout << " |    | "<<RED<<"3"<<RESET<<" | 6 | "<<RED<<"9"<<RESET<<" | "<<RED<<"12"<<RESET<<" | 15 | "<<RED<<"18"<<RESET<<" | "<<RED<<"21"<<RESET<<" | 24 | "<<RED<<"27"<<RESET<<" | "<<RED<<"30"<<RESET<<" | 33 | "<<RED<<"36"<<RESET<<" | 3 LINEA |" << endl;
    cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
    cout << "|     |---+---+---+----+----+----+----+----+----+----+----+----+---------+" << endl;
    cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
    cout << "|  "<<GREEN<<"0"<<RESET<<"  | 2 | "<<RED<<"5"<<RESET<<" | 8 | 11 | "<<RED<<"14"<<RESET<<" | 17 | 20 | "<<RED<<"23"<<RESET<<" | 26 | 29 | "<<RED<<"32"<<RESET<<" | 35 | 2 LINEA |" << endl;
    cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
    cout << "|     |---+---+---+----+----+----+----+----+----+----+----+----+---------+" << endl;
    cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
    cout << " |    | "<<RED<<"1"<<RESET<<" | 4 | "<<RED<<"7"<<RESET<<" | 10 | 13 | "<<RED<<"16"<<RESET<<" | "<<RED<<"19"<<RESET<<" | 22 | "<<RED<<"25"<<RESET<<" | 28 | 31 | "<<RED<<"34"<<RESET<<" | 1 LINEA |" << endl;
    cout << " |____|___|___|___|____|____|____|____|____|____|____|____|____|_________|" << endl;
    cout << "      |                |                   |                   |" << endl;
    cout << "      |   1ra Docena   |    2nda Docena    |    3era Docena    |" << endl;
    cout << "      |                |                   |                   |" << endl;
    cout << "      +----------------+-------------------+-------------------+" << endl;
    cout << "      |       |        |         |         |         |         |" << endl;
    cout << "      |1 a 18 |  Par   |  Rojo   |  Negro  |  Impar  | 19 a 36 |" << endl;
    cout << "      |       |        |         |         |         |         |" << endl;
    cout << "      +-------+--------+---------+---------+---------+---------+" << endl;
    cout << "" << endl;
}

void tablero(int opciones){
    switch (opciones) {
        case 0:
            cout << " _________________________________________________________________________" << endl;
            break;
        case 1:
            cout << " |    |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 2:
            cout << " |    | " << RED << "3" << RESET << " | 6 | " << RED << "9" << RESET << " | " << RED << "12" << RESET << " | 15 | " << RED << "18" << RESET << " | " << RED << "21" << RESET << " | 24 | " << RED << "27" << RESET << " | " << RED << "30" << RESET << " | 33 | " << RED << "36" << RESET << " | 3 LINEA |" << endl;
            break;
        case 3:
            cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 4:
            cout << "|     |---+---+---+----+----+----+----+----+----+----+----+----+---------+" << endl;
            break;
        case 5:
            cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 6:
            cout << "|  " << GREEN << "0" << RESET << "  | 2 | " << RED << "5" << RESET << " | 8 | 11 | " << RED << "14" << RESET << " | 17 | 20 | " << RED << "23" << RESET << " | 26 | 29 | " << RED << "32" << RESET << " | 35 | 2 LINEA |" << endl;
            break;
        case 7:
            cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 8:
            cout << "|     |---+---+---+----+----+----+----+----+----+----+----+----+---------+" << endl;
            break;
        case 9:
            cout << " |    |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 10:
            cout << " |    | " << RED << "1" << RESET << " | 4 | " << RED << "7" << RESET << " | 10 | 13 | " << RED << "16" << RESET << " | " << RED << "19" << RESET << " | 22 | " << RED << "25" << RESET << " | 28 | 31 | " << RED << "34" << RESET << " | 1 LINEA |" << endl;
            break;
        case 11:
            cout << " |____|___|___|___|____|____|____|____|____|____|____|____|____|_________|" << endl;
            break;
        case 12:
            cout << "      |                |                   |                   |" << endl;
            break;
        case 13:
            cout << "      |   1ra Docena   |    2nda Docena    |    3era Docena    |" << endl;
            break;
        case 14:
            cout << "      |                |                   |                   |" << endl;
            break;
        case 15:
            cout << "      +----------------+-------------------+-------------------+" << endl;
            break;
        case 16:
            cout << "      |       |        |         |         |         |         |" << endl;
            break;
        case 17:
            cout << "      |1 a 18 |  Par   |  Rojo   |  Negro  |  Impar  | 19 a 36 |" << endl;
            break;
        case 18:
            cout << "      |       |        |         |         |         |         |" << endl;
            break;
        case 19:
            cout << "      +-------+--------+---------+---------+---------+---------+" << endl;
            break;
        default:
            break;
    }
}



//
//
//
//   ____  _   _ _     _____ _____  _    
//  |  _ \| | | | |   | ____|_   _|/ \   
//  | |_) | | | | |   |  _|   | | / _ \  
//  |  _ <| |_| | |___| |___  | |/ ___ \ 
//  |_| \_\\___/|_____|_____| |_/_/   \_\                              
//
//
//
//

int girar() {
    // // Generacion de numeros random
    // srand((unsigned)time(0));
    // int num;
    // int min = 74; // Establece el mínimo
    // int max = 370; // Establece el máximo
    // num = (rand() % (max - min + 1)) + min;

    int num = numRandom(74, 148);

    int i = -1;
    int ii = 0;
    int iii = 1;
    int contador = 0;
    bool colorI;
    bool colorII;
    bool colorIII;
    while (num > 0) {
        int rojitos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
        int negritos[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
        colorI = false;
        colorII = false;
        colorIII = false;
        clean();
        num--;
        i++;
        ii++;
        iii++;
        contador++;
        for(int value:rojitos){
            if(i == value){
                colorI = true;
            }
            if(ii == value){
                colorII = true;
            }
            if(iii == value){
                colorIII = true;
            }
        }
        // Imprimir ruleta
        if (ii == 36) {
            i = 35;
            ii = 36;
            iii = 0;
        } else if (ii == 37){
            i = 36;
            ii = 0;
            iii = 1;
        } else if (ii == 1){
            i = 0;
            ii = 1;
            iii = 2;
        }
        if (i < 10) {
            
            cout << "Ruleta" << endl;
            cout << "             ____________" << endl;
            cout << "        ____|            |____" << endl;
            cout << "       |    |            |    |" << endl;
            // si es rojo true, si es negro false
            if(colorI == true){
                cout << "       |  " << RED << i << RESET ;
            } else {
                cout << "       |  " << RESET << i;
            }
            if(colorII == true){
                cout << " |      " << RED << ii << RESET;
            } else {
                cout << " |      " << ii << RESET;
            }
            if(colorIII == true){
                cout << "     |  " << RED << iii << RESET << " |" << endl;
            } else {
                cout << "     |  " << iii << RESET << " |" << endl;
            }
            cout << "       |____|            |____|" << endl;
            cout << "            |____________|" << endl;
            cout << endl;
            cout << endl;
        } else {
            cout << "ruleta" << endl;
            cout << "             ____________" << endl;
            cout << "        ____|            |____" << endl;
            cout << "       |    |            |    |" << endl;
            // si es rojo true, si es negro false
            if(colorI == true){
                cout << "       | " << RED << i << RESET ;
            } else {
                cout << "       | " << RESET << i;
            }
            if(colorII == true){
                cout << " |     " << RED << ii << RESET;
            } else {
                cout << " |     " << ii << RESET;
            }
            if(colorIII == true){
                cout << "     | " << RED << iii << RESET << " |"<< endl;
            } else {
                cout << "     | " << iii << RESET << " |" << endl;
            }
            
            
            cout << "       |____|            |____|" << endl;
            cout << "            |____________|" << endl;
            cout << endl;
            cout << endl;
        }

        // Darle efecto a la ruleta que se va reelentizando
        if (num > 150) {
            usleep(30000);
        } else if (num > 70) {
            usleep(70000);
        } else if (num > 30) {
            usleep(100000);
        } else if (num > 15) {
            usleep(200000);
        } else if (num > 10) {
            usleep(250000);
        } else if (num > 4) {
            usleep(500000);
        } else if (num > 2) {
            usleep(600000);
        } else if (num > 1) {
            usleep(700000);
        }
        // int dormir = map(contador, 0, num, 0, 400000);
        // usleep(dormir);
    }
    ruletaVer();
    if (i < 10) {
        cout << "             ____________" << endl;
        cout << "        ____|            |____" << endl;
        cout << "       |    |            |    |" << endl;
        // si es rojo true, si es negro false
        if(colorI == true){
            cout << "       |  " << RED << i << RESET ;
        } else {
            cout << "       |  " << RESET << i;
        }
        if(colorII == true){
            cout << " |      " << RED << ii << RESET;
        } else {
            cout << " |      " << ii << RESET;
        }
        if(colorIII == true){
            cout << "     |  " << RED << iii << RESET << " |" << endl;
        } else {
            cout << "     |  " << iii << RESET << " |" << endl;
        }
        cout << "       |____|            |____|" << endl;
        cout << "            |____________|" << endl;
        cout << endl;
        cout << endl;
    } else {
        cout << "             ____________" << endl;
        cout << "        ____|            |____" << endl;
        cout << "       |    |            |    |" << endl;
        // si es rojo true, si es negro false
        if(colorI == true){
            cout << "       | " << RED << i << RESET ;
        } else {
            cout << "       | " << RESET << i;
        }
        if(colorII == true){
            cout << " |     " << RED << ii << RESET;
        } else {
            cout << " |     " << ii << RESET;
        }
        if(colorIII == true){
            cout << "     | " << RED << iii << RESET << " |"<< endl;
        } else {
            cout << "     | " << iii << RESET << " |" << endl;
        }
        
        
        cout << "       |____|            |____|" << endl;
        cout << "            |____________|" << endl;
        cout << endl;
        cout << endl;
    }
    return ii;
}

//
//
//
//   __  __ _____ _   _ _   _ 
//  |  \/  | ____| \ | | | | |
//  | |\/| |  _| |  \| | | | |
//  | |  | | |___| |\  | |_| |
//  |_|  |_|_____|_| \_|\___/ 
//
//
//
//

void menu(int op) {
    // Menu de apuestas
    // int menu1o2 = 1;
    // string opciones[17];
    cout << "OPCIONES (W,S(up down) y E(intro)): ------------------------------------------------------------------------------------------" << endl;
    // if(menu1o2 == 1){
    //     opciones[0] ="(x2) Par";
    //     opciones[1] = "(x2) Impar";
    //     opciones[2] = "(x2) Rojo";
    //     opciones[3] = "(x2) Negro";
    //     opciones[4] = "(x2) 1 a 18";
    //     opciones[5] = "(x2) 19 a 36";
    //     opciones[6] = "(x3) 1ra Docena";
    //     opciones[7] = "(x3) 2nda Docena";
    //     opciones[8] = "(x3) 3era Docena";
    //     opciones[9] = "(x3) 1 Linea";
    //     opciones[10] = "(x3) 2 Linea";
    //     opciones[11] = "(x3) 3 Linea" ;
    //     opciones[12] = "(x6, x9, x18) Multiples numero (A la vez)" ;
    //     opciones[13] = "(x36) Numero unico" ;
    //     opciones[14] = "GIRAR LA RULETA" ;
    //     opciones[15] = "REINICIAR APUESTAS" ;
    //     opciones[16] = "VOLVER" ;
    // } else {
        
    // }
    string opciones[17] = {
        "(x2) Par                                         ",
        "(x2) Impar                                       ",
        "(x2) Rojo                                        ",
        "(x2) Negro                                       ",
        "(x2) 1 a 18                                      ",
        "(x2) 19 a 36                                     ",
        "(x3) 1ra Docena                                  ",
        "(x3) 2nda Docena                                 ",
        "(x3) 3era Docena                                 ",
        "(x3) 1 Linea                                     ",
        "(x3) 2 Linea                                     ",
        "(x3) 3 Linea                                     ",
        "(x6, x9, x18) Multiples numero (A la vez)        ",
        "(x36) Numero unico                               ",
        "GIRAR LA RULETA                                  ",
        "REINICIAR APUESTAS                               ",
        "VOLVER                                           "
    };

    // Marcador de opciones
    for(int i = 0; i < 2; i++) {
        for(int ii = 0; ii < 54; ii++){
            cout << " ";
        }
        tablero(i);
    }
    for (int i = 0; i < 17; i++) {
        if (i == op) {
            cout << RED << " --> " << opciones[i] << RESET;
            tablero(i+2);
        } else {
            cout << "     " << opciones[i];
            tablero(i+2);
        }
    }
    for(int i = 17; i < 18; i++) {
        for(int ii = 0; ii < 54; ii++){
            cout << " ";
        }
        tablero(i+2);
    }
}

//
//
//
//       _ _   _ _____ ____  ___  
//      | | | | | ____/ ___|/ _ \ 
//   _  | | | | |  _|| |  _| | | |
//  | |_| | |_| | |__| |_| | |_| |
//   \___/ \___/|_____\____|\___/ 
//
//
//
//
                             
void jugabilidad(int &coin) {
    string texto = "ruleta";

    animacion(texto);
    cout << endl;
    int monto;
    int numGanador;
    int apuestaIndividualNumero;
    int apuestaMultiplesNumeros[37] = {0}; // Almacena las apuestas a números específicos
    // Vector que almacena apuestas sin modificar
    int apuestas[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // Array que almacena las ganancias ganadoras
    int ganancias[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // Multiplicacion en el caso de que gane
    int multiplicacion[14] = {2,2,2,2,2,2,3,3,3,3,3,3,6,36};
    // Tecla apretada
    int tecla;
    // Opcion a seleccionar
    int op = 0;
    // Tecla sin importancia
    int atecla;
    // Monto a devolver en caso de reiniciar las apuestas
    int montoDevolver = 0;

    bool bucle = true;
    while (bucle) {
        // ruletaVer();
        clean();
        apuestasVer(apuestas, 14);
        cout << "Saldo: " << coin << endl;
        cout << endl;
        string texto = "ruleta";
        menu(op);

        // Si hay alguna tecla presionada, que diga cual es
        tecla = keyPress();
        switch (tecla) {
            case 'w': // Flecha arriba
                op = (op - 1 + 17) % 17; // Evitar valores negativos
                break;
            case 's': // Flecha abajo
                op = (op + 1) % 17;
                break;
            case 'e': // Enter
                if (op == 16) {
                    //
                    //
                    //
                    //   ____    _    _     ___ ____    ____  _____ _           _ _   _ _____ ____  ___  
                    //  / ___|  / \  | |   |_ _|  _ \  |  _ \| ____| |         | | | | | ____/ ___|/ _ \ 
                    //  \___ \ / _ \ | |    | || |_) | | | | |  _| | |      _  | | | | |  _|| |  _| | | |
                    //   ___) / ___ \| |___ | ||  _ <  | |_| | |___| |___  | |_| | |_| | |__| |_| | |_| |
                    //  |____/_/   \_\_____|___|_| \_\ |____/|_____|_____|  \___/ \___/|_____\____|\___/                                                               
                    //
                    //
                    //
                    //
                    bucle = false;
                } else if (op == 15) {
                    //
                    //
                    //
                    //   ____  _____ ___ _   _ ___ ____ ___    _    ____       _    ____  _   _ _____ ____ _____  _    ____  
                    //  |  _ \| ____|_ _| \ | |_ _/ ___|_ _|  / \  |  _ \     / \  |  _ \| | | | ____/ ___|_   _|/ \  / ___| 
                    //  | |_) |  _|  | ||  \| || | |    | |  / _ \ | |_) |   / _ \ | |_) | | | |  _| \___ \ | | / _ \ \___ \ 
                    //  |  _ <| |___ | || |\  || | |___ | | / ___ \|  _ <   / ___ \|  __/| |_| | |___ ___) || |/ ___ \ ___) |
                    //  |_| \_\_____|___|_| \_|___\____|___/_/   \_\_| \_\ /_/   \_\_|    \___/|_____|____/ |_/_/   \_\____/                                                                                                                                                            
                    //
                    //
                    //
                    //
                    for(int i = 0; i < 14; i++){
                        apuestas[i] = 0;
                        ganancias[i] = 0;
                    }
                    for(int i = 0; i < 37; i++){
                        apuestaMultiplesNumeros[i] = 0;
                    }
                    coin += montoDevolver;
                    montoDevolver = 0;
                } else if (op == 14) {
                    //
                    //
                    //
                    //    ____ ___ ____      _    ____    _        _      ____  _   _ _     _____ _____  _    
                    //   / ___|_ _|  _ \    / \  |  _ \  | |      / \    |  _ \| | | | |   | ____|_   _|/ \   
                    //  | |  _ | || |_) |  / _ \ | |_) | | |     / _ \   | |_) | | | | |   |  _|   | | / _ \  
                    //  | |_| || ||  _ <  / ___ \|  _ <  | |___ / ___ \  |  _ <| |_| | |___| |___  | |/ ___ \ 
                    //   \____|___|_| \_\/_/   \_\_| \_\ |_____/_/   \_\ |_| \_\\___/|_____|_____| |_/_/   \_\                                                                                                                                            
                    //
                    //
                    //
                    //
                    montoDevolver = 0;
                    // Girar la ruleta
                    numGanador = girar();
                    // Plata a ganar
                    cout << "Numero ganador: " << numGanador << endl;
                    int gananciasTotales = 0;

                    int rojitos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
                    int negritos[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

                    // Evaluar las apuestas
                    for (int i = 0; i < 14; i++) {
                        // Revisar todas las apuestas
                        if (ganancias[i] > 0) {
                            bool gano = false;
                            switch (i) {
                                case 0: // Par
                                    gano = (numGanador % 2 == 0);
                                    break;
                                case 1: // Impar
                                    gano = (numGanador % 2 != 0);
                                    break;
                                case 2: // Rojo
                                    for(int valores:rojitos){
                                        if(numGanador == valores){
                                            gano = (numGanador == valores);
                                            break;
                                        }
                                    }
                                    break;
                                case 3: // Negro
                                    for(int valores:negritos){
                                        if(numGanador == valores){
                                            gano = (numGanador == valores);
                                            break;
                                        }
                                    }
                                    break;
                                case 4: // 1 a 18
                                    gano = (numGanador >= 1 && numGanador <= 18);
                                    break;
                                case 5: // 19 a 36
                                    gano = (numGanador >= 19 && numGanador <= 36);
                                    break;
                                case 6: // 1ra Docena
                                    gano = (numGanador >= 1 && numGanador <= 12);
                                    break;
                                case 7: // 2nda Docena
                                    gano = (numGanador >= 13 && numGanador <= 24);
                                    break;
                                case 8: // 3era Docena
                                    gano = (numGanador >= 25 && numGanador <= 36);
                                    break;
                                case 9: // 1 Linea
                                    gano = (numGanador % 3 == 1);
                                    break;
                                case 10: // 2 Linea
                                    gano = (numGanador % 3 == 2);
                                    break;
                                case 11: // 3 Linea
                                    gano = (numGanador % 3 == 0);
                                    break;
                            }
                            if (gano) {
                                gananciasTotales += ganancias[i];
                            }
                        }
                    }

                    // Revisar apuesta a número único
                    if (apuestaMultiplesNumeros[numGanador] > 0) {
                        gananciasTotales += apuestaMultiplesNumeros[numGanador];
                    }
                    cout << "Saldo anterior: " << coin << endl;
                    coin += gananciasTotales;
                    cout << "Ganancias totales: " << gananciasTotales << endl;
                    cout << "Saldo actualizado: " << coin << endl;
                    cout << "Presiona cualquier tecla para continuar...";
                    tecla = keyPress();

                    for(int i = 0; i < 14; i++){
                        apuestas[i] = 0;
                        ganancias[i] = 0;
                    }
                    for(int i = 0; i < 37; i++){
                        apuestaMultiplesNumeros[i] = 0;
                    }


                } else {
                    //
                    //
                    //
                    //    ____    _    ____   ____    _    ____       _    ____  _   _ _____ ____ _____  _    ____  
                    //   / ___|  / \  |  _ \ / ___|  / \  |  _ \     / \  |  _ \| | | | ____/ ___|_   _|/ \  / ___| 
                    //  | |     / _ \ | |_) | |  _  / _ \ | |_) |   / _ \ | |_) | | | |  _| \___ \ | | / _ \ \___ \ 
                    //  | |___ / ___ \|  _ <| |_| |/ ___ \|  _ <   / ___ \|  __/| |_| | |___ ___) || |/ ___ \ ___) |
                    //   \____/_/   \_\_| \_\\____/_/   \_\_| \_\ /_/   \_\_|    \___/|_____|____/ |_/_/   \_\____/                                                                                                                                                                                                                      
                    //
                    //
                    //
                    //

                    
                    string input;
                    while (true) {
                        
                        cout << "Monto: ";
                        getline(cin, input);

                        istringstream iss(input);
                        if (iss >> monto and monto > 0) {
                            break;
                        } else {
                            cout << "Entrada inválida. Por favor, ingresa solo numeros positivos..." << endl;
                        }
                    }

                    if (monto > coin) {
                        cout << "Fondos insuficientes!" << endl;
                        tecla = keyPress();
                    } else {
                        coin -= monto;
                        // Opción de múltiples números deshabilitada
                        if (op == 12) {
                            cout << "Opcion deshabilitada, presiona cualquier tecla para continuar...";
                            tecla = keyPress();
                        } else if (op == 13) {
                            // Apostar a un número específico
                            cout << "Numero a apostar (0-36): ";
                            bool buu = true;
                            while (buu) {
                                cin >> apuestaIndividualNumero;
                                if (apuestaIndividualNumero <= 36 && apuestaIndividualNumero >= 0) {
                                    buu = false;
                                } else {
                                    cout << "Numero invalido! Escriba otra vez: ";
                                }
                            }
                            apuestaMultiplesNumeros[apuestaIndividualNumero] += monto * 36;
                            montoDevolver += monto;
                        } else {
                            // Otras apuestas
                            ganancias[op] += (monto * multiplicacion[op]);
                            apuestas[op] += monto;
                            montoDevolver += monto;
                        }
                    }
                }
                break;
            default:
                break;
        }

    }
}


//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS
//SLOTS



void draw_strawberry(int line){
    switch(line){
        case 1:
            cout<<"        ⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⢀⠀ ⠀         ";
            break;
        case 2:
            cout<<"        ⠀⠀⠀⠀⠀⠀⣏⠓⠒⠤⣰⠋⠹⡄⠀⣠⠞⣿⠀⠀          ";
            break;
        case 3:
            cout<<"        ⠀⠀⠀⢀⠄⠂⠙⢦⡀⠐⠨⣆⠁⣷⣮⠖⠋⠉⠁⠀          ";
            break;
        case 4:
            cout<<"        ⠀⠀⡰⠁⠀⠮⠇⠀⣩⠶⠒⠾⣿⡯⡋⠩⡓⢦⣀⡀          ";
            break;
        case 5:
            cout<<"        ⠀⡰⢰⡹⠀⠀⠲⣾⣁⣀⣤⠞⢧⡈⢊⢲⠶⠶⠛⠁          ";
            break;
        case 6:
            cout<<"        ⢀⠃⠀⠀⠀⣌⡅⠀⢀⡀⠀⠀⣈⠻⠦⣤⣿⡀⠀⠀          ";
            break;
        case 7:                  
            cout<<"        ⠸⣎⠇⠀⠀⡠⡄⠀⠷⠎⠀⠐⡶⠁⠀⠀⣟⡇⠀         ⠀ ";
            break;
        case 8:
            cout<<"        ⡇⠀⡠⣄⠀⠷⠃⠀⠀⡤⠄⠀⠀⣔⡰⠀⢩⠇⠀         ⠀ ";
            break;
        case 9:
            cout<<"        ⡇⠀⠻⠋⠀⢀⠤⠀⠈⠛⠁⠀⢀⠉⠁⣠⠏⠀⠀          ⠀";
            break;
        case 10:
            cout<<"        ⣷⢰⢢⠀⠀⠘⠚⠀⢰⣂⠆⠰⢥⡡⠞⠁⠀⠀⠀          ⠀";
            break;
        case 11:
            cout<<"        ⠸⣎⠋⢠⢢⠀⢠⢀⠀⠀⣠⠴⠋⠀⠀⠀⠀⠀          ⠀⠀";
            break;
        case 12:
            cout<<"        ⠀⠘⠷⣬⣅⣀⣬⡷⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀          ⠀⠀";
            break;
        case 13:
            cout<<"⠀        ⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀         ⠀ ⠀⠀";
            break;
        case 14:
            cout<<"                                      ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}

void draw_cherry(int line){
    switch(line){
        case 1:
            cout<<"                        ████          ";      
            break;
        case 2:
            cout<<"                    ████████          ";
            break;
        case 3:
            cout<<"                  ██    ██            ";
            break;
        case 4:
            cout<<"                ██      ██            ";
            break;
        case 5:
            cout<<"              ██        ██            ";
            break;
        case 6:
            cout<<"          ██████        ██            ";
            break;
        case 7:
            cout<<"        ██▓▓▓▓▓▓██      ██            ";
            break;
        case 8:
            cout<<"      ██▓▓  ▓▓▓▓▓▓██  ██████          ";
            break;
        case 9:
            cout<<"      ██▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓██        ";
            break;
        case 10:
            cout<<"      ██▓▓▓▓▓▓▓▓▓▓██▓▓  ▓▓▓▓▓▓██      ";
            break;
        case 11:
            cout<<"        ██▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓██      ";
            break;
        case 12:
            cout<<"          ██████  ██▓▓▓▓▓▓▓▓▓▓██      ";
            break;
        case 13:
            cout<<"                    ██▓▓▓▓▓▓██        ";
            break;
        case 14:
            cout<<"                      ██████          ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}


void draw_grapes(int line){
    //https://emojicombos.com/grapes-ascii-art
    switch(line){
        case 1:
            cout<<"      ⢀⣀⣠⣤⣄⣀⡀     ⢠⡄                  ";
            break;
        case 2:
            cout<<"      ⠈⠙⢛⣿⣿⣿⣿⣷⣄   ⢸⡇                  ";
            break;
        case 3:
            cout<<"    ⠠⠤⣶⠿⠿⠟⠛⣻⣿⡿⠛⣷⡀⣾⠇⣀⣤⣤⣤⣄⡀             ";
            break;
        case 4:
            cout<<"           ⣰⠿⠏   ⠸⣷⣿⡾⠋⠁ ⠹⣿⣿⣷⣄.        ";
            break;
        case 5:
            cout<<"             ⣤⣤⣄ ⢿⠟       ⣿⡟⢿⡍⠃       ";
            break;
        case 6:
            cout<<"         ⣴⣿⡇⠸⠿⣿⣿⠇⣠⣤⣤⡄   ⠛⠁⠈⠃          ";

            break;
        case 7:
            cout<<"        ⠻⠿⠁⣠⣤⣄⠁ ⠛⠛⠿⡟⢀⣀⡀               ";
            break;
        case 8:
            cout<<"      ⢀⣤⣤⡄⢸⣿⣿⣿⠆⢰⣿⣷⣆ ⣾⣿⣷               ";
            break;
        case 9:
            cout<<"      ⢺⡿⠋⣁⣀⠙⠛⠋ ⢿⣿⣿⠟  ⠻⠿⠋              ";
            break;
        case 10:
            cout<<"         ⢼⣿⣿⣿ ⣿⣷⣤⡉⢡⣴⣿⣶                ";
            break;
        case 11:
            cout<<"         ⠈⠛⠛⠋ ⠿⠿⠛⢀⣦⣈⡉                 ";
            break;
        case 12:
            cout<<"         ⢺⣿ ⣿⣷⣶⡖ ⠻⢿⠿⠃                 ";
            break;
        case 13:
            cout<<"          ⠉⠂⠈⠙⠋⣀⠘⢶⣤⠄                  ";
            break;
        case 14:
            cout<<"            ⢸⣿⣿⣿⠇⠈⠁                   ";
            break;
        case 15:
            cout<<"             ⠉⠉⠁                      ";
            break;
    }
}

void draw_diamond(int line){
    switch(line){
        case 1:
            cout<<"     .:::::--.-===+=====:.    ...     ";
            break;
        case 2:
            cout<<"   .::::--===. :=++===:  :.  .::::.   ";
            break;
        case 3:
            cout<<" .::::-======-   :+=-   .::. :::::::. ";
            break;
        case 4:
            cout<<"::::::...:---------.   .---------:::::";
            break;
        case 5:
            cout<<" .::::.    :::-====    -========-:::. ";
            break;
        case 6:
            cout<<"   .::::   .:::====   .=======-:::.   ";
            break;
        case 7:
            cout<<"     .:::.  .::-===   -======-::.     ";
            break;
        case 8:
            cout<<"       .::.  .::===  .=====-::.       ";
            break;
        case 9:
            cout<<"         .::  .:-==  -====-:.         ";
            break;
        case 10:
            cout<<"           .:. .:==  ====::           ";
            break;
        case 11:
            cout<<"             .: .-= :==-:             ";
            break;
        case 12:
            cout<<"               ..:= ==:.              ";  
            break;
        case 13:
            cout<<"                ..-:-.                ";
            break;
        case 14:
            cout<<"                  ..                  ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}

void draw_seven(int line){
    switch(line){
        case 1:
            cout<<"        ++++++++++++++    +++++       ";
            break;

        case 2:
            cout<<"        +++++++++++++++++++++++       ";
            break;
        case 3:
            cout<<"        +++++++++++++++++++++         ";
            break;
        case 4:
            cout<<"        ++++++++++++++++++++          ";
            break;
        case 5:
            cout<<"        +++++       +++++++           ";
            break;
        case 6:
            cout<<"        ++++      +++++++++           ";
            break;
        case 7:
            cout<<"                ++++++++++            ";
            break;
        case 8:
            cout<<"              ++++++++++++            ";
            break;
        case 9:
            cout<<"             ++++++++++++             ";
            break;
        case 10:
            cout<<"            ++++++++++++              ";
            break;
        case 11:
            cout<<"            ++++++++++++              ";
            break;
        case 12:
            cout<<"            +++++++++++++             ";
            break;
        case 13:
            cout<<"            +++++++++++++             ";
            break;
        case 14:
            cout<<"                                      ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}

void draw_empty(int line){
    switch(line){
        case 1:
            cout<<"                                      ";
            break;

        case 2:
            cout<<"                                      ";
            break;
        case 3:
            cout<<"                                      ";
            break;
        case 4:
            cout<<"                                      ";
            break;
        case 5:
            cout<<"                                      ";
            break;
        case 6:
            cout<<"                                      ";
            break;
        case 7:
            cout<<"                                      ";
            break;
        case 8:
            cout<<"                                      ";
            break;
        case 9:
            cout<<"                                      ";
            break;
        case 10:
            cout<<"                                      ";
            break;
        case 11:
            cout<<"                                      ";
            break;
        case 12:
            cout<<"                                      ";
            break;
        case 13:
            cout<<"                                      ";
            break;
        case 14:
            cout<<"                                      ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}



void draw_machine_top(){
    cout<<"                                   ________________________________________"<<endl;
 cout<<"                                      |                                      |"<<endl;
cout<<"---------------------------------------|             SLOT MACHINE             |--------------------------------------|"<<endl;
cout<<"|                                      |______________________________________|                                      |"<<endl;
cout<<"|____________________________________________________________________________________________________________________|"<<endl;
cout<<"|                                      |                                      |                                      |"<<endl;
}

void draw_machine_bottom(string prize){
    cout<<"(|                                      |                                      |                                      |"<<endl;
cout<<"|______________________________________|______________________________________|______________________________________|"<<endl;
cout<<"|                                              ________________________                                              |"<<endl;
cout<<"|                                              |                      |                                              |"<<endl;
cout<<")";
cout<<"|                                              |        "<<prize<<"        |                                              |"<<endl;
cout<<"|                                              |______________________|                                              |"<<endl;
cout<<"|____________________________________________________________________________________________________________________|"<<endl;
}


void draw_fruit_line(int num, int line){
    switch(num){
        case 1:
            draw_strawberry(line);
            break;
        case 2:
            draw_grapes(line);
            break;
        case 3:
            draw_cherry(line);
            break;
        case 4:
            draw_diamond(line);
            break;
        case 5:
            draw_seven(line);
            break;
        case 6:
            draw_empty(line);
    }
}
    

void draw_fruits(int num1, int num2, int num3){
    for(int i = 1; i <= 15; i++){
            cout<<"|";
            draw_fruit_line(num1, i);
            cout<<"|";
            draw_fruit_line(num2, i);
            cout<<"|";
            draw_fruit_line(num3, i);
            cout<<"|";
            cout<<endl;
        }
}


int recompensa_de(int fruit){
    int prize;

    switch(fruit){
        case 1:
            prize = 10;
            break;

        case 2:
            prize = 100;
            break;
        case 3:
            prize = 1000;
            break;
        case 4:
            prize = 10000;
            break;
        case 5:
            prize = 100000;
            break;
    }

    return prize;
}


void slot_game(int &coins){
    clear();
    
    draw_machine_top();
    draw_fruits(5, 5, 5);
    draw_machine_bottom("999999");
    
    bool slot = true;
    while(slot){

        cout<<"Ingrese E para iniciar. O toca la K para salir. El juego cuesta 5 monedas. Tienes "<<coins<<" monedas."<<endl;

        char input;
        while(true){
            if(read(STDIN_FILENO, &input, 1) > 0){
                if(input == 'k'){
                    return;
                }else if(input == 'e'){
                    break;
                }
            }
        }
        
        coins -= 5;

        draw_machine_top();
    
        int fruit1 = rand_range(1, 5);
        int fruit2 = rand_range(1, 5);
        int fruit3 = rand_range(1, 5);
        float fruit1d = 0;
        float fruit1i = 10;
        float fruit2d = 0;
        float fruit2i = 10;
        float fruit3d = 0;
        float fruit3i = 10;

        int time = 50; // 25 - 75
        for(int i = 0; i < time + 160; i++){ // 50 - 70

            clear();
            draw_machine_top();

            if(i < (time + fruit1d)){
                if(fruit1 < 5){
                    fruit1++;
                }else{
                    fruit1 = 1;
                }
            }else{
                fruit1d += fruit1i;
                fruit1i = (fruit1i/1.1);
            }
            
            if(i < time + 30 + fruit2d){
                if(fruit2 < 5){
                    fruit2++;
                }else{
                    fruit2 = 1;
                }
           }else{
                fruit2d += fruit2i;
                fruit2i = (fruit2i/1.1);
            }

           if(i < time + 60 + fruit3d){
                if(fruit3 < 5){
                    fruit3++;
                }else{
                    fruit3 = 1;
                }
           }else{
                fruit3d += fruit3i;
                fruit3i = (fruit3i/1.1);
            }

            draw_fruits(fruit1, fruit2, fruit3);

            draw_machine_bottom("000000");

            usleep(50000);
        }

        if(fruit1 == fruit2 && fruit1 == fruit3){
            int prize = recompensa_de(fruit1);
            coins += prize;
            string prize_s = to_string(prize);

            while(prize_s.size() < 6){
                prize_s = "0" + prize_s;
            }

            for(int i = 0; i < 10; i++){
                clear();

                draw_machine_top();
                draw_fruits(fruit1, fruit2, fruit3);
                draw_machine_bottom(prize_s);

                usleep(10000);
                clear();

                draw_machine_top();
                draw_fruits(6, 6, 6);
                draw_machine_bottom(prize_s);

                usleep(10000);
            }
        }
    }
}




//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:
//MAIN GAME:




void draw_square(int x1, int y1, int x2, int y2){

    for(int i = y1; i < y2; i++){
        map[x1][i] = "|";
    }
    for(int i = y1; i < y2; i++){  
        map[x2][i] = "|";
    }


    for(int i = x1; i <= x2; i++){
        map[i][y1] = "_";
    }
    for(int i = x1; i <= x2; i++){
        map[i][y2] = "-";
    }

}

void create_map(){

    for(int i = 0; i < map_y; i++){
        for(int ii = 0; ii < map_x; ii++){
            map[ii][i] = " ";
        }
    }

    for(int i = 0; i < map_y; i++){
        map[0][i] = "|";
    }
    for(int i = 0; i < map_y; i++){
        map[map_x -1][i] = "|";
    }


    for(int i = 0; i < map_x; i++){
        map[i][0] = "_";
    }
    for(int i = 0; i < map_x; i++){
        map[i][map_y -1] = "-";
    }

    //BLACKJACK TABLE
    draw_square(2, 1, 9, 8);
    map[4][5] = "B";
    map[5][5] = "J";
    map[6][5] = "2";
    map[7][5] = "1";


    //RULETA TABLE
    draw_square(48, 1, 57, 8);
    map[50][5] = "R";
    map[51][5] = "U";
    map[52][5] = "L";
    map[53][5] = "E";
    map[54][5] = "T";
    map[55][5] = "A";
    

    //SLOTS
    draw_square(21, 0, 27, 2);
    draw_square(27, 0, 33, 2);
    draw_square(33, 0, 39, 2);
    map[28][1] = "S";
    map[29][1] = "L";
    map[30][1] = "O";
    map[31][1] = "T";
    map[32][1] = "S";
}

void draw_screen(int &playerx, int &playery){
    for(int i = 0; i < map_y; i++){
        for(int ii = 0; ii < map_x; ii++){
            if(playerx == ii && playery == i){
                cout<<"o";
            }else{
                cout<<map[ii][i];
            }
        }
        cout<<endl;
    }
}

bool player_colission(int dir, int playerx, int playery){
    switch(dir){
        case 1:
            if(playery > 3){
                return true;
            }else{
                return false;
            }
            break;
        
        case 2:
            if(playerx > 10){
                return true;
            }else{
                return false;
            }
            break;
        
        case 3:
            if(playery < map_y-2){
                return true;
            }else{
                return false;
            }
            break;
        
        case 4:
            if(playerx < map_x-13){
                return true;
            }else{
                return false;
            }
            break;
        
        default: return false;
    }

    return false;
}

void update_player(int &playerx, int &playery, int &coins){
    char input;
    if (read(STDIN_FILENO, &input, 1) > 0){
        switch(input){
            case 'w':
            if(player_colission(1, playerx, playery)){
                playery--;
                }
                break;

            case 'a':
            if(player_colission(2, playerx, playery)){
                playerx--;
                }
                break;

            case 's':
            if(player_colission(3, playerx, playery)){
                playery++;
                }
                break;

            case 'd':
            if(player_colission(4, playerx, playery)){
                playerx++;
                }
                break;
            
            case 'e':
                if(playerx <= 40 && playerx >= 20 && playery == 3){
                    clear();
                    slot_game(coins);
                }

                if(playerx == 47){
                    jugabilidad(coins);
                }

                if(playerx == 10){
                    juego(coins);
                }

            default:
                return;
                break;
        }
    }else{
        cout<<"a";
    }
}




void interact_message(int playerx, int playery, int &coins){
    cout<<"Tienes "<<coins<<" monedas";

    if(playerx == 10){
        cout<<"                 Toca E para jugar al blackjack";
    }

    if(playerx == 47){
        cout<<"                Toca E para jugar a la ruleta";
    }
    
    if(playerx <= 40 && playerx >= 20 && playery == 3){
        cout<<"                Toca E para jugar a los slots";
    }
    
    cout<<endl;
}

void main_game(int &coins){
    int playerx = 30;
    int playery = 7;

    create_map();


    cout<<"              CASINO virtual - WASD para moverte"<<endl;
    while(true){
        interact_message(playerx, playery, coins);
        draw_screen(playerx, playery);
       
        update_player(playerx, playery, coins);
        
        clear();
    }
}






int main(){
    int coins = 1000;
    setup_terminal();
    
    main_game(coins);
}