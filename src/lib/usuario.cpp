#include "usuario.hpp"

Usuario::Usuario(PetShop petshop, string nome, int cargo, string usuario, string senha, double salario) : nome(nome), cargo(cargo),  usuario(usuario), senha(senha), salario(salario){}

Usuario::~Usuario(){};

string Usuario::getNome() const{
    return nome;
}

int Usuario::getCargo() const{
    return cargo;
}

string Usuario::getUsuario() const{
    return usuario;
}

string Usuario::getSenha() const{
    return senha;
}

double Usuario::getSalario() const{
    return salario;
}

void Usuario::setSalario(double salario){
    this->salario = salario;
}

void Usuario::setNome(string nome){
    this->nome = nome;
}

void Usuario::setCargo(int cargo){
    this->cargo = cargo;
}

void Usuario::setUsuario(string usuario){
    this->usuario = usuario;
}

void Usuario::setSenha(string senha){
    this->senha = senha;
}