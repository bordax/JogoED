#include <iostream>
#include "Carta.h"
#include "Pilha.h"
#include "Baralho.h"
using namespace std;
int menu_inicial();
int main()
{
    if(menu_inicial()==1){
        string opcao = "S";
        Baralho mesa;
        mesa.embaralhar();
        Pilha<Carta> maoplayer1;
        Pilha<Carta> maoplayer2;
        cout << "O baralho foi embaralhado!" << endl;
        Carta topo;
        do{
            topo = mesa.Tira_Topo();
            maoplayer1.empilha(topo);
            cout << "Carta: " << topo.repr() << endl;
            cout << "Soma dos itens na mao: "<< maoplayer1.soma_elementos()<<endl;
            if(maoplayer1.soma_elementos() > 21){
                cout << "Perdeu!!";
                break;
            }
            if(maoplayer1.soma_elementos()==21){
                cout << "Ganhou!!";
                break;
            }
            cout << "Deseja retirar outra carta? (S/N)" <<endl;
            cin >> opcao;
        }while (opcao=="S");
        return 1;
    }else{
        return 0;
    }

}
int menu_inicial(){
    cout << "--------Bem vindo ao 21 dos Brother!--------" << endl;
    cout<< "1. Começar Jogo"<< endl << "2. Sair"<<endl;
    int op;
    cin >> op;
    return op;
}
