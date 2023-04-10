#include "Usuario.cpp"

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