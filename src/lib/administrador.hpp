#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "lib.hpp"

class Administrador : public Veterinario, public Vendedor
{

public:
    Administrador(PetShop petshop, string nome = "");
    ~Administrador();

    /*Incrementa uma certa quantidade do produto no estoque*/
    void reposicaoEstoque(Produto produto, int qtd, string descricao, double preco);
    /*Registra que um determinado equipamento foi comprado neste momento*/
    void comprarEquipamentos(string equipamento, double preco);
    /*Cadastra um novo veterinário, o adicionando no vetor de usuários*/
    void cadastrarVeterinario(string nome, string usuario, string senha, double salario);
    /*Cadastra um novo vendedor, o adicionando no vetor de usuários*/
    void cadastrarVendedor(string nome, string usuario, string senha, double salario)
    /*Imprime um relatório com os históricos do sistema*/
    void gerarRelatorio();
    /*Registra que uma determinada conta foi paga neste exato momento*/
    void pagarConta(string descricao, Data dataVencimento, double valor);
};

#endif