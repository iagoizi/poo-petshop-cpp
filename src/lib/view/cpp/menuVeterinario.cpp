#include "../hpp/menuVeterinario.hpp"

MenuVeterinario::MenuVeterinario(PetShop *petshop) : Menu(petshop) {}
MenuVeterinario::~MenuVeterinario() {}

Veterinario *MenuVeterinario::getVeterinario()
{
    Veterinario *veterinario = dynamic_cast<Veterinario *>(this->petshop->getSessaoAtual());
    if (!veterinario)
    {
        printErro("ERRO NO CASTING DE VETERINÁRIO");
        return NULL;
    }
    return veterinario;
}

void MenuVeterinario::menuListarOrdensDeServicos()
{
    printTitulo("Lista de Ordens de Serviços:");
    Veterinario *veterinario = getVeterinario();
    veterinario->listarOrdemServico();
    esperarEnter();
}
void MenuVeterinario::menuListarClientes()
{
    printTitulo("Lista de Clientes:");
    Veterinario *veterinario = getVeterinario();
    veterinario->listarClientes();
    esperarEnter();
}

void MenuVeterinario::menuBuscarOrdensDeServico()
{
    printTitulo("Busca de ordens de serviços");
    Veterinario *veterinario = getVeterinario();
    int id;
    //long cpf;
    //bool clienteCadastrado;
    Cliente cliente;

    printTitulo("Digite o ID da ordem de serviço:");
    cout << "\tID: ";
    cin >> id;

    bool ordemCadastrada;
    OrdemServico ordemServico = veterinario->buscarOrdemServico(id, &ordemCadastrada);
    if (!ordemCadastrada)
    {
        this->popUp = "Ordem de serviço não cadastrada!";
    }
    else
    {
        //int dia, mes, ano, hora, minuto;
        this->popUp = "Ordem de serviço encontrada: " + cliente.getNome() + " - " + ordemServico.getServico().getNome();
    }

    cout << endl;
}

//Corrigir Registrar Tratamento
void MenuVeterinario::menuRegistrarTratamento()
{
    printTitulo("Cadastro de tratamento");
    Veterinario *veterinario = getVeterinario();
    int id;

    printTitulo("ID da Ordem de Serviço:");
    cout << "\tID: ";
    cin >> id;
    bool resposta;
    OrdemServico ordemServico = veterinario->buscarOrdemServico(id, &resposta);

    if (!resposta)
    {
        printErro("Ordem de serviço não cadastrada!");
        //Atualizando a mensagem de pop-up
        this->popUp = "Ordem de serviço não encontrada";
    }
    else
    {
        cout << "Adicione uma observação relacionada ao tratamento: ";
        string tratamento;
        cin.ignore();
        getline(cin, tratamento);
        veterinario->registrarTratamento(ordemServico, tratamento);
        //Atualizando a mensagem de pop-up
        this->popUp = "Tratamento registrado com sucesso";
    }

    cout << endl;
}

void MenuVeterinario::printMenu()
{
    Menu::printMenu();
    printTitulo("MENU VETERINÁRIO");
    printOpcao(REGISTRAR_TRATAMENTO, "Registrar tratamento");
    printOpcao(LISTAR_CLIENTES, "Listar clientes do PetShop");
    printOpcao(LISTAR_ORDENS_SERVICO, "Listar Ordens de Serviço");
    printOpcao(BUSCAR_ORDENS_SERVICO, "Buscar Ordem de Serviço");
    cout << endl
         << endl;
}

void MenuVeterinario::realizaOperacao(int op)
{
    Menu::realizaOperacao(op);
    cout << endl
         << endl;
    switch (op)
    {
    case REGISTRAR_TRATAMENTO:
    {
        menuRegistrarTratamento();
        break;
    }
    case LISTAR_CLIENTES:
    {
        menuListarClientes();
        break;
    }
    case LISTAR_ORDENS_SERVICO:
    {
        menuListarOrdensDeServicos();
        break;
    }
    case BUSCAR_ORDENS_SERVICO:
    {
        menuBuscarOrdensDeServico();
        break;
    }
    default:
        if (op != OPCODE_SAIDA)
            //Coloca para a mensagem aparecer lá em cima do menu principal.
            this->popUp = "Opção não encontrada";
        break;
    }
}