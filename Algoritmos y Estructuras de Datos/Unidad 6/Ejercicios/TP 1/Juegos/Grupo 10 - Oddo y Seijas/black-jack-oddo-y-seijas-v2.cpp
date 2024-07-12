#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

// Función que genera dos números aleatorios únicos, uno del 0 al 3 y otro del 0 al 12
void num_rand(int &fila_rand, int &colum_rand) {
    static bool numerosUtilizados[4][13] = {false}; // Matriz para mantener un registro de los números utilizados
    random_device rd;  // Semilla para el generador
    mt19937 gen(rd()); // Generador de números aleatorios
    uniform_int_distribution<> dis1(0, 3); // Números aleatorios entre 0 y 3
    uniform_int_distribution<> dis2(0, 12);// Genera un número aleatorio en el rango de 0 a 12

    do {
        fila_rand = dis1(gen); 
        colum_rand = dis2(gen); 
    } while (numerosUtilizados[fila_rand][colum_rand]); // Comprueba si los números generados ya han sido utilizados
    numerosUtilizados[fila_rand][colum_rand] = true; // Marca los números generados como utilizados
}

// Función que verifica si la mano tiene un AS y lo ajusta si es necesario
void ajustar_valor_ases(int &mano, vector<int> &valores_cartas) {
    mano = 0;
    int ases = 0;
    
    for (int valor : valores_cartas) {
        if (valor == 11) {
            ases++;
        }
        mano += valor;
    }
    
    while (mano > 21 && ases > 0) {
        mano -= 10;
        ases--;
    }
}

// Función que reparte una carta al jugador o al dealer
void dar_carta(int &mano, int selec_cartas[4][13], string selec_cartas_visual[4][13], string &carta_visual, int &fila, int &columna, vector<int>& valores_cartas, vector<string>& vector_cartas) {
    int carta;
    num_rand(fila, columna); // Genera números aleatorios para seleccionar una carta
    carta = selec_cartas[fila][columna]; // Obtiene el valor de la carta
    valores_cartas.push_back(carta); // Añade el valor de la carta a la lista de valores de cartas
    ajustar_valor_ases(mano, valores_cartas); // Ajusta el valor de los ases si es necesario
    carta_visual = selec_cartas_visual[fila][columna]; // Obtiene la representación visual de la carta
    vector_cartas.push_back(carta_visual); // Añade la carta visual al mazo del jugador o del dealer
}

// Función que muestra las cartas del jugador o del dealer
void mostrar_mazo(vector<string>& vector_cartas) {
    for (int i = 0; i != vector_cartas.size(); i++) {
        cout << vector_cartas.at(i); // Imprime cada carta en el mazo
    }
}

int main() {
    cout << "BJ"<<endl;

    int jugar_otra_ronda=0;
    float dinero = 0.0, apuesta = 0.0;

    // Preguntar si el jugador quiere empezar el juego
    while(jugar_otra_ronda != 1){
    cout << "(--Presione 1 si quiere comenzar el juego--: )";
    cin >> jugar_otra_ronda;
    }

    // Solicitar la cantidad de dinero inicial
    cout << "Ingrese la cantidad de dinero con la que quiere comenzar: ";
    cin >> dinero;

    // Bucle principal del juego 
    while (jugar_otra_ronda == 1) {
        cout<<"START"<<endl;

        // Solicitar la apuesta
        cout << "Ingrese su apuesta: ";
        cin >> apuesta;

        if (apuesta > dinero) {
            cout << "No tienes suficiente dinero para esa apuesta. Intenta de nuevo." << endl;
            continue;
        }
        dinero=dinero-apuesta;

        int fila, columna, mano_jugador = 0, mano_deler = 0, opcion = 1, carta_deler = 0, carta_jugador = 0;
        string carta_visual;
        vector<int> valores_cartas_jugador;
        vector<int> valores_cartas_deler;
        vector<string> cartas_del_jugador;
        vector<string> cartas_del_deler;

        // Inicialización de las cartas y sus representaciones visuales
        int selec_cartas[4][13] = { {2,3,4,5,6,7,8,9,10,10,10,10,11},{2,3,4,5,6,7,8,9,10,10,10,10,11},{2,3,4,5,6,7,8,9,10,10,10,10,11},{2,3,4,5,6,7,8,9,10,10,10,10,11} };
        string selec_cartas_visual[4][13] = { {"|2♥|","|3♥|","|4♥|","|5♥|","|6♥|","|7♥|","|8♥|","|9♥|","|10♥|","|J♥|","|K♥|","|Q♥|","|A♥|"},{"|2♦|","|3♦|","|4♦|","|5♦|","|6♦|","|7♦|","|8♦|","|9♦|","|10♦|","|J♦|","|K♦|","|Q♦|","|A♦|"},{"|2♣|","|3♣|","|4♣|","|5♣|","|6♣|","|7♣|","|8♣|","|9♣|","|10♣|","|J♣|","|K♣|","|Q♣|","|A♣|"},{"|2♠|","|3♠|","|4♠|","|5♠|","|6♠|","|7♠|","|8♠|","|9♠|","|10♠|","|J♠|","|K♠|","|Q♠|","|A♠|"} };

        // Mano del dealer
        //llama a sus respectivas funciones pasandole sus datos asociados a el dealer o el jugador
        dar_carta(mano_deler, selec_cartas, selec_cartas_visual, carta_visual, fila, columna, valores_cartas_deler, cartas_del_deler);
        mostrar_mazo(cartas_del_deler);
cout << "CARTAS DELEAR"<< carta_visual << "|?|" <<"="<<mano_deler;

        // Mano del jugador
        cout << "sus cartas son: ";
        // le da sus rpimeras 2 cartas al jugador mientras el dealer tiene 2, una la muestra y la otra esta dada vuelta
        for (int i = 0; i != 2; i++) {
            dar_carta(mano_jugador, selec_cartas, selec_cartas_visual, carta_visual, fila, columna, valores_cartas_jugador, cartas_del_jugador);
        }
        mostrar_mazo(cartas_del_jugador);
        cout << " = " << mano_jugador << endl;

        bool blackjack = false;
        while (opcion == 1) {
            // Primer if para comprobar si sacamos blackjack en la primera ronda
            if (mano_jugador == 21 && valores_cartas_jugador.size() == 2) {
                opcion = 2; // Si el jugador obtiene 21 con las primeras dos cartas, se considera blackjack
                blackjack = true;
            } else if (mano_jugador == 21) {
                opcion = 2; // Si el jugador obtiene 21, pasa directamente a la decisión del dealer
            } else {
                opcion = 0;
        
                cout << "--Elija una opcion--" << endl;
                while (opcion != 1 && opcion != 2) { // No te deja elegir una opción que no sea 1 o 2
                    cout << "1°-pedir o 2°-quedarse: "; //te hace elejir si quedarte o pedir. si te quedas el deler va tomar cartas hasta que su mazo se mayor a 16
                    cin >> opcion;
                }
            }

            if (opcion == 1) { // El jugador pide una carta
                cout << "sus cartas son: ";
                dar_carta(mano_jugador, selec_cartas, selec_cartas_visual, carta_visual, fila, columna, valores_cartas_jugador, cartas_del_jugador);
                mostrar_mazo(cartas_del_jugador);
                cout << " = " << mano_jugador << endl;
            }
            if (mano_jugador > 21) { // Si el jugador se pasa de 21, pierde
                opcion = 3;
            }
        } // Termina el primer while

        if (opcion != 3) { // Si el jugador no se pasa de 21 sigue ejecutando
            cout << "dealer en juego...." << endl;
            {
            // El jugador se queda
            if (opcion == 2) 
            //el deler da vuelta su carta
                cout << "mano del deler: ";
                dar_carta(mano_deler, selec_cartas, selec_cartas_visual, carta_visual, fila, columna, valores_cartas_deler, cartas_del_deler);
                mostrar_mazo(cartas_del_deler);
                cout << " = " << mano_deler << endl;

                while (mano_deler <= 16) { // El dealer sigue pidiendo cartas hasta que su mano sea mayor que 16
                    cout << "mano del deler: ";
                    dar_carta(mano_deler, selec_cartas, selec_cartas_visual, carta_visual, fila, columna, valores_cartas_deler, cartas_del_deler);
                    mostrar_mazo(cartas_del_deler);
                    cout << " = " << mano_deler << endl;
                    if (mano_deler > 21) { // Si el dealer se pasa de 21, pierde
                        opcion = 4;
                    }
                }
            }
        }
        if (opcion == 4) { // Si el dealer pierde
            mano_deler = 0; // deja el puntaje del dealer en 0
        }
        if (opcion == 3) { // Si el jugador pierde
            mano_deler += mano_jugador; // hace crecer el puntaje del dealer para que le gane al del jugador
        }

        // Comparación final para determinar el ganador
        if (mano_jugador > mano_deler) {
            if (blackjack) {
                dinero += apuesta * 3; // Multiplica la apuesta por 3 si el jugador saca blackjack
                cout << "FELICIDADES" << endl;
            } else {
                dinero += apuesta * 2; // Multiplica la apuesta por 2 si el jugador gana
                cout << "FELICIDADES"<< endl;
            }
        } else if (mano_deler == mano_jugador) {
            dinero=dinero+apuesta;
            cout << "EMPATASTE"<< endl;
        } else {
            //dinero -= apuesta; // Resta la apuesta si el jugador pierde
            cout << "PERDISTE"<< endl;
        }

        // Mostrar el dinero actual del jugador
        cout << "Dinero actual: " << dinero << endl;

        // Preguntar si el jugador quiere jugar otra ronda
        cout << "--presione 1 si quieres jugar otra ronda: ";
        cin >> jugar_otra_ronda;
    }
}
