#ifndef CLIENTE_H
#define CLIENTE_H

#include "lib.hpp"

class Cliente{
    //private: 
    char nome[M];
    char tipo_animal[M];
    char nome_pet[M];
    char endereco[M];
    int telefone;
    vector <Compra> compras;

    public:
    
    Cliente(string nome="", string tipo_animal="", string nome_pet="", string endereco="",  int telefone=0, vector <Compra> compras = {});
    ~Cliente();

    void setNome(string nome);
    void setTipo_Animal(string tipo_animal);
    void setNome_Pet(string nome_pet);
    void setEndereco(string endereco);
    void setTelefone(int telefone);
    //void setCompras(vector<Compras> compras);
    string getNome();
    string getTipo_animal();
    string getNome_pet();
    string getEndereco();
    int getTelefonr();
    // vector<Compras> getCompras();
};
#endif