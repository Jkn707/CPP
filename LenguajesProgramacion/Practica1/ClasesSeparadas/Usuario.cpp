#include "Controller.cpp"

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