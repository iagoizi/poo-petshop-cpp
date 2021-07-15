#ifndef MENU_ADMINISTRADOR_HPP
#define MENU_ADMINISTRADOR_HPP

#include "../../model/hpp/petshop.hpp"
//#include "../../model/hpp/administrador.hpp"
#include "../../model/hpp/produto.hpp"
#include "../../model/hpp/servico.hpp"
#include "menu.hpp"
#include "menuVeterinario.hpp"
#include "menuVendedor.hpp"

/*Macros que gerenciam as funcionalidades do menu administrador*/
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
//Menu administrador herda funções do menu Vendedor e Veterinario
class MenuAdministrador : public MenuVendedor, public MenuVeterinario
{
    //private:
    //Tem o intuito de retornar os dados do administrador logado
    Administrador *getAdministrador();
    //Função resposavel pelo menu de cadastro de um novo vendedor
    void menuCadastrarVendedor();
    //Função resposavel pelo menu de cadastro de um novo veterinario
    void menuCadastrarVeterinario();
    //Função do menu para o cadastro de um novo produto
    void menuCadastrarProdutos();
    //Função do menu para o cadastro de um novo serviço
    void menuCadastrarServicos();
    //Menu da opção que lista todos os funionarios cadastrados no PetShop
    void menuListarFuncionarios();
    //Menu mostrado para a opção de repor o estoque
    void menuReporEstoque();
    //Menu que gerencia o pagamento das contas
    void menuPagamentoContas();
    //Menu que gera os relatorios
    void menuRelatorios();

public:
    //Construtor do menu administrador
    MenuAdministrador(PetShop *petshop);
    //Destrutor do menu administrador
    ~MenuAdministrador();
    //Função que mostra o menu
    virtual void printMenu();
    //Função que gerencia as decisões do usuario
    virtual void realizaOperacao(int op);
};
#endif