#ifndef PRODUTO_H
#define PRODUTO_H

#include "lib.hpp"

class Produto{
    char nome[M];
    double preco;
    int quantidade;
    long id;

    public:

    Produto(string nome="", double preco=0.0, int quantidade=0, long id = -1);
    ~Produto();
    
    void setNome(string nome);
    void setPreco(double preco);
    void setQuantidade(int quantidade);
    void setId(long id);

    string getNome();
    double getPreco();
    int getQuantidade();
    long getId();
};
#endif