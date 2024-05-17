#include <iostream>
using namespace std;

// Realizar un programa para simular un sistema de autenticación de usuarios. Se le pide al usuario que ingrese un nombre de usuario y una contraseña, luego el sistema verifica si coinciden con los valores de usuario y contraseña almacenados en el programa. Si la autenticación es exitosa, se concede el acceso, caso contrario, se deniega.

int main() {
    string usuario, contrasena, usuario_valido = "admin", contrasena_valida = "secreta";
    bool acceso_concedido = false;

    cout << "Ingrese su nombre de usuario: ";
    cin >> usuario;

    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    if (usuario == usuario_valido && contrasena == contrasena_valida) {
        acceso_concedido = true;
    }

    if (!acceso_concedido) {
        cout << "Acceso denegado. Verifique su nombre de usuario y contraseña." << endl;
    } else {
        cout << "¡Bienvenido, " << usuario << "! Acceso concedido." << endl;
    }

}
