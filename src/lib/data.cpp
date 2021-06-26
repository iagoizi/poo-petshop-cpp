#include "data.hpp"

Data::Data(int dia, int mes, int ano, int hora, int minuto) : dia(dia), mes(mes), ano(ano), hora(hora),minuto(minuto){} 

Data::~Data(){}

int Data::getDia(){
    return this->dia;
}
int Data::getMes(){
    return this->mes;
}
int Data::getAno(){
    return this->ano;
}
int Data::getHora(){
    return this->hora;
}
int Data::getMinuto(){
    return this->minuto;
}
void Data::setDia(int diaAtual){
        this->dia = diaAtual;
}
void Data::setMes(int mesAtual){
        this->mes = mesAtual;
}
void Data::setAno(int anoAtual){
    this->ano = anoAtual;
}
void Data::setHora(int hora){
        this->hora = hora;
}
void Data::setMinuto(int minuto){
        this->minuto = minuto;
}

bool Data::operator==(Data comp){
    return this->dia == comp.getDia() && 
           this->mes == comp.getMes() && 
           this->ano == comp.getAno() && 
           this->hora == comp.getHora() &&
           this->minuto == comp.getMinuto();
}
void Data::now(){
    time_t now = time(0);
    tm *time = gmtime(&now);
    this->dia = time->tm_mday;
    this->mes = time->tm_mon;
    this->ano = time->tm_year + 1900;
}
