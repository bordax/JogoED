#ifndef CARTA_H
#define CARTA_H

//Naipe:
//      1 = Paus
//      2 = Copas
//      3 = Ouros
//      4 = Espadas
//Valor:
//      1 = Ás
//      11 = Valete
//      12 = Dama
//      13 = Rei

class Carta
{
    public:
        Carta(int naipe, int valor);
        Carta();
        virtual ~Carta();

        int GetNaipe() { return Naipe; }
        void SetNaipe(int val) { Naipe = val; }
        int GetValor() { return Valor; }
        void SetValor(int val) { Valor = val; }

    private:
        int Naipe;
        int Valor;
};

#endif // CARTA_H
