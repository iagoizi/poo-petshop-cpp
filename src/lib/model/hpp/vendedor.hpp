#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "lib.hpp"
#include "produto.hpp"
#include "cliente.hpp"
#include "usuario.hpp"
#include "servico.hpp"
#include "ordemservico.hpp"

class Vendedor : virtual public Usuario
{

public:
    /*Todos os campos são obrigatórios com exceção do salário*/
    Vendedor(PetShop *petshop, string nome, string usuario, string senha, double salario = 0.0);
    ~Vendedor();

    /*Cadastra um novo cliente, o adicionando no vetor de clientes do petshop*/
    void cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf);
    /*Registra uma venda de produtos para um determinado cliente*/
    void vendaProduto(Cliente &cliente, vector<Produto> carrinho);
    /*Registra uma venda de um serviço para um determinado cliente*/
    void vendaServico(Cliente cliente, Servico servico, Data dataServico);
    /*Busca um determinado produto*/
    Produto buscarProduto(long id, bool *success);
    /*Busca um determinado produto*/
    Servico buscarServico(long id, bool *success);
    /*Lista os produtos cadastros*/
    void listarProdutos();
    /*Lista os produtos cadastros*/
    void listarServicos();
};

#endif