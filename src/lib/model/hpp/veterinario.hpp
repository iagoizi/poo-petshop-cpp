#ifndef VETERINARIO_HPP
#define VETERINARIO_HPP

#include "lib.hpp"
#include "ordemservico.hpp"
#include "cliente.hpp"
#include "usuario.hpp"

/*Classe que herda funções e atributos da classe usuario*/
class Veterinario : virtual public Usuario
{

public:
    /*Construtor de veterinario -> Todos os campos são obrigatórios com exceção do salário*/
    Veterinario(PetShop *petshop, string nome, string usuario, string senha, double salario = 0.0);
    /*Destrutor de veterinario */
    ~Veterinario();

    /*Registra o tratamento recomendado e move o serviço para o histórico*/
    void registrarTratamento(OrdemServico &ordem, string tratamento);

    /*Busca uma ordem de servico a partir do Id da ordem de servico*/
    OrdemServico buscarOrdemServico(int id, bool *sucess);
    
    /*Lista todos as ordens de serviços ainda não realizados*/
    void listarOrdemServico();

    /*Lista os clientes cadastrados*/
    void listarClientes();
};

#endif