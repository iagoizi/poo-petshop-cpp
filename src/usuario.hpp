#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "lib.hpp"

class Usuario{

protected:
    char nome[M];
    char cargo[M];
    char usuario[M];
    char senha[M];
    double salario;

public:
    Usuario(string nome = "", string cargo = "", string usuario = "", string senha = "", double salario = 0.0);
    ~Usuario();
    string getNome();
    string getCargo();
    string getUsuario();
    string getSenha();
    double getSalario();

    void setNome(string);
    void setCargo(string);
    void setUsuario(string);
    void setSenha(string);
    void setSalario(double);

};

#endif