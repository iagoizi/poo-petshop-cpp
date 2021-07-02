#include "../hpp/usuario.hpp"
#include "../hpp/petshop.hpp"

Usuario::Usuario(PetShop *petshop, string nome, int cargo, string usuario, string senha, double salario)
{
    this->petshop = petshop;
    setNome(nome);
    setCargo(cargo);
    setUsuario(usuario);
    setSenha(senha);
    setSalario(salario);
}

Usuario::~Usuario(){}

string Usuario::getNome()
{
    return this->nome;
}

int Usuario::getCargo()
{
    return this->cargo;
}

string Usuario::getUsuario()
{
    return this->usuario;
}

string Usuario::getSenha()
{
    return this->senha;
}

double Usuario::getSalario()
{
    return this->salario;
}

void Usuario::setSalario(double salario)
{
    this->salario = salario;
}

void Usuario::setNome(string nome)
{
    const char *novoNome = nome.data();
    int length = nome.size();
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);
    this->nome[length] = '\0';
}

void Usuario::setCargo(int cargo)
{
    this->cargo = cargo;
}

void Usuario::setUsuario(string usuario)
{
    const char *novoUsuario = usuario.data();
    int length = usuario.size();
    length = (length < M ? length : M - 1);
    strncpy(this->usuario, novoUsuario, length);
    this->usuario[length] = '\0';
}

void Usuario::setSenha(string senha)
{
    const char *novaSenha = senha.data();
    int length = senha.size();
    length = (length < M ? length : M - 1);
    strncpy(this->senha, novaSenha, length);
    this->senha[length] = '\0';
}

Cliente Usuario::buscarCadastro(long cpf, bool *success)
{
    for (vector<Cliente>::iterator i = this->petshop->getClientes().begin(); i != this->petshop->getClientes().end(); i++)
    {
        if ((*i).getCpf() == cpf)
        {
            *success = true;
            return *i;
        }
    }
    *success = false;
    return {};
}

ostream &operator<<(ostream &os, const Usuario &usuario)
{
    os << "(" << usuario.cargo << ") " << usuario.usuario << " -> " << usuario.nome << " R$" << usuario.salario;
    return os;
}