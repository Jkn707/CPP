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
        Node* current2 = head;
        Node* new_node = new Node(Creator::createArticulo());

        while(current2 != NULL){
            if (current2->articulo->id == new_node->articulo->id || current2->articulo->name == new_node->articulo->name){
                cout << "Ya existe un artículo con este ID o nombre" << endl;
                return;
            }
            current2 = current2->next;
        }

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
        Node* current2 = head;
        Node* new_node;

        if (type == 1){
            new_node = new Node(new ArticuloTecnologia(name, price, id, existencias, tax));
        }else if (type == 2){
            new_node = new Node(new ArticuloDeporte(name, price, id, existencias, tax));
        }else{
            new_node = new Node(new ArticuloExtranjero(name, price, id, existencias, tax));
        }

        while(current2 != NULL){
            if (current2->articulo->id == new_node->articulo->id || current2->articulo->name == new_node->articulo->name){
                cout << "Ya existe un artículo con este ID o nombre" << endl;
                return;
            }
            current2 = current2->next;
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
        Node* current2 = head;
        string nextname;
        long long nextid;
        if (current == NULL){
            cout << "No hay artículos en el inventario." << endl;
        }else{
            while(current != NULL){
                if (current->articulo->id == id){
                    cout << "Ingrese el nuevo nombre del artículo" << endl;
                     while ((cin >> nextname)) {  
                     bool var1 = true;  
                     for (char c : nextname) {  
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
                  
                    cout << "Ingrese el nuevo precio del artículo" << endl;
                    while (!(cin >> current->articulo->price)) {  
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Error. Por favor, ingrese un número adecuado: ";
                    }
                  
                    cout << "Ingrese el nuevo ID del artículo" << endl;
                    while (!(cin >> nextid)) {  
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Error. Por favor, ingrese un número adecuado: ";
                    }
                  
                    cout << "Ingrese el nuevo número de existencias del artículo" << endl;
                    while (!(cin >> current->articulo->existencias)) {  
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Error. Por favor, ingrese un número adecuado: ";
                    }

                    while(current2 != NULL){
                        if (current2->articulo->id == nextid || current2->articulo->name == nextname){
                            cout << "Ya existe un artículo con este ID o nombre" << endl;
                            return;
                        }
                      current2 = current2->next;
                    }
                    current->articulo->name = nextname;
                    current->articulo->id = nextid;
                    cout << "Artículo modificado correctamente" << endl;
                    break;
                }
              current = current->next;
            }
            
        }
    }


    void DeleteItem(int id){
        Node* current = head;
        Node* prev;
        if (current == NULL){
            cout << "No hay artículos en el inventario." << endl;
        }else{
            while(current != NULL){
                if (current->articulo->id == id){
                  if(current == head){
                    head = head -> next;
                    cout << "Artículo eliminado" << endl;
                    return;
                  }
                  prev->next=current->next;
                  delete current;
                  cout << "Artículo eliminado" << endl;
                  return;
                }
                prev = current;
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
        cout << "----------------------------------" << endl;
        cout << "Nombre: " << current->articulo->name << endl;
        cout << "Precio: " << current->articulo->price << endl;
        cout << "ID: " << current->articulo->id << endl;
        cout << "Existencias: " << current->articulo->existencias << endl;

        if (dynamic_cast<ArticuloExtranjero*>(current->articulo) != NULL){
            cout << "Tipo: Extranjero" << endl;
        }
        if (dynamic_cast<ArticuloTecnologia*>(current->articulo) != NULL){
            cout << "Tipo: Tecnología" << endl;
        }
        if (dynamic_cast<ArticuloDeporte*>(current->articulo) != NULL){
            cout << "Tipo: Deporte" << endl;
        }
        cout << "----------------------------------" << endl;
        cout << endl;
        current = current->next;

    }
  }
  

}

};