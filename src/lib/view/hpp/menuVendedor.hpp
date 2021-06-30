#ifndef MENU_VENDEDOR_HPP
#define MENU_VENDEDOR_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/petshop.hpp"
#include "../../model/hpp/usuario.hpp"
#include "menu.hpp"

using namespace std;

class MenuVendedor : virtual public Menu
{
protected:
    void menuCadastrarCliente();
    void menuVenderProduto();
    void menuVenderServico();

public:
    MenuVendedor(PetShop *petshop);
    ~MenuVendedor();
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif