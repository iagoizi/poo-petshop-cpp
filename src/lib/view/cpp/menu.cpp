#include "../hpp/menu.hpp"
#include "../../model/hpp/petshop.hpp"

Menu::Menu(PetShop *petshop) : petshop(petshop)
{
}
Menu::~Menu()
{
}
void Menu::setPetshop(PetShop *petshop)
{
    this->petshop = petshop;
}
PetShop *Menu::getPetshop()
{
    return this->petshop;
}
void Menu::printOpcao(int opcode, string label)
{
    cout << opcode << " - " << label << endl;
}
void Menu::printMenu()
{
    cout << "Usuário não logado." << endl;
}
void Menu::realizaOperacao(int op)
{
    cout << "Sem login, não há nada que pode ser feito." << endl;
}