#include "Node.cpp"

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


    void AddAtTail(string name, long long price, long long id, int existencias, float tax, int type){
        Node* current = head;
        Node* new_node;

        if (type == 1){
            new_node = new Node(new ArticuloTecnologia(name, price, id, existencias, tax));
        }else if (type == 2){
            new_node = new Node(new ArticuloDeporte(name, price, id, existencias, tax));
        }else{
            new_node = new Node(new ArticuloExtranjero(name, price, id, existencias, tax));
        }

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
                    if (current == head){
                        head = head->next;
                    }
                    delete current;
                    cout << "Artículo eliminado." << endl;
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
        cout << "----------------------------------" << endl;
        cout << "No hay articulos en el inventario." << endl;
        cout << "----------------------------------" << endl;
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