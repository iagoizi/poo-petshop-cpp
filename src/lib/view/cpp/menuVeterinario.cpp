#include "../hpp/menuVeterinario.hpp"

MenuVeterinario::MenuVeterinario(PetShop* petshop) : Menu(petshop){} 
MenuVeterinario::~MenuVeterinario(){}

Veterinario* MenuVeterinario::getVeterinario(){
    Veterinario* veterinario = dynamic_cast< Veterinario* >(this->petshop->getSessaoAtual());
    if(!veterinario){
        printErro("ERRO NO CASTING DE VETERINÁRIO");
        return NULL;
    }
    return veterinario;
}
void MenuVeterinario::menuListarOrdensDeServicos(){
    printTitulo("Lista de Ordens de Serviços:");
    Veterinario* veterinario = getVeterinario();
    veterinario->listarOrdemServico();

}
void MenuVeterinario::menuListarClientes(){
    printTitulo("Lista de Clientes:");
    this->petshop->getClientes();

}
void MenuVeterinario::menuBuscarOrdensDeServico(){
    printTitulo("Busca de ordens de serviços");
    Veterinario* veterinario = getVeterinario();
    long cpf;
    bool clienteCadastrado;

    printTitulo("Dados do cliente:");
    cout << "\tCPF: "; cin >> cpf;
    Cliente cliente = veterinario->buscarCadastro(cpf, &clienteCadastrado);
    if(!clienteCadastrado){
        printErro("Cliente não cadastrado!");
    }else{
        printTitulo("Dados da data da ordem de serviço agendada:");
        Data dataAgendada;
        int dia, mes, ano, hora, minuto;
        cout << "\tHora: "; cin >> hora;
        cout << "\tMinuto: "; cin >> minuto;
        cout << "\tDia: "; cin >> dia;
        cout << "\tMes: "; cin >> mes;
        cout << "\tAno: "; cin >> ano;
        dataAgendada = Data(dia, mes, ano, hora, minuto);
        bool ordemCadastrada;
        OrdemServico ordemServico = veterinario->buscarOrdemServico(cliente, dataAgendada, &ordemCadastrada);
        if(!ordemCadastrada){
            printErro("Ordem de serviço não cadastrada!");
        }else{
            printTitulo("Ordem de serviço encontrada: ");
            cout << ordemServico;
        }
    } 
    cout << endl;
    
}
void MenuVeterinario::menuRegistrarTratamento(){
    printTitulo("Cadastro de tratamento");
     Veterinario* veterinario = getVeterinario();
    long cpf;
    bool clienteCadastrado;

    printTitulo("Dados do cliente:");
    cout << "\tCPF: "; cin >> cpf;
    Cliente cliente = veterinario->buscarCadastro(cpf, &clienteCadastrado);
    if(!clienteCadastrado){
        printErro("Cliente não cadastrado!");
    }else{
        printTitulo("Dados da data da ordem de serviço agendada:");
        Data dataAgendada;
        int dia, mes, ano, hora, minuto;
        cout << "\tHora: "; cin >> hora;
        cout << "\tMinuto: "; cin >> minuto;
        cout << "\tDia: "; cin >> dia;
        cout << "\tMes: "; cin >> mes;
        cout << "\tAno: "; cin >> ano;
        dataAgendada = Data(dia, mes, ano, hora, minuto);
        bool ordemCadastrada;
        OrdemServico ordemServico = veterinario->buscarOrdemServico(cliente, dataAgendada, &ordemCadastrada);
        if(!ordemCadastrada){
            printErro("Ordem de serviço não cadastrada!");
        }else{
            printTitulo("Ordem de serviço encontrada: ");
            cout << ordemServico;
        }
    } 
    cout << endl;
} 

void MenuVeterinario::printMenu(){
    Menu::printMenu();
    printTitulo("MENU VETERINÁRIO");
    printOpcao(REGISTRAR_TRATAMENTO, "Registrar tratamento");
    printOpcao(LISTAR_CLIENTES, "Listar clientes do PetShop");
    printOpcao(LISTAR_ORDENS_SERVICO, "Listar Ordens de Serviço");
    printOpcao(BUSCAR_ORDENS_SERVICO, "Buscar Ordem de Serviço");
    cout << endl 
         << endl;
}
void MenuVeterinario::realizaOperacao(int op){
    Menu::realizaOperacao(op);
    cout << endl
         << endl;
    switch (op){
        case REGISTRAR_TRATAMENTO:{
            menuRegistrarTratamento();
            break;
        }
        case LISTAR_CLIENTES:{
            menuListarClientes();
            break;
        }
        case LISTAR_ORDENS_SERVICO:{
            menuListarOrdensDeServicos();
            break;
        }
        case BUSCAR_ORDENS_SERVICO:{
            menuBuscarOrdensDeServico();
            break;
        }
        default:
            if(op != OPCODE_SAIDA)
                //Coloca para a mensagem aparecer lá em cima do menu principal.
                this->popUp = "Opção não encontrada";
            break;
    }
}