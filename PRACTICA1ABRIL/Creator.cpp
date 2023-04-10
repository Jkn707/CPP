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
        while ((cin >> name)) {  
        bool var1 = true;  
        for (char c : name) {  
            if (!isalpha(c)) {  
                var1 = false;  
                break;  
            }
        }
        if (var1) {  
            break;
        }
        cout << "Error. Por favor, ingrese una cadena de letras: ";
        }

        cout << "Ingrese el precio del artículo" << endl;
        while (!(cin >> price)) {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error. Por favor, ingrese un número adecuado: ";
        }

        cout << "Ingrese el ID del artículo" << endl;
        while (!(cin >> id)) {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error. Por favor, ingrese un número adecuado: ";
        }
      
        cout << "Ingrese el número de existencias del artículo" << endl;
        while (!(cin >> existencias)) {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error. Por favor, ingrese un número adecuado: ";
        }
      
        cout << "Ingrese el tipo de artículo (1 = Tecnología, 2 = Deporte, 3 = Extranjero)" << endl;
        while ((cin >> type), type != 1 && type != 2 && type != 3) {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Por favor ingresar un tipo adecuado: ";
        }

        Articulo* articulo;

        if (type == 1){
            articulo = new ArticuloTecnologia(name, price, id, existencias, 0);
        }else if (type == 2){
            articulo = new ArticuloDeporte(name, price, id, existencias, 0);
        }else if (type == 3){
            articulo = new ArticuloExtranjero(name, price, id, existencias, 0.05);
        }
      
        articulo->price += articulo->price * articulo->tax_factor;

        return articulo;
    }
    
};