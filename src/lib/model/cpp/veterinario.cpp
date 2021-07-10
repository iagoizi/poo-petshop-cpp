#include "../hpp/veterinario.hpp"
#include "../hpp/petshop.hpp"

Veterinario::Veterinario(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VETERINARIO, usuario, senha, salario)
{
}

Veterinario::~Veterinario(){};

void Veterinario::registrarTratamento(OrdemServico &ordem, string tratamento)
{
    //Removendo serviço da lista de serviços a serem feitos
    for (vector<OrdemServico>::iterator it = this->petshop->getOrdemServico().begin(); it < this->petshop->getOrdemServico().end(); it++)
    {
        if (*it == ordem)
        {
            cout << "Removendo" << endl;
            this->petshop->getOrdemServico().erase(it);
        }
    }
    //Acessar ordem de servico e usar set observacao
    ordem.setObservacao(tratamento);
    this->petshop->getHistoricoServico().push_back(ordem);
}

OrdemServico Veterinario::buscarOrdemServico(int id, bool *sucess)
{

    for (vector<OrdemServico>::iterator i = this->petshop->getOrdemServico().begin(); i != this->petshop->getOrdemServico().end(); i++)
    {
        if ((*i).getId() == id)
        {
            *sucess = true;
            return *i;
        }
    }
    *sucess = false;
    return {};
}

void Veterinario::listarOrdemServico()
{
    cout << setw(20) << "Data e hora |" << setw(7) << "idServiço"
         << "| " << setw(7) << "Preço"
         << "  | NomeServiço [Nome do cliente]" << endl;
    for (auto listaServicos : petshop->getOrdemServico())
    {
        cout << listaServicos << endl;
    }
    cout << endl;
}

void Veterinario::listarClientes()
{
    for (auto cliente : petshop->getClientes())
    {
        cout << cliente << endl;
    }
}