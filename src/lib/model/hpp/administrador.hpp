#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "lib.hpp"
#include "vendedor.hpp"
#include "veterinario.hpp"
#include "petshop.hpp"
#include "usuario.hpp"

class Administrador : public Vendedor, public Veterinario
{

public:
    Administrador(PetShop *petshop, string nome = "");
    ~Administrador();

    /*Incrementa uma certa quantidade do produto no estoque*/
    void reposicaoEstoque(Produto produto, int qtd, string descricao, double preco);
    /*Registra que um determinado equipamento foi comprado neste momento*/
    void comprarEquipamentos(string equipamento, double preco, int qtd);
    /*Cadastra um novo veterinário, o adicionando no vetor de usuários*/
    void cadastrarVeterinario(string nome, string usuario, string senha, double salario);
    /*Cadastra um novo vendedor, o adicionando no vetor de usuários*/
    void cadastrarVendedor(string nome, string usuario, string senha, double salario);
    /*Cadastra um novo produto, o adicionando no vetor de produtos cadastrados*/
    void cadastrarProduto(string nome, double preco, int quantidade, long id);
    /*Cadastra um novo servico, o adicionando no vetor de servicos*/
    void cadastrarServico(string nome, double preco, long id);
    /*Cadastra um novo vendedor, o adicionando no vetor de usuários*/
    void listarFuncionarios();
    /*Imprime um relatório com os históricos do sistema*/
    void gerarRelatorio();
    /*Registra que uma determinada conta foi paga neste exato momento*/
    void pagarConta(string descricao, Data dataVencimento, double valor);
};

#endif