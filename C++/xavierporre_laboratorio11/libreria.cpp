#include <iostream>
#include <list>


using namespace std;




class libro{
    public:
    string titulo; 
    string autor ;
    string editorial; 
    int numeroPaginas; 
    list<string> comentarios;
    int sumaPuntuaciones=0; 
    int cantidadPuntuaciones=0 ;

    libro();
    libro(string titulo, string autor, string editorial,int numeroPaginas );

    void agregaComentario (string a){comentarios.push_back(a);}
    
    void agregarPuntuaciones(int a){
        sumaPuntuaciones += a;
        cantidadPuntuaciones ++;
    }

    int getPuntuacion(){return sumaPuntuaciones/cantidadPuntuaciones;}

};

class clientes{
    public:
    string nombre ;
    string apellido; 
    int rut ;
    char dv ;
    int celular ;
    string email ;
    list<libro> libros ;

    clientes();
    clientes(string nombre, string apellido, int rut, char dv, int celular, string email);

    string getRut(){
        string token = rut + "-" + dv;
        return token;
    }
    void compraLibro(libro a){
        libros.push_back(a);
    } 
    int numeroLibros(){
        return libros.size();
    }




};
