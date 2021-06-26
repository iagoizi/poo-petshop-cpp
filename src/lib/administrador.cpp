#include "administrador.hpp"

Administrador(PetShop petshop, string nome): nome(nome) {};
~Administrador();

void reposicaoEstoque(Produto produto, int qtd){
    cout << "Quantidade de produtos: " <<endl;
    cin << qtd;
    setQuantidade(qtd);
}

void comprarEquipamentos(string equipamento){

}

void cadastrarVeterinario(Veterinario veterinario){

}

void cadastrarVendedor(Vendedor vendedor);{

}

void gerarRelatorio(){

}

void pagarConta(Conta conta){

}