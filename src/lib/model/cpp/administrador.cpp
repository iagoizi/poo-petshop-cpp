#include "../hpp/administrador.hpp"

/**/
Administrador::Administrador(PetShop *petshop, string nome) : Usuario(petshop, nome, ADMINISTRADOR, "admin", "admin", 0.0),
                                                              Vendedor(petshop, nome, "admin", "admin", 0.0),
                                                              Veterinario(petshop, nome, "admin", "admin", 0.0)
{
    /*instância os valores do objeto por meio do set*/
    this->setCargo(ADMINISTRADOR);
}

Administrador::~Administrador() {}

void Administrador::reposicaoEstoque(Produto produto, int qtd, string descricao, double preco)
{
    /*criando uma compra de acordo com as informações passadas por referência*/
    Compra compra = Compra(descricao, preco);
    /*pagando a compra feita*/
    compra.pagar();
    /*adicionando a compra feita ao vetor de compras*/
    this->petshop->getCompras().push_back(compra);
    /*percorrendo o vetor de produtos para realizar as devidas alterações*/
    for (vector<Produto>::iterator produtoEstoque = this->petshop->getProdutos().begin(); produtoEstoque != this->petshop->getProdutos().end(); produtoEstoque++)
    {
        /*verificando se o produto está presente no estoque*/
        if (produto == (*produtoEstoque))
        {
            /*alterando a quantidade de produtos*/
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
    /*criando uma conta*/
    Compra compra = Compra(equipamento, preco);
    /*chamando o método de pagamento*/
    compra.pagar();
    /*adicionando a compra ao vetor de compras*/
    this->petshop->getCompras().push_back(compra);
}

void Administrador::cadastrarVeterinario(string nome, string usuario, string senha, double salario)
{
    /*criando um novo veterinário de acordo com as informações passadas por referência*/
    Veterinario *veterinario = new Veterinario(this->petshop, nome, usuario, senha, salario);
    /*inserindo o veterinário no vetor de usuários*/
    this->petshop->getUsuarios().push_back(veterinario);
}

void Administrador::cadastrarVendedor(string nome, string usuario, string senha, double salario)
{
    /*criando um novo vendedor de acordo com as informações passadas por referência*/
    Vendedor *vendedor = new Vendedor(this->petshop, nome, usuario, senha, salario);
    /*inserindo o vendedor no vetor de usuários*/
    this->petshop->getUsuarios().push_back(vendedor);
}

void Administrador::cadastrarProduto(string nome, double preco, int quantidade, long id)
{
    /*criando um novo produto de acordo com as informações passadas por referência*/
    Produto produto = Produto(nome, preco, quantidade, id);
    /*inserindo o produto no vetor de produtos*/
    this->petshop->getProdutos().push_back(produto);
}

void Administrador::cadastrarServico(string nome, double preco, long id)
{
    /*criando um novo serviço de acordo com as informações passadas por referência*/
    Servico servico = Servico(nome, preco, id);
    /*inserindo o serviço no vetor de serviços*/
    this->petshop->getServicos().push_back(servico);
}

void Administrador::listarFuncionarios()
{
    /*percorrendo o vetor de usuário e realizando a impressão dos dados*/
    for (auto usuario : petshop->getUsuarios())
    {
        cout << *usuario << endl;
    }
}

void Administrador::gerarRelatorio()
{
    bool empty = true;

    /*verificando se o vetor ta vazio*/
    if (!petshop->getContas().empty())
    {
        empty = false;
        cout << "\t\tCONTAS" << endl
             << endl;
        /*percorrendo o vetor de contas e realizando a impressão*/
        for (auto conta : petshop->getContas())
        {
            cout << conta << endl;
        }
        cout << endl
             << endl;
    }

     /*verificando se o vetor ta vazio*/
    if (!petshop->getCompras().empty())
    {
        empty = false;
        cout << "\t\tCOMPRAS" << endl
             << endl;
        /*percorrendo o vetor de compras e realizando a impressão*/
        for (auto compra : petshop->getCompras())
        {
            cout << compra << endl;
        }
        cout << endl
             << endl;
    }
    /*verificando se o vetor ta vazio*/
    if (!petshop->getVendas().empty())
    {
        empty = false;
        cout << "\t\tVENDAS" << endl
             << endl;
        /*percorrendo o vetor de vendas e realizando a impressão*/
        for (auto venda : petshop->getVendas())
        {
            cout << venda << endl;
        }
        cout << endl
             << endl;
    }

    /*verificando se o vetor ta vazio*/
    if (!petshop->getHistoricoServico().empty())
    {
        empty = false;
        cout << setw(20) << "Data e hora |" << setw(7) << " idOrdem "
             << "|" << setw(7) << "idServiço"
             << "| " << setw(7) << "Preço"
             << "  | NomeServiço [Nome do cliente]" << endl;
        /*percorrendo o vetor de historico de serviços e realizando a impressão*/
        for (auto ordem : petshop->getHistoricoServico())
        {
            cout << ordem << endl;
        }
        cout << endl
             << endl;
    }

     /*verificando se o vetor ta vazio*/
    if (!petshop->getOrdemServico().empty())
    {
        empty = false;
        cout << "\t\tORDENS DE SERVIÇO (Serviços a serem realizados)" << endl
             << endl;
        cout << setw(20) << "Data e hora |" << setw(7) << " idOrdem "
             << "|" << setw(7) << "idServiço"
             << "| " << setw(7) << "Preço"
             << "  | NomeServiço [Nome do cliente]" << endl;
        /*percorrendo o vetor de ordens de serviços e realizando a impressão*/
        for (auto ordem : petshop->getOrdemServico())
        {
            cout << ordem << endl;
        }
        cout << endl
             << endl;
    }
    /*caso a vetor esteja vazio, não será mostrado nada na tela*/
    if (empty)
    {
        cout << "Nada para mostrar no relatório" << endl
             << endl;
    }
}

void Administrador::pagarConta(string descricao, Data dataVencimento, double valor)
{
    /*criando a conta de acordo com as informações passadas por referência*/
    Conta conta = Conta(descricao, dataVencimento, valor);
    /*chamando o método de pagamento*/
    conta.pagar();
    /*adicionando a conta paga ao vetor de contas*/
    this->petshop->getContas().push_back(conta);
}