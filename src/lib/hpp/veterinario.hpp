#ifndef VETERINARIO_HPP
#define VETERINARIO_HPP

#include "lib.hpp"

class Veterinario : virtual public Usuario
{

public:
    /*Todos os campos são obrigatórios com exceção do salário*/
    Veterinario(PetShop petshop, string nome, string usuario, string senha, double salario = 0.0);
    ~Veterinario();

    /*Registra o tratamento recomendado e move o serviço para o histórico*/
    void registrarTratamento(OrdemServico& ordem, string tratamento);
    
    /*Busca uma ordem de servico a partir do Cliente e da data marcada*/
    OrdemServico buscarOrdemServico(Cliente cliente, Data dataAgendada);
    
    /*Busca um cliente no sistema a partir do seu cpf*/
    Cliente buscarCadastro(long cpf);
    
    /*Lista todos os serviços ainda não realizados*/
    void listarOrdemServico();
};

#endif