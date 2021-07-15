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
    /*Construtor de Produto*/
    Produto(string nome = "", double preco = 0.0, int quantidade = 0, long id = -1);
    /*Destrutor de Produto*/
    ~Produto();
    /*Setters dos atributos de Produto*/
    void setNome(string nome);
    void setPreco(double preco);
    void setQuantidade(int quantidade);
    void setId(long id);
    /*Getters dos atributos de Produto*/
    string getNome();
    double getPreco();
    int getQuantidade();
    long getId();
    /*Sobrecarga do operador == para Produto*/
    bool operator==(Produto);
    /*Sobrecarga do operador << para Produto*/
    friend ostream &operator<<(ostream &os, const Produto &produto);
    /*Retorna um objeto Produto instanciado, com os mesmos valores de atributo do abjeto que chama o método clone*/
    Produto clone();
};
#endif