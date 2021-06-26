#include "../hpp/vendedor.hpp"

Vendedor::Vendedor(PetShop petshop, string nome, string usuario, string senha, double salario = 0.0) : Usuario(petshop, nome, ADMINISTRADOR, string("admin"), string("admin"), 0.0)
{
    setNome(nome);
    setUsuario(usuario);
    setSenha(senha);
    setSalario(salario);
}
Vendedor::~Vendedor() {}

void Vendedor::cadastrarCliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf, vector<Compra> compras)
{ // mudar no uml
    Cliente cliente = Cliente(nome, tipo_animal, nome_pet, endereco, telefone, cpf, compras);
    this->petshop.getClientes().push_back(cliente);
}

void Vendedor::vendaProdutos(Cliente cliente, vector<Produto> produto)
{ //mudar diagrama uml
    //preciso ver pra qual cliente estou vendendo
    //preciso listar os produtos e depois escolher um para efetuar a compra
    //depois de escolher, set e retiro o produto do estoque
}

void Vendedor::vendaServico(Cliente cliente, vector<Servico> servico)
{
    //preciso ver pra qual cliente estou vendendo
    //preciso listar os serviços e depois escolher um para efetuar a compra
    //depois de escolher, set e retiro o serviço do estoque
}