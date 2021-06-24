#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "lib.hpp"

class Vendedor : virtual public Usuario{

public:
    Vendedor(string nome = "", string cargo = "", string usuario = "", string senha = "", double salario = 0.0);
    ~Vendedor();

    void cadastrarCliente(Cliente cliente);
    void vendaProdutos(vector <Produto> produto);
    void vendaServico(Cliente cliente, vector <Servico> servico);
};

#endif