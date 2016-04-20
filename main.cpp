#include <iostream>
#include "Carta.h"
#include "Pilha.h"
#include "Baralho.h"
#include "Jogador.h"
using namespace std;
int menu_inicial();
Jogador cria_jogador(int i);
int main()
{
    if(menu_inicial()==1){
        Jogador j1 = cria_jogador(1);
        Jogador j2 = cria_jogador(2);

        string opcao = "S";
        Baralho mesa;
        mesa.embaralhar();
        cout << "O baralho foi embaralhado!" << endl;
        Carta topo;

        do{
            topo = mesa.Tira_Topo();
            j1.coloca_na_mao(topo);

            topo = mesa.Tira_Topo();
            j2.coloca_na_mao(topo);

            cout << "Mao: " << j1.repr_mao() << endl;
            cout << "Soma dos itens na mao: "<< j1.soma_mao()<<endl;
            if(j1.soma_mao() > 21){
                cout << "Perdeu!!";
                break;
            }
            if(j1.soma_mao()==21){
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

Jogador cria_jogador(int i){
    string nome;
    cout<<"Digite o nome do Jogador " << i << ": ";
    cin >> nome;
    return Jogador(nome);
}
