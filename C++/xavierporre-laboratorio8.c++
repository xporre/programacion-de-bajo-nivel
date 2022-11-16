#include <iostream>
using namespace std;

class persona{
private:
public:
    persona(string,int,string);

    string name;
    int age;
    string equipoF;
};

int main(){
    int largo,edad;
    string nombre, equipoF;

    cout<<"ingrese la cantidad de personas desea agregar"<<"\n";
    cin>>largo;
    

    persona *lista[largo];

    for(int i=0;i<largo;i++){
        cout<<"ingrese nombre"<<"\n";
        getline(cin,nombre);

        cout<<"ingrese edad"<<"\n";
        cin>>edad;

        cout<<"ingrese equipo de futbol"<<"\n";
        getline(cin,equipoF);

        lista[i] = new persona(nombre,edad,equipoF);
        
    }

    for (int i = 0; i < largo; i++)
    {
        cout << lista[i]->name<<lista[i]->age<<lista[i]->equipoF;
    }
    

}
