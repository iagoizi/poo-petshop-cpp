#include "../hpp/veterinario.hpp"

Veterinario::Veterinario(PetShop petshop, string nome, string usuario, string senha, double salario) : Usuario(petshop, nome, VETERINARIO, usuario, senha, salario)
{
}

Veterinario::~Veterinario(){};

void Veterinario::registrarTratamento(OrdemServico ordem, string tratamento)
{
    //Acessar ordem de servico e usar set observacao
    ordem.setObservacao(tratamento);
}

/*
OrdemServico Veterinario::buscarOrdemServico(Cliente cliente, Data dataAgendada){
    
    return this->getNome() == cliente.getNome();

}

*/

/*
Cliente Veterinario::buscarCadastro(long cpf)
{

    for (vector<Cliente>::iterator i = this->petshop.getClientes().begin(); i != this->petshop.getClientes().end(); i++)
    {
        if ((*i).getCpf() == cpf)
            return *i;
    }
    return {};
}
*/

void Veterinario::listarOrdemServico()
{

    /*for (vector<OrdemServico>::iterator i = petshop.ordemservicos.begin(); i != petshop.ordemservicos.end(); i++){
        cout << *i << endl;
    }
    */

    
    for (auto listaServicos : petshop.ordemservicos)
    {
        cout << listaServicos << endl;
    }
    
}
