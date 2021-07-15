# Sistema de PetShop

## Descrição do projeto

    Projeto desenvolvido como atividade avaliativa da disciplina BCC221 UFOP. 
O presente trabalho prático foi idealizado por meio da linguagem de programação C++, uma das principais linguagens na área de desenvolvimento de software. Além disso, é um projeto construído utilizando **os paradigmas de Programação Orientada a Objetos**, cujo principal objetivo é facilitar modelagens e o desenvolvimento de sistemas, já que possui uma maior aproximação com a vida real. Além disso, buscamos seguir os princípios **SOLID** com o objetivo de facilitar a manutenção e estensão do projeto.

O projeto consiste na implementação de um sistema de **controle e gerenciamento de uma loja Pet Shop**. Para isso, foi construído o diagrama UML, sendo este o principal responsável pelo norteamento da implementação das classes do sistema, assim como seus atributos e métodos. Além disso, por meio do UML, a visualização da comunicação entre cada classe tornou-se ainda mais clara. 

## Ambiente de desenvolvimento e ferramentas

- gcc versão: 9.3.0
- make versão: 4.2.1

## Instruções de compilação e execução

Para compilar e executar o programa, basta clonar esse repositório e executar os seguintes comandos:

```
cd src
make
make run
```
## Descrição da arquitetura

Cada tipo de usuário tem um certo conjunto de poderes, sendo o usuário administrador um "faz tudo". Na imagem abaixo, temos um diagrama de funcionalidades descrevendo o que cada um pode fazer.

![Funcionalidades](https://i.imgur.com/AaS21Xl.jpg)

Descrevendo detalhadamente cada classe da arquitetura implementada, temos: 
- **PetShop:** classe responsável pelo controle geral do estabelecimento, a qual possui acesso a todas as outras e contém todas as informações para o devido funcionamento da mesma.

- **Usuário:** classe virtual, e também classe da qual todas as classes relacionadas aos indivíduos do estabelecimentos irão herdar atributos e métodos, sendo essas as informações que eram gerais para todos esses.

- **Veterinário:** classe que herda características da classe usuário, e como foi nomeada, representa os veterinários do estabelecimento.

- **Vendedor:** como a classe veterinário, também herda as informações gerais da classe usuário, e representa os vendedores que trabalham na clínica.

- **Administrador:** como essa classe, além de atributos e métodos especiais para ela, também possui os mesmos que qualquer outro funcionário do PetShop, foi implementada de forma que herdasse essas informações da classe usuário, veterinário e vendedor. Como citado, ela possui alguns métodos que são destinados a ter controle total sobre o estabelecimento.

![Diagrama dos usuários](https://i.imgur.com/PDsKfOI.jpg)

No lugar de colocar a visualização dos dados e menus de cada usuário dentro do próprio usuário, decidimos colocar isso em classes separadas buscando seguir os príncipios SOLID. Dessa maneira, as classes Veterinario, Vendedor, Administrador e Usuario se tornam **mais reutilizáveis independentemente da camada de visualização dos dados** que coloquemos por cima delas. Isso facilitará, e muito, na hora de substituir a visualização de dados que temos no momento por algo mais interessante como uma interface gráfica.

- **Menu:** Classe com funções mais genéricas que vão ser utiizadas pelos demais menus. Ela tem também um atributo chamado popUp que armazena uma mensagem a ser mostrada na tela para o usuário.

- **MenuVendedor:** Classe responsável por imprimir na tela as operações acessíveis para o vendedor, fazendo as entradas e saídas necessárias para cumprir essas operações.

- **MenuVenterinario:** Classe responsável por imprimir na tela as operações acessíveis para o veterinário, fazendo as entradas e saídas necessárias para cumprir essas operações.

- **MenuAdministrador:** Classe responsável por imprimir na tela as operações acessíveis para o administrador, fazendo as entradas e saídas necessárias para cumprir essas operações.

![Diagrama dos menus](https://i.imgur.com/zykmr8n.jpg)

- **Cliente:** apesar de representar indivíduos que se relacionam com a clínica, ela independe da classe usuário, pois contém atributos e métodos próprios que representam somente os clientes. 

- **Produto:** classe que representa todos os produtos que serão comercializados na clínica.

- **Serviço:** criada com o intuito de representar os serviços oferecidos, como por exemplo, banho, tosa e atendimento veterinário.

- **OrdemServico:** classe que irá receber o serviço vendido para um cliente, sendo nessa classe a especificação de quando ele será realizado, sendo possível explicitar também se foi para algum cliente cadastrado ou não. Nessa classe, será permitido para atendimentos veterinários o preenchimento pelo veterinário as informações relacionadas ao tratamento realizado.

- **Conta:** classe destinada para organizar os pagamentos internos do PetShop, como contas de luz, água, entre outros.

- **Compra:** classe direcionada para a compra de produtos ou equipamentos para a clínica. Podendo envolver desde produtos para vendas, a produtos e equipamentos para seu funcionamento. 

- **Data:** classe utilizada para guardar qualquer informação relacionada às datas. Datas de serviços, de pagamentos ou vencimentos de contas. 

![Diagrama do petshop](https://i.imgur.com/BVg6hXf.jpg)

## Decisões de projeto 

- ### **Não persistência dos dados (dados voláteis)**

Em um cenário real, não faz sentido existir um sistema de gerenciamento de estoque, compras/vendas de serviços, funcionários e clientes se os dados desse sistema não persistirem. Porém, como o objetivo deste trabalho é treinar e praticar conceitos, paradigmas e implementação em POO, **a persistência dos dados não foi implementada** e, portanto, os dados do sistema são voláteis (os dados existem apenas durante a execução do programa).

Para facilitar testes, alguns produtos (osso, coleira, bolinha), serviços (tosa, banho) e funcionários já vem cadastrados.

- ### **Classes separadas para os menus**

No lugar de colocar a visualização dos dados e menus de cada usuário dentro do próprio usuário, decidimos colocar isso em classes separadas buscando seguir os príncipios SOLID. Dessa maneira, as classes Veterinario, Vendedor, Administrador e Usuario se tornam **mais reutilizáveis independentemente da camada de visualização dos dados** que coloquemos por cima delas. Isso facilitará, e muito, na hora de substituir a visualização de dados que temos no momento por algo mais interessante como uma interface gráfica.

- ### **Classe Petshop como um agregado de atributos**

Decidimos criar a classe PetShop de maneira que ela permitisse acessar todos os dados e informações do sistema, diminuindo assim a quantidade de parâmetros em funções que dependem de diversos dados do sistema. Sendo assim, a classe PetShop nada mais é que um apanhado de informações/atributos.

## Dificuldades encontradas

Quando se trabalha com Programação Orientada a Objetos em C++, é comum acabar se deparando com alguns problemas e, nessa atividade, não foi diferente. 
O famoso **Problema do Diamante** apareceu logo no início da implementação, uma vez que, segundo nossa arquitetura, a classe Administrador herda tanto de Veterinário quanto de Vendedor e ambas herdam de Usuário. 
Com isso, na hora de acessar os membros de Usuário a partir de um objeto Administrador, o compilador ficava confuso sobre qual dos caminhos seguir. 
Para resolver esse problema, tivemos que usar **herança virtual**, uma vez que ela garante que apenas uma instância dos membros da classe base seja associada ao objeto da classe "neta". 
Além de estar presente no Administrador, esse problema também ocorreu na classe MenuAdministrador, já que ela herda de MenuVendedor e MenuVeterinario e ambas herdam de Menu.

Um outro problema associado ao Problema do Diamante aconteceu na hora de fazer o downcast da classe Usuário e Menu para uma de suas classes filhas. Na hora de fazer o **downcast com base virtual** numa hierarquia diamante, encontramos um problema. Estávamos tentando fazer o *casting* usando *static_cast*, mas o compilador sempre acusava erro. Depois de muito pesquisar, descobrimos que, nesse caso, como estamos lidando com **polimorfismo** e é necessário informação em tempo de execução, devemos usar *dynamic_cast*.

Além do Problema do Diamante e dos problemas relacionados ao downcast com base virtual, nos deparamos com **referências cíclicas (dependências circulares)**. 
A Classe Usuário precisava saber de Petshop, uma vez que um de seus atributos é da classe Petshop e, com isso, ela precisava de uma implementação completa de Petshop para conseguir alocar o espaço necessário para aquele atributo. 
Porém, Petshop também precisava conhecer a implementação completa de Usuário, já que ela possui um atributo da classe Usuário. 
Sem conseguir encontrar implementações completas dessas duas classes, o compilador lançava uma mensagem de erro e dizia que os tipos estavam incompletos. 
Para resolver esse problema, usamos **o recurso de implementação tardia (*forward declarations*)** e mudamos os atributos problemáticos dessas classes para ponteiros.
