#include "../hpp/menuAdministrador.hpp"
#include "../../model/hpp/administrador.hpp"

//Construtor do menu administrador
MenuAdministrador::MenuAdministrador(PetShop *petshop) : Menu(petshop), MenuVendedor(petshop), MenuVeterinario(petshop)
{
}

//Destrutor do menu administrador
MenuAdministrador::~MenuAdministrador()
{
}

/*Transforma o usuario logado em um usuario do tipo administrador,
permitindo a esse usuario o acesso a todas as funções do administrador*/
Administrador *MenuAdministrador::getAdministrador()
{
    Administrador *administrador = dynamic_cast<Administrador *>(this->petshop->getSessaoAtual());
    if (!administrador)
    {
        printErro("ERRO NO CASTING");
        return NULL;
    }
    return administrador;
}

//Menu responsavel pelo cadastro dos vendedores
void MenuAdministrador::menuCadastrarVendedor()
{
    printTitulo("Cadastrando Vendedor...");
    Administrador *administrador = getAdministrador();
    string nome;
    string usuario;
    string senha;
    double salario;

    //Saida e entrada de dados referentes ao vendedor
    cout << "Vendedor" << endl
         << "\tNome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "\tUsuário: ";
    cin >> usuario;
    cout << "\tSenha: ";
    cin >> senha;
    cout << "\tSalário: ";
    cin >> salario;

    //Chamada da função que cadastra o vendedor. Esta sendo passado todas as informações para cadastro
    administrador->cadastrarVendedor(nome, usuario, senha, salario);
    this->popUp = "Cadastro realizado com sucesso!";
}

//Menu que cadastra os veterinarios do PetShop
void MenuAdministrador::menuCadastrarVeterinario()
{   
    printTitulo("Cadastrando Veterinário...");
    Administrador *administrador = getAdministrador();
    string nome;
    string usuario;
    string senha;
    double salario;

    //Entrada e Saida de dados para coletar informações e realizar o cadastro do Veterinario
    cout << "Veterinário" << endl
         << "\tNome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "\tUsuário: ";
    cin >> usuario;
    cout << "\tSenha: ";
    cin >> senha;
    cout << "\tSalário: ";
    cin >> salario;
    //Função na qual passamos todos os dados para cadastrar um novo usuario veterinario
    administrador->cadastrarVeterinario(nome, usuario, senha, salario);
    this->popUp = "Cadastro realizado com sucesso!";
}

/* Menu semelhante aos anteriores porem direcionado ao cadastro de produtos */
void MenuAdministrador::menuCadastrarProdutos()
{
    printTitulo("Cadastrando Produto...");
    Administrador *administrador = getAdministrador();
    string nome;
    double preco;
    int quantidade;
    long id;

    /* Entrada de dados para realizar o cadastro de novos produtos */
    cout << "Produto" << endl
         << "\tNome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "\tPreço: ";
    cin >> preco;
    cout << "\tQuantidade: ";
    cin >> quantidade;
    cout << "\tId: ";
    cin >> id;

    bool jaCadastrado = false;
    /* Função que realiza a busca de produto, retornando true/false. 
    Informação utilizada para não cadastrar 2 produtos semelhantes */
    administrador->buscarProduto(id, &jaCadastrado);
    if (jaCadastrado)
    {   
        /*Print caso o produto ja esteja cadastrado*/  
        this->popUp = "Produto já cadastrado";
    }
    else
    {
        /*Caso o produto ainda não tenha sido cadastrado realizaremos seu cadastro.
        Sera passado todos os dados para tal ação. */
        administrador->cadastrarProduto(nome, preco, quantidade, id);
        //cout que confirma o cadastramento
        this->popUp = "Cadastro realizado com sucesso!";
    }
}

/* Mostra o menu para cadastrar novos serviços*/
void MenuAdministrador::menuCadastrarServicos()
{
    printTitulo("Cadastrando Serviço...");
    Administrador *administrador = getAdministrador();
    string nome;
    double preco;
    long id;

    //Solicita os dados necessarios para o cadastro do serviço.
    //Permite a entrada de dados para o cadastro
    cout << "Serviço" << endl
         << "\tNome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "\tPreço: ";
    cin >> preco;
    cout << "\tId: ";
    cin >> id;

    bool jaCadastrado = false;
    //Confere se ja possui um servico cadastrado no ID digitado
    administrador->buscarServico(id, &jaCadastrado);
    if (jaCadastrado)
    {
        //Caso ja possua um servico cadastrado nesse id
        this->popUp = "Serviço já cadastrado";
    }
    else
    {
        //Função que realiza o cadastro do serviço 
        administrador->cadastrarServico(nome, preco, id);
        this->popUp = "Cadastro realizado com sucesso!";
    }
}

//Lista todos os funcionarios cadastrados
void MenuAdministrador::menuListarFuncionarios()
{
    printTitulo("Listando Funcionários...");
    //Pega os dados do administrador do sistema
    Administrador *administrador = getAdministrador();
    //Chamada da função que realiza a listagem dos usuarios no terminal
    administrador->listarFuncionarios();
    //Função para usuario solicitar o continuação da execução do programa
    esperarEnter();
}

//Menu para a reposição do estoque dos produtos
void MenuAdministrador::menuReporEstoque()
{
    printTitulo("Repondo Estoque...");
    
    //Permite ao usuario acesso a função do administrador
    Administrador *administrador = getAdministrador();
    
    //Função que lista os produtos cadastrados     
    administrador->listarProdutos();

    int quantidade;
    long id;
    bool jaCadastrado = false;
    double preco;

    //Entrada dos dados para repor o estoque
    cout << "Produto" << endl;
    cout << "\tID: ";
    cin >> id;
    cout << "\tPreço de aquisição: ";
    cin >> preco;

    //Confere se o produto esta cadastrado
    Produto produto = administrador->buscarProduto(id, &jaCadastrado);
    string nomeProduto = produto.getNome();

    if (jaCadastrado)
    {   
        //Solicita a quantidade de itens que iremos repor do produto solicitado
        cout << "\tQuantidade: ";
        cin >> quantidade;
        /*Função que ira realizar todos os procedimentos de reposição de estoque: aumento da quantidade disponivel,
        registro da compra*/
        administrador->reposicaoEstoque(produto, quantidade, nomeProduto, (preco * quantidade));
        this->popUp = "Reposição de estoque realizada com sucesso!";
    }
    else
    {
        this->popUp = "Produto inexistente no estoque!";
    }
}

//Menu para pagar as contas 
void MenuAdministrador::menuPagamentoContas()
{
    printTitulo("Pagando Contas...");
    //Permite ao usuario acesso a função do administrador
    Administrador *administrador = getAdministrador();
    string descricao;
    double valor;

    //Entrada de todos os dados para realizar o pagamento de contas
    cout << "Conta" << endl
         << "\tDescricao: ";
    cin.ignore();
    getline(cin, descricao);
    cout << "\tData de vencimento: " << endl;
    Data data;
    int dia, mes, ano;

    cout << "\t-Dia: ";
    cin >> dia;
    cout << "\t-Mes: ";
    cin >> mes;
    cout << "\t-Ano: ";
    cin >> ano;
    data = Data(dia, mes, ano);
    cout << "\tValor: ";
    cin >> valor;

    //Função que realiza o cadastro da conta paga
    administrador->pagarConta(descricao, data, valor);
    this->popUp = "Pagamento realizado com sucesso!";
}

//Menu mostrado qual escolhemos gerar relatorios
void MenuAdministrador::menuRelatorios()
{
    printTitulo("Relatórios");
    Administrador *administrador = getAdministrador();
    //Chamada da função que gera relatorio
    administrador->gerarRelatorio();
    //Função que permite continuar a execução do programa
    esperarEnter();
}

//Função que mostra todas as opções do menu administrador
void MenuAdministrador::printMenu()
{
    Menu::printMenu();
    printTitulo("MENU ADMINISTRADOR");
    printOpcao(CADASTRAR_CLIENTE_ADMIN, "Cadastrar novo cliente");
    printOpcao(CADASTRAR_VENDEDOR, "Cadastrar novo vendedor");
    printOpcao(CADASTRAR_VETERINARIO, "Cadastrar novo veterinário");
    printOpcao(CADASTRAR_PRODUTOS_ADMIN, "Cadastrar novo produto");
    printOpcao(CADASTRAR_SERVICOS_ADMIN, "Cadastrar novo serviço");
    printOpcao(VENDER_PRODUTO_ADMIN, "Vender produtos");
    printOpcao(VENDER_SERVICO_ADMIN, "Vender serviços");
    printOpcao(LISTAR_FUNCIONARIOS, "Listar funcionários");
    printOpcao(LISTAR_CLIENTES_ADMIN, "Listar clientes do PetShop");
    printOpcao(LISTAR_ORDENS_SERVICO_ADMIN, "Listar Ordens de Serviço");
    printOpcao(REGISTRAR_TRATAMENTO_ADMIN, "Registrar tratamento");
    printOpcao(REPOR_ESTOQUE, "Repor estoque");
    printOpcao(PAGAR_CONTAS, "Pagar contas");
    printOpcao(GERAR_RELATORIOS, "Gerar relatórios");

    cout << endl
         << endl;
}

/*Função responsável pelo gerenciamento das decisoes do usuario,
mostrando os menus de acordo com a escolha do administrador*/
void MenuAdministrador::realizaOperacao(int op)
{
    Menu::realizaOperacao(op);
    //Espaço para organizar o menu
    cout << endl
         << endl;
    //Switch case que organiza as escolhas dos menus
    switch (op)
    {
    case VENDER_PRODUTO_ADMIN: // 6
        menuVenderProduto();
        break;
    case VENDER_SERVICO_ADMIN: // 7
        menuVenderServico();
        break;
    case CADASTRAR_CLIENTE_ADMIN: // 1
        menuCadastrarCliente();
        break;
    case LISTAR_CLIENTES_ADMIN: // 9
        menuListarClientes();
        break;
    case CADASTRAR_PRODUTOS_ADMIN: // 4
        menuCadastrarProdutos();
        break;
    case CADASTRAR_SERVICOS_ADMIN: // 5
        menuCadastrarServicos();
        break;
    case REGISTRAR_TRATAMENTO_ADMIN: // 11
        menuRegistrarTratamento();
        break;
    case LISTAR_ORDENS_SERVICO_ADMIN: // 10
        menuListarOrdensDeServicos();
        break;
    case CADASTRAR_VENDEDOR: // 2
        menuCadastrarVendedor();
        break;
    case CADASTRAR_VETERINARIO:  // 3
        menuCadastrarVeterinario();
        break;

    case LISTAR_FUNCIONARIOS:  // 8
        menuListarFuncionarios();
        break;
    case REPOR_ESTOQUE: // 12
        menuReporEstoque();
        break;
    case PAGAR_CONTAS: // 13
        menuPagamentoContas();
        break;
    case GERAR_RELATORIOS: // 14
        menuRelatorios();
        break;
    default:
        if (op != OPCODE_SAIDA)
            //Coloca para a mensagem aparecer lá em cima do menu principal.
            this->popUp = "Opção não encontrada";
        break;
    }
}