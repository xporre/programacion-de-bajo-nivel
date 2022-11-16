using namespace std;


class soldado{
    public:

        string name;
        int HP;
        double campo;
        double torre;
        double camaras;
        double trinchera;
        double perros;

        void exito(){}
        void fracaso(){}
        void HP_barre(){}
        void curar(soldado a){}
        
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
};
class med:public soldado{
    public:

        med(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){}
};
class generic:public soldado{
    public:  
        generic(string a,int b,double c,double d,double e,double f,double g):soldado(a,b,c,d,e,f,g){}
};
class def_torre{
    public:
        string nombre;
        char t_defensa;


        double Set_Prob(){double a; return a;}

        def_torre(){};

        def_torre(string b,char c){
            nombre = b;
            t_defensa = c;            
        }
       
};

