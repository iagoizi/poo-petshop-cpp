#ifndef CONTA_H
#define CONTA_H
#include "data.h"
#include <string>
#include <string.h>
#include "lib.h"
class Conta{
    char descricao[M];
    Data dataVencimento;
    Data dataPagamento;
    double valor;
    public:
    Conta(std::string descricao="",Data dataVencimento=Data(),Data dataPagamento=Data(), double valor=0.0);
    ~Conta();
    std::string getDescricao();
    Data getDataVencimento();
    Data getDataPagamento();
    double getValor();
    void setDescricao(std::string descricao);
    void setDataPagamento(Data data);
    void setDataVencimento(Data data);
    void setValor(double);
    void pagar();
};
#endif