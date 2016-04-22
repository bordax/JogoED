#include "Carta.h"
#include <sstream>
Carta::Carta(int naipe, int valor)
{
    Naipe = naipe;
    Valor = valor;
}
std::string Carta::repr(){
    std::string _naipe, _valor;
    switch (Naipe){
        case 1:
            _naipe="Paus";
            break;
        case 2:
            _naipe="Copas";
            break;
        case 3:
            _naipe="Ouros";
            break;
        case 4:
            _naipe="Espadas";
            break;
        default:
            _naipe = "Errado";
            break;
    }
    switch (Valor){
        case 1:
            _valor = "As";
            break;
        case 11:
            _valor = "Valete";
            break;
        case 12:
            _valor = "Dama";
            break;
        case 13:
            _valor = "Rei";
            break;
        default:
            std::ostringstream convert;
            convert << Valor;
            _valor = convert.str();
            break;
    }
    return (_valor + " de " + _naipe);

}
int Carta::operator+(Carta c){
    int valorc2;
    switch(c.Valor){
        case 11:
            valorc2 = 11;
            break;
        case 12:
            valorc2 = 12;
            break;
        case 13:
            valorc2 = 13;
            break;
        default:
            valorc2 = c.Valor;
            break;
    }
    return Valor + valorc2;
}
int Carta::operator+(int v){
    int valorc2;
    switch(Valor){
        case 11:
            valorc2 = 11;
            break;
        case 12:
            valorc2 = 12;
            break;
        case 13:
            valorc2 = 13;
            break;
        default:
            valorc2 = Valor;
            break;
    }
    return valorc2+v;
}
Carta::Carta(){}
Carta::~Carta(){}
