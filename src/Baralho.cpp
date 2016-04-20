#include "Baralho.h"
#include "Carta.h"
#include <cstdlib>
#include <ctime>

Baralho::Baralho()
{
    int naipe,valor;
    for(naipe=1; naipe <=4; naipe++){
        for(valor = 1; valor <=13; valor++){
            baralho.empilha(Carta(naipe,valor));
        }
    }
}

Baralho::~Baralho(){}

void Baralho::embaralhar()
{
    int random_index;
    Carta aux;
    std::srand(std::time(0));
    Carta tmp[52];
    for(int index = 0; index < 52; index++)
        tmp[index] = baralho.desempilha();
    for(int index = 0; index < 52; index++){
        random_index = std::rand() % 51; //gera um numero pseudo aleatório entre 0 e 51
        aux = tmp[index];
        tmp[index] = tmp[random_index];
        tmp[random_index] = aux;
    }
    for(int index = 0; index <52; index++)
        baralho.empilha(tmp[index]);

}

Carta Baralho::Tira_E_Recoloca()
{
    Carta c =  baralho.desempilha();
    baralho.empilha(c);
    return c;
}

Carta Baralho::Tira_Topo()
{
    return baralho.desempilha();
}
