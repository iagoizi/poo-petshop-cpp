#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "lib.hpp"

class OrdemServico
{

protected:
    Servico servico;
    Cliente cliente;
    Data data;
    char observacao[M];

public:
    OrdemServico(Servico servico = {}, Cliente cliente = {}, Data data = 0, string observacao = "");
    ~OrdemServico();

    Servico getServico();
    Cliente getCliente();
    Data getData();
    string getObservacao();

    void setServico(Servico);
    void setCliente(Cliente);
    void setData(Data);
    void setObservacao(string);

    /*Se as ordens de serviço tiverem mesmo cliente, serviço e data, eles são iguais*/
    bool operator==(OrdemServico);
    friend ostream &operator<<(ostream &os, OrdemServico &ordem);
};

#endif