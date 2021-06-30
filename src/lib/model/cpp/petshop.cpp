#include "../hpp/usuario.hpp"
#include "../hpp/petshop.hpp"

PetShop::PetShop(string nome)
{
    setNome(nome);
}

PetShop::~PetShop()
{
}

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
    const char *novoNome = nome.data();
    int length = nome.size();
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);
    this->nome[length] = '\0';
}

Menu *PetShop::login(string usuario, string senha, bool *success)
{
    for (auto item : this->usuario)
    {
        if (item.getUsuario().compare(usuario) == 0 && item.getSenha().compare(senha) == 0)
        {
            this->sessaoAtual = item;
            *success = true;
            switch (item.getCargo())
            {
            case VENDEDOR:
                return new MenuVendedor(this);
                break;
            case VETERINARIO:
                //return new MenuVeterinario(this);
                break;
            case ADMINISTRADOR:
                //return new MenuAdministrador(this);
                break;
            }
        }
    }
    *success = false;
    return new Menu(this);
}

void PetShop::logOut()
{
    //chama método para salvar informações em arquivo;
}
