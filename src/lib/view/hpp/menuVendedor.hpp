#ifndef MENU_VENDEDOR_HPP
#define MENU_VENDEDOR_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/petshop.hpp"
#include "../../model/hpp/usuario.hpp"
#include "../../model/hpp/vendedor.hpp"
#include "menu.hpp"

#define CADASTRAR_CLIENTE 1
#define VENDER_PRODUTO 2
#define VENDER_SERVICO 3

using namespace std;

class MenuVendedor : virtual public Menu
{
    /*Pega o usuário logado no momento e faz um cast para que possamos acessar suas funcionalidades específicas*/
    Vendedor *getVendedor();
    Cliente compradorPossuiCadastro(Vendedor *vendedor);

protected:
    Cliente menuCadastrarCliente();
    void menuVenderProduto();
    void menuVenderServico();

public:
    MenuVendedor(PetShop *petshop);
    ~MenuVendedor();
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif