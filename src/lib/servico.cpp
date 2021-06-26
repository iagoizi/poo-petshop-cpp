#include "servico.hpp"
Servico::Servico(string nome, double preco, long id)
{
    setNome(nome);
    setPreco(preco);
    setId(id);
}
Servico::~Servico() {}

void Servico::setNome(string nome)
{
    const char *novoNome = nome.data(); //Pegar um vetor de char como string
    int length = nome.size(); //Pegar o tamanho do vetor 
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length); //Copiar a string para outra variável
    this->nome[length] = '\0';
}
void Servico::setPreco(double preco)
{
    this->preco = preco;
}
void Servico::setId(long id)
{
    this->id = id;
}

string Servico::getNome()
{
    return this->nome;
}
double Servico::getPreco()
{
    return this->preco;
}
long Servico::getId()
{
    return this->id;
}

bool Servico::operator==(Servico servico)
{
    return this->nome == servico.getNome() &&
           this->preco == servico.getPreco() &&
           this->id == servico.getId();
}