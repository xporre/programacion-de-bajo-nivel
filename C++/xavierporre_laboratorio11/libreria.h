using namespace std;


class libro{
    public:

    libro();
    libro(string titulo, string autor, string editorial,int numeroPaginas );

    void agregaComentario (string a);
    
    void agregarPuntuaciones(int a);

    int getPuntuacion();
};

class clientes{
    public:
    clientes();
    clientes(string nombre, string apellido, int rut, char dv, int celular, string email);

    string getRut();
    void compraLibro(libro a); 
    int numeroLibros();


};
