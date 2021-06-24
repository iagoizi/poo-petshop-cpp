#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <iostream>
#include "stdlib.h"
#include <stdio.h>
#include <ctime>
using namespace std;
class Data{
    int dia, mes, ano, hora, minuto;

public:
    Data(int dia = -1, int mes = -1, int ano = -1, int hora = -1, int minuto = -1);
    ~Data();
    Data setData(int dia, int mes, int ano);
    void setAno(int ano);
    void setDia(int dia);
    void setMes(int mes);
    void setHora(int hora);
    void setMinuto(int minuto);
    Data getData(Data);
    int getDia();
    int getAno();
    int getMes();
    int getHora();
    int getMinuto();
    bool operator==(Data);
    void now();
};
#endif