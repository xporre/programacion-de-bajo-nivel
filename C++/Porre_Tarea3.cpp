#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include "clases.h"

using namespace std;




// class soldado{
//     public:

//         string name;
//         int HP;
//         double campo;
//         double torre;
//         double camaras;
//         double trinchera;
//         double perros;

//         void exito(){
//             cout<<name<<" elimino la defensa"<<endl;
//         }
//         void fracaso(){
//             cout<<name<<" fallo al neutralizar la defensa"<<endl;
//             HP -= 7;
//         }

//         void HP_barre(){
//             if(HP<=0){
//                 cout<<name<<" callo en combate."<<endl;  

//             }
//             if(HP>10){HP=10;}
//         }
        
//         void curar(soldado a){
//             int U_curar = 0;
//             if(U_curar <8 ){
//                 if(a.HP<10 && a.HP>0){
//                     cout<<"Medico curo a "<<a.name<<endl;
//                     a.HP += 5;
//                     U_curar +=1;
//                 }
//             }

//         }
        

        
//         soldado(){}

//         soldado(string a,int b,double c,double d,double e,double f,double g)
//         {
//             name = a;
//             HP = b;
//             campo = c;
//             torre = d;
//             camaras = e;
//             trinchera = f;
//             perros = g;
//         }
// };
// class med:public soldado{
//     public:

//         med(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){}
// };
// class generic:public soldado{
//     public:
//             void fracaso(){
//             cout<<name<<" fallo al neutralizar la defensa"<<endl;
//             HP = 0;
//         }
        
//         generic(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){}
// };
// class def_torre{
//     public:
//         string nombre;
//         char t_defensa;


//         double Set_Prob(){
//             double a;
//             a = 0 + (float)(rand()) / ((float)(RAND_MAX/(1 - 0)));
//             return a;
            
//         }

//         def_torre(){};

//         def_torre(string b,char c){
//             nombre = b;
//             t_defensa = c;            
//         }
       
// };


int main(){
//generar soldados
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
        generic("Gen1",10,0.4,0.6,0.4,0.5,0.4),
        generic("Gen2",10,0.4,0.6,0.4,0.5,0.4),
        generic("Gen3",10,0.4,0.6,0.4,0.5,0.4),
        generic("Gen4",10,0.4,0.6,0.4,0.5,0.4),
        med("Medico",10,0.3,0.1,0.2,0.2,0.6)
        };

    

    
//instrucciones del juego
    cout << "Las defensas que puede agregar a su torre:"<<"\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------"<<"\n";
    cout << "Campo minado (m) | Torre de vigilancia con vigías (t) | Cámaras de video (v) | Trinchera profunda (h) | Perros entrenados (p)"<<"\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------"<<"\n";
    cout << "puede ingresar de 3 a 10 defensas para su torre"<<"\n";
    cout << "para esto solo ingrese la letra del tipo de defensa que desea ingresar"<<"\n";

// crear la torre


   
    string input;

    //validar input

    string tipos = "mtvhpMTVHP";
    string input_validado = "";


    int i=0;
    while(i != 1){

        cout << "Ingrese las defensas:";
        getline(cin, input);
        //string validador esta vacio
        if(!input_validado.empty()){
            input_validado.clear();
        }
        //validar los tipos de defensa
        for(int j=0; j<input.length(); j++){
            for(int i=0; i<tipos.length(); i++){
                if(tipos[i] == input[j]){
                    input_validado.push_back(input[j]);
                    break;
                }
                /*else{
                    cout<<"Error <"<<input[j]<<"> no es un tipo de defensa valido para este juego"<<"\n";
                    cout<<"<"<<input[j]<<"> se va a eliminar"<<"\n";
                }*/
            }

            
            
        }

        cout<<input_validado<<"\n";

        //validar la cantidad de defensas

        if(input_validado.length()<3 ){
            cout<<"Ingreso un numero de defensas menor a 3"<<"\n";
            cout <<"Ingreso "<<input_validado.length()<<" defensas para la torre"<<"\n";
        }

        if(input_validado.length()>10){
            cout<<"Ingreso un numero de defensas mayor a 10"<<"\n";
            cout <<"Ingreso "<<input_validado.length()<<" defensas para la torre"<<"\n";
        }

        if(input_validado.length()>=3 && input_validado.length()<=10){i=1;}
    }
    

    cout <<"Ingreso "<<input.length()<<" defensas para la torre"<<" de estas se pudieron validar "<<input_validado.length()<<endl;  

// crear las defensas

    vector <def_torre> Defensa_de_Torre;
    string defensas[]={"Campo minado","Torre de vigilancia con vigías","Cámaras de video","Trinchera profunda","Perros entrenados"};
    srand(time(0));
    

    for(int i=0; i<input_validado.length();i++){
        
        
            switch(input_validado[i]){
                case 'm':
                    Defensa_de_Torre.push_back(def_torre(defensas[0],input_validado[i]));

                break;                 

                case 't':
                    Defensa_de_Torre.push_back(def_torre(defensas[1],input_validado[i]));
                break;

                case 'v':
                    Defensa_de_Torre.push_back(def_torre(defensas[2],input_validado[i]));
                break;  

                case 'h':
                    Defensa_de_Torre.push_back(def_torre(defensas[3],input_validado[i]));
                break;

                case 'p':
                    Defensa_de_Torre.push_back(def_torre(defensas[4],input_validado[i]));
                break;                 
            }
        
        

        }
   
   
    // for(int x = 0; x <input_validado.length(); x++){
    //     cout<<Defensa_de_Torre[x].nombre<<"|"<<Defensa_de_Torre[x].t_defensa<<"|"<<Defensa_de_Torre[x].Set_Prof()<<endl;
        
    // }
    

//juego
    int pos=0;
    int x = 0;
    while(x < Defensa_de_Torre.size()){
        // cout<<"defensa "<<Defensa_de_Torre[contador].nombre<<"\n";
        for( int i=0; i<=sizeof(grupo_de_ataque)/sizeof(soldado); i++ ){
            int val = 0;
            if(grupo_de_ataque[i].HP<10){
                grupo_de_ataque[sizeof(grupo_de_ataque)/sizeof(soldado)].curar(grupo_de_ataque[i]);
                val++;
            }
            if(val==2){
                continue;
            }
        }
        double ma1=0;//variable auxiliar

        switch(Defensa_de_Torre[x].t_defensa){
                case 'm':
                    cout<<"La escuadra se enfrenta "<<Defensa_de_Torre[x].nombre<<"\n";
                    // encuentra el mejor soldado para la tarea y define su posicion en el array
                    
                    grupo_de_ataque[pos].HP_barre();
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1<=grupo_de_ataque[con].campo && grupo_de_ataque[con].HP != 0){ma1=grupo_de_ataque[con].campo;} 
                    }                    
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1==grupo_de_ataque[con].campo){
                            pos = con;
                            break;} 
                    }
                    // comparacion del soldado contra la torre
                    if(grupo_de_ataque[pos].campo < Defensa_de_Torre[x].Set_Prob()){
                        grupo_de_ataque[pos].fracaso();
                        grupo_de_ataque[pos].HP_barre();

                    }else{
                        grupo_de_ataque[pos].exito();

                        x++;
                    }      
                break;                 

                case 't':
                    cout<<"La escuadra se enfrenta "<<Defensa_de_Torre[x].nombre<<"\n";
                    grupo_de_ataque[pos].HP_barre();

                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1<=grupo_de_ataque[con].torre && grupo_de_ataque[con].HP != 0){ma1=grupo_de_ataque[con].torre;} 
                    }                    
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1==grupo_de_ataque[con].torre){
                            pos = con;
                            break;} 
                    }
                    // comparacion del soldado contra la torre
                    if(grupo_de_ataque[pos].torre < Defensa_de_Torre[x].Set_Prob()){
                        grupo_de_ataque[pos].fracaso();
                        grupo_de_ataque[pos].HP_barre();

                    }else{
                        grupo_de_ataque[pos].exito();
                        x++;
                    } 
                break;

                case 'v':
                    cout<<"La escuadra se enfrenta "<<Defensa_de_Torre[x].nombre<<"\n";
                    grupo_de_ataque[pos].HP_barre();

                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1<=grupo_de_ataque[con].camaras && grupo_de_ataque[con].HP != 0){ma1=grupo_de_ataque[con].camaras;} 
                    }                    
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1==grupo_de_ataque[con].camaras){
                            pos = con;
                            break;} 
                    }
                    // comparacion del soldado contra la torre
                    if(grupo_de_ataque[pos].camaras < Defensa_de_Torre[x].Set_Prob()){
                        grupo_de_ataque[pos].fracaso();
                        grupo_de_ataque[pos].HP_barre();

                    }else{
                        grupo_de_ataque[pos].exito();
                        x++;
                    } 
                break;  

                case 'h':
                    cout<<"La escuadra se enfrenta "<<Defensa_de_Torre[x].nombre<<"\n";
                    grupo_de_ataque[pos].HP_barre();

                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1<=grupo_de_ataque[con].trinchera && grupo_de_ataque[con].HP != 0){ma1=grupo_de_ataque[con].trinchera;} 
                    }                    
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1==grupo_de_ataque[con].trinchera){
                            pos = con;
                            break;} 
                    }
                    // comparacion del soldado contra la torre
                    if(grupo_de_ataque[pos].trinchera < Defensa_de_Torre[x].Set_Prob()){
                        grupo_de_ataque[pos].fracaso();
                        grupo_de_ataque[pos].HP_barre();

                    }else{
                        grupo_de_ataque[pos].exito();
                        x++;
                    } 
                break;

                case 'p':
                    cout<<"La escuadra se enfrenta "<<Defensa_de_Torre[x].nombre<<"\n";
                    grupo_de_ataque[pos].HP_barre();

                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1<=grupo_de_ataque[con].perros && grupo_de_ataque[con].HP != 0){ma1=grupo_de_ataque[con].perros;} 
                    }                    
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1==grupo_de_ataque[con].perros){
                            pos = con;
                            break;} 
                    }
                    // comparacion del soldado contra la torre
                    if(grupo_de_ataque[pos].perros < Defensa_de_Torre[x].Set_Prob()){
                        grupo_de_ataque[pos].fracaso();
                        grupo_de_ataque[pos].HP_barre();

                    }else{
                        grupo_de_ataque[pos].exito();
                        x++;
                    } 
                break;                 
            }
                 
    }
//Fin de juego
    if(x==Defensa_de_Torre.size()){
                    double ma1=0;//variable auxiliar
                    grupo_de_ataque[pos].HP_barre();

                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1<=grupo_de_ataque[con].campo){ma1=grupo_de_ataque[con].campo;} 
                    }                    
                    for( int con=0; con<=sizeof(grupo_de_ataque)/sizeof(soldado); con++ ){
                        if(ma1==grupo_de_ataque[con].campo){
                            pos = con;
                            break;} 
                    }
                    // comparacion del soldado contra la torre
                    if(grupo_de_ataque[pos].campo < Defensa_de_Torre[x].Set_Prob()){
                        cout<<"La escuadra llega finalmente a la torre de comunicaciones"<<endl;
                        cout << "Un demoledor coloca la carga de dinamita"<<endl;
                        cout<<"La escuadra se pone a cubierto"<<endl;
                        cout<<"La carga fallo y la misión es un fracaso "<<endl;

                    }else{
                        cout<<"La escuadra llega finalmente a la torre de comunicaciones"<<endl;
                        cout << "Un demoledor coloca la carga de dinamita"<<endl;
                        cout<<"La escuadra se pone a cubierto"<<endl;
                        cout<<"La dinamita explota y la torre queda destruida."<<endl;
                    }


    }


    return 0;
}
