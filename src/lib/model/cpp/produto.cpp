#include "../hpp/produto.hpp"

Produto::Produto(string nome, double preco, int quantidade, long id)
{
    /*instância os valores do objeto por meio dos métodos setters*/
    setNome(nome);
    setPreco(preco);
    setQuantidade(quantidade);
    setId(id);
}
Produto::~Produto() {}

void Produto::setNome(string nome)
{
    /*realiza a conversão de string para char 
      para setar o nome*/
    const char *novoNome = nome.data();  //Pegar um vetor de char como string
    int length = nome.size();  //Pegar o tamanho do vetor
    length = (length < M ? length : M - 1);
    strncpy(this->nome, novoNome, length);  //Copiar a string para outra variável
    this->nome[length] = '\0';
}
void Produto::setPreco(double preco)
{
    this->preco = preco;
}
void Produto::setId(long id)
{
    this->id = id;
}

void Produto::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

string Produto::getNome()
{
    return this->nome;
}
double Produto::getPreco()
{
    return this->preco;
}
long Produto::getId()
{
    return this->id;
}

int Produto::getQuantidade()
{
    return this->quantidade;
}
/*Produtos iguais possuemo mesmo ID*/
bool Produto::operator==(Produto produto)
{
    return this->id == produto.getId();
}
/*Saída dos valores de produto formatada*/
ostream &operator<<(ostream &os, const Produto &produto)
{
    os << setw(7) << produto.id << " | " << setw(7) << produto.quantidade << " | " << setw(7) << produto.preco << " | " << produto.nome;
    return os;
}
Produto Produto::clone()
{
    /*Uso de get dos atributos para fazer a clonagem dos valores*/
    return Produto(getNome(), getPreco(), getQuantidade(), getId());
}
