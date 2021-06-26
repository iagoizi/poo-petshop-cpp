#include "veterinario.hpp"

Veterinario::Veterinario(PetShop petshop, string nome, string usuario, string senha, double salario){
    
    setNome(nome);
    setUsuario(usuario);
    setSenha(senha);
    setSalario(salario);
}

Veterinario::~Veterinario(){};

void Veterinario::registrarTratamento(OrdemServico ordem, string tratamento){
    //Acessar ordem de servico e usar set observacao
    ordem.setObservacao(tratamento);
}

/*
OrdemServico Veterinario::buscarOrdemServico(Cliente cliente, Data dataAgendada){
    
    return this->getNome() == cliente.getNome();

}


Cliente Veterinario::buscarCadastro(long cpf){

    for(vector<Cliente>::iterator i = petshop.clientes.begin(); i != petshop.clientes.end();i++){
        
        .getCpf() == cpf;

    }

}
*/

void Veterinario::listarOrdemServico(){
    //    vector<OrdemServico> ordemservicos;

    for(vector <OrdemServico>::iterator i = petshop.ordemservicos.begin(); i != petshop.ordemservicos.end();i++){
        
    }

}

