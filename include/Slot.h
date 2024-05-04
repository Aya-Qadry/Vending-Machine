
using namespace std;
#ifndef SLOT_H
#define SLOT_H
#include<string>
#include "Moteur.h"
class Slot
{
    public:
        Slot(int slotId , string nom,int prix);
        Slot(const Slot& s) ;
        Slot() ;
        virtual ~Slot();
        virtual void drop() const = 0 ;

        string getProductName(){return productName;};
        void setProductName(string name){productName = name ;};

        int getNumProducts(){return numProduits ;};
        void setNumProducts(int num){numProduits = num ; };

        int getPrice(){return prix;};
        void setPrice(int p){prix = p;};
        int getId(){return slotId ;} ;

    protected:

    private:
        string productName;
        int slotId ;
        int numProduits ;
        int prix ;

};

#endif // SLOT_H
