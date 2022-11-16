#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Vehiculo{
    public: 
    string marca;
    int largoCM;
    int peso_kg;
    enum Tipo {auto,camion,bus,ambulancia};
    Vehiculo();
    Vehiculo(string a,int b,int c,Tipo tipo){
        marca = a;
        largoCM = b;
        peso_kg = c;
        Tipo=tipo;
    }

    int getLargoCM(){
        return largoCM;
    }
    int getPeso(){ 
        return peso_kg;
    }
    
};



class Transbordador{

    public:
        string Nombre;
        string puertoActual;
        int capacidad_de_cargar;
        int cantidad_filas;
        int largo_fila;
        list<Vehiculo> f0;
        list<Vehiculo> f1;
        list<Vehiculo> f2;
        list<Vehiculo> f3;
        list<Vehiculo> f4;


        Transbordador(){}
        Transbordador(string a, string b, int c, int d, int e){
            Nombre = a;
            puertoActual = b;
            capacidad_de_cargar = c;
            cantidad_filas = d;
            largo_fila = e;
        }

        void popVehiculo(int fila){
            switch(fila){
                case 0:
                    f0.pop_front();
                break;
                case 1: 
                    f1.pop_front();
                break;
                case 2:
                    f2.pop_front(); 
                break;
                case 3:
                    f3.pop_front(); 
                break;
                case 4:
                    f4.pop_front(); 
                break;
                
            }
            
        }

        int getLargoFila(int fila) {
             switch(fila){
                case 0:
                    return f0.size();
                break;
                case 1: 
                    return f1.size();
                break;
                case 2:
                    return f2.size(); 
                break;
                case 3:
                    return f3.size(); 
                break;
                case 4:
                    return f4.size(); 
                break;
                
            }
        }
        int getEspacioLibre(int fila){
            
            switch(fila){
                int t;
                case 0:
                    if(getLargoFila(fila)==0){
                        return largo_fila;
                    }else{
                        for(list<Vehiculo>::iterator it=f0.begin();it!=f0.end();it++){
                            t += it->getLargoCM();
                        }
                        int libre =largo_fila - t+15*getLargoFila(fila);
                        return libre;
                    }
                break;
                case 1:
                    if(getLargoFila(fila)==0){
                        return largo_fila;
                    }else{
                        for(list<Vehiculo>::iterator it=f1.begin();it!=f1.end();it++){
                            t += it->getLargoCM();
                        }
                        int libre =largo_fila - t+15*getLargoFila(fila);
                        return libre;
                    }
                break;
                case 2:
                    if(getLargoFila(fila)==0){
                        return largo_fila;
                    }else{
                        for(list<Vehiculo>::iterator it=f2.begin();it!=f2.end();it++){
                            t += it->getLargoCM();
                        }
                        int libre =largo_fila - t+15*getLargoFila(fila);
                        return libre;
                    }
                break;
                case 3:
                    if(getLargoFila(fila)==0){
                        return largo_fila;
                    }else{
                        for(list<Vehiculo>::iterator it=f3.begin();it!=f3.end();it++){
                            t += it->getLargoCM();
                        }
                        int libre =largo_fila - t+15*getLargoFila(fila);
                        return libre;
                    }
                break;
                case 4:
                    if(getLargoFila(fila)==0){
                        return largo_fila;
                    }else{
                        for(list<Vehiculo>::iterator it=f4.begin();it!=f4.end();it++){
                            t += it->getLargoCM();
                        }
                        int libre =largo_fila - t+15*getLargoFila(fila);
                        return libre;
                    }
                break;
            }

        }
        int getPesoLibre(){
            int token = 0;
            int t = 0 ;
                for(list<Vehiculo>::iterator it=f0.begin();it!=f0.end();it++){
                    t += it->getPeso();
                }
                for(list<Vehiculo>::iterator it=f1.begin();it!=f1.end();it++){
                    t += it->getPeso();
                }
                for(list<Vehiculo>::iterator it=f2.begin();it!=f2.end();it++){
                    t += it->getPeso();
                }
                for(list<Vehiculo>::iterator it=f3.begin();it!=f3.end();it++){
                    t += it->getPeso();
                }
                for(list<Vehiculo>::iterator it=f4.begin();it!=f4.end();it++){
                    t += it->getPeso();
                }

            return capacidad_de_cargar - t;

        }

        bool pushVehiculo(int fila , Vehiculo v){

             switch(fila){
                case 0:
                if(getEspacioLibre(fila)>v.getLargoCM() && getPesoLibre()>v.getPeso()){f0.push_back(v); return true;}
                else{return false;}                 
                break;
                case 1: 
                   if(getEspacioLibre(fila)>v.getLargoCM() && getPesoLibre()>v.getPeso()){f1.push_back(v); return true;}
                   else{return false;}
                break;
                case 2:
                    if(getEspacioLibre(fila)>v.getLargoCM() && getPesoLibre()>v.getPeso()){f2.push_back(v); return true;}
                    else{return false;} 
                break;
                case 3:
                    if(getEspacioLibre(fila)>v.getLargoCM() && getPesoLibre()>v.getPeso()){f3.push_back(v); return true;}
                    else{return false;} 
                break;
                case 4:
                    if(getEspacioLibre(fila)>v.getLargoCM() && getPesoLibre()>v.getPeso()){f4.push_back(v); return true;}
                    else{return false;} 
                break;
                
            }

        }        

};



int main(){
    //class vehiculo lista
    Vehiculo v1("onda",10,100,auto);

    Transbordador t1("t1","t2",1000,10,10000),t2;

    cout <<"largo "<<v1.getLargoCM()<<" y peso "<<v1.getPeso()<<endl;

    list<Vehiculo> l1;
    l1.push_back(v1);
    l1.push_back(v1);
    l1.push_back(v1);
    l1.push_back(v1);
    l1.push_back(v1);

    int token;

    for(list<Vehiculo>::iterator it=l1.begin();it!=l1.end();it++){
        token += it->getLargoCM();
    }

    cout<<token<<endl;



    return 0;

}