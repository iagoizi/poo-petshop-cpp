#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "lib.hpp"

class OrdemServico
{

protected:
    char servico[M];
    char cliente[M];
    Data data;
    char observacao[M];

public:
    OrdemServico(string servico = "", string cliente = "", Data data = 0, string obs = "");
    ~OrdemServico();

    string getServico();
    string getCliente();
    string getData();
    string getObservacao();

    void setServico(string);
    void setCliente(string);
    void setData(Data);
    void setObservacao(string);

    /*Se as ordens de serviço tiverem mesmo cliente, serviço e data, eles são iguais*/
    bool operator==(OrdemServico);
};

#endif