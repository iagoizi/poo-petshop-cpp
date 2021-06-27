#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "lib.hpp"

class Vendedor : virtual public Usuario
{

public:
    /*Todos os campos são obrigatórios com exceção do salário*/
    Vendedor(PetShop petshop, string nome, string usuario, string senha, double salario = 0.0);
    ~Vendedor();

    /*Cadastra um novo cliente, o adicionando no vetor de clientes do petshop*/
    void cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf, vector<Compra> compras);
    /*Registra uma venda de produtos para um determinado cliente*/
    void vendaProduto(Cliente& cliente, vector<Produto> produtos);
    /*Registra uma venda de serviços para um determinado cliente*/
    void vendaServico(Cliente cliente, vector<Servico> servico, Data dataServico);
};

#endif