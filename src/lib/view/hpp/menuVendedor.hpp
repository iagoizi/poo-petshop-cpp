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
    /*Pergunta se o comprador possui cadastro e, em caso negativo, dá a opção de realizar o cadastro.*/
    Cliente compradorPossuiCadastro(Vendedor *vendedor);

protected:
    /*Faz as impressões, entradas e saídas referentes ao cadastro do cliente*/
    Cliente menuCadastrarCliente();
    /*Faz as impressões, entradas e saídas referentes à venda de um produto*/
    void menuVenderProduto();
    /*Faz as impressões, entradas e saídas referentes à venda/agendamento de um serviço*/
    void menuVenderServico();

public:
    MenuVendedor(PetShop *petshop);
    ~MenuVendedor();
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif