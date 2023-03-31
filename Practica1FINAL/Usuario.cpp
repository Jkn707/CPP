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

    LinkedList Comprar(LinkedList Inventory, LinkedList Carrito){
        Inventory.DisplayList();
        Carrito = Controller::askforProductID(Inventory, Carrito);
        return Carrito;
    }

    void Pagar(LinkedList Carrito){
        Controller::finishTransaction(Carrito);
    }
};

class Administrador : public Usuario{
    public:

    Administrador(){

    }

    LinkedList AgregarArticulo(LinkedList Inventory){
        Inventory.AddAtTail();
        return Inventory;
    }

    LinkedList ModificarArticulo(LinkedList Inventory){
        Inventory.DisplayList();
        cout << "Ingrese el ID del artículo que desea modificar" << endl;
        int input = Controller::catchInput();
        Inventory.ModifyItem(input);
        return Inventory;
    }

    LinkedList EliminarArticulo(LinkedList Inventory){
        Inventory.DisplayList();
        cout << "Ingrese el ID del artículo que desea eliminar" << endl;
        int input = Controller::catchInput();
        Inventory.DeleteItem(input);
        return Inventory;
    }

};