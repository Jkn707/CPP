#include <iostream>
#include <string>
#include <limits>
#include <cctype> 

using namespace std;

// Vuelo class

class Articulo{
    public:
    string name;
    long long price;
    long long id;
    int existencias;
    float tax_factor;

    Articulo(string name, long long price, long long id, int existencias, float tax_factor){
        this->name = name;
        this->price = price;
        this->id = id;
        this->existencias = existencias;
        this->tax_factor = tax_factor;
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
    ArticuloTecnologia(string name, long long price, long long id, int existencias, float tax_factor) : Articulo(name, price, id, existencias, tax_factor){}
};

class ArticuloDeporte : public Articulo{
    public:
    ArticuloDeporte(string name, long long price, long long id, int existencias, float tax_factor) : Articulo(name, price, id, existencias, tax_factor){}
};

class ArticuloExtranjero : public Articulo{
    public:
    ArticuloExtranjero(string name, long long price, long long id, int existencias, float tax_factor) : Articulo(name, price, id, existencias, tax_factor){}
};