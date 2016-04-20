#ifndef JOGADOR_H
#define JOGADOR_H
#include<string>
#include"Carta.h"
#include"Pilha.h"
class Jogador
{
    public:
        Jogador(std::string nome);
        virtual ~Jogador();
        int soma_mao();
        void coloca_na_mao(Carta c);
        std::string getNome();
        std::string repr_mao();


    private:
        Pilha<Carta> mao;
        std::string repr;
        std::string Nome;
};

#endif // JOGADOR_H
