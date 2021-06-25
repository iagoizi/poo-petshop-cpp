#ifndef PETSHOP_HPP
#define PETSHOP_HPP

#include "lib.hpp"

class PetShop
{
    //private:
    string nome;
    vector<Usuario> usuario;
    vector<Cliente> clientes;
    vector<Conta> conta;
    vector<Produto> produto;
    vector<Servico> servico;
    vector<OrdemServico> ordemservicos;
    vector<OrdemServico> historicoServicos;
    vector<Compra> compras;
    vector<Compra> vendas;

public:
    PetShop();
    ~PetShop();

    vector<Usuario> getUsuarios();
    vector<Cliente> getClientes();
    vector<Conta> getContas();
    vector<Produto> getProdutos();
    vector<Servico> getServicos();
    vector<OrdemServico> getOrdemServico();
    vector<OrdemServico> getHistoricoServico();
    vector<Compra> getCompras();
    vector<Compra> getVendas();

    void setNome(string);
};

#endif