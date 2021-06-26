#ifndef CONTA_H
#define CONTA_H

#include "lib.hpp"

class Conta
{
    //private:
    char descricao[M];
    Data dataVencimento;
    Data dataPagamento;
    double valor;

public:
    Conta(string descricao = "", Data dataVencimento = Data(), Data dataPagamento = Data(), double valor = 0.0);
    ~Conta();
    string getDescricao();
    Data getDataVencimento();
    Data getDataPagamento();
    double getValor();
    void setDescricao(string descricao);
    void setDataPagamento(Data data);
    void setDataVencimento(Data data);
    void setValor(double);
    void pagar();
};
#endif