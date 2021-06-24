#ifndef COMPRA_H
#define COMPRA_H

#include "lib.hpp"

class Compra{
    //private:
    char descricao[M];
    Data data;
    double preco;
    
    public:
    Compra(string descricao="", Data data=Data(), double preco=0.0);
    ~Compra();
    string getDescricao();
    Data getData();
    double getPreco();
    void setDescricao(string descricao);
    void setData(Data data);
    void setPreco(double);
    void pagar();
};
#endif