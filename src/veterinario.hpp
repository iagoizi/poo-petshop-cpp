#ifndef VETERINARIO_HPP
#define VETERINARIO_HPP

#include "lib.hpp"

class Veterinario : virtual public Usuario{

public:
    Veterinario(string nome = "", string cargo = "", string usuario = "", string senha = "", double salario = 0.0);
    ~Veterinario();

    void registrarTratamento(OrdemServico ordem);
    Cliente buscarCadastro(long cpf);
    void listarOrdemServico();

};

#endif