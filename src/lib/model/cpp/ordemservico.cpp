#include "../hpp/ordemservico.hpp"

OrdemServico::OrdemServico(Servico servico, Cliente cliente, Data data, int id, string observacao)
{
    setServico(servico);
    setCliente(cliente);
    setData(data);
    setId(id);
    setObservacao(observacao);
}

OrdemServico::~OrdemServico(){};

Servico OrdemServico::getServico()
{
    return this->servico;
}

Cliente OrdemServico::getCliente()
{
    return this->cliente;
}

Data OrdemServico::getData()
{
    return this->data;
}

string OrdemServico::getObservacao()
{
    return this->observacao;
}

void OrdemServico::setServico(Servico servico)
{
    this->servico = servico;
}

void OrdemServico::setCliente(Cliente cliente)
{
    this->cliente = cliente;
}

void OrdemServico::setData(Data data)
{
    this->data = data;
}

void OrdemServico::setObservacao(string observacao)
{

    const char *novaObservacao = observacao.data(); //Pegar um vetor de char como string
    int length = observacao.size();                 //Pegar o tamanho do vetor
    length = (length < M ? length : M - 1);
    strncpy(this->observacao, novaObservacao, length); //Copiar a string para outra variável
    this->observacao[length] = '\0';
}

int OrdemServico::getId()
{
    return this->id;
}

void OrdemServico::setId(int id)
{
    this->id = id;
}
//Fazendo comparação entre 2 IDs de serviços
bool OrdemServico::operator==(OrdemServico comp)
{
    return this->id == comp.id;
}

ostream &operator<<(ostream &os, OrdemServico &ordem)
{
    os << ordem.data << " | " << setw(7) << ordem.id << " | " << ordem.servico << " [" << ordem.cliente.getNome() << "]";
    if (ordem.observacao[0] != '\0')
    {
        os << " (" << ordem.observacao << ")";
    }

    return os;
}
