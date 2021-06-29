#ifndef PRODUTO_H
#define PRODUTO_H

#include "lib.hpp"
#include <string>
#include <string.h>
using namespace std;

class Produto
{
    char nome[M];
    double preco;
    int quantidade;
    long id;

public:
    Produto(string nome = "", double preco = 0.0, int quantidade = 0, long id = -1);
    ~Produto();

    void setNome(string nome);
    void setPreco(double preco);
    void setQuantidade(int quantidade);
    void setId(long id);

    string getNome();
    double getPreco();
    int getQuantidade();
    long getId();

    /*Se os produtos tiverem mesmo id, são iguais*/
    bool operator==(Produto);
    friend ostream &operator<<(ostream &os, const Produto &produto);
};
#endif