#ifndef MENU_HPP
#define MENU_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/usuario.hpp"

using namespace std;

class Menu
{
protected:
    PetShop *petshop;
    /*Uma mensagem que vai aparecer na tela dizendo se a operação foi bem sucedida ou qual foi o erro que aconteceu*/
    string popUp;
    /*imprime uma opção do menu na tela*/
    void printOpcao(int opcode, string label);
    /*imprime uma mensagem de erro com tabulação na tela*/
    void printErro(string mensagem);
    /*imprime um título de uma operação*/
    void printTitulo(string titulo);

public:
    Menu(PetShop *petshop);
    ~Menu();
    void setPetshop(PetShop *petshop);
    PetShop *getPetshop();
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif