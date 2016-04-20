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
            _valor = "Ás";
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
Carta::Carta(){}
Carta::~Carta(){}
