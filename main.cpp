#include <iostream>
#include "Carta.h"
#include "Pilha.h"
#include "Baralho.h"
using namespace std;

int main()
{
    Baralho b;
    Carta topo;
    b.embaralhar();
    for(int index = 0; index < 52; index++){
        topo = b.Tira_Topo();
        cout << topo.repr() << endl;
    }


    return 0;


}
