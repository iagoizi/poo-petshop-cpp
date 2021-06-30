#ifndef MENU_HPP
#define MENU_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/usuario.hpp"

using namespace std;

class Menu
{
protected:
    PetShop *petshop;

public:
    Menu(PetShop *petshop);
    ~Menu();
    void setPetshop(PetShop *petshop);
    PetShop *getPetshop();
    void printOpcao(int opcode, string label);
    virtual void printMenu();
    virtual void realizaOperacao(int op);
};
#endif