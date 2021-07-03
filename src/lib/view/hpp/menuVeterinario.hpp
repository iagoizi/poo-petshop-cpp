#ifndef MENU_VETERINARIO
#define MENU_VETERINARIO
#include "menu.hpp"
#include "../../model/hpp/petshop.hpp"
#include "../../model/hpp/veterinario.hpp"
#include "../../model/hpp/vendedor.hpp"
#include "../../model/hpp/administrador.hpp"
#include "../../model/hpp/cliente.hpp"
#include "../../model/hpp/servico.hpp"
#include "../../model/hpp/ordemservico.hpp"

#define REGISTRAR_TRATAMENTO 1
#define LISTAR_CLIENTES 2
#define LISTAR_ORDENS_SERVICO 3
#define BUSCAR_ORDENS_SERVICO 4
using namespace std;

class MenuVeterinario : virtual public Menu
{
    Veterinario *getVeterinario();

protected:
    void menuRegistrarTratamento();
    void menuListarOrdensDeServicos();
    void menuBuscarOrdensDeServico();
    void menuListarClientes();

public:
    MenuVeterinario(PetShop *petshop);
    ~MenuVeterinario();
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif