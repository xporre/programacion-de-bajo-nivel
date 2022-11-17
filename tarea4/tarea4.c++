#include <iostream>
#include <list>
#include <iterator>

using namespace std;
enum Tipo {Auto,Camion,Bus,Ambulancia};

class Vehiculo{
    
    public: 
    string marca;
    int largoCM;
    int peso_kg;
    Tipo ti;
    Vehiculo(){}
    Vehiculo(string a,int b,int c,Tipo tipo){
        marca = a;
        largoCM = b;
        peso_kg = c;
        ti = tipo;
    }

    int getLargoCM(){
        return largoCM;
    }
    int getPeso(){ 
        return peso_kg;
    }
    Tipo getTipo(){
        return ti;
    }
    
};



class Transbordador{

    public:
        string Nombre;
        string puertoActual;
        int capacidad_de_cargar;
        int cantidad_filas;
        int largo_fila;
        list<Vehiculo> filas[5];


        Transbordador(){}
        Transbordador(string a, string b, int c, int d, int e){
            Nombre = a;
            puertoActual = b;
            capacidad_de_cargar = c;
            cantidad_filas = d;
            largo_fila = e;
        }

        void popVehiculo(int fila){
            filas[fila].pop_front();            
        }
        int getLargoFila(int fila) {
            return filas[fila].size();
        }
        int getEspacioLibre(int fila){
            int t=0;
                    if(getLargoFila(fila)==0){
                        return largo_fila;
                    }else{
                for(list<Vehiculo>::iterator it=filas[fila].begin();it!=filas[fila].end();it++){
                            t += it->getLargoCM();
                        }
                        int libre =largo_fila - t+15*getLargoFila(fila);
                        return libre;
                    }

        }
        int getPesoLibre(){
            int t = 0 ;
            for(int i=0;i<cantidad_filas;i++){
                for(list<Vehiculo>::iterator it=filas[i].begin();it!=filas[i].end();it++){
                    t += it->getPeso();
                }
                }

            return capacidad_de_cargar - t;

        }
        bool getTipo(Tipo a){
            for(int i=0;i<cantidad_filas;i++){
                for(list<Vehiculo>::iterator it=filas[i].begin();it!=filas[i].end();it++){
                    if(it->getTipo()==a){
                        return true;
                    }else{return false;}
                }
            }
        }

        bool pushVehiculo(int fila , Vehiculo v){
            
            if(getEspacioLibre(fila)>v.getLargoCM() && getPesoLibre()>v.getPeso()){
                filas[fila].push_back(v); 
                return true;
            }
            else{return false;}                                 

        }        

};



int main(){
    //class vehiculo lista
    Vehiculo v1("onda",10,100,Auto);

    Transbordador t1("Antares", "Quellón", 100000, 3, 50000);

    cout <<"largo "<<v1.getLargoCM()<<" y peso "<<v1.getPeso()<<"y tipo "<<v1.getTipo()<<endl;
    cout <<"largofila "<<t1.getLargoFila(1)<<"| CARGA "<<t1.getPesoLibre()<<" y espacio "<<t1.getEspacioLibre(1)<<endl;

    list<Vehiculo> l1;
    l1.push_back(v1);
    l1.push_back(v1);
    l1.push_back(v1);
    l1.push_back(v1);
    l1.push_back(v1);

    int token=0;

    for(list<Vehiculo>::iterator it=l1.begin();it!=l1.end();it++){
        token += it->getLargoCM();
    }

    cout<<token<<endl;

    list<Vehiculo> l2[5];

    l2[0].push_back(v1);
    l2[0].push_back(v1);
    l2[4].push_back(v1);
    l2[3].push_back(v1);
    l2[2].push_back(v1);
    l2[1].push_back(v1);

    for (int i = 0; i <5 ; i++){
        cout <<l2[i].front().getTipo() <<l2[i].size() <<endl;
    }
    
    return 0;

}