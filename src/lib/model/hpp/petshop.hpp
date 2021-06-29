#ifndef PETSHOP_HPP
#define PETSHOP_HPP

#include "lib.hpp"
#include "cliente.hpp"
#include "conta.hpp"
#include "produto.hpp"
#include "servico.hpp"
#include "ordemservico.hpp"
#include "compra.hpp"

class Usuario;
class PetShop
{
    //private:
    string nome;
    //Usuario sessaoAtual;
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

    vector<Usuario> &getUsuarios();
    vector<Cliente> &getClientes();
    vector<Conta> &getContas();
    vector<Produto> &getProdutos();
    vector<Servico> &getServicos();
    vector<OrdemServico> &getOrdemServico();
    vector<OrdemServico> &getHistoricoServico();
    vector<Compra> &getCompras();
    vector<Compra> &getVendas();

    void setNome(string);

    bool login(string usuario, string senha);
    void logOut();
};

#endif