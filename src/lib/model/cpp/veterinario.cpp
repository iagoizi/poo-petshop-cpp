#include "../hpp/veterinario.hpp"
#include "../hpp/petshop.hpp"

Veterinario::Veterinario(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VETERINARIO, usuario, senha, salario)
{
}

Veterinario::~Veterinario(){};

void Veterinario::registrarTratamento(OrdemServico &ordem, string tratamento)
{
    //Acessar ordem de servico e usar set observacao
    ordem.setObservacao(tratamento);
}

OrdemServico Veterinario::buscarOrdemServico(Cliente cliente, Data dataAgendada, bool *sucess)
{

    for (vector<OrdemServico>::iterator i = this->petshop->getOrdemServico().begin(); i != this->petshop->getOrdemServico().end(); i++)
    {
        if ((*i).getCliente() == cliente && (*i).getData() == dataAgendada)
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
    for (auto listaServicos : petshop->getOrdemServico())
    {
        cout << listaServicos << endl;
    }
}

void Veterinario::listarClientes()
{
    for (auto cliente : petshop->getClientes())
    {
        cout << cliente << endl;
    }
}