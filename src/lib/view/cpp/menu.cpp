#include "../hpp/menu.hpp"

Menu::Menu(PetShop petshop) : petshop(petshop)
{
}
void Menu::setPetshop(PetShop petshop)
{
    this->petshop = petshop;
}
PetShop Menu::getPetshop()
{
    return this->petshop;
}