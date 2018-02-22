#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
using namespace std;

void limpiarPantalla();

int main(){

    char buster[25][22];
    char prds=186;
    char crs=177;
    int cont=0;
    bool pausa=false;
    //int msec=0;
    int ultimosJuegos[10];

    for(int i=0;i<10;i++){
        ultimosJuegos[i]=0;
    }

    int nivelEstats[10];

    for(int i=0;i<10;i++){
        nivelEstats[i]=0;
    }

    menu:
    //Cargar el mapa con 5 carriles y con bordes ya incluidos
    for(int i=0; i < 20; ++i) {
      for(int j=0; j < 17; ++j) {
        buster[i][0] = prds;
        buster[i][15] = prds;
        buster[i][j] = ' ';
      }
    }


    int y = 15, x =9; // las cordenadas del carrito
    srand(time(0));
    int a = 0, b = rand() % 12 + 2; //Cordenadas de obstaculos
    int pnts = 0; //Puntuacion
    int vel = 200; //determina la velocidad de el carrito y los obstaculos
    bool startup = true;
    int vidas=9;

    char obstaculo= 178;

    char car = crs;
    buster[y][x] = car;


    cout<<"----------------MENU PRINCIPAL------------------"<<endl;
    cout<<"1.Jugar al Brick Racing"<<endl;
    cout<<"2.Ultimos 10 Juegos "<<endl;
    cout<<"3.Salir"<<endl;
    int opcionMenu;
    cin>>opcionMenu;
    system("CLS");


    if(opcionMenu==1){
        //clock_t tiempo;
        //tiempo =clock();
        for(;;) {//Ciclo del juego
            limpiarPantalla();


            //pone el carrito en la posicion inicial
            buster[y][x] = crs;
            buster[y][x+1] = ' ';
            buster[y][x-1] = ' ';
            buster[y+1][x-1] = crs;
            buster[y+1][x+1] = crs;
            buster[y-1][x-1] = crs;
            buster[y-1][x+1] = crs;

            //genera los campos de espacios
            buster[a][b] = ' ';
            buster[a][b+1] = ' ';
            buster[a][b-1] = ' ';
            buster[a+1][b-1] = ' ';
            buster[a+1][b+1] = ' ';
            buster[a-1][b-1] = ' ';
            buster[a-1][b+1] = ' ';
            ++a;

            //genera los carritos contrarios
            buster[a][b] = obstaculo;
            buster[a][b+1] = obstaculo;
            buster[a][b-1] = obstaculo;
            buster[a+1][b-1] = obstaculo;
            buster[a+1][b+1] = obstaculo;
            buster[a-1][b-1] = obstaculo;
            buster[a-1][b+1] = obstaculo;
            if(a > 20) {
                a = 0;
                b = rand() % 12 + 2;
            }
        //Control de tiempo
        /*tiempo= clock()-tiempo;
        msec= float(tiempo);
        if(msec== 10){
            tiempo=0.00;
            if(nivel!=10)
                nivel++;
            else{
                nivel=1;
                vel=250;
            }


        }*/

        //muetra el mapa llamado buster
        if(vidas!=0){
                for(int i=0; i < 20; ++i) {
                    for(int j=0; j < 17; ++j) {
                        cout << buster[i][j];
                        if(j >= 16) {
                            cout << endl;
                    }
                }
            }

            cout<<endl<< "  Puntos: " << pnts<<endl<<"  VIDAS: "<<vidas/3<<endl;
            //cout<<"Nivel: "<<nivel<<endl;
            if(pnts>=20 && pnts<40){
                cout<<"  Nivel 1"<<endl;
            }else if(pnts>=40 && pnts<60){
                cout<<"  Nivel 2"<<endl;
            }else if(pnts>=60 && pnts<80){
                cout<<"  Nivel 3"<<endl;
            }else if(pnts>=80 && pnts<100){
                cout<<"  Nivel 4"<<endl;
            }else if(pnts>=100 && pnts<130){
                cout<<"  Nivel 5"<<endl;
            }else if(pnts>=130 && pnts<170){
                cout<<"  Nivel 6"<<endl;
            }else if(pnts>=170 && pnts<200){
                cout<<"  Nivel 7"<<endl;
            }else if(pnts>=200 && pnts<230){
                cout<<"  Nivel 8"<<endl;
            }else if(pnts>=230 && pnts<280){
                cout<<"  Nivel 9"<<endl;
            }else if(pnts>280){
                cout<<"  Nivel 10"<<endl;
            }

        }
        //empieza el juego cuando se presiona cualquier tecla;
        if(startup) {
            _getch();
            startup = false;
        }
        //pausar
        if(GetAsyncKeyState(VK_ESCAPE)){
            pausa=true;
            Sleep(1000);
            if (pausa==true){
                Sleep(0);
                pausa=false;
            }
        }
        //mueve el carro a la izquierda
        if(GetAsyncKeyState(VK_LEFT)) {
            if(buster[y][x-3] == obstaculo) {
                goto lost;//vamos a la parte especifica del juego de perder
            }else if(buster[y][x-3] != prds) {
                buster[y][x] = ' ';
                buster[y][x+1] = ' ';
                buster[y][x-1] = ' ';
                buster[y+1][x-1] = ' ';
                buster[y+1][x+1] = ' ';
                buster[y-1][x-1] = ' ';
                buster[y-1][x+1] = ' ';
                x -= 3;
                buster[y][x] = crs;
                buster[y][x+1] = ' ';
                buster[y][x-1] = ' ';
                buster[y+1][x-1] = crs;
                buster[y+1][x+1] = crs;
                buster[y-1][x-1] = crs;
                buster[y-1][x+1] = crs;
            }
        }
        //mover carro a derecha
        if(GetAsyncKeyState(VK_RIGHT)) {
            if(buster[y][x+3] == obstaculo) {
                goto lost;//vamos a la parte especifica del juego de perder
            }else if(buster[y][x+3] != prds) {
                buster[y][x] = ' ';
                buster[y][x+1] = ' ';
                buster[y][x-1] = ' ';
                buster[y+1][x-1] = ' ';
                buster[y+1][x+1] = ' ';
                buster[y-1][x-1] = ' ';
                buster[y-1][x+1] = ' ';
                x += 3;
                buster[y][x] = crs;
                buster[y][x+1] = ' ';
                buster[y][x-1] = ' ';
                buster[y+1][x-1] = crs;
                buster[y+1][x+1] = crs;
                buster[y-1][x-1] = crs;
                buster[y-1][x+1] = crs;
            }
        }

        //Revisamos si el carro choca
        if(buster[y-2][x] == obstaculo || buster[y-2][x-1] == obstaculo || buster[y-2][x+1] == obstaculo) {
        lost:

            vidas--;// disminuyo la vida
        }
        ++pnts;

        //Aumenta la velocidad a medida vamos ganando los puntos
        /*if(nivel==1){
            pnts=20;
            vel=vel;
        }else if(nivel==2){
            pnts=40;
            vel-=25;
        }else if(nivel==3){
            pnts=60;
            vel-=25;
        }else if(nivel==4){
            pnts=80;
            vel-=25;
        }else if(nivel==5){
            pnts=100;
            vel-=25;
        }else if(nivel==6){
            pnts=130;
            vel-=25;
        }else if(nivel==7){
            pnts=170;
            vel-=25;
        }else if(nivel==8){
            pnts=200;
            vel-=25;
        }else if(nivel==9){
            pnts=240;
            vel-=25;
        }else if(nivel==10){
            pnts=280;
            vel-=25;
        }*/
        if(pnts == 20 || pnts == 40 || pnts == 60 || pnts == 80 || pnts == 100 || pnts == 130 || pnts== 170 || pnts == 200 || pnts == 230 || pnts== 280 ) {
            vel -= 20;
        }

        if(vidas <=0){
            system("CLS");
            cout<<"...Has Chocado..."<<endl;

            if(cont<10){
                    ultimosJuegos[cont]=pnts;

            }else{

                cont=0;
                ultimosJuegos[cont]=pnts;
            }
            cont++;
            goto menu;
        }
        Sleep(vel);
        }

    //Opcion 2  es donde mostramos las estadisticas del juego
    }else if(opcionMenu==2){

        for(int i=0;i<10;i++){
            cout<<i+1<<". "<<"Puntos: \t"<<ultimosJuegos[i]<<endl;
        }

        cout<<"5 Segundos regresara al menu Principal"<<endl;
        Sleep(5000);
        system("CLS");
        goto menu;

    }else if(opcionMenu==3){
        exit(1);
    }

  return 0;
}


void limpiarPantalla(){
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
