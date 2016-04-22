#ifndef JOGADOR_H
#define JOGADOR_H
#include<string>
#include"Carta.h"
#include"Pilha.h"

// Sobrecarga do operador "cout<<" para impressão do nome do jogador
#include<iostream>
using std::ostream;


class Jogador
{
    public:
        Jogador(std::string nome);
        virtual ~Jogador();
        int soma_mao();
        void coloca_na_mao(Carta c);
        std::string getNome();
        std::string repr_mao();

        // Sobrecarga do operador "cout<<" para impressão do nome do jogador
        friend ostream& operator<< (ostream& os, Jogador &p){
            os << p.getNome();
            return os;
        }
        bool get_isDerrotado();
        void set_isDerrotado(bool);

    private:
        Pilha<Carta> mao;
        std::string repr;
        std::string Nome;
        bool isDerrotado;   // Se true, quer dizer que o respectivo jogador perdeu
};

#endif // JOGADOR_H
