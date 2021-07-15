#include "../hpp/usuario.hpp"
#include "../hpp/petshop.hpp"

Usuario::Usuario(PetShop *petshop, string nome, int cargo, string usuario, string senha, double salario)
{
    this->petshop = petshop;
    /*instância os valores do objeto por meio dos métodos setters*/
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
    /*realiza a conversão de string para char para setar o nome*/
    const char *novoNome = nome.data(); //Pegar um vetor de char como string
    int length = nome.size(); //Pegar o tamanho do vetor
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length); //Copiar a string para outra variável
    this->nome[length] = '\0';
}

void Usuario::setCargo(int cargo)
{
    this->cargo = cargo;
}

void Usuario::setUsuario(string usuario)
{
    /*realiza a conversão de string para char para setar o usuario*/
    const char *novoUsuario = usuario.data(); //Pegar um vetor de char como string
    int length = usuario.size(); //Pegar o tamanho do vetor
    length = (length < M ? length : M - 1);
    strncpy(this->usuario, novoUsuario, length); //Copiar a string para outra variável
    this->usuario[length] = '\0';
}

void Usuario::setSenha(string senha)
{
    /*realiza a conversão de string para char para setar a senha*/
    const char *novaSenha = senha.data(); //Pegar um vetor de char como string
    int length = senha.size(); //Pegar o tamanho do vetor
    length = (length < M ? length : M - 1);
    strncpy(this->senha, novaSenha, length); //Copiar a string para outra variável
    this->senha[length] = '\0';
}

Cliente Usuario::buscarCadastro(long cpf, bool *success)
{
    /*percorre o vetor de clientes para buscar um cadastro específico*/
    for (vector<Cliente>::iterator i = this->petshop->getClientes().begin(); i != this->petshop->getClientes().end(); i++)
    {
        /*compara cpf passado por referencia com cpf contido no vetor de clientes*/
        if ((*i).getCpf() == cpf)
        {
            /*se for igual, retorna verdade*/
            *success = true;
            return *i;
        }
    }
    *success = false;
    /*retorna o vetor*/
    return {};
}

/*Saída dos valores de produto formatada*/
ostream &operator<<(ostream &os, const Usuario &usuario)
{
    os << "(" << usuario.cargo << ") " << usuario.usuario << " -> " << usuario.nome << " R$" << usuario.salario;
    return os;
}