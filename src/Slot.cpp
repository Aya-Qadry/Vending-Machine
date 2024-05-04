#include "Slot.h"
#include <string>
#include "Moteur.h"
using namespace std ;

Slot::Slot(int id , string nom,int p)
{
    productName = nom ;
    prix = p ;
    numProduits = 0 ;
    slotId = id ;
}

Slot::~Slot()
{
//    delete motor1 ;
  //  delete motor2 ;
}

Slot::Slot()
{
    productName = "" ;
    prix = 0 ;
    numProduits = 0 ;
    slotId = -1 ;
}

Slot::Slot(const Slot &s){
    productName = s.productName;
    prix = s.prix ;
    numProduits = s.numProduits ;
    slotId = s.slotId ;
}
