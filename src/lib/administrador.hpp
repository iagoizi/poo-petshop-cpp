#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "lib.hpp"

class Administrador : public Veterinario, public Vendedor
{

public:
    Administrador(PetShop petshop, string nome = "");
    ~Administrador();

    /*Incrementa uma certa quantidade do produto no estoque*/
    void reposicaoEstoque(Produto produto, int qtd);
    /*Registra que um determinado equipamento foi comprado neste momento*/
    void comprarEquipamentos(string equipamento);
    /*Cadastra um novo veterinário, o adicionando no vetor de usuários*/
    void cadastrarVeterinario(Veterinario veterinario);
    /*Cadastra um novo vendedor, o adicionando no vetor de usuários*/
    void cadastrarVendedor(Vendedor vendedor);
    /*Imprime um relatório com os históricos do sistema*/
    void gerarRelatorio();
    /*Registra que uma determinada conta foi paga neste exato momento*/
    void pagarConta(Conta conta);
};

#endif