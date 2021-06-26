#ifndef CLIENTE_H
#define CLIENTE_H

#include "lib.hpp"

class Cliente
{
    //private:
    char nome[M];
    char tipo_animal[M];
    char nome_pet[M];
    char endereco[M10];
    int telefone;
    long cpf;
    vector<Compra> compras;

public:
    Cliente(string nome, string tipo_animal, string nome_pet, string endereco, int telefone, long cpf,
            vector<Compra> compras = {});
    ~Cliente();

    void setNome(string nome);
    void setTipo_Animal(string tipo_animal);
    void setNome_Pet(string nome_pet);
    void setEndereco(string endereco);
    void setTelefone(int telefone);
    void setCpf(long cpf);
    void setCompras(vector<Compra> compras);
    string getNome();
    string getTipo_animal();
    string getNome_pet();
    string getEndereco();
    int getTelefone();
    long getCpf();
    vector<Compra> getCompras();

    /*Se os clientes tiverem o mesmo cpf, são o mesmo cliente*/
    bool operator==(Cliente);
};
#endif