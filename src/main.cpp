#include "main.hpp"
int main()
{
    /*cadastro manual de usuário <APENAS PARA TESTES>*/
    PetShop petshop = PetShop("Puppycat");
    petshop.getUsuarios().push_back(Vendedor(&petshop, "Vendy Claudia", "vendedor", "senha"));
    petshop.getUsuarios().push_back(Veterinario(&petshop, "Vet Samira", "veterniria", "senha"));
    petshop.getUsuarios().push_back(Administrador(&petshop, "Adimênia"));
    string usuarioTeste = "vendedor";
    string senhaTeste = "senha";

    //Aqui começa o main de verdade
    int op = 1;
    bool loggedIn = false;
    Menu *menu = petshop.login(usuarioTeste, senhaTeste, &loggedIn);
    cout << (loggedIn ? "Login efetuado com sucesso" : "Usuário ou senha incorretos") << endl;
    do
    {
        menu->printMenu();
        cin >> op;
        menu->realizaOperacao(op);
    } while (op != OPCODE_SAIDA);
    return 0;
}
