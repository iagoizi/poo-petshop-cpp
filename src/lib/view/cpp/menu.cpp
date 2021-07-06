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

void Menu::printMenu()
{
    //Limpando a tela.
    cout << string(3, '\n');
    //Imprime a mensagem de pop-up (caso não esteja vazia).
    cout << (!this->popUp.empty() ? ("(" + this->popUp + ")") : "") << endl
         << endl;
    //Imprimindo a opção de saída (mesmo valor para todos os menus).
    cout << "\t\t\t\t\t" << OPCODE_SAIDA << " : LOG OUT" << endl;
}

void Menu::realizaOperacao(int op)
{
    //Limpa a mensagem de pop-up para que ela não se perpetue para os tempos seguintes.
    this->popUp.clear();
}

void Menu::printErro(string mensagem)
{
    cout << "\t\t\t**" << mensagem << endl;
}

void Menu::printOpcao(int opcode, string label)
{
    cout << setw(2) << opcode << " - " << label << endl;
}

void Menu::printTitulo(string titulo)
{
    cout << "\t\t" << titulo << endl
         << endl;
}

void Menu::esperarEnter()
{
    char c;
    cout << "Digite qualquer coisa para continuar" << endl;
    cin >> c;
}