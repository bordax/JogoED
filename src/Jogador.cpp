#include "Jogador.h"

Jogador::Jogador(std::string nome)
{
    Nome = nome;
    repr = "";
    isDerrotado = false; //
}

int Jogador::soma_mao()
{
    return mao.soma_elementos();
}

void Jogador::coloca_na_mao(Carta c)
{
    mao.empilha(c);
    repr = repr + "\n" + c.repr();
}

std::string Jogador::getNome()
{
    return Nome;
}

std::string Jogador::repr_mao()
{
    return repr;
}

bool Jogador::get_isDerrotado()
{
    return isDerrotado;
}

void Jogador::set_isDerrotado(bool resultado)
{
    isDerrotado = resultado;
}

Jogador::~Jogador(){}

