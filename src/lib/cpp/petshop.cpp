#include "../hpp/usuario.hpp"
#include "../hpp/petshop.hpp"

PetShop::PetShop()
{
}

PetShop::~PetShop() {}

vector<Usuario> &PetShop::getUsuarios()
{
    return this->usuario;
}

vector<Cliente> &PetShop::getClientes()
{
    return this->clientes;
}

vector<Conta> &PetShop::getContas()
{
    return this->conta;
}

vector<Produto> &PetShop::getProdutos()
{
    return this->produto;
}

vector<Servico> &PetShop::getServicos()
{
    return this->servico;
}

vector<OrdemServico> &PetShop::getOrdemServico()
{
    return this->ordemservicos;
}

vector<OrdemServico> &PetShop::getHistoricoServico()
{
    return this->historicoServicos;
}

vector<Compra> &PetShop::getCompras()
{
    return this->compras;
}

vector<Compra> &PetShop::getVendas()
{
    return this->vendas;
}

void PetShop::setNome(string nome)
{
}

bool PetShop::login(string usuario, string senha)
{
    return true;
}

void PetShop::logOut()
{
}
