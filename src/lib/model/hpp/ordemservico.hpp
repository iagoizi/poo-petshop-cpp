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
    OrdemServico(Servico servico = {}, Cliente cliente = {}, Data data = 0,  int id = 0, string observacao = "");
    ~OrdemServico();

    Servico getServico();
    Cliente getCliente();
    Data getData();
    string getObservacao();

    void setServico(Servico);
    void setCliente(Cliente);
    void setData(Data);
    void setObservacao(string);

    int getId();
    void setId(int);

    /*Se as ordens de serviço tiverem mesmo cliente, serviço e data, eles são iguais*/
    bool operator==(OrdemServico);
    friend ostream &operator<<(ostream &os, OrdemServico &ordem);
};

#endif