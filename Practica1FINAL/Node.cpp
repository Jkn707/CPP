#include "Creator.cpp"

class Node{
    public:

    Articulo* articulo;
    Node* next;

    Node(Articulo* articulo){
        this->articulo = articulo;
        this->next = NULL;
    }
};