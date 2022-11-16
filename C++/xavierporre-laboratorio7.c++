#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;

void max_doble_element(int X[], int largo){

    doble ma1 = 0.0 , ma2 = 0.0;
    for( int i=0; i<=largo; i++ ){
        if( ma1<X[i]){ma1=X[i];} 
    }

    cout<<"1° numero mayor "<<ma1<<"\n";
    

}
bool comp(int a, int b) 
{ 
 return (a < b); 
} 


int main() 
{
//    cout<<"ingrese el largo de la lista como un numero"<<"\n";
//    int largo,b;
//     cin>>largo;
//     largo=largo;
//     int lista[largo];

//     for(int a; a<=largo ; a++){
//         cout<<"ingrese numero :"<<"\n";
//         cin>>b;
//         lista[a]=b;
//     }
//     max2(lista,largo);

    int i[]={1, 2, 3, 4, 5, 10, -1, 7};
    int* a=max_element(i,i+8,comp);
    cout << *a << "\n";


    return 0;
}

