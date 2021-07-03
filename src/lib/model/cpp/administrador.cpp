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
    cout << "DENTRO DA FUNÇÃO REPOSIÇÃO DE ESTOQUE\n";
    cout << "Quantidade do produto antes de setar: \n"
         << produto.getQuantidade();
    produto.setQuantidade(produto.getQuantidade() + qtd);
    cout << "Quantidade do produto antes de setar: \n"
         << produto.getQuantidade();
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

    if (!petshop->getContas().empty())
    {
        cout << "\t\tCONTAS" << endl;
        for (auto conta : petshop->getContas())
        {
            cout << conta << endl;
        }
    }
    if (!petshop->getCompras().empty())
    {
        cout << "\t\tCOMPRAS" << endl;
        for (auto compra : petshop->getCompras())
        {
            cout << compra << endl;
        }
    }
    if (!petshop->getVendas().empty())
    {
        cout << "\t\tVENDAS" << endl;
        for (auto venda : petshop->getVendas())
        {
            cout << venda << endl;
        }
    }

    if (!petshop->getServicos().empty())
    {
        cout << "\t\tSERVICOS" << endl;
        for (auto servico : petshop->getServicos())
        {
            cout << servico << endl;
        }
    }
}

void Administrador::pagarConta(string descricao, Data dataVencimento, double valor)
{
    Conta conta = Conta(descricao, dataVencimento, valor);
    conta.pagar();
    this->petshop->getContas().push_back(conta);
}