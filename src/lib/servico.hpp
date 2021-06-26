#ifndef SERVICO_H
#define SERVICO_H

#include "lib.hpp"

class Servico
{
    //private:
    char nome[M];
    double preco;
    long id;

public:
    Servico(string nome = "", double preco = 0.0, long id = -1);
    ~Servico();

    void setNome(string nome);
    void setPreco(double preco);
    void setId(long id);

    string getNome();
    double getPreco();
    long getId();

    /*Se os serviços tiverem mesmo id, são iguais*/
    bool operator==(Servico);
};
#endif