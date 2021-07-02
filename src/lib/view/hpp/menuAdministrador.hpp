#ifndef MENU_ADMINISTRADOR_HPP
#define MENU_ADMINISTRADOR_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/petshop.hpp"
#include "../../model/hpp/administrador.hpp"
#include "../../model/hpp/produto.hpp"
#include "../../model/hpp/servico.hpp"
#include "menu.hpp"

#define CADASTRAR_VENDEDOR 1
#define CADASTRAR_VETERINARIO 2
#define CADASTRAR_PRODUTOS 3
#define CADASTRAR_SERVICOS 4
#define LISTAR_FUNCIONARIOS 5
#define REPOR_ESTOQUE 6 
#define PAGAR_CONTAS 7
#define GERAR_RELATORIOS 8
using namespace std;
class Administrador;
class MenuAdministrador : virtual public Menu{
    Administrador* getAdministrador();
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