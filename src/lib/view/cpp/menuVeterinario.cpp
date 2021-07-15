#include "../hpp/menuVeterinario.hpp"
/*Intância o menu por meio de lista de valores
Usa os dados do sistema PetShop*/
MenuVeterinario::MenuVeterinario(PetShop *petshop) : Menu(petshop) {}
MenuVeterinario::~MenuVeterinario() {}

Veterinario *MenuVeterinario::getVeterinario()
{
    /*Pega o usuário veterinário logado na sessão atual*/
    Veterinario *veterinario = dynamic_cast<Veterinario *>(this->petshop->getSessaoAtual());
    if (!veterinario)
    {
        printErro("ERRO NO CASTING DE VETERINÁRIO");
        return NULL;
    }
    return veterinario;
}
/*Métodos de prints de título, erro e opções de um Menu são utilizadas 
nos menus de veterinário.
O atributo popUp de Menu é usada para atulizar um popUp na tela*/
void MenuVeterinario::menuListarOrdensDeServicos()
{
    printTitulo("Lista de Ordens de Serviços:");
    Veterinario *veterinario = getVeterinario();
    /*Chamada do método de listagem de Ordens de serviço
    para mostrar na tela as ordens.*/
    veterinario->listarOrdemServico();
    /*Método de um Menu para esperar um retorno de um usuáro veterinário*/
    esperarEnter();
}
void MenuVeterinario::menuListarClientes()
{
    printTitulo("Lista de Clientes:");
    Veterinario *veterinario = getVeterinario();
     /*Chamada do método para fazer a listagem de clientes na tela*/
    veterinario->listarClientes();
    esperarEnter();
}

void MenuVeterinario::menuBuscarOrdensDeServico()
{
    printTitulo("Busca de ordens de serviços");
    Veterinario *veterinario = getVeterinario();
    /*Para armazenar os valores para a busca de uma ordem de serviço*/
    int id;
    Cliente cliente;

    printTitulo("Digite o ID da ordem de serviço:");
    cout << "\tID: ";
    cin >> id;

    bool ordemCadastrada;
    /*Busca a Ordem de Serviço de acordo com o id informado pelo usuário
    retorna a ordem, e atuliza ou não a variável lógica ordemCadastra, para
    verificar se a ordem foi ou não encontrada*/
    OrdemServico ordemServico = veterinario->buscarOrdemServico(id, &ordemCadastrada);
    /*Caso não tenha a ordem com o id, é passada um mensagem para popUp
    Caso tenha, é passada uma menagem e os dados da Ordem de Serviço*/
    if (!ordemCadastrada)
    {
        this->popUp = "Ordem de serviço não cadastrada!";
    }
    else
    {
        this->popUp = "Ordem de serviço encontrada: " + cliente.getNome() + " - " + ordemServico.getServico().getNome();
    }

    cout << endl;
}

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
        /*Entrada da observação da Ordem de Serviço tratamento que foi
        encontrada*/
        cout << "Adicione uma observação relacionada ao tratamento: ";
        string tratamento;
        cin.ignore();
        getline(cin, tratamento);
        /*Chamada do método para fazer o registro do tratamento
        com os dados da ordem de serviço e a descrição do tratamento*/
        veterinario->registrarTratamento(ordemServico, tratamento);
        //Atualizando a mensagem de pop-up
        this->popUp = "Tratamento registrado com sucesso";
    }

    cout << endl;
}

void MenuVeterinario::printMenu()
{
    /*Printa o menu e inclui o Menu padrão com as opções
    das operações que usuário veterinário pode fazer no sistema*/
    Menu::printMenu();
    /*Chamadass do método de prinOpcao,
    passando a opção para chamar cada menu de veterinário 
    e os valores das labels de cada opção*/
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
    /*Realiza um opção de acordo com o valor de opção
    passado como parâmetro na função*/
    Menu::realizaOperacao(op);
    cout << endl
         << endl;
    /*Chama um menu de acordo com o valor de op,
    se o valor for -1, ele sai do menu de usuário veterinário*/
    switch (op) 
    /*são usadas as macros definidas, para chamar os menus de veterinário*/
    {
    case REGISTRAR_TRATAMENTO: // 1
    {
        menuRegistrarTratamento();
        break;
    }
    case LISTAR_CLIENTES: // 2
    {
        menuListarClientes();
        break;
    }
    case LISTAR_ORDENS_SERVICO: // 3
    {
        menuListarOrdensDeServicos();
        break;
    }
    case BUSCAR_ORDENS_SERVICO: // 4
    {
        menuBuscarOrdensDeServico();
        break;
    }
    default:
        if (op != OPCODE_SAIDA) // -1
            //Coloca para a mensagem aparecer lá em cima do menu principal.
            this->popUp = "Opção não encontrada";
        break;
    }
}