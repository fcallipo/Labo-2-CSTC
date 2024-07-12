#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Jugador {
    int fila, columna;
};

struct Salida {
    int filita, columnita;
};

struct Punto {
    int fila, columna;
};

vector<string> laberinto = {
    "  __________________",
    "|                  |",
    "| .                |",
    "|                  |",
    "| .O.....        ..|",
    "|                  |",
    "|       .O.    ....|",
    "|                  |",
    "|.......      .  ..|",
    "|                  |",
    "|     ...  ..      |",
    "|                  |",
    "|O.   . .      ....|",
    "|                  |",
    "| ...   ...O..  ...|",
    "|                  |",
    "|   ....         | *",
    "|__________________|"
};

void mover_arriba(Jugador& jugador) {
    if (jugador.fila > 0 && laberinto[jugador.fila - 1][jugador.columna] != '|') {
        jugador.fila--;
    }
}

void mover_abajo(Jugador& jugador, int fila) {
    if (jugador.fila < fila - 1 && laberinto[jugador.fila + 1][jugador.columna] != '|') {
        jugador.fila++;
    }
}

void mover_izquierda(Jugador& jugador) {
    if (jugador.columna > 0 && laberinto[jugador.fila][jugador.columna - 1] != '|') {
        jugador.columna--;
    }
}

void mover_derecha(Jugador& jugador, int columna) {
    if (jugador.columna < columna - 1 && laberinto[jugador.fila][jugador.columna + 1] != '|') {
        jugador.columna++;
    }
}

int main() {
    const int fila = 18;
    const int columna = 20;
    int vidas = 3;
    bool juego_activo;
    string eleccion;

    Jugador jugador;
    jugador.columna = 0;
    jugador.fila = 0; // posición inicial

    Salida salida;
    salida.filita = 17;
    salida.columnita = 20; // posición final

    char obstaculo = 'O';

    vector<Punto> puntos = {{2, 2}, {4, 2}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 19}, {4, 20}, {6, 10}, {6, 18}, {6, 17}, {6, 18}, {6, 19}, {6, 20}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 6}, {8, 5}, {8, 7}, {8, 8}, {8, 9}, {8, 13}, {10, 6}, {10, 9}, {12, 2}, {12, 6}, {12, 15}, {12, 18},  {15, 8}, {15, 9}, {15, 10}, {15, 12}, {15, 13}, {15, 16}, {15, 17}, {17, 4}, {17, 5}, {17, 6}, {17, 7} };

    cout<<"Bienvenido al juego del laberinto!"<<endl;
    cout<<"El objetivo es llegar a la salida (*)" <<endl;
    cout<<"pero cuidado! no podes tocar los obstaculos, o se reiniciara el juego"<<endl;
    cout<<"tambien tendras que ser cauteloso con algunos de los puntos o se te descontarán vidas"<<endl;
    cout<<"Buena suerte! Quieres comenzar el juego?"<<endl;
    cin>>eleccion;

    if (eleccion == "si" || eleccion == "Si" || eleccion == "SI"){
        juego_activo = true;
    }
    else{
        juego_activo = false;
    }

    while (juego_activo) {
        // muestra laberinto
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < columna; j++) {
                if (i == jugador.fila && j == jugador.columna) {
                    cout << "☻"; // personita
                } else {
                    cout << laberinto[i][j];
                }
            }
            cout << endl;
        }

        // controla movimientos
        char movimiento;
        cout << "Ingrese movimiento (w/a/s/d): ";
        cin >> movimiento;

        if (movimiento == 'w') {
            mover_arriba(jugador);
        } 
        else if (movimiento == 'a') {
            mover_izquierda(jugador);
        } 
        else if (movimiento == 's') {
            mover_abajo(jugador, fila);
        } 
        else if (movimiento == 'd') {
            mover_derecha(jugador, columna);
        } 
        else {
            cout << "movimiento invalido" << endl;
        }

        // verifica si el jugador gana
        if (laberinto[jugador.fila][jugador.columna] == laberinto[salida.filita][salida.columnita]) {
            cout << "Felicidades! Encontraste la salida!" << endl;
            break;
        }

        // verifica si el jugador pierde vida
        for (const Punto& punto : puntos) {
            if (jugador.fila == punto.fila && jugador.columna == punto.columna) {
                cout << "Has perdido 1 vida" << endl;
                vidas--;
                cout << "Te quedan " << vidas << endl;
                break;
            }
        }

        // verifica si el jugador perdio
        if (vidas == 0) {
            cout << "Perdiste" << endl;
            juego_activo = false;
        } 
        else if (laberinto[jugador.fila][jugador.columna] == obstaculo) {
            cout << "tocaste un obstaculo, el juego se reiniciara..." << endl;
            jugador.fila = 0;
            jugador.columna = 0;
            vidas = 3;
        }
    }

    return 0;
}