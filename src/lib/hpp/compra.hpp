#ifndef COMPRA_H
#define COMPRA_H

#include "lib.hpp"

class Compra
{
    //private:
    char descricao[M10];
    Data data;
    double preco;

public:
    Compra(string descricao, double preco, Data data = Data());
    ~Compra();
    string getDescricao();
    Data getData();
    double getPreco();
    void setDescricao(string descricao);
    void setData(Data data);
    void setPreco(double);
    void pagar();
    friend ostream &operator<<(ostream &os, const Compra &compra);
};
#endif