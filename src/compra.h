#ifndef COMPRA_H
#define COMPRA_H
#include "data.h"
#include <string>
#include <string.h>
#include "lib.h"
class Compra{
    char descricao[M];
    Data data;
    double preco;
    public:
    Compra(std::string descricao="",Data data=Data(), double preco=0.0);
    ~Compra();
    std::string getDescricao();
    Data getData();
    double getPreco();
    void setDescricao(std::string descricao);
    void setData(Data data);
    void setPreco(double);
    void pagar();
};
#endif