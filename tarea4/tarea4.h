using namespace std;


class vehiculo{
    public: 
        vehiculo();
        vehiculo(string a,int b,int c);
        int getLargoCM();
        int getPeso();
        Tipo getTipo();
        
};

class Transbordador{
    public:
        Transbordador();
        Transbordador(string a, string b, int c, int d, int e);
        void popVehiculo();
        int getLargoFila();
        int getPesoLibre();
        bool getTipo();
        bool pushVehiculo();

};