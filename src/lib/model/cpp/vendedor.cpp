#include "../hpp/vendedor.hpp"
#include "../hpp/petshop.hpp"

Vendedor::Vendedor(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VENDEDOR, usuario, senha, salario)
{
    setNome(nome);
}

Vendedor::~Vendedor() {}

Cliente Vendedor::cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf)
{
    Cliente cliente = Cliente(nome, tipo_animal, nome_pet, endereco, telefone, cpf);
    cout << this->petshop->getNome() << endl;
    this->petshop->getClientes().push_back(cliente);
    return cliente;
}

void Vendedor::vendaProduto(Cliente &cliente, vector<Produto> carrinho)
{
    string descricaoCompra = "";
    double preco = 0.0;

    vector<Produto>::iterator it;
    for (it = carrinho.begin(); it != carrinho.end(); it++)
    {
        //Transformando o valor do produto numa string com no máximo 2 casas decimais.
        string precoString = to_string((int)it->getPreco()) + "." + to_string((int)((it->getPreco() - ((int)it->getPreco())) * 100));
        //Adicionando a quantidade e o valor à descrição da compra
        descricaoCompra += to_string(it->getQuantidade()) + "x " + it->getNome() + " (R$" + precoString + " cada)";
        //Se ainda existirem mais produtos a serem adicionados...
        if (it->getId() != (carrinho.end() - 1)->getId())
        {
            descricaoCompra += ", ";
        }
        preco += it->getPreco() * it->getQuantidade();
        vector<Produto>::iterator produtoEstoque;
        for (produtoEstoque = this->petshop->getProdutos().begin(); produtoEstoque != this->petshop->getProdutos().end(); produtoEstoque++)
        {
            if ((*it) == (*produtoEstoque))
            {
                produtoEstoque->setQuantidade(produtoEstoque->getQuantidade() - it->getQuantidade());
                if (produtoEstoque->getQuantidade() < 0)
                {
                    produtoEstoque->setQuantidade(0);
                }
            }
        }
    }
    Compra venda = Compra(descricaoCompra, preco);
    venda.pagar();
    this->petshop->getVendas().push_back(venda);
    cliente.getCompras().push_back(venda);
}

void Vendedor::vendaServico(Cliente cliente, Servico servico, Data dataServico)
{
    OrdemServico ordemservico = OrdemServico(servico, cliente, dataServico, "");
    this->petshop->getOrdemServico().push_back(ordemservico);
}

Produto Vendedor::buscarProduto(long id, bool *success)
{
    for (auto produto : this->petshop->getProdutos())
    {
        if (produto.getId() == id)
        {
            *success = true;
            return produto;
        }
    }
    *success = false;
    return {};
}
void Vendedor::listarProdutos()
{
    cout << setw(7) << "id"
         << " | " << setw(7) << "Qtd"
         << " | " << setw(7) << " Preço"
         << "  | Nome" << endl;
    for (auto produto : this->petshop->getProdutos())
    {
        cout << produto << endl;
    }
    cout << endl;
}
Servico Vendedor::buscarServico(long id, bool *success)
{
    for (auto servico : this->petshop->getServicos())
    {
        if (servico.getId() == id)
        {
            *success = true;
            return servico;
        }
    }
    *success = false;
    return {};
}
void Vendedor::listarServicos()
{
    cout << setw(7) << "id"
         << " | " << setw(7) << "Preço"
         << "  | Nome" << endl;
    for (auto servico : this->petshop->getServicos())
    {
        cout << servico << endl;
    }
    cout << endl;
}