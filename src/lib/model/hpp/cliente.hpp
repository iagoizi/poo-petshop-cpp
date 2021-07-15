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
    long telefone;
    long cpf;
    vector<Compra> compras;

public:
    /*Construtor de Cliente*/
    Cliente(string nome = "", string tipoAnimal = "", string nomePet = "", string endereco = "", long telefone = 0,
            long cpf = 0, vector<Compra> compras = {});
    /*Destrutor de Cliente*/
    ~Cliente();
    /*Setters dos atributos de Cliente*/
    void setNome(string nome);
    void setTipoAnimal(string tipoAnimal);
    void setNomePet(string nomePet);
    void setEndereco(string endereco);
    void setTelefone(long telefone);
    void setCpf(long cpf);
    void setCompras(vector<Compra> compras);
    /*Getters dos atributos de Cliente*/
    string getNome();
    string getTipoAnimal();
    string getNomePet();
    string getEndereco();
    long getTelefone();
    long getCpf();
    vector<Compra> &getCompras();
    /*Sobrecarga do operador == para Cliente*/
    bool operator==(Cliente);
    /*Sobrecarga do operador << para Cleinte*/
    friend ostream &operator<<(ostream &out, Cliente &cliente);
};
#endif