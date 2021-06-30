#ifndef USUARIO_HPP
#define USUARIO_HPP

#define ADMINISTRADOR 0
#define VENDEDOR 1
#define VETERINARIO 2

#include "lib.hpp"
class PetShop;
class Usuario
{

protected:
    char nome[M];
    int cargo; //ADMINISTRADOR(0), VENDEDOR(1) ou VETERINARIO(2)
    char usuario[M];
    char senha[M];
    double salario;
    PetShop *petshop;

public:
    Usuario(PetShop *petshop = NULL, string nome = "", int cargo = 0, string usuario = "", string senha = "", double salario = 0.0);
    ~Usuario();
    string getNome();
    int getCargo();
    string getUsuario();
    string getSenha();
    double getSalario();

    void setNome(string);
    void setCargo(int);
    void setUsuario(string);
    void setSenha(string);
    void setSalario(double);

    /*Se os usuários tiverem mesmo usuario, são iguais*/
    bool operator==(Usuario);
};

#endif