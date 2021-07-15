#include "../hpp/veterinario.hpp"
#include "../hpp/petshop.hpp"

// Construtor de Veterinario
Veterinario::Veterinario(PetShop *petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VETERINARIO, usuario, senha, salario)
{
}

//Destrutor de Veterinario
Veterinario::~Veterinario(){};

//Registra um tratamento em uma ordem de servico
void Veterinario::registrarTratamento(OrdemServico &ordem, string tratamento)
{
    //Removendo serviço da lista de serviços a serem feitos
    for (vector<OrdemServico>::iterator it = this->petshop->getOrdemServico().begin(); it < this->petshop->getOrdemServico().end(); it++)
    {
        //Entra na condicao quando encontra o ordem buscada
        if (*it == ordem)
        {
            cout << "Removendo" << endl;
            //Remove a ordem de servico
            this->petshop->getOrdemServico().erase(it);
        }
    }
    //Acessar ordem de servico e usar set observacao
    ordem.setObservacao(tratamento);
    //Adiciona a ordem no historico de servico
    this->petshop->getHistoricoServico().push_back(ordem);
}

//Função utilizada para buscar uma ordem de servico -> retorna true/false e a ordem caso seja encontrada
OrdemServico Veterinario::buscarOrdemServico(int id, bool *sucess)
{
    // Laço que passa pelos Id das ordens de servico para encontrar a buscada
    for (vector<OrdemServico>::iterator i = this->petshop->getOrdemServico().begin(); i != this->petshop->getOrdemServico().end(); i++)
    {
        //Condição que verifica se é o ID buscado
        if ((*i).getId() == id)
        {
            *sucess = true;
            return *i;
        }
    }

    //Caso não seja encontrado a ordem buscado
    *sucess = false;
    return {};
}

// Lista no terminal todas as ordens de  servico juntamente com seus dados
void Veterinario::listarOrdemServico()
{
    cout << setw(20) << "Data e hora |" << setw(7) << " idOrdem "
         << "|" << setw(7) << "idServiço"
         << "| " << setw(7) << "Preço"
         << "  | NomeServiço [Nome do cliente]" << endl;
    //laço para buscar todas as ordens
    for (auto listaServicos : petshop->getOrdemServico())
    {
        cout << listaServicos << endl;
    }
    cout << endl;
}

// Mostra no terminal todos os clientes cadastrados
void Veterinario::listarClientes()
{
    // For que percorre o vetor de clientes cadastrados e os printa
    for (auto cliente : petshop->getClientes())
    {
        cout << cliente << endl;
    }
}