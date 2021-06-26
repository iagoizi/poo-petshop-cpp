#include "cliente.hpp"
// talvez tenha que mudar as strings para ponteiro de char porque ta alertando erro
// daí acho que para fazer a cópia dos valores, vamos ter que usar a função strcpy
// (cpp de cliente, servico e produto com esses erros)
Cliente::Cliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf,
            vector<Compra> compras) : nome(nome), tipo_animal(tipo_animal), nome_pet(nome_pet), endereco(endereco), telefone(telefone), cpf(cpf), compras(compras) {}
Cliente::~Cliente(){}

void Cliente::setNome(string nome){
    this->nome = nome;
}
void Cliente::setTipo_Animal(string tipo_animal){
    this->tipo_animal = tipo_animal;
}
void Cliente::setNome_Pet(string nome_pet){
    this->nome_pet = nome_pet;
}
void Cliente::setEndereco(string endereco){
    this->endereco = endereco;
}
void Cliente::setTelefone(int telefone){
    this->telefone = telefone;
}
void Cliente::setCpf(long cpf){
    this->cpf = cpf;
}
void Cliente::setCompras(vector<Compra> compras){
    this->compras = compras;
}
string Cliente::getNome(){
    return this->nome;
}
string Cliente::getTipo_animal(){
    return this->tipo_animal;
}
string Cliente::getNome_pet(){
    return this->nome_pet;
}
string Cliente::getEndereco(){
    return this->endereco;
}
int Cliente::getTelefone(){
    return this->telefone;
}
long Cliente::getCpf(){
    return this->cpf;
}
vector<Compra> Cliente::getCompras(){
    return this->compras;
}
bool Cliente::operator==(Cliente cliente){
    return this->nome == cliente.getNome() &&
        this->nome_pet == cliente.getNome_pet() && 
        this->tipo_animal == cliente.getTipo_animal() &&
        this->endereco == cliente.getEndereco() &&
        this->telefone == cliente.getTelefone() &&
        this->cpf == cliente.getCpf() &&
        this->compras == cliente.getCompras();
}