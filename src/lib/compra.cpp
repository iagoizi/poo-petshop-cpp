#include "compra.hpp"

Compra::Compra(string descricao, double preco, Data data)
{
    setDescricao(descricao);
    setPreco(preco);
    setData(data);
}
Compra::~Compra()
{
}
string Compra::getDescricao()
{
    return this->descricao;
}
Data Compra::getData()
{
    return this->data;
}
double Compra::getPreco()
{
    return this->preco;
}
void Compra::setDescricao(string descricao)
{
    const char *novaDescricao = descricao.data();
    int length = descricao.size();
    length = (length < M10 ? length : M10 - 1);
    strncpy(this->descricao, novaDescricao, length);
    this->descricao[length] = '\0';
}
void Compra::setData(Data data)
{
    this->data = data;
}
void Compra::setPreco(double preco)
{
    this->preco = preco;
}
void Compra::pagar()
{
    this->data.now();
}