#include "produto.hpp"

Produto::Produto(string nome, double preco, int quantidade, long id)
{
    setNome(nome);
    setPreco(preco);
    setQuantidade(quantidade);
    setId(id);
}
Produto::~Produto() {}

void Produto::setNome(string nome)
{
    const char *novoNome = nome.data();
    int length = nome.size();
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);
    this->nome[length] = '\0';
}
void Produto::setPreco(double preco)
{
    this->preco = preco;
}
void Produto::setId(long id)
{
    this->id = id;
}

string Produto::getNome()
{
    return this->nome;
}
double Produto::getPreco()
{
    return this->preco;
}
long Produto::getId()
{
    return this->id;
}

bool Produto::operator==(Produto produto)
{
    return this->nome == produto.getNome() &&
           this->preco == produto.getPreco() &&
           this->quantidade == produto.getQuantidade() &&
           this->id == produto.getId();
}