#ifndef PILHA_H
#define PILHA_H
#include "Carta.h"
#include <iostream>

template <class T>
class Pilha {
    public:
        Pilha();
        virtual ~Pilha();
        bool empilha(T);
        T desempilha();
        int rtopo(){return topo;}
        int rtam(){return tamanho;}
        int soma_elementos();


    private:
        T pilha[52];
        int topo;
        int tamanho;
        bool Vazia();
        bool Cheia();
};

template<class T>
Pilha<T>::Pilha() {
    topo = -1;
    tamanho = 0;
}

template<class T>
Pilha<T>::~Pilha(){}

template<class T>
bool Pilha<T>::empilha(T c){
    if (Cheia())
        return false;
    pilha[topo+1] = c;
    topo++;
    tamanho++;
    return true;
}

template<class T>
T Pilha<T>::desempilha(){
    try{
        if(Vazia())
            throw 0;
        T retorno = pilha[topo];
        topo--;
        tamanho--;
        return retorno;
    }catch(int e){
        std::cout << "Impossivel desempilhar de uma pilha vazia";
    }
}

template<class T>
bool Pilha<T>::Vazia(){
    return (tamanho == 0);
}
template<class T>
int Pilha<T>::soma_elementos(){
    int resultado=0;
    for(int index = 0; index < tamanho; index++){
        resultado = pilha[index]+resultado;
    }
    return resultado;
}
template<class T>
bool Pilha<T>::Cheia(){
    return (tamanho == 52);
}

#endif // PILHA_H
