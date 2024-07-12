#include <iostream>
#include <random>
using namespace std;

int menu(){
    int indice_menu=0;
    cout<<"1-Iniciar"<<endl<<"2-Salir"<<endl;
    cin>>indice_menu;
    return indice_menu;
}
bool Pelea1(int vida_personaje, int vida_enemigo, int dano_arma_personaje, int dano_arma_enemigo, int &rations, bool boss){
    int accion;
    bool estado=true;
    bool estado_enemigo=true;
    bool turno=true;
    bool test=true;
    bool resultado;
    bool defense=false;
    bool parry_tf=false;
    bool stun=false;
    int porc_vida_enemigo=vida_enemigo/10;
    int accion_personaje;
    int new_life=vida_personaje;
    int boss_hp=vida_enemigo;
    while (estado==true and estado_enemigo==true){
        random_device hp;
        mt19937 gen(hp());
        uniform_int_distribution<> gen_dano_personaje(1,dano_arma_personaje);
        uniform_int_distribution<> gen_dano_enemigo(1,dano_arma_enemigo);
        uniform_int_distribution<> parry(1,100);
        uniform_int_distribution<> boss_accion(1,2);
        uniform_int_distribution<> boss_regen(1,100);
        int life_regen=boss_regen(gen);
        int accion_boss=boss_accion(gen);
        int dano_personaje= gen_dano_personaje(gen);
        int dano_enemigo= gen_dano_enemigo(gen);
        int dano=dano_enemigo;
        int Parry_probabilidad= parry(gen);
        //texto de historia de la pelea
        if(vida_personaje>0 and vida_enemigo>0){
        cout<<"Vida: "<<vida_personaje<<endl;
        cout<<"1- Atacar."<<endl<<"2- Accion."<<endl<<"3- Usar raciones."<<endl;
        
        while(turno==true){
            cout<<"Tu turno."<<endl;
            cin>>accion_personaje;
        switch(accion_personaje){
            case 1:
                if(defense==false){
                vida_enemigo=vida_enemigo-dano_personaje;
                cout<<"daño: "<<dano_personaje<<endl<<"Vida del enemigo: "<<vida_enemigo<<endl;
                }
                else{
                    cout<<"El jefe no ha tomado daño, se ha defendido."<<endl;
                    defense=false;
                }
                turno=false;
                break;
            case 2:
                cout<<"1- Stats."<<endl<<"2- Parry."<<endl;
                while(test==true){
                cin>>accion;
                if(accion>2 or accion<1){
                    cout<<"Ingrese numero valido"<<endl;
                }
                else{
                    test=false;
                }
                }
                if(accion==1){
                    cout<<"Stats:"<<endl<<"Vida del enemigo: "<<vida_enemigo<<endl<<"daño enemigo: "<<dano_enemigo<<endl;
                    turno=false;
                }
                else if(accion==2){
                    if(Parry_probabilidad<51){
                        cout<<"Has defendido todo el daño"<<endl;
                        parry_tf=true;
                        turno=false;
                    }
                    else if(Parry_probabilidad>50 and Parry_probabilidad<76){
                        vida_personaje=vida_personaje-dano_enemigo;
                        cout<<"Has recibido "<<dano_enemigo<<" daño y quedaste tonto."<<endl;
                        parry_tf=false;
                        turno=false;
                    }
                    else if(Parry_probabilidad>75 and Parry_probabilidad<101){
                        cout<<"Has stuneado al enemigo!"<<endl;
                        parry_tf=true;
                        turno=false;
                    }
                }
                break;
            case 3:
                if(rations>0){
                new_life=vida_personaje+50;
                    if(new_life>100){
                        int res_new_life=new_life-100;
                        new_life=new_life-res_new_life;
                    }
                    vida_personaje=new_life;
                    cout<<"Vida: "<<vida_personaje<<endl;
                    rations--;
                    turno=false;
                }
                else{
                    cout<<"No tienes raciones."<<endl;
                    turno=false;
                }
                break;
        }
        defense=false;
    }
    if (parry_tf==true){
        turno=true;
        parry_tf=false;
    }
    else if(stun==true){
        turno=true;
        stun=false;
    }
    while(turno==false){
        if(boss==false){
        cout<<"Turno enemigo."<<endl;
                int dan=dano_enemigo;
                cout<<"El marciano te pega."<<endl<<"Has recibido "<<dan<<" daño"<<endl;
                vida_personaje=vida_personaje-dan;
                turno=true;
        }
        else{
            defense=false;
            //10% probabilidad de q se cure 100% de la vida si va debajo de 10% y esta defendiendo
            switch(accion_boss){
                case 1:
                    
                    cout<<"Zorgax te pega con su martillo."<<endl<<"Has recibido "<<dano<<" daño"<<endl;
                    vida_personaje=vida_personaje-dano;
                    turno=true;
                    break;
                case 2:
                    cout<<"El jefe se ha defendido!"<<endl;
                    defense=true;
                    if(vida_enemigo<porc_vida_enemigo){
                        if(life_regen<6){
                            cout<<"Zorgax se curó toda la vida!!"<<endl;
                            vida_enemigo=boss_hp;
                        }
                    }
                    turno=true;
                    break;
            }
        }
        }
    }
    else if(vida_enemigo<=0){
        resultado=true;
        return resultado;
        estado_enemigo=false;
    }
    else if(vida_personaje<=0){
        resultado=false;
        return resultado;
        estado=false;
    }
    }
}
void aventura(){
    int decision=0;/*Elije la opción*/
    int dia=1;/*Indica el día*/
    bool ahorros=false;/*Decisiones y objetos que pueden alteran la historia*/
    int raciones=5;
    int dano_arma=15;
    int vida=100;
    int id_aventura=1;/*Almacena la parte de la historia en la que se encuentra*/
    bool fin_aventura=false;/*Muestra cuando se llega a un final*/
    while (fin_aventura==false)
    switch (id_aventura)
    {
    case 1:
        cout<<"Tu padre fue secuestrado por un grupo criminal de marcianos, tu deber es viajar a su base en marte y salvar a tu  padre. ¿Estas dispuesto a realizar esta aventura?"<<endl;
        cout<<"1-Si"<<endl<<"2-No"<<endl;
        cin>>decision;
        if(decision==1){
            id_aventura=2;
            
        }
        else if (decision==2){
            fin_aventura=true;
            
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;
        
    case 2:
        cout<<"Dia "<<dia<<endl;
        cout<<"Necesitas un vehículo interespacial, el cual no tienes. Conoces a alguien que tiene uno pero ni le caes bien ni tecae bien. ¿Decides pedirle prestada la nave o buscas algun lugar para alquilar?"<<endl;
        cout<<"1-Pedir prestado"<<endl<<"2-Buscar alquilar una"<<endl;
        cin>>decision;
        if(decision==1){
            id_aventura=3;
            cout<<"Le pedis prestada la nave y acepta a regañadientes. ";
            
        }
        else if (decision==2){
            id_aventura=4;
            
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;
        
    case 3:
        cout<<"Dia "<<dia++<<endl;
        cout<<"Ahora tenes una nave, ¿Preferis zarpar ahora mismo o quedarte un dia mas en la ciudad para prepararte mejor?"<<endl;
        cout<<"1-Zarpar"<<endl<<"2-Quedarse"<<endl;
        cin>>decision;
        if(decision==1){
            id_aventura=6;
            
        }
        else if (decision==2){
            if (ahorros==true){
                cout<<"No tenes plata, zarpas al día siguiente"<<endl;
                id_aventura=7;
            }
            else{
                id_aventura=5;
            }
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
            
            dia--;
        }
        break;
        
    case 4:
        cout<<"Encontras un lugar que alquilan naves, pero un viaje de ida y vuelta cuesta todos tus ahorros ¿Decides alquilar   una o decides pedirle a tu conocido la nave?"<<endl;
        cout<<"1-Alquilar"<<endl<<"2-Pedir"<<endl;
        cin>>decision;
        if(decision==1){
            id_aventura=3;
            ahorros=true;
            
        }
        else if (decision==2){
            id_aventura=3;
            cout<<"Le pedis prestada la nave y acepta a regañadientes. ";
            
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;
        
    case 5:
        cout<<"Dia "<<dia++<<endl;
        cout<<"Te quedas un día mas y compras raciones ¿Quedarse otro día o zarpar? "<<endl;
        raciones++;
        cout<<"Cantidad de raciones: "<<raciones<<endl;
        cout<<"1-Zarpar"<<endl<<"2-Quedarse"<<endl;
        cin>>decision;
        if(decision==1){
            id_aventura=7;
            cout<<"Zarpas.";
        }
        else if (decision==2){
            id_aventura=5;
            
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
            raciones--;
            dia--;
        }
        break;
        
    case 6:
        cout<<"Zarpas en dirección a marte sin pensartelo mucho. Ves que se acerca un asteroide. ¿Decides dispararle, hacer una maniobra evasiva o simplemente quedarte quieto y esperar que pase?"<<endl;
        cout<<"1-Disparar"<<endl<<"2-Maniobra"<<endl<<"3-Esperar";
        cin>>decision;
        if(decision==1){
            cout<<"Le disparas, explota y varios pedazos caen en tu nave, rompiendola y haciendo que todo el oxigeno se vaya. FIN"<<endl;
            fin_aventura=true;
            
        }
        else if (decision==2){
            cout<<"Tratas de hacer una maniobra evasiva, pero tu poca experiencia manejando naves y los nervios hacen que te estralles de cara contra el asteroide. FIN"<<endl;
            fin_aventura=true;
            
        }
        else if (decision==3){
            cout<<"El asteroide pasa a escasos metros de la nave, pero resulta ilesa"<<endl;
            id_aventura=7;
            
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;
    case 7:
        cout<<"Te encontras en medio del espacio en dirección a marte. Finalmente aterrizas en la superficie del planeta rojo. Te dirijes a la base cuando te das cuenta de que ellos estan armados hasta los dientes y vos no tenes con que defenderte. pero subitamente te acordas que suelen ir sin casco cuando no estan en combate. Agarras una piedra y te pones a esperar que pase un guardia. Cuando pasa le pegas un piedrazo y lo matas. Conseguiste una armadura marciana y un blaster. ¿Queres entrar por la puerta principal o por una entrada alternativa?"<<endl;
        cout<<"1-Principal"<<endl<<"2-Alternativa"<<endl;
        cin>>decision;
        if(decision==1){
            cout<<"Son demasiados. Abren fuego sin que tengas capacidad de reacción. FIN"<<endl;
            fin_aventura=true;
        }
        else if (decision==2){
            cout<<"Encontras un conducto de ventilación y entras a la base. ";
            id_aventura=8;
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;
    case 8:
        cout<<"Te encuentras en una bifurcación"<<endl;
        cout<<"1-Izquierda"<<endl<<"2-Derecha"<<endl;
        cin>>decision;
        if(decision==1){
            cout<<"Te encuentras un marciano sargento."<<endl;
            if(Pelea1(vida,60,dano_arma,30,raciones,false)==true){
                cout<<"Conseguiste su arma!"<<endl;
                dano_arma=30;
                id_aventura=10;
            }
            else{
                fin_aventura=true;
            }
        }
        else if (decision==2){
            id_aventura=9;
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;        
    case 9:
        cout<<"Vas por un pasillo y te encontras un placard. ¿Lo abris?"<<endl;
        cout<<"1-Si"<<endl<<"2-No"<<endl;
        cin>>decision;
        if(decision==1){
            cout<<"Encontraste LA PERCHA"<<endl;
            dano_arma=50;
            decision=2;
        }

        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        cout<<"Te encuentras un marciano."<<endl;
        if(Pelea1(vida,30,dano_arma,10,raciones,false)==true){
            id_aventura=10;
        }
        else{
            fin_aventura=true;
            }
        break;
    case 10:
        cout<<"Encontras la sala de Zorgax el implacable. ¿Inicias la pelea?"<<endl;
        cout<<"1-Si"<<endl<<"2-No"<<endl;
        cin>>decision;
        if(decision==1){
            cout<<"Te peleas con Zorgax."<<endl;
            if(Pelea1(vida,200,dano_arma,40,raciones,true)==true){
                cout<<"Rescatas a tu padre y escapan de marte. FIN"<<endl<<"Gracias por jugar!";
                fin_aventura=true;
            }
            else{
                cout<<"Pierdes contra Zorgax. FIN"<<endl<<"Gracias por jugar!";
                fin_aventura=true;
            }
        }
        else if (decision==2){
            cout<<"Te cagas y escapas de marte. FIN"<<endl<<"Gracias por jugar!";
            fin_aventura=true;
        }
        else{
            cout<<"Por favor elija un numero válido";
            cout<<endl;
        }
        break;
    }
}
int main(){
    if (menu()==1){
        cout<<"Iniciando..."<<endl;
       aventura();    
    }
    else{
        cout<<"Saliendo..."<<endl;
    }
}