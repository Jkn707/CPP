#include "LinkedList.cpp"

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