#include <iostream>

using namespace std;

//
//
// Vuelo class
//

class Articulo{
    public:
    string name;
    long long price;
    long long id;
    int existencias;

    Articulo(string name, long long price, long long id, int existencias){
        this->name = name;
        this->price = price;
        this->id = id;
        this->existencias = existencias;
    }

    virtual ~Articulo(){}

    // Se deben agregar los métodos de la clase Articulo
    string getName(){
        return name;
    }

    long long getPrice(){
        return price;
    }

    long long getId(){
        return id;
    }

    int getExistencias(){
        return existencias;
    }

    void setName(string name){
        this->name = name;
    }

    void setPrice(long long price){
        this->price = price;
    }

    void setId(long long id){
        this->id = id;
    }

    void setExistencias(int existencias){
        this->existencias = existencias;
    }
};

class ArticuloTecnologia : public Articulo{
    public:
    ArticuloTecnologia(string name, long long price, long long id, int existencias) : Articulo(name, price, id, existencias){}
};

class ArticuloDeporte : public Articulo{
    public:
    ArticuloDeporte(string name, long long price, long long id, int existencias) : Articulo(name, price, id, existencias){}
};

//
//
// Creator class
//
//

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



//
//
// Node class
//
//


class Node{
    public:

    Articulo* articulo;
    Node* next;

    Node(Articulo* articulo){
        this->articulo = articulo;
        this->next = NULL;
    }
};

//
//
// LinkedList class
//
//


class LinkedList{

  public: 

  LinkedList(){};

    Node* head = NULL;

    void AddAtHead(){
        Node* current = head;
        Node* new_node = new Node(Creator::createArticulo());

        if (current == NULL){
            head = new_node;
        }else{
            Node* temp = head;
            head = new_node;
            new_node->next = temp;
        }

    };

    void AddAtTail(){
        Node* current = head;
        Node* new_node = new Node(Creator::createArticulo());

        if (current == NULL){
            head = new_node;
        }else{
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new_node;
        }

    };


    void AddAtTail(string name, long long price, long long id, int existencias){
        Node* current = head;
        Node* new_node = new Node(new Articulo(name, price, id, existencias));

        if (current == NULL){
            head = new_node;
        }else{
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new_node;
        }

        Node* temp = head;
        Node* temp2 = head;
            
            while(temp->next != NULL){
            if (dynamic_cast<ArticuloTecnologia*>(temp->next->articulo) != NULL && dynamic_cast<ArticuloDeporte*>(temp->articulo) != NULL){
                temp2 = temp->next;
                temp->next = temp2->next;
                temp2->next = temp;
                temp = temp2;
            }
            temp = temp->next;
        }

    };

    void ModifyItem(int id){
        Node* current = head;
        if (current == NULL){
            cout << "No hay artículos en el inventario." << endl;
        }else{
            while(current != NULL){
                if (current->articulo->id == id){
                    cout << "Ingrese el nuevo nombre del artículo" << endl;
                    cin >> current->articulo->name;
                    cout << "Ingrese el nuevo precio del artículo" << endl;
                    cin >> current->articulo->price;
                    cout << "Ingrese el nuevo ID del artículo" << endl;
                    cin >> current->articulo->id;
                    cout << "Ingrese el nuevo número de existencias del artículo" << endl;
                    cin >> current->articulo->existencias;
                    break;
                }
                current = current->next;
            }
        }
    }

    void DeleteItem(int id){
        Node* current = head;
        if (current == NULL){
            cout << "No hay artículos en el inventario." << endl;
        }else{
            while(current != NULL){
                if (current->articulo->id == id){
                    Node* temp = current->next;
                    delete current;
                    current = temp;
                    break;
                }
                current = current->next;
            }
        }
    }

    

    void PopFirst(){

        Node* current = head;
        if (current == NULL){
            cout << "No hay artículos en el inventario." << endl;
        }else{
            head = head->next;
            delete current;
        }
    }
    

  void DisplayList(){
    Node* current = head;
    if (current == NULL){
        cout << "No hay articulos en el inventario." << endl;
    }else{
      while(current != NULL){
        cout << "Nombre: " << current->articulo->name << endl;
        cout << "Precio: " << current->articulo->price << endl;
        cout << "ID: " << current->articulo->id << endl;

        if (dynamic_cast<ArticuloTecnologia*>(current->articulo) != NULL){
            cout << "Tipo: Tecnología" << endl;
        }else{
            cout << "Tipo: Deporte" << endl;
        }
        cout << endl;
        current = current->next;

    }
  }
  

}

};

class Controller{

    public:
    static int catchInput(){
        int input;
        cin >> input;
        return input;
    }

    static void askforProductID(LinkedList Inventory, LinkedList Carrito){
        int input;
        bool empty = true;
        cout << "Ingrese el ID del producto que desea comprar" << endl;
        input = Controller::catchInput();

        Node* current = Inventory.head;
        while(current != NULL){
            if (current->articulo->id == input){
                int cantidad;
                cout << "Ingrese la cantidad de este artículo que desea" << endl;
                cantidad = Controller::catchInput();

                if(cantidad > current->articulo->existencias){
                    cout << "No hay suficientes existencias de este artículo" << endl;
                    break;
                }else{
                    Carrito.AddAtTail(current->articulo->name, current->articulo->price, current->articulo->id, cantidad);
                    current->articulo->existencias -= cantidad;
                    cout << "Artículo agregado al carrito" << endl;
                    break;
                    empty = false;
                }
            }
            current = current->next;
        }

        if (empty){
            cout << "No se encontró el artículo" << endl;
        }

        cout << "¿Desea agregar otro artículo? (1 = Sí, 2 = No)" << endl;
        int input2 = Controller::catchInput();
        if (input2 == 1){
            Controller::askforProductID(Inventory, Carrito);
    }


    }

    static void finishTransaction(LinkedList Carrito){
        Carrito.DisplayList();

        Node* current = Carrito.head;
        int total = 0;

        while(current != NULL){
            total += current->articulo->price * current->articulo->existencias;
            current = current->next;
        }

        cout << "¿Desea confirmar la compra? (1 = Sí, 2 = No)" << endl;
        int input = Controller::catchInput();
        if (input == 1){
            cout << "Compra realizada con éxito" << endl;
            while(Carrito.head != NULL){
                Carrito.PopFirst();
            }
        }else{
            cout << "Compra cancelada" << endl;
        }

    }

};

class Usuario{
    public:

    Usuario(){

    }

    virtual ~Usuario(){}
};

class Cliente : public Usuario{
    public:

    Cliente(){
    }

    void Comprar(LinkedList Inventory, LinkedList Carrito){
        Inventory.DisplayList();
        Controller::askforProductID(Inventory, Carrito);
    }

    void Pagar(LinkedList Carrito){
        Controller::finishTransaction(Carrito);
    }
};

class Administrador : public Usuario{
    public:

    Administrador(){

    }

    void AgregarArticulo(LinkedList Inventory){
        Inventory.AddAtTail();
    }

    void ModificarArticulo(LinkedList Inventory){
        Inventory.DisplayList();
        cout << "Ingrese el ID del artículo que desea modificar" << endl;
        int input = Controller::catchInput();
        Inventory.ModifyItem(input);
    }

    void EliminarArticulo(LinkedList Inventory){
        Inventory.DisplayList();
        cout << "Ingrese el ID del artículo que desea eliminar" << endl;
        int input = Controller::catchInput();
        Inventory.DeleteItem(input);
    }

};

class Menu{
    public: 

    static void DisplayMainMenu(){

            cout << "Bienvenido" << endl;
            cout << "Tipo de usuario: " << endl;
            cout << "1. Administrador" << endl;
            cout << "2. Cliente" << endl;
            cout << "3. Salir" << endl;


        }
    
    static void DisplayAdminMenu(){

            cout << "Bienvenido, administrador." << endl;
            cout << "1. Agregar artículo" << endl;
            cout << "2. Modificar artículo" << endl;
            cout << "3. Eliminar artículo" << endl;
            cout << "4. Mostrar inventario" << endl;
            cout << "5. Salir" << endl;

        }

    static void DisplayClientMenu(){

            cout << "Bienvenido, cliente." << endl;
            cout << "1. Realizar compra" << endl;
            cout << "2. Realizar pago" << endl;
            cout << "3. Salir" << endl;

        }


};

//
//
// System Class
//
//

class System{

    public:
    Administrador admin;
    Cliente cliente;
    LinkedList Inventory;
    LinkedList Carrito;

    void run(){
        int input;
        bool runningmain = true;
        bool runningadmin = true;
        bool runningclient = true;
        while(runningmain){
            Menu::DisplayMainMenu();
            input = Controller::catchInput();
            switch(input){
                case 1:
                    while(runningadmin){
                    Menu::DisplayAdminMenu();
                    input = Controller::catchInput();
                    switch(input){
                        case 1:
                            admin.AgregarArticulo(Inventory);
                            break;
                        case 2:
                            admin.ModificarArticulo(Inventory);
                            break;
                        case 3:
                            admin.EliminarArticulo(Inventory);
                            break;
                        case 4:
                            Inventory.DisplayList();
                            break;
                        case 5:
                            runningadmin = false;
                            break;
                        default:
                            cout << "Opción inválida" << endl;
                            break;
                        }
                    }
                    break;
                case 2:
                    while(runningclient){
                    Menu::DisplayClientMenu();
                    input = Controller::catchInput();
                    switch(input){
                        case 1:
                            cliente.Comprar(Inventory, Carrito);
                            break;
                        case 2:
                            cliente.Pagar(Carrito);
                            break;
                        case 3:
                            runningclient = false;
                            break;
                        default:
                            cout << "Opción inválida" << endl;
                            break;
                        }
                    }
                    break;
                case 3:
                    runningmain = false;
                    break;
                default:
                    cout << "Opción inválida" << endl;
                    break;
            }
        }
    }

};

int main(){
    System system;
    system.run();
    return 0;
}