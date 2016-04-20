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
        Baralho b;
        b.embaralhar();

        cout << "O baralho foi embaralhado!" << endl;
        Carta topo;
        do{
            topo = b.Tira_Topo();
            cout << "Carta: " << topo.repr() << endl;
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
