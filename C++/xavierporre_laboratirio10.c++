#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Pizza {
    public:
        string SaborPizza;
        string T_llegada;
        int T_salida;

        Pizza(string s, string tl){
            SaborPizza=s;
            T_llegada=tl;
        }

        void setHoraSalida(int h, int m, int s){
            T_salida = h/60+m+s/60;
        }
        void getTiempoEspera(){
            
        }

        
};
class Pizzeria {
    public:

        string comuna;
        int CapacidadHorno=5;
        queue<Pizza> horno;
        queue<Pizza> cocina;

        Pizzeria(string c){
            comuna=c;
        } 
        void popHorno(){
            horno.pop();
        }
        void getEstadoHorno(){
            cout<<"El horno tiene "<< horno.size() <<" pizzas."<<endl;
        }
        void pushHorno(Pizza p){
            if(horno.size()<CapacidadHorno){
                horno.push(p);
            }else{cout<<"horno lleno"<<endl;}
        }

};


int main(){
    vector<Pizzeria> pizzerías;
    vector<string> sucursales;

    ifstream archivo("datos pizzería.csv");
    string linea;
    char delimiter = ';';
    getline(archivo, linea);
    while(getline(archivo, linea)){
        stringstream stream(linea);
        string Local, Pizza , Horas;

        getline(stream, Local ,delimiter);
        getline(stream, Pizza ,delimiter);
        getline(stream, Horas ,delimiter);
        
        

        cout << "=======================================================" << endl;
        cout << "local:"<<Local<<"| pizza:"<<Pizza<<"| Horas:"<<Horas<<endl;
    }
    archivo.close();

}
