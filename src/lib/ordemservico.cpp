#include "lib.hpp"

OrdemServico::OrdemServico(Servico servico, Cliente cliente, Data data, string observacao){
    setServico(servico);
    setCliente(cliente);
    setData(data);
    setObservacao(observacao);
}
    
OrdemServico::~OrdemServico(){};

Servico OrdemServico::getServico(){
    return this->servico;
}

Cliente OrdemServico::getCliente(){
    return this->cliente;
}

Data OrdemServico::getData(){
    return this->data;
}

string OrdemServico::getObservacao(){
    return this->observacao;
}

void OrdemServico::setServico(Servico servico){
    this->servico = servico;
}

void OrdemServico::setCliente(Cliente cliente){
    this->cliente = cliente;
}

void OrdemServico::setData(Data data){
    this->data = data;
}

void OrdemServico::setObservacao(string observacao){

    const char *novaObservacao = observacao.data();     //Pegar um vetor de char como string
    int length = observacao.size();                     //Pegar o tamanho do vetor 
    length = (length < M ? length : M - 1);
    strncpy(this->observacao, novaObservacao, length);  //Copiar a string para outra variável
    this->observacao[length] = '\0';
}

//Fazendo comparação entre 2 IDs de serviços
bool OrdemServico::operator==(OrdemServico comp){
    return this->servico == comp.getServico() &&
           this->data == comp.getData() &&
           this->cliente == comp.getCliente();
}
