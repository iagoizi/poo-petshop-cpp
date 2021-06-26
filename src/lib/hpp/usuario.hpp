#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "lib.hpp"

#define ADMINISTRADOR 0
#define VENDEDOR 1
#define VETERINARIO 2

class Usuario
{

protected:
    char nome[M];
    int cargo; //ADMINISTRADOR(0), VENDEDOR(1) ou VETERINARIO(2)
    char usuario[M];
    char senha[M];
    double salario;
    PetShop petshop;

public:
    /*Todos os campos são obrigatórios com exceção do salário*/
    Usuario(PetShop petshop, string nome, int cargo, string usuario, string senha, double salario = 0.0);
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