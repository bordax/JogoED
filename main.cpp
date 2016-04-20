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
        cout << topo.GetNaipe() << " " << topo.GetValor() << endl;
    }



//    Pilha<Carta> p;
//    int i = 0, j=0;
//    for (i=0;i<52;i++,j++){
//    cout << "Tamanho antes> " << p.rtam() << endl;
//    cout << "Topo antes> " << p.rtopo() << endl;
//    p.empilha(Carta(i,j));
//    cout << "Tamanho depois> " << p.rtam() << endl;
//    cout << "Topo depois> " << p.rtopo() << endl;
//    }
//
//    Carta a = p.desempilha();
//    Carta b = p.desempilha();
//
//    cout << endl << a.GetNaipe() << " " << a.GetValor() << endl;
//    cout << endl << b.GetNaipe() << " " << b.GetValor() << endl;
    return 0;


}
