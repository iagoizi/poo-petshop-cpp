#ifndef MENU_ADMINISTRADOR_HPP
#define MENU_ADMINISTRADOR_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/petshop.hpp"
#include "../../model/hpp/usuario.hpp"
#include "menu.hpp"

using namespace std;

class MenuAdministrador : virtual public Menu
{
private:
    void menuCadastrarCliente();
    void menuCadastrarVendedor();
    void menuCadastrarVeterinario();
    void menuCadastrarProdutos();
    void menuCadastrarServicos();
    void menuListarFuncionarios();
    void menuReporEstoque();
    void menuPagamentoContas();
    void menuRelatorios();

public:
    MenuAdministrador(PetShop *petshop);
    ~MenuAdministrador();
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif