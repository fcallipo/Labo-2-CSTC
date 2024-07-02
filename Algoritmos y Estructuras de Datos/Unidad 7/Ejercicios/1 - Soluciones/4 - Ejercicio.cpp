#include <iostream>
#include <fstream>
#include <cstdio> // para std::remove y std::rename
using namespace std;

/*
    Realizar un gestor de archivos que realice lo pedido en cada una de las opciones, el programa deberá mostrar el siguiente menú:
    1- Abrir archivo.
    2- Eliminar archivo.
    3- Renombrar archivo.
    4- Mover archivo.
*/

void mostrarMenu() {
    cout << "1- Abrir archivo" << endl;
    cout << "2- Eliminar archivo" << endl;
    cout << "3- Renombrar archivo" << endl;
    cout << "4- Mover archivo" << endl;
    cout << "0- Salir" << endl;
}

int main() {
    int opcion = 5;
    string nombre_archivo;
    string linea;
    string texto;
    ifstream archivo;

    while (opcion != 0) {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el nombre del archivo a abrir: ";
                cin >> nombre_archivo;
                archivo.open(nombre_archivo, ios::out);

                if (archivo.is_open()) {
                    texto.clear();
                    while (getline(archivo, linea)) {
                        texto += linea + '\n';
                    }
                    archivo.close();
                    cout << "Contenido del archivo:\n" << texto << endl;
                }else {
                    cout << "No se pudo abrir el archivo" << endl;
                }

                break;
            }
            case 2: {
                cout << "Ingrese el nombre del archivo a eliminar: ";
                cin >> nombre_archivo;
                if (remove(nombre_archivo.c_str()) != 0) {
                    cerr << "Error al eliminar el archivo " << nombre_archivo << endl;
                } else {
                    cout << "Archivo eliminado con éxito" << endl;
                }
                break;
            }
            case 3: {
                cout << "Ingrese el nombre del archivo a renombrar: ";
                cin >> nombre_archivo;
                string nuevo_nombre;
                cout << "Ingrese el nuevo nombre: ";
                cin >> nuevo_nombre;
                if (rename(nombre_archivo.c_str(), nuevo_nombre.c_str()) != 0) {
                    cerr << "Error al renombrar el archivo " << nombre_archivo << endl;
                } else {
                    cout << "Archivo renombrado con éxito" << endl;
                }
                break;
            }
            case 4: {
                cout << "Ingrese el nombre del archivo a mover: ";
                cin >> nombre_archivo;
                string nueva_ruta;
                cout << "Ingrese la nueva ruta: ";
                cin >> nueva_ruta;
                if (rename(nombre_archivo.c_str(), nueva_ruta.c_str()) != 0) {
                    cerr << "Error al mover el archivo " << nombre_archivo << endl;
                } else {
                    cout << "Archivo movido con éxito" << endl;
                }
                break;
            }
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida, por favor intente de nuevo." << endl;
                break;
        }
    }
}
