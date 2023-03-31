#include "Articulo.cpp"

class Creator{
    public:
    static Articulo* createArticulo(){
        string name;
        long long price;
        long long id;
        int type;
        int existencias;

        cout << "Ingrese el nombre del artículo" << endl;
        cin >> name;
        cout << "Ingrese el precio del artículo" << endl;
        cin >> price;
        cout << "Ingrese el ID del artículo" << endl;
        cin >> id;
        cout << "Ingrese el número de existencias del artículo" << endl;
        cin >> existencias;
        cout << "Ingrese el tipo de artículo (1 = Tecnología, 2 = Deporte)" << endl;
        cin >> type;



        Articulo* articulo;

        if (type == 1){
            articulo = new ArticuloTecnologia(name, price, id, existencias);
        }else{
            articulo = new ArticuloDeporte(name, price, id, existencias);
        }

        return articulo;
    }

    
};