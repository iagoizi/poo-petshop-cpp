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
/*Macros para opções do menu veterinário*/
#define REGISTRAR_TRATAMENTO 1
#define LISTAR_CLIENTES 2
#define LISTAR_ORDENS_SERVICO 3
#define BUSCAR_ORDENS_SERVICO 4
using namespace std;

class MenuVeterinario : virtual public Menu
{
    /*Pega os dados do usuário logado na sessão*/
    Veterinario *getVeterinario();

protected:
    /*Menu para realizar o registro de um tratamento*/
    void menuRegistrarTratamento();
    /*Menu para fazer a listagem das ordens de serviço cadastradas no sistema*/
    void menuListarOrdensDeServicos();
    /*Menu para fazer a listagem dos serviços cadastrados no sistema*/
    void menuBuscarOrdensDeServico();
    /*Menu para fazer a listagem dos clientes cadastrados no sistema*/
    void menuListarClientes();
public:
    /*Construtor de MenuVeterinario*/
    MenuVeterinario(PetShop *petshop);
    /*Destrutor de MenuVeterinario*/
    ~MenuVeterinario();
    /*Saída com as opções de operações do usuário veterinário*/
    virtual void printMenu();
    /*Executa a operação escolhida pelo usuário veterinário*/
    virtual void realizaOperacao(int op);
};
#endif