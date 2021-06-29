#include "../hpp/vendedor.hpp"
#include "../hpp/petshop.hpp"

Vendedor::Vendedor(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VENDEDOR, usuario, senha)
{
}

Vendedor::~Vendedor() {}

void Vendedor::cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf, vector<Compra> compras)
{ // mudar diagrama uml
    Cliente cliente = Cliente(nome, tipo_animal, nome_pet, endereco, telefone, cpf, compras);
    this->petshop->getClientes().push_back(cliente);
}

void Vendedor::vendaProduto(Cliente &cliente, vector<Produto> produtos)
{ //mudar diagrama uml
    string descricaoCompra = "";
    double preco = 0.0;

    vector<Produto>::iterator it;
    for (it = produtos.begin(); it != produtos.end(); it++)
    {
        descricaoCompra += to_string((*it).getQuantidade()) + "x " + (*it).getNome() + "(R$" + to_string((*it).getPreco()) + ")\n";
        preco += (*it).getPreco() * (*it).getQuantidade();
        vector<Produto>::iterator itEstoque;
        for (itEstoque = this->petshop->getProdutos().begin(); itEstoque != this->petshop->getProdutos().end(); itEstoque++)
        {
            if ((*it) == (*itEstoque))
            {
                (*itEstoque).setQuantidade((*itEstoque).getQuantidade() - (*it).getQuantidade());
                if ((*itEstoque).getQuantidade() < 0)
                {
                    (*itEstoque).setQuantidade(0);
                }
            }
        }
    }
    Compra venda = Compra(descricaoCompra, preco);
    venda.pagar();
    this->petshop->getVendas().push_back(venda);
    cliente.getCompras().push_back(venda);
}

void Vendedor::vendaServico(Cliente cliente, vector<Servico> servico, Data dataServico)
{
    vector<Servico>::iterator it;
    for (it = servico.begin(); it != servico.end(); it++)
    {
        for (auto itemVenda : servico)
        {
            if (itemVenda == (*it))
            {
                OrdemServico ordemservico = OrdemServico(itemVenda, cliente, dataServico, "");
                this->petshop->getOrdemServico().push_back(ordemservico);
            }
        }
    }
}