#include "../hpp/administrador.hpp"

Administrador::Administrador(PetShop *petshop, string nome) : Usuario(petshop, nome, ADMINISTRADOR, "admin", "admin", 0.0),
                                                              Vendedor(petshop, nome, "admin", "admin", 0.0),
                                                              Veterinario(petshop, nome, "admin", "admin", 0.0)
{
    this->setCargo(ADMINISTRADOR);
}

Administrador::~Administrador() {}

void Administrador::reposicaoEstoque(Produto produto, int qtd, string descricao, double preco)
{ // isso aqui tem que ser modificado no uml
    Compra compra = Compra(descricao, preco);
    compra.pagar();
    this->petshop->getCompras().push_back(compra);
    produto.setQuantidade(produto.getQuantidade() + qtd);
}

void Administrador::comprarEquipamentos(string equipamento, double preco, int qtd)
{ // isso aqui tem que ser modificado no uml
    Compra compra = Compra(equipamento, preco);
    compra.pagar();
    this->petshop->getCompras().push_back(compra);
}

void Administrador::cadastrarVeterinario(string nome, string usuario, string senha, double salario)
{ // isso aqui tem que ser modificado no uml
    Veterinario veterinario = Veterinario(this->petshop, nome, usuario, senha, salario);
    this->petshop->getUsuarios().push_back(veterinario);
}

void Administrador::cadastrarVendedor(string nome, string usuario, string senha, double salario)
{ // isso aqui tem que ser modificado no uml
    Vendedor vendedor = Vendedor(this->petshop, nome, usuario, senha, salario);
    this->petshop->getUsuarios().push_back(vendedor);
}

void Administrador::gerarRelatorio()
{
    for (auto itemCompras : petshop->getCompras())
    {
        cout << itemCompras << endl;
    }

    for (auto itemVendas : petshop->getVendas())
    {
        cout << itemVendas << endl;
    }

    for (auto itemServicos : petshop->getHistoricoServico())
    {
        cout << itemServicos << endl;
    }

    /*
    for(vector <Compra>::iterator i = petshop.compras.begin(); i!= petshop.compras.end(); i++){
       cout << *i << endl;
    }

    for(vector <Compra>::iterator j = petshop.vendas.begin(); j!= petshop.vendas.end(); j++){
       cout << *j << endl;
    }

    for(vector <Compra>::iterator k = petshop.historicoServicos.begin(); k!= petshop.historicoServicos.end(); k++){
       cout << *k << endl;
    }*/
}

void Administrador::pagarConta(string descricao, Data dataVencimento, double valor)
{ // isso aqui tem que ser modificado no uml
    Conta conta = Conta(descricao, dataVencimento, valor);
    conta.pagar();
    this->petshop->getContas().push_back(conta);
}