#include "servico.hpp"
// talvez tenha que mudar as strings para ponteiro de char porque ta alertando erro
// daí acho que para fazer a cópia dos valores, vamos ter que usar a função strcpy
// (cpp de cliente, servico e produto com esses erros)
Servico::Servico(string nome, double preco, long id) : nome(nome), preco(preco), id(id){}
Servico::~Servico(){}

void Servico::setNome(string nome){
    this->nome = nome;
}
void Servico::setPreco(double preco){
    this->preco = preco;
}
void Servico::setId(long id){
    this->id = id;
}

string Servico::getNome(){
    return this->nome;
}
double Servico::getPreco(){
    return this->preco;
}
long Servico::getId(){
    return this->id;
}

bool Servico::operator==(Servico servico){
    return this->nome == servico.getNome() &&
    this->preco == servico.getPreco() &&
    this->id == servico.getId();
}