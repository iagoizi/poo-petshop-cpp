#include "main.hpp"

int main()
{
    string usuarioTeste, senhaTeste;
    PetShop *petshop = testes(&usuarioTeste, &senhaTeste);

    //Aqui começa o main de verdade
    int op = 2;
    bool loggedIn = false;
    Menu *menu = petshop->login(usuarioTeste, senhaTeste, &loggedIn);
    cout << (loggedIn ? "Login efetuado com sucesso" : "Usuário ou senha incorretos") << endl;
    while (op != OPCODE_SAIDA && loggedIn)
    {
        menu->printMenu();
        cout << "-> Escolha uma opção: ";
        cin >> op;
        menu->realizaOperacao(op);
    }
    return 0;
}

/*cadastro manual de usuário <APENAS PARA TESTES>*/
PetShop *testes(string *usuarioTeste, string *senhaTeste)
{
    PetShop *petshop = new PetShop("Puppycat");
    petshop->getUsuarios().push_back(new Vendedor(petshop, "Vendy Claudia", "vendedor", "senha"));
    petshop->getUsuarios().push_back(new Veterinario(petshop, "Vet Samira", "veterinaria", "senha"));
    petshop->getUsuarios().push_back(new Administrador(petshop, "Adimênia"));
    *usuarioTeste = "veterinaria";
    *senhaTeste = "senha";
    return petshop;
}