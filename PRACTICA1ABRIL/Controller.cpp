#include "LinkedList.cpp"

class Controller{

    public:

    static int catchInput(){
        int input;
        while (!(cin >> input)) {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error. Por favor, ingrese un número adecuado: ";
        }
        return input;
    }

    static LinkedList askforProductID(LinkedList Inventory, LinkedList Carrito){
        int input;
        int cantidad;
        bool empty = true;
        cout << "Ingrese el ID del producto que desea comprar" << endl;
        input = Controller::catchInput();

        Node* current = Inventory.head;
        while(current != NULL){
            if (current->articulo->id == input){
                cout << "Ingrese la cantidad de este artículo que desea" << endl;
                cantidad = Controller::catchInput();

                if(cantidad > current->articulo->existencias){
                    cout << "No hay suficientes existencias de este artículo" << endl;
                    empty = false;
                    break;
                }else{

                    if(dynamic_cast<ArticuloTecnologia*>(current->articulo) != NULL){
                        Carrito.AddAtTail(current->articulo->name, current->articulo->price, current->articulo->id, cantidad, current->articulo->tax_factor, 1);
                    }else if(dynamic_cast<ArticuloDeporte*>(current->articulo) != NULL){
                        Carrito.AddAtTail(current->articulo->name, current->articulo->price, current->articulo->id, cantidad, current->articulo->tax_factor, 2);
                    }else{
                        Carrito.AddAtTail(current->articulo->name, current->articulo->price, current->articulo->id, cantidad, current->articulo->tax_factor, 3);
                    }
                    current->articulo->existencias -= cantidad;
                    cout << "Artículo agregado al carrito" << endl;
                    empty = false;
                    break;
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

    return Carrito;


    }

    static void finishTransaction(LinkedList Carrito){
        Carrito.DisplayList();

        Node* current = Carrito.head;
        int total = 0;

        while(current != NULL){
            total += current->articulo->price * current->articulo->existencias;
            current = current->next;
        }

        current = Carrito.head;
        bool type_contiguo_tec = false;
        bool type_contiguo_dep = false;
        bool type_contiguo_ext = false;
        while (current->next != NULL){

            if ((dynamic_cast<ArticuloTecnologia*>(current->articulo) != NULL) && (dynamic_cast<ArticuloTecnologia*>(current->next->articulo) != NULL)){
                type_contiguo_tec = true;
            }
            if (dynamic_cast<ArticuloDeporte*>(current->articulo) != NULL && (dynamic_cast<ArticuloDeporte*>(current->next->articulo) != NULL)){
                type_contiguo_dep = true;
            }
            if ((dynamic_cast<ArticuloExtranjero*>(current->articulo) != NULL) && (dynamic_cast<ArticuloExtranjero*>(current->next->articulo) != NULL)){
                type_contiguo_ext = true;
            }
            current = current->next;
        }
        long long discount = total;

        if ((type_contiguo_tec)||(type_contiguo_dep)||(type_contiguo_ext)){
            discount -= discount * 0.1;
        }

        cout << "El total de su compra es de: " << total << endl;
        cout << "El total de su compra con descuento es de: " << discount << endl;

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