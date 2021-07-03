#ifndef MENU_ADMINISTRADOR_HPP
#define MENU_ADMINISTRADOR_HPP

#include "../../model/hpp/petshop.hpp"
//#include "../../model/hpp/administrador.hpp"
#include "../../model/hpp/produto.hpp"
#include "../../model/hpp/servico.hpp"
#include "menu.hpp"
#include "menuVeterinario.hpp"
#include "menuVendedor.hpp"

#define CADASTRAR_CLIENTE_ADMIN 1
#define CADASTRAR_VENDEDOR 2
#define CADASTRAR_VETERINARIO 3
#define CADASTRAR_PRODUTOS_ADMIN 4
#define CADASTRAR_SERVICOS_ADMIN 5
#define VENDER_PRODUTO_ADMIN 6
#define VENDER_SERVICO_ADMIN 7
#define LISTAR_FUNCIONARIOS 8
#define LISTAR_CLIENTES_ADMIN 9
#define LISTAR_ORDENS_SERVICO_ADMIN 10
#define REGISTRAR_TRATAMENTO_ADMIN 11
#define REPOR_ESTOQUE 12
#define PAGAR_CONTAS 13
#define GERAR_RELATORIOS 14

using namespace std;
class Administrador;
class MenuAdministrador : public MenuVendedor, public MenuVeterinario
{
    //private:
    Administrador *getAdministrador();
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