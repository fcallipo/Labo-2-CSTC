#include <iostream>
#include <cstdlib>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"    
#define BLUE    "\033[34m"     

int main(){
    srand(time(0));
    int num_random = rand() % 85;
    //otra manera de conseguir numeros aleatorios
    //int randomIndex = rand() / (RAND_MAX / 85 + 1);
    string intento;
    int intentos = 0;
    string jugadores[85] = {"messi", "ronaldo", "neymar", "mbappe", "salah", "lewandowski", "hazard", "modric", "kane", "benzema", "haaland", "ramos", "fernandes", "lukaku", "suarez", "griezmann", "sterling", "pogba", "muller", "alisson", "son", "kimmich", "kante", "rashford", "courtois", "cavani", "dybala", "thiago", "aguero", "casemiro", "navas", "gomez", "vidal", "firmino", "ziyech", "rodri", "oblak", "eriksen", "wijnaldum", "fabinho", "donnarumma", "immobile", "neuer", "hummels", "alli", "felix", "koulibaly", "gnabry", "ederson", "laporte", "valverde", "cancelo", "varane", "robertson", "sancho", "llorente", "partey", "grealish", "hakimi", "coutinho", "henderson", "upamecano", "mount", "mahrez", "bonucci", "martinez", "mertens", "maguire", "dias", "depay", "silva","palermo","riquelme","aimar","armani"};
    string adivino = jugadores[num_random];
    int largo = adivino.size();
    cout<<"Si quieres rendirte escribe ´rendirse´ en el terminal"<<endl;
    cout << "El jugador tiene " << largo << " letras." << endl;

    while(intentos <= 5){
        cout << "Introduce tu intento: ";
        cin >> intento;
        intentos++;
        
        if (intentos == 6 and intento != adivino)
        {
            cout << ""  << endl;
            cout << RED<<"██████╗ ███████╗██████╗ ██████╗ ██╗███████╗████████╗███████╗██╗" << endl;
            cout << RED<<"██╔══██╗██╔════╝██╔══██╗██╔══██╗██║██╔════╝╚══██╔══╝██╔════╝██║" << endl;
            cout << RED<<"██████╔╝█████╗  ██████╔╝██║  ██║██║███████╗   ██║   █████╗  ██║" << endl;
            cout << RED<<"██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║╚════██║   ██║   ██╔══╝  ╚═╝" << endl;
            cout << RED<<"██║     ███████╗██║  ██║██████╔╝██║███████║   ██║   ███████╗██╗" << endl;
            cout << RED<<"╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝" <<  endl;
            cout << RED<<"                                                               " << RESET << endl;
            cout<< BLUE <<"El jugador era "<< adivino <<RESET<< endl;
        }
        

        if (intento == "rendirse") {
            cout << ""  << endl;
            cout << RED<<"██████╗ ███████╗██████╗ ██████╗ ██╗███████╗████████╗███████╗██╗" << endl;
            cout << RED<<"██╔══██╗██╔════╝██╔══██╗██╔══██╗██║██╔════╝╚══██╔══╝██╔════╝██║" << endl;
            cout << RED<<"██████╔╝█████╗  ██████╔╝██║  ██║██║███████╗   ██║   █████╗  ██║" << endl;
            cout << RED<<"██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║╚════██║   ██║   ██╔══╝  ╚═╝" << endl;
            cout << RED<<"██║     ███████╗██║  ██║██████╔╝██║███████║   ██║   ███████╗██╗" << endl;
            cout << RED<<"╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝" <<  endl;
            cout << RED<<"                                                               " << RESET << endl;
            cout<< BLUE <<"El jugador era "<< adivino <<RESET<< endl;

            return 0;
        }

        if (intento == adivino) {
            cout << GREEN<< ""<< RESET << endl;
            cout << GREEN<< " ██████╗  █████╗ ███╗   ██╗ █████╗ ███████╗████████╗███████╗██╗"<< RESET << endl;
            cout << GREEN<< "██╔════╝ ██╔══██╗████╗  ██║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██║"<< RESET << endl;
            cout << GREEN<< "██║  ███╗███████║██╔██╗ ██║███████║███████╗   ██║   █████╗  ██║"<< RESET << endl;
            cout << GREEN<< "██║   ██║██╔══██║██║╚██╗██║██╔══██║╚════██║   ██║   ██╔══╝  ╚═╝"<< RESET << endl;
            cout << GREEN<< "╚██████╔╝██║  ██║██║ ╚████║██║  ██║███████║   ██║   ███████╗██╗"<< RESET << endl;
            cout << GREEN<< " ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝"<< RESET << endl;
            cout << GREEN<< "                                                               "<< RESET << endl;
            return 0;
        }

bool esta_en_palabra = false;
bool esta_en_posicion_correcta = false;

for (int i = 0; i < largo; i++) {
    if (intento[i] == adivino[i]) {
        cout << GREEN << "|" << intento[i]<< "|" << RESET << " "; 
        esta_en_posicion_correcta = true;
    } else {
        esta_en_palabra = false;
        for (int ii = 0; ii < largo; ii++) {
            if (intento[i] == adivino[ii]) {
                cout << YELLOW << "|" << intento[i] << "|" << RESET << " ";
                esta_en_palabra = true;
                break;
            }
        }
        if (!esta_en_palabra) {
            cout << RED << "|" << intento[i] << "|" << RESET << " "; 
        }
    }

}
cout << endl;


if (esta_en_posicion_correcta) {
    cout << "";

}
}
}
