#include "../hpp/vendedor.hpp"
#include "../hpp/petshop.hpp"

Vendedor::Vendedor(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VENDEDOR, usuario, senha)
{
    setNome(nome);
}

Vendedor::~Vendedor() {}

void Vendedor::cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf)
{ // mudar diagrama uml
    cout << "AQUIIIIIIIIIII" << endl;
    Cliente cliente = Cliente(nome, tipo_animal, nome_pet, endereco, telefone, cpf);

    cout << "AQUIIIIIIIIIII_2" << endl;
    cout << getUsuario() << endl;
    cout << this->petshop->getNome() << endl;
    this->petshop->getClientes().push_back(cliente);

    cout << "AQUIIIIIIIIIII_3" << endl;
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
    for (auto produto : this->petshop->getProdutos())
    {
        cout << produto << endl;
    }
}