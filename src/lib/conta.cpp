#include "conta.hpp"
Conta::Conta(std::string descricao, Data dataVencimento, Data dataPagamento, double valor)
{
    setDescricao(descricao);
    setDataVencimento(dataVencimento);
    setDataPagamento(dataPagamento);
    setValor(valor);
}
Conta::~Conta()
{
}
std::string Conta::getDescricao()
{
    return this->descricao;
}
Data Conta::getDataVencimento()
{
    return this->dataVencimento;
}
Data Conta::getDataPagamento()
{
    return this->dataPagamento;
}
double Conta::getValor()
{
    return this->valor;
}
void Conta::setDescricao(std::string descricao)
{
    const char *novaDescricao = descricao.data();
    int length = descricao.size();
    length = (length < M ? length : M - 1);
    strncpy(this->descricao, novaDescricao, length);
    this->descricao[length] = '\0';
}
void Conta::setDataPagamento(Data data)
{
    this->dataPagamento = data;
}
void Conta::setDataVencimento(Data data)
{
    this->dataVencimento = data;
}
void Conta::setValor(double valor)
{
    this->valor = valor;
}

void Conta::pagar()
{
    this->dataPagamento.now();
}