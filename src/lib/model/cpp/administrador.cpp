#include "../hpp/administrador.hpp"

Administrador::Administrador(PetShop *petshop, string nome) : Usuario(petshop, nome, ADMINISTRADOR, "admin", "admin", 0.0),
                                                              Vendedor(petshop, nome, "admin", "admin", 0.0),
                                                              Veterinario(petshop, nome, "admin", "admin", 0.0)
{
    this->setCargo(ADMINISTRADOR);
}

Administrador::~Administrador() {}

void Administrador::reposicaoEstoque(Produto produto, int qtd, string descricao, double preco)
{
    Compra compra = Compra(descricao, preco);
    compra.pagar();
    this->petshop->getCompras().push_back(compra);
    for (vector<Produto>::iterator produtoEstoque = this->petshop->getProdutos().begin(); produtoEstoque != this->petshop->getProdutos().end(); produtoEstoque++)
    {
        if (produto == (*produtoEstoque))
        {
            produtoEstoque->setQuantidade(produtoEstoque->getQuantidade() + qtd);
            if (produtoEstoque->getQuantidade() < 0)
            {
                produtoEstoque->setQuantidade(0);
            }
        }
    }
}

void Administrador::comprarEquipamentos(string equipamento, double preco, int qtd)
{
    Compra compra = Compra(equipamento, preco);
    compra.pagar();
    this->petshop->getCompras().push_back(compra);
}

void Administrador::cadastrarVeterinario(string nome, string usuario, string senha, double salario)
{
    Veterinario *veterinario = new Veterinario(this->petshop, nome, usuario, senha, salario);
    this->petshop->getUsuarios().push_back(veterinario);
}

void Administrador::cadastrarVendedor(string nome, string usuario, string senha, double salario)
{
    Vendedor *vendedor = new Vendedor(this->petshop, nome, usuario, senha, salario);
    this->petshop->getUsuarios().push_back(vendedor);
}
void Administrador::cadastrarProduto(string nome, double preco, int quantidade, long id)
{
    Produto produto = Produto(nome, preco, quantidade, id);
    this->petshop->getProdutos().push_back(produto);
}
void Administrador::cadastrarServico(string nome, double preco, long id)
{
    Servico servico = Servico(nome, preco, id);
    this->petshop->getServicos().push_back(servico);
}
void Administrador::listarFuncionarios()
{
    for (auto usuario : petshop->getUsuarios())
    {
        cout << *usuario << endl;
    }
}

void Administrador::gerarRelatorio()
{
    bool empty = true;

    if (!petshop->getContas().empty())
    {
        empty = false;
        cout << "\t\tCONTAS" << endl
             << endl;
        for (auto conta : petshop->getContas())
        {
            cout << conta << endl;
        }
        cout << endl
             << endl;
    }

    if (!petshop->getCompras().empty())
    {
        empty = false;
        cout << "\t\tCOMPRAS" << endl
             << endl;
        for (auto compra : petshop->getCompras())
        {
            cout << compra << endl;
        }
        cout << endl
             << endl;
    }

    if (!petshop->getVendas().empty())
    {
        empty = false;
        cout << "\t\tVENDAS" << endl
             << endl;
        for (auto venda : petshop->getVendas())
        {
            cout << venda << endl;
        }
        cout << endl
             << endl;
    }

    if (!petshop->getHistoricoServico().empty())
    {
        empty = false;
        cout << setw(20) << "Data e hora |" << setw(7) << " idOrdem "
             << "|" << setw(7) << "idServiço"
             << "| " << setw(7) << "Preço"
             << "  | NomeServiço [Nome do cliente]" << endl;
        for (auto ordem : petshop->getHistoricoServico())
        {
            cout << ordem << endl;
        }
        cout << endl
             << endl;
    }

    if (!petshop->getOrdemServico().empty())
    {
        empty = false;
        cout << "\t\tORDENS DE SERVIÇO (Serviços a serem realizados)" << endl
             << endl;
        cout << setw(20) << "Data e hora |" << setw(7) << " idOrdem "
             << "|" << setw(7) << "idServiço"
             << "| " << setw(7) << "Preço"
             << "  | NomeServiço [Nome do cliente]" << endl;
        for (auto ordem : petshop->getOrdemServico())
        {
            cout << ordem << endl;
        }
        cout << endl
             << endl;
    }

    if (empty)
    {
        cout << "Nada para mostrar no relatório" << endl
             << endl;
    }
}

void Administrador::pagarConta(string descricao, Data dataVencimento, double valor)
{
    Conta conta = Conta(descricao, dataVencimento, valor);
    conta.pagar();
    this->petshop->getContas().push_back(conta);
}