#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "lib.hpp"
#include "servico.hpp"
#include "data.hpp"
#include "cliente.hpp"

class OrdemServico
{

protected:
    Servico servico;
    Cliente cliente;
    Data data;
    int id;
    char observacao[M];

public:
    /*Construtor da Ordem de Servico*/
    OrdemServico(Servico servico = {}, Cliente cliente = {}, Data data = 0,  int id = 0, string observacao = "");
    
    /*Destrutor da ordem de servico*/
    ~OrdemServico();

    /*Getters dos atributos de Ordem de Servico*/
    Servico getServico();
    Cliente getCliente();
    Data getData();
    string getObservacao();
    int getId();

    /*Setters dos atributos de Ordem de Servico*/
    void setServico(Servico);
    void setCliente(Cliente);
    void setData(Data);
    void setObservacao(string);
    void setId(int);

    /*Sobrecarga do operador == para Ordem Servico: Se as ordens de serviço tiverem mesmo cliente, serviço e data, eles são iguais*/
    bool operator==(OrdemServico);

    /*Sobrecarga do operador << para Ordem de Servico*/
    friend ostream &operator<<(ostream &os, OrdemServico &ordem);
};

#endif