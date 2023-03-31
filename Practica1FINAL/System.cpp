#include "Menu.cpp"

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
                            Inventory = admin.AgregarArticulo(Inventory);
                            break;
                        case 2:
                            Inventory = admin.ModificarArticulo(Inventory);
                            break;
                        case 3:
                            Inventory = admin.EliminarArticulo(Inventory);
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
                            Carrito = cliente.Comprar(Inventory, Carrito);
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