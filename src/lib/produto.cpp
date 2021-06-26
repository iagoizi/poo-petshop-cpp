#include "produto.hpp"
// talvez tenha que mudar as strings para ponteiro de char porque ta alertando erro
// daí acho que para fazer a cópia dos valores, vamos ter que usar a função strcpy
// (cpp de cliente, servico e produto com esses erros)
Produto::Produto(string nome, double preco, int quantidade, long id) : nome(nome), preco(preco), quantidade(quantidade), id(id){}
Produto::~Produto(){}

void Produto::setNome(string nome){
    this->nome = nome;
}
void Produto::setPreco(double preco){
    this->preco = preco;
}
void Produto::setId(long id){
    this->id = id;
}

string Produto::getNome(){
    return this->nome;
}
double Produto::getPreco(){
    return this->preco;
}
long Produto::getId(){
    return this->id;
}

bool Produto::operator==(Produto produto){
    return this->nome == produto.getNome() &&
    this->preco == produto.getPreco() &&
    this->quantidade == produto.getQuantidade() &&
    this->id == produto.getId();
}