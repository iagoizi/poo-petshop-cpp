#include "administrador.hpp"

Administrador(PetShop petshop, string nome)
{
    setNome(nome);
}

~Administrador();

void reposicaoEstoque(Produto produto, int qtd, string descricao, double preco){ // isso aqui tem que ser modificado no uml
    Compra compra = Compra(descricao, preco);
    compra.pagar();
    this->petshop.getCompras.add(compra);
    produto.setQuantidade(produto.getQuantidade() + qtd);
}

void comprarEquipamentos(string equipamento, double preco){ // isso aqui tem que ser modificado no uml
    Compra compra = Compra(equipamento, preco);
    compra.pagar();
    this->petshop.getCompras().push_back(compra);
    produto.setQuantidade(produto.getQuantidade() + qtd);
}

void cadastrarVeterinario(string nome, string usuario, string senha, double salario){ // isso aqui tem que ser modificado no uml
    Veterinario veterinario = Veterinario(this->petshop, nome, usuario, senha, salario);
    this->petshop.getUsuario().push_back(veterinario);
}

void cadastrarVendedor(string nome, string usuario, string senha, double salario){ // isso aqui tem que ser modificado no uml
    Vendedor vendedor = Vendedor(this->petshop, nome, usuario, senha, salario);
    this->petshop.getUsuario().push_back(vendedor);
}

void gerarRelatorio(){
    for(vector <Compra>::iterator i = petshop.compras.begin(); i!= petshop.compras.end(); i++){
       cout << *i << endl;
    }

    for(vector <Compra>::iterator j = petshop.vendas.begin(); j!= petshop.vendas.end(); j++){
       cout << *j << endl;
    }

    for(vector <Compra>::iterator k = petshop.historicoServicos.begin(); k!= petshop.historicoServicos.end(); k++){
       cout << *k << endl;
    }
}

void pagarConta(string descricao, Data dataVencimento, double valor){ // isso aqui tem que ser modificado no uml
    Conta conta = Conta(descricao, dataVencimento, valor);
    conta.pagar();
    this->petshop.getContas().push_back(conta);
}