#include <iostream>
#include <random>
#include "clases.h"

using namespace std;
//soldados
soldado::soldado(){}
soldaso::soldado(string a,int b,double c,double d,double e,double f,double g)
            {
                name = a;
                HP = b;
                campo = c;
                torre = d;
                camaras = e;
                trinchera = f;
                perros = g;
            }

void soldado::exito(){
            cout<<name<<" elimino la defensa"<<endl;
        }
void soldado::fracaso(){
            cout<<name<<" fallo al neutralizar la defensa"<<endl;
            HP -= 7;
        }

void soldado::HP_barre(){
            if(HP<=0){
                cout<<name<<" callo en combate."<<endl;  

            }
            if(HP>10){HP=10;}
        }
        
void soldado::curar(soldado a){
        int U_curar = 0;
            if(U_curar <8 ){
                if(a.HP<10 && a.HP>0){
                    cout<<"Medico curo a "<<a.name<<endl;
                    a.HP += 5;
                    U_curar +=1;
                }
            }

        }

med::med(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){}
generic::generic(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){if(b<10){a=0;}}
//defensas
def_torre::def_torre(){}
def_torre::def_torre(string b,char c){
            nombre = b;
            t_defensa = c;            
        }
double def_torre::Set_Prob(){
            double a;
            a = 0 + (float)(rand()) / ((float)(RAND_MAX/(1 - 0)));
            return a;
            
        }




