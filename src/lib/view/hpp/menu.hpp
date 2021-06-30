#ifndef MENU_HPP
#define MENU_HPP

#include "../../model/hpp/lib.hpp"
#include "../../model/hpp/petshop.hpp"
#include "../../model/hpp/usuario.hpp"

using namespace std;

class Menu
{
protected:
    PetShop petshop;

public:
    Menu(PetShop petshop);
    ~Menu();
    void setPetshop(PetShop petshop);
    PetShop getPetshop();
    virtual void printMenu() = 0;
    virtual void realizaOperacao(int op) = 0;
};
#endif