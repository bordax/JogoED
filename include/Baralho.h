#ifndef BARALHO_H
#define BARALHO_H
#include "Pilha.h"
#include "Carta.h"

class Baralho
{
    public:
        Baralho();
        virtual ~Baralho();
        void embaralhar();
        Carta Tira_Topo(); //Tira permanentemente uma carta do topo do baralho
        Carta Tira_E_Recoloca(); //Tira a carta do topo do baralho, retorna e recoloca

    private:
        Pilha<Carta> baralho;
};

#endif // BARALHO_H
