#ifndef CLIENTE_H
#define CLIENTE_H

#include "lib.hpp"
#include "compra.hpp"

class Cliente
{
    //private:
    char nome[M];
    char tipoAnimal[M];
    char nomePet[M];
    char endereco[M10];
    int telefone;
    long cpf;
    vector<Compra> compras;

public:
    Cliente(string nome = "", string tipoAnimal = "", string nomePet = "", string endereco = "", int telefone = 0,
            long cpf = 0, vector<Compra> compras = {});
    ~Cliente();

    void setNome(string nome);
    void setTipoAnimal(string tipoAnimal);
    void setNomePet(string nomePet);
    void setEndereco(string endereco);
    void setTelefone(int telefone);
    void setCpf(long cpf);
    void setCompras(vector<Compra> compras);
    string getNome();
    string getTipoAnimal();
    string getNomePet();
    string getEndereco();
    int getTelefone();
    long getCpf();
    vector<Compra> &getCompras();

    /*Se os clientes tiverem o mesmo cpf, são o mesmo cliente*/
    bool operator==(Cliente);
    friend ostream &operator<<(ostream &out, Cliente &cliente);
};
#endif