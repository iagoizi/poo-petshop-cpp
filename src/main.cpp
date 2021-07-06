#include "main.hpp"

int main()
{
    PetShop *petshop = initPetshop();
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

/*Configuração padrão do petshop, com alguns produtos, funcionários e serviços*/
PetShop *initPetshop()
{
    PetShop *petshop = new PetShop("Puppycat");
    Administrador *admin = new Administrador(petshop, "Adimênia");
    petshop->getUsuarios().push_back(admin);
    admin->cadastrarServico("Tosa", 200.0, 1);
    admin->cadastrarServico("Banho", 50.0, 2);
    admin->cadastrarProduto("Brinquedo de osso", 14.99, 20, 1);
    admin->cadastrarProduto("Coleira", 24.99, 10, 2);
    admin->cadastrarProduto("Brinquedo de bolinha", 9.99, 15, 3);

    admin->cadastrarVeterinario("João Vitor Vaz", "Joao", "123", 2.49);
    admin->cadastrarVendedor("Danielle", "Danielle", "123", 1100);

    return petshop;
}