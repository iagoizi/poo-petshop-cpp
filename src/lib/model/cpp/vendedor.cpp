#include "../hpp/vendedor.hpp"
#include "../hpp/petshop.hpp"

Vendedor::Vendedor(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VENDEDOR, usuario, senha, salario)
{
    /*instância os valores do objeto por meio dos métodos setters*/
    setNome(nome);
}

Vendedor::~Vendedor() {}

Cliente Vendedor::cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, long telefone, long cpf)
{
    /*criando um novo cliente de acordo com as informações passadas por referência*/
    Cliente cliente = Cliente(nome, tipo_animal, nome_pet, endereco, telefone, cpf);
    cout << this->petshop->getNome() << endl;
    /*inserindo o cliente no vetor de cliente*/
    this->petshop->getClientes().push_back(cliente);
    return cliente;
}

void Vendedor::vendaProduto(Cliente &cliente, vector<Produto> carrinho)
{
    string descricaoCompra = "";
    double preco = 0.0;

    vector<Produto>::iterator it;
    //percorre o vetor de produtos
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
        //percorre o vetor de produtos
        vector<Produto>::iterator produtoEstoque;
        for (produtoEstoque = this->petshop->getProdutos().begin(); produtoEstoque != this->petshop->getProdutos().end(); produtoEstoque++)
        {
            //se o produto solicitado estiver no carrinho, faz o que ta dentro da condição
            if ((*it) == (*produtoEstoque))
            {
                //alterando a quantidade de produtos
                produtoEstoque->setQuantidade(produtoEstoque->getQuantidade() - it->getQuantidade());
                if (produtoEstoque->getQuantidade() < 0)
                {
                    produtoEstoque->setQuantidade(0);
                }
            }
        }
    }
    //cria uma nova compra
    Compra venda = Compra(descricaoCompra, preco);
    //chama o método de pagamento
    venda.pagar();
    //adiciona a venda efetuada ao vetor de vendas
    this->petshop->getVendas().push_back(venda);
    //percorre o vetor de clientes
    for (vector<Cliente>::iterator it = this->petshop->getClientes().begin(); it < this->petshop->getClientes().end(); it++)
    {
        //se o cliente informado for igual ao cliente existente no vetor, faz o que ta dentro da condição
        if (*it == cliente)
        {
            //insere o cliente na compra que foi efetuada
            it->getCompras().push_back(venda);
        }
    }
}

void Vendedor::vendaServico(Cliente cliente, Servico servico, Data dataServico)
{
    int id = 0;
    //Se o vetor não estiver vazio, passamos para o próximo id
    if (!this->petshop->getOrdemServico().empty())
    {
        vector<OrdemServico>::iterator last = this->petshop->getOrdemServico().end();
        last--;
        id = last->getId() + 1;
    }
    //criamos a ordem de serviço utilizando as informações presentes no vetorS
    OrdemServico ordemservico = OrdemServico(servico, cliente, dataServico, id, "");
    //adicionamos a ordem de serviço criada no vetor de ordens de serviço
    this->petshop->getOrdemServico().push_back(ordemservico);
}

Produto Vendedor::buscarProduto(long id, bool *success)
{
    /*percorrendo o vetor de produtos em busca de um produto específico*/
    for (auto produto : this->petshop->getProdutos())
    {
         /*verificando se o id do vetor é igual ao id passado por referência*/
        if (produto.getId() == id)
        {
            /*se for igual, teremos sucesso*/
            *success = true;
            /*retornaremos as informações*/
            return produto;
        }
    }
    /*se nao for igual retornaremos vazio*/
    *success = false;
    return {};
}

void Vendedor::listarProdutos()
{
    cout << setw(7) << "id"
         << " | " << setw(7) << "Qtd"
         << " | " << setw(7) << " Preço"
         << "  | Nome" << endl;
    /*percorrer vetor de produtos e realizar a impressão*/
    for (auto produto : this->petshop->getProdutos())
    {
        cout << produto << endl;
    }
    cout << endl;
}

Servico Vendedor::buscarServico(long id, bool *success)
{
    /*percorrendo o vetor de serviços em busca de um serviço específico*/
    for (auto servico : this->petshop->getServicos())
    {
        /*verificando se o id do vetor é igual ao id passado por referência*/
        if (servico.getId() == id)
        {
            /*se for igual, teremos sucesso*/
            *success = true;
            /*retornaremos as informações*/
            return servico;
        }
    }
    /*se nao for igual retornaremos vazio*/
    *success = false;
    return {};
}

void Vendedor::listarServicos()
{
    cout << setw(7) << "id"
         << " | " << setw(7) << "Preço"
         << "  | Nome" << endl;
    /*percorrer vetor de serviços e realizar a impressão*/
    for (auto servico : this->petshop->getServicos())
    {
        cout << servico << endl;
    }
    cout << endl;
}