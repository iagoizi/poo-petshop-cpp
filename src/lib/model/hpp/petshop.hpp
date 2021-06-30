#ifndef PETSHOP_HPP
#define PETSHOP_HPP

#include "lib.hpp"
#include "cliente.hpp"
#include "conta.hpp"
#include "produto.hpp"
#include "servico.hpp"
#include "ordemservico.hpp"
#include "compra.hpp"
#include "../../view/hpp/menu.hpp"
#include "../../view/hpp/menuVendedor.hpp"

class Usuario;
class PetShop
{
    //private:
    char nome[M];
    Usuario sessaoAtual;
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
    PetShop(string nome);
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

    Menu *login(string usuario, string senha, bool *success);
    void logOut();
};

#endif