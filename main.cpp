/* ------
JOGO 21 DOS BROTHER
AUTORES: Gabriel Gonçalves (628123)
         Rafael Bordin     (59algumacoisa)
         Tulio Reis        (628050)
DESCRIÇÃO: Jogo baseado nas regras do clássico de baralho "21"
JOGADORES: 2
----- */

#include <iostream>
#include <stdlib.h> // system("cls");
#include "Carta.h"
#include "Pilha.h"
#include "Baralho.h"
#include "Jogador.h"
using namespace std;


int menu_inicial();
Jogador cria_jogador(int i);
void Capitalizar(string&);
bool Rodada(Jogador&, Baralho&, bool&); //
void isGanhando(Jogador, Jogador); //
int contadorCartas=52;  // Contador global de cartas

void imprimeRegras();
void imprimeMao(Jogador);

int main(){
    int resposta = menu_inicial();
    if(resposta !=3) {
        if(resposta==2)
            imprimeRegras();
        Jogador j1 = cria_jogador(1);
        Jogador j2 = cria_jogador(2);
        bool p1=false, p2=false;
        bool opt1=true, opt2=true;


        // Criando e embaralhando o baralho do jogo
        Baralho mesa;
        mesa.embaralhar();
        cout << "O baralho foi embaralhado!" << endl;


        // Computando as rodadas de uma partida
        do{
            p1 = Rodada(j1, mesa, opt1);
            p2 = Rodada(j2, mesa, opt2);
            system("cls");
        }while((opt1)&&(opt2));

        while((opt1) && (!p2)){
            p1 = Rodada(j1, mesa, opt1);
            imprimeMao(j2);
            }
        while((opt2) && (!p1)){
            imprimeMao(j1);
            p2 = Rodada(j2, mesa, opt2);
        }

        // Comparativo e impressão do placar da partida realizada
        isGanhando(j1,j2);

        return 1;
    }else
        return 0;
}



int menu_inicial(){
    cout << "--------Bem vindo ao 21 dos Brother!--------" << endl;
    cout << "1. Comecar Jogo\n";
    cout << "2. Regras\n";
    cout << "3. Sair\n";
    int op;
    do {
        cin >> op;
        if(op!=1 && op!=2 && op!=3)
            cout << "Resposta invalida! Escolha uma opcao do menu acima.\n";
    }while (op!=1 && op!=2 && op!=3);
    return op;
}

Jogador cria_jogador(int i){
    string nome;
    cout<<"Digite o nome do Jogador " << i << ": ";
    cin >> nome;
    Capitalizar(nome); //
    return Jogador(nome);
}

//
// Função que deixa em caixa alta o parâmetro entrado por referência
void Capitalizar(string& x){
    for(int i=0; i<int(x.length()); i++)
        if ((x[i]>=97)&&(x[i]<=122))
            x[i]-=32;
}

// Função para processar cada rodada de uma partida
bool Rodada(Jogador& j, Baralho &mesa, bool &opt){
    string opcao = "s";
    Carta topo;

    topo = mesa.Tira_Topo();
    j.coloca_na_mao(topo);

    cout << endl;
    cout << "Mao do(a) " << j << ": " << j.repr_mao() << endl;
    cout << "Soma dos itens na mao do(a) " << j << ": " << j.soma_mao() << endl;
    if(j.soma_mao() > 21){
        cout << "Perdeu!!\n\n";
        j.set_isDerrotado(true);
        opt = false;
        return false;
    }
    if(j.soma_mao()==21){
        cout << "Ganhou!!\n\n";
        j.set_isDerrotado(false);
        opt = false;
        return false;
    }
    cout << j << ", deseja retirar outra carta? (S/N)" << endl;
    cin >> opcao;
    Capitalizar(opcao);

    if (opcao=="S"){
        opt = true;
        return true;
    }
    else{
        opt = false;
        return false;
    }
}

// Função de comparação e impressão dos resultados de uma partida
void isGanhando(Jogador j1, Jogador j2) {
    system("cls");
    imprimeMao(j1);
    imprimeMao(j2);

    if(j1.get_isDerrotado() && j2.get_isDerrotado())    // Se os dois perderam
        cout << "NINGUEM VENCEU!\n";

    if(j1.get_isDerrotado() && !j2.get_isDerrotado())   // Somente o j1 foi derrotado
        cout << j2 << " VENCEU!\n";

    if(!j1.get_isDerrotado() && j2.get_isDerrotado())   // Somente o j2 foi derrotado
        cout << "\n\n" << j1 << " VENCEU!\n";

    if(!j1.get_isDerrotado() && !j2.get_isDerrotado()){ // Ninguém perdeu ainda, isto é, os dois escolheram parar
        if(j1.soma_mao()>j2.soma_mao())                 // Compara quem tem a soma mais próxima de 21
            cout << "\n\n" << j1 << " VENCEU!\n";
        else if(j1.soma_mao()<j2.soma_mao())
            cout << "\n\n" << j2 << " VENCEU!\n";
        else                                            // Se a soma dos dois é igual, há empate
            cout << "\n\nNINGUEM VENCEU!\n";
    }
}

void imprimeRegras(){
    system("cls");
    cout << "BEM-VINDO AO JOGO 21 DOS BROTHER!\n\n\
        O jogo eh como o classico jogo de cartas no qual o objetivo eh acumular a soma de 21 dentre a\
s cartas da sua mao. Dessa forma, se voce tem um 3 de Copas e um 5 de Espadas, por exemplo, a sua som\
a sera 8. Todos os naipes tem valores iguais nessa versao do jogo.\n\
        Alem disso, para aumentar o dinamismo das partidas, as cartas As valem 1, os Valetes valem 11\
, as Rainhas valem 12 e os Reis valem 13. Quem somar 21 pontos ganha! Porem se os dois jogadores soma\
rem 21 pontos na mao, ninguem vence. Quem ultrapassar 21 perde.\n\
        Se a pessoa decidir que esta bem proxima de somar 21 pontos e nao quer se arriscar a mais uma\
rodada, ela pode encerrar a partida dela ali. Nesse cenario, o jogador que mais se aproximar de 21 (s\
em ultrapassar) vence.\n\n\
        PRESSIONE ENTER PARA COMECAR O JOGO\n\n";
    system("pause>>clean");
    system("cls");
}

void imprimeMao(Jogador j){
    cout << endl;
    cout << "Mao do(a) " << j << ": " << j.repr_mao() << endl;
    cout << "Soma dos itens na mao do(a) " << j << ": " << j.soma_mao() << endl;
}
