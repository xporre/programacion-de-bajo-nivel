#include<stdio.h>
int main(){
int i=0,e=0,a=0;
char tx[20], mtx[200], morse[]={".-", "-...", "-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-"},
 letras[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"," ",".",","};

printf("\ningrese su texto:");
scanf("%c",tx);

while (a<sizeof(tx))
{
    if (tx[e]==letras[i] )
    {
        printf(morse[i]);
        e+=1;
        i+=1;
        a+=1;
    }else{
        i+=1;
    }
    if (i==50)
    {
        break;
    }
    
}



return 0;
}