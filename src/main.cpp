#include "main.hpp"

int main()
{
    //string usuarioTeste, senhaTeste;
    //PetShop *petshop = testes(&usuarioTeste, &senhaTeste);
    //Aqui começa o main de verdade
    PetShop *petshop = new PetShop("Puppycat");
    petshop->getUsuarios().push_back(new Administrador(petshop, "Adimênia"));
    int op = 0;
    bool loggedIn = false;
    string usuario, senha;
    while (op != OPCODE_SAIDA)
    {
        cout << "LOGIN" << endl
             << "Usuário: ";
        cin >> usuario;
        cout << "Senha: ";
        cin >> senha;
        Menu *menu = petshop->login(usuario, senha, &loggedIn);
        cout << (loggedIn ? "Login efetuado com sucesso" : "Usuário ou senha incorretos") << endl;
        //Enquanto o usuario estiver logado
        while (op != OPCODE_SAIDA && loggedIn)
        {
            menu->printMenu();
            cout << "-> Escolha uma opção: ";
            cin >> op;
            menu->realizaOperacao(op);
        }
        cout << "Fechar o programa? Se sim, digite " << OPCODE_SAIDA
             << ". Se quiser continuar, digite qualquer valor:  " << endl;
        cin >> op;
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
    *usuarioTeste = "vendedor";
    *senhaTeste = "senha";
    return petshop;
}