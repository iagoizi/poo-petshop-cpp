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
    /*Construtor de Serviço*/
    Servico(string nome = "", double preco = 0.0, long id = -1);
    /*Destrutor de Serviço*/
    ~Servico();
    /*Setters dos atributos de Serviço*/
    void setNome(string nome);
    void setPreco(double preco);
    void setId(long id);
    /*Getters dos atributos de Serviço*/
    string getNome();
    double getPreco();
    long getId();
   /*Sobrecarga do operador == para Serviço*/
    bool operator==(Servico);
    /*Sobrecarga do operador << para Serviço*/
    friend ostream &operator<<(ostream &os, const Servico &servico);
};
#endif