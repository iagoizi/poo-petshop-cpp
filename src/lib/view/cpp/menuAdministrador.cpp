#include "../hpp/menuAdministrador.hpp"
#include "../../model/hpp/administrador.hpp"

MenuAdministrador::MenuAdministrador(PetShop *petshop) : Menu(petshop), MenuVendedor(petshop), MenuVeterinario(petshop)
{
}

MenuAdministrador::~MenuAdministrador()
{
}

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

void MenuAdministrador::menuCadastrarVendedor()
{
    printTitulo("Cadastrando Vendedor...");
    Administrador *administrador = getAdministrador();
    string nome;
    string usuario;
    string senha;
    double salario;

    cout << "Vendedor" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tUsuário: ";
    cin >> usuario;
    cout << "\tSenha: ";
    cin >> senha;
    cout << "\tSalário: ";
    cin >> salario;

    administrador->cadastrarVendedor(nome, usuario, senha, salario);
    this->popUp = "Cadastro realizado com sucesso!";
}

void MenuAdministrador::menuCadastrarVeterinario()
{
    printTitulo("Cadastrando Veterinário...");
    Administrador *administrador = getAdministrador();
    string nome;
    string usuario;
    string senha;
    double salario;

    cout << "Veterinário" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tUsuário: ";
    cin >> usuario;
    cout << "\tSenha: ";
    cin >> senha;
    cout << "\tSalário: ";
    cin >> salario;
    administrador->cadastrarVeterinario(nome, usuario, senha, salario);
    this->popUp = "Cadastro realizado com sucesso!";
}

void MenuAdministrador::menuCadastrarProdutos()
{
    printTitulo("Cadastrando Produto...");
    Administrador *administrador = getAdministrador();
    string nome;
    double preco;
    int quantidade;
    long id;

    cout << "Produto" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tPreço: ";
    cin >> preco;
    cout << "\tQuantidade: ";
    cin >> quantidade;
    cout << "\tId: ";
    cin >> id;

    bool jaCadastrado = false;
    administrador->buscarProduto(id, &jaCadastrado);
    if (jaCadastrado)
    {
        this->popUp = "Produto já cadastrado";
    }
    else
    {
        administrador->cadastrarProduto(nome, preco, quantidade, id);
        this->popUp = "Cadastro realizado com sucesso!";
    }
}

void MenuAdministrador::menuCadastrarServicos()
{
    printTitulo("Cadastrando Serviço...");
    Administrador *administrador = getAdministrador();
    string nome;
    double preco;
    long id;

    cout << "Serviço" << endl
         << "\tNome: ";
    cin >> nome;
    cout << "\tPreço: ";
    cin >> preco;
    cout << "\tId: ";
    cin >> id;

    bool jaCadastrado = false;
    administrador->buscarServico(id, &jaCadastrado);
    if (jaCadastrado)
    {
        this->popUp = "Serviço já cadastrado";
    }
    else
    {
        administrador->cadastrarServico(nome, preco, id);
        this->popUp = "Cadastro realizado com sucesso!";
    }
}

void MenuAdministrador::menuListarFuncionarios()
{
    printTitulo("Listando Funcionários...");
    Administrador *administrador = getAdministrador();
    //Criar listar vendedores e veterinarios
    administrador->listarFuncionarios();
    esperarEnter();
}

void MenuAdministrador::menuReporEstoque()
{
    printTitulo("Repondo Estoque...");
    Administrador *administrador = getAdministrador();
    administrador->listarProdutos();
    int quantidade;
    long id;
    bool jaCadastrado = false;
    double preco;
    cout << "Produto" << endl;
    cout << "\tID: ";
    cin >> id;
    cout << "\tPreço de aquisição: ";
    cin >> preco;

    Produto produto = administrador->buscarProduto(id, &jaCadastrado);
    string nomeProduto = produto.getNome();

    if (jaCadastrado)
    {
        cout << "\tQuantidade: ";
        cin >> quantidade;
        administrador->reposicaoEstoque(produto, quantidade, nomeProduto, (preco * quantidade));
        this->popUp = "Reposição de estoque realizada com sucesso!";
    }
    else
    {
        this->popUp = "Produto inexistente no estoque!";
    }
}

void MenuAdministrador::menuPagamentoContas()
{
    printTitulo("Pagando Contas...");
    Administrador *administrador = getAdministrador();
    string descricao;
    double valor;

    cout << "Conta" << endl
         << "\tDescricao: ";
    cin.ignore();
    getline(cin, descricao);
    cout << "\tData: " << endl;
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

    administrador->pagarConta(descricao, data, valor);
    this->popUp = "Pagamento realizado com sucesso!";
}

void MenuAdministrador::menuRelatorios()
{
    printTitulo("Relatórios");
    Administrador *administrador = getAdministrador();
    administrador->gerarRelatorio();
    esperarEnter();
}

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

void MenuAdministrador::realizaOperacao(int op)
{
    Menu::realizaOperacao(op);
    cout << endl
         << endl;
    switch (op)
    {
    case VENDER_PRODUTO_ADMIN:
        menuVenderProduto();
        break;
    case VENDER_SERVICO_ADMIN:
        menuVenderServico();
        break;
    case CADASTRAR_CLIENTE_ADMIN:
        menuCadastrarCliente();
        break;
    case LISTAR_CLIENTES_ADMIN:
        menuListarClientes();
        break;
    case CADASTRAR_PRODUTOS_ADMIN:
        menuCadastrarProdutos();
        break;
    case CADASTRAR_SERVICOS_ADMIN:
        menuCadastrarServicos();
        break;
    case REGISTRAR_TRATAMENTO_ADMIN:
        menuRegistrarTratamento();
        break;
    case LISTAR_ORDENS_SERVICO_ADMIN:
        menuListarOrdensDeServicos();
        break;
    case CADASTRAR_VENDEDOR:
        menuCadastrarVendedor();
        break;
    case CADASTRAR_VETERINARIO:
        menuCadastrarVeterinario();
        break;

    case LISTAR_FUNCIONARIOS:
        menuListarFuncionarios();
        break;
    case REPOR_ESTOQUE:
        menuReporEstoque();
        break;
    case PAGAR_CONTAS:
        menuPagamentoContas();
        break;
    case GERAR_RELATORIOS:
        menuRelatorios();
        break;
    default:
        if (op != OPCODE_SAIDA)
            //Coloca para a mensagem aparecer lá em cima do menu principal.
            this->popUp = "Opção não encontrada";
        break;
    }
}