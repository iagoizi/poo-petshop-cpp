#include "../hpp/cliente.hpp"
Cliente::Cliente(string nome, string tipoAnimal, string nomePet, string endereco, int telefone, long cpf,
                 vector<Compra> compras)
{
    setNome(nome);
    setTipoAnimal(tipoAnimal);
    setNomePet(nomePet);
    setEndereco(endereco);
    setTelefone(telefone);
    setCpf(cpf);
    setCompras(compras);
}
Cliente::~Cliente() {}

void Cliente::setNome(string nome)
{
    const char *novoNome = nome.data();
    int length = nome.size();
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);
    this->nome[length] = '\0';
}
void Cliente::setTipoAnimal(string tipoAnimal)
{
    const char *novoAnimal = tipoAnimal.data();
    int length = tipoAnimal.size();
    length = (length < M ? length : M - 1);
    strncpy(this->tipoAnimal, novoAnimal, length);
    this->tipoAnimal[length] = '\0';
}
void Cliente::setNomePet(string nomePet)
{
    const char *novoNome = nomePet.data();
    int length = nomePet.size();
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);
    this->nome[length] = '\0';
}
void Cliente::setEndereco(string endereco)
{
    const char *novoEndereco = endereco.data();
    int length = endereco.size();
    length = (length < M10 ? length : M10 - 1);
    strncpy(this->nome, novoEndereco, length);
    this->nome[length] = '\0';
}
void Cliente::setTelefone(int telefone)
{
    this->telefone = telefone;
}
void Cliente::setCpf(long cpf)
{
    this->cpf = cpf;
}
void Cliente::setCompras(vector<Compra> compras)
{
    this->compras = compras;
}
string Cliente::getNome()
{
    return this->nome;
}
string Cliente::getTipoAnimal()
{
    return this->tipoAnimal;
}
string Cliente::getNomePet()
{
    return this->nomePet;
}
string Cliente::getEndereco()
{
    return this->endereco;
}
int Cliente::getTelefone()
{
    return this->telefone;
}
long Cliente::getCpf()
{
    return this->cpf;
}
vector<Compra> Cliente::getCompras()
{
    return this->compras;
}
//Um cliente é o mesmo quando o cpf é igual
bool Cliente::operator==(Cliente cliente)
{
    return this->cpf == cliente.getCpf();
}