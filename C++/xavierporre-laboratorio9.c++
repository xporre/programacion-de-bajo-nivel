#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vehiculo{
    public:
        string marca;
        string modelo;
        int año; 
        string rut_propietario;
        string color;
        double cilindrado;

        Vehiculo(){}

        Vehiculo(string ma, string mo, int a, string rut, string col, double b)
        {
            marca = ma;
            modelo = mo;
            año = a;
            rut_propietario = rut;
            color = col;
            cilindrado = b;
        }
};

class Auto: public Vehiculo{
    public:
        int ruedas = 4; 
        // Auto(){}
        Auto(string ma, string mo, int a, string rut, string col, double b):Vehiculo(ma,mo,a,rut,col,b){}

};

class Moto: public Vehiculo{
    public:
        int ruedas = 2;
        // Moto(){}
        Moto(string ma, string mo, int a, string rut, string col, double b):Vehiculo(ma,mo,a,rut,col,b){}

};

class soldado{
    public:
 
        soldado(){}

        soldado(string a,int b,double c,double d,double e,double f,double g)
        {
            name = a;
            HP = b;
            campo = c;
            torre = d;
            camaras = e;
            trinchera = f;
            perros = g;
        }

        string name;
        int HP;
        double campo;
        double torre;
        double camaras;
        double trinchera;
        double perros;

        void exito(){
            cout<<name<<" elimino la defensa."<<endl;
        }
        void fracaso(){
            cout<<name<<" fallo al neutralizar la defensa."<<endl;
            HP -= 7;
        }

        void HP_barre(){
            if(HP<=0){
                cout<<name<<" callo en combate."<<endl;  

            }
            if(HP>10){HP=10;}
        }
       

       
};
class med:public soldado{
    public:
        int U_curar = 0;

        void curar(soldado a){
            if(U_curar <8 ){
                if(a.HP<10 && a.HP>0){
                    a.HP += 5;
                    U_curar +=1;
                }
            }

        }
         med(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){}
};

int main(){
    //cout <<"test"<<endl;
    //Auto xd("hola","hola",21,"2,","olr",1.2);
    //cout << xd.marca << endl;
    Auto automobiles[]={
        Auto("ford","focus",2008,"11111111-1","azul",0.3),
        Auto("ford","focus",2018,"11111111-1","azul",0.3),
        Auto("ford","focus",2004,"11111111-1","verde",0.3),
        Auto("ford","focus",2019,"11111111-1","azul",0.3),
        Auto("ford","focus",2011,"11111111-1","rojo",0.3),
        Auto("ford","focus",2018,"11111111-1","rojo",0.3),
        Auto("ford","focus",2018,"11111111-1","azul",0.3),
        Auto("ford","focus",2020,"11111111-1","verde",0.3),
        Auto("ford","focus",2021,"11111111-1","azul",0.3),
        Auto("ford","focus",2004,"11111111-1","azul",0.3),
        Auto("ford","focus",2010,"11111111-1","azul",0.3)
    };

    Moto motos[]={
        Moto("nissan","alto",2014,"11111111-1","rojo",0.3),
        Moto("nissan","alto",2003,"11113111-1","verde",0.3),
        Moto("nissan","alto",2010,"11124111-1","azul",0.3),
        Moto("nissan","alto",2014,"11111111-1","rojo",0.3),
        Moto("nissan","alto",2003,"11113111-1","verde",0.3),
        Moto("nissan","alto",2010,"11124111-1","azul",0.3),
        Moto("nissan","alto",2014,"11111111-1","rojo",0.3),
        Moto("nissan","alto",2003,"11113111-1","verde",0.3),
        Moto("nissan","alto",2010,"11124111-1","azul",0.3),
        Moto("nissan","alto",2010,"11124111-1","azul",0.3)
       
    };

    soldado grupo_de_ataque[]={
        soldado("demoledor1",10,0.8,0.2,0.1,0.4,0.3),
        soldado("demoledor2",10,0.8,0.2,0.1,0.4,0.3),
        soldado("demoledor3",10,0.8,0.2,0.1,0.4,0.3),
        soldado("Sniper1",10,0.3,0.9,0.4,0.3,0.2),
        soldado("Sniper2",10,0.3,0.9,0.4,0.3,0.2),
        soldado("Hacker1",10,0.2,0.1,0.8,0.3,0.3),
        soldado("Hacker2",10,0.2,0.1,0.8,0.3,0.3),
        soldado("Constructor",10,0.4,0.2,0.3,0.8,0.2),
        soldado("Entrenador",10,0.2,0.3,0.3,0.3,0.8),
        soldado("Gen1",10,0.4,0.6,0.4,0.5,0.4),
        soldado("Gen2",10,0.4,0.6,0.4,0.5,0.4),
        soldado("Gen3",10,0.4,0.6,0.4,0.5,0.4),
        soldado("Gen4",10,0.4,0.6,0.4,0.5,0.4),
        med("Medico",10,0.3,0.1,0.2,0.2,0.6)
        };

    


    double ma2=0;

    for( int i=0; i<=sizeof(grupo_de_ataque)/sizeof(soldado); i++ ){
        if(ma2<=grupo_de_ataque[i].campo && grupo_de_ataque[i].HP != 0 ){ma2=grupo_de_ataque[i].campo;} 
    }
    
    for( int i=0; i<=sizeof(grupo_de_ataque)/sizeof(soldado); i++ ){
        if(ma2==grupo_de_ataque[i].campo){
            cout<<grupo_de_ataque[i].name<<" tiene "<<grupo_de_ataque[i].campo<<"\n";
            grupo_de_ataque[i].exito();
            grupo_de_ataque[i].fracaso();
            grupo_de_ataque[i].fracaso();
            grupo_de_ataque[i].HP_barre();
            } 
    }






    

    //cout << "hola"<< endl;
    // cout <<"Vehiculos menores a 5 años"<< endl;
    // for(int i = 0; i <10 ;i++){
    //     if(2022-automobiles[i].año<5){
    //         cout <<automobiles[i].ruedas<<"|"<<automobiles[i].marca<<"|"<<automobiles[i].modelo<<"|"<<automobiles[i].año<<"|"<<automobiles[i].rut_propietario<<"|"<<automobiles[i].color<<"|"<<automobiles[i].cilindrado<<"\n";
    //     }
    //     if(2022-motos[i].año<5){
    //         cout <<motos[i].ruedas<<"|"<<motos[i].marca<<"|"<<motos[i].modelo<<"|"<<motos[i].año<<"|"<<motos[i].rut_propietario<<"|"<<motos[i].color<<"|"<<motos[i].cilindrado<<"\n";
    //     }
    // }

    // cout <<"motos asociadas al rut 11111111-1 "<< endl;
    // for(int i = 0; i <10 ;i++){
    //     if(motos[i].rut_propietario=="11111111-1"){
    //         cout <<motos[i].ruedas<<"|"<<motos[i].marca<<"|"<<motos[i].modelo<<"|"<<motos[i].año<<"|"<<motos[i].rut_propietario<<"|"<<motos[i].color<<"|"<<motos[i].cilindrado<<"\n";
    //     }
    // }

    // cout <<"Vehiculos rojos"<< endl;
    // for(int i = 0; i <10 ;i++){
    //     if(automobiles[i].color=="rojo"){
    //         cout <<automobiles[i].ruedas<<"|"<<automobiles[i].marca<<"|"<<automobiles[i].modelo<<"|"<<automobiles[i].año<<"|"<<automobiles[i].rut_propietario<<"|"<<automobiles[i].color<<"|"<<automobiles[i].cilindrado<<"\n";
    //     }
    //     if(motos[i].color=="rojo"){
    //         cout <<motos[i].ruedas<<"|"<<motos[i].marca<<"|"<<motos[i].modelo<<"|"<<motos[i].año<<"|"<<motos[i].rut_propietario<<"|"<<motos[i].color<<"|"<<motos[i].cilindrado<<"\n";
    //     }
    // }



    return 0;
}



