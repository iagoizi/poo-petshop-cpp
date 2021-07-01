#include "../hpp/menuVendedor.hpp"

MenuVendedor::MenuVendedor(PetShop *petshop) : Menu(petshop)
{
}

MenuVendedor::~MenuVendedor()
{
}

Vendedor *MenuVendedor::getVendedor()
{
    Vendedor *vendedor = dynamic_cast<Vendedor *>(this->petshop->getSessaoAtual());
    if (!vendedor)
    {
        printErro("ERRO NO CASTING");
        return NULL;
    }
    return vendedor;
}

void MenuVendedor::menuCadastrarCliente()
{
    printTitulo("Cadastrando cliente...");
    Vendedor *vendedor = getVendedor();
    string nome,
        nomePet, tipoAnimal, endereco;
    int tel;
    long cpf;
    /*Pegando as informações do usuário*/
    cout << "Cliente" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tEndereço: ";
    cin >> endereco;
    cout << "\tTelefone: ";
    cin >> tel;
    cout << "\tCPF: ";
    cin >> cpf;

    cout << endl
         << "PET" << endl
         << "\tNome do pet: ";
    cin >> nomePet;
    cout << "\tTipo do animal: ";
    cin >> tipoAnimal;

    /*Conferindo para ver se o cliente já não está cadastrado*/
    bool jaCadastrado = false;
    vendedor->buscarCadastro(cpf, &jaCadastrado);
    if (jaCadastrado)
    {
        //Coloca para a mensagem aparecer lá em cima do menu principal.
        this->popUp = "Cliente já cadastrado no sistema!";
    }
    else
    {
        vendedor->cadastrarCliente(nome, tipoAnimal, nomePet, endereco, tel, cpf);
        //Coloca para a mensagem aparecer lá em cima do menu principal.
        this->popUp = "Cadastro realizado com sucesso!";
    }
}
void MenuVendedor::menuVenderProduto()
{
    printTitulo("Lista de produtos cadastrados:");
    Vendedor *vendedor = getVendedor();
    vendedor->listarProdutos();

    long id = OPCODE_SAIDA;
    int qtd = 0;
    bool success = false;
    vector<Produto> carrinho;
    Produto produto, produtoCarrinho;
    do
    {
        cout << "Deseja comprar o produto..." << endl
             << "\tId: ";
        cin >> id;
        if (id != OPCODE_SAIDA)
        {
            produto = vendedor->buscarProduto(id, &success);
            if (success)
            {
                cout << "\tQuantidade: ";
                cin >> qtd;
                if (qtd <= produto.getQuantidade())
                {
                    produtoCarrinho = produto.clone();
                    produtoCarrinho.setQuantidade(qtd);
                    carrinho.push_back(produtoCarrinho);
                }
                else
                {
                    printErro("Quantidade insuficiente!");
                }
            }
            else
            {
                printErro("Produto não encontrado!");
            }
        }
        cout << endl;
    } while (id != OPCODE_SAIDA);

    if (!carrinho.empty())
    {
        /*Finalizando a compra*/
        Cliente comprador = compradorPossuiCadastro(vendedor);
        vendedor->vendaProduto(comprador, carrinho);
        //Coloca para a mensagem aparecer lá em cima do menu principal.
        this->popUp = "Compra registrada com sucesso!";
    }
}
void MenuVendedor::menuVenderServico()
{
    printTitulo("Lista de serviços cadastrados:");
    Vendedor *vendedor = getVendedor();

    vendedor->listarServicos();

    long id = OPCODE_SAIDA;
    bool success = true;
    Servico servicoCarrinho;

    do
    {
        if (!success)
        {
            printErro("Serviço não encontrado");
        }
        cout << "Deseja agendar o servico..." << endl
             << "\tId: ";
        cin >> id;
        servicoCarrinho = vendedor->buscarServico(id, &success);
    } while (id != OPCODE_SAIDA && !success);

    /*Caso o usuário não tenha cancelado a operação, marcamos a data*/
    if (id != OPCODE_SAIDA)
    {
        int dia, mes, ano, hora, min;
        cout << "Data" << endl
             << "\tDia: ";
        cin >> dia;
        cout << "\tMês: ";
        cin >> mes;
        cout << "\tAno: ";
        cin >> ano;
        cout << "\tHora: ";
        cin >> hora;
        cout << "\tMinuto: ";
        cin >> min;
        Data dataAgendada = Data(dia, mes, ano, hora, min);
        /*Finalizando a compra*/
        Cliente comprador = compradorPossuiCadastro(vendedor);
        vendedor->vendaServico(comprador, servicoCarrinho, dataAgendada);
        //Coloca para a mensagem aparecer lá em cima do menu principal.
        this->popUp = "Serviço agendado com sucesso!";
    }
}

Cliente MenuVendedor::compradorPossuiCadastro(Vendedor *vendedor)
{
    cout << "Comprador tem cadastro? (Se sim, digite 'sim'. Senão, apenas aperte enter) ";
    string sim;
    cin >> sim;
    /*A priori, o cliente é dado como desconhecido*/
    Cliente comprador = Cliente("Desconhecido");
    if (sim.compare("sim") == 0)
    {
        long cpf;
        cout << "CPF do cliente: ";
        cin >> cpf;
        /*Conferindo para ver se o cliente está cadastrado*/
        bool jaCadastrado = false;
        comprador = vendedor->buscarCadastro(cpf, &jaCadastrado);
        if (!jaCadastrado)
        {
            cout << "-> Cliente não cadastrado" << endl;
        }
        else
        {
            cout << "Criar cadastro?  (Se sim, digite 'sim'. Senão, apenas aperte enter) ";
            cin >> sim;
            if (sim.compare("sim") == 0)
            {
                menuCadastrarCliente();
                comprador = vendedor->buscarCadastro(cpf, &jaCadastrado);
            }
        }
    }
    return comprador;
}

void MenuVendedor::printMenu()
{
    Menu::printMenu();
    printTitulo("MENU VENDEDOR");
    printOpcao(CADASTRAR_CLIENTE, "Cadastrar novo cliente");
    printOpcao(VENDER_PRODUTO, "Vender produtos");
    printOpcao(VENDER_SERVICO, "Vender serviços");
    cout << endl
         << endl;
}
void MenuVendedor::realizaOperacao(int op)
{
    Menu::realizaOperacao(op);
    cout << endl
         << endl;
    switch (op)
    {
    case CADASTRAR_CLIENTE:
        menuCadastrarCliente();
        break;
    case VENDER_PRODUTO:
        menuVenderProduto();
        break;
    case VENDER_SERVICO:
        menuVenderServico();
        break;
    default:
        if (op != OPCODE_SAIDA)
            //Coloca para a mensagem aparecer lá em cima do menu principal.
            this->popUp = "Opção não encontrada";
        break;
    }
}