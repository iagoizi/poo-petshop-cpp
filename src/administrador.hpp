#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "lib.hpp"

class Administrador : public Veterinario, Vendedor{

public:
    Administrador(string nome = "", string cargo = "", string usuario = "", string senha = "");
    ~Administrador();

    void reposicaoEstoque(Produto produto, int qtd);
    void comprarEquipamentos(string equipamento);
    void cadastrarVeterinario(Veterinario veterinario);
    void cadastrarVendedor(Vendedor vendedor);
    void gerarRelatorio();
    void pagarConta(Conta conta);
};

#endif