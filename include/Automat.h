#ifndef AUTOMAT_H
#define AUTOMAT_H
#include "Slot.h"
#include<string>
#include"CoinSlot.h"
#include"Keypad.h"
#include"DropCheck.h"
#include<string>
#include<vector>

using namespace std ;

class Automat
{
    public:
        Automat(int numSlots , int perslot);
        virtual ~Automat();

        bool addSlot(string productName , int slotId , int motorId , int price ) ;
        void addSlot(Slot *slot) ;

        Slot* searchSlot(int slotId) ;
        void changeSlot(int slotId , string name , int price) ;

        int getPieces(int slotId) ;
        bool estDisponible(int slotId) ;
        int getPrice(int slotId) ;
        bool dropSlot(int slotId) ;
        void fillAll() ;
        void fill_(int slotId , int numProducts) ;

        int getNumSlots(){return numSlots ; } ;

        CoinSlot getCoinSlot(){return coinSlot ;};
        Keypad getKeypad(){return keypad ;} ;
        DropCheck getDropcheck(){return dropcheck ; };

        Slot* getCached(){return cached ;} ;

    protected:

    private:
        vector<Slot*> slots ;
        int numSlots ;
        int numProductPerSlot ;
        Slot* cached ;
        CoinSlot coinSlot ;
        Keypad keypad ;
        DropCheck dropcheck ;

};

#endif // AUTOMAT_H
