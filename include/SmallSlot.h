#ifndef SMALLSLOT_H
#define SMALLSLOT_H

#include <Slot.h>
#include"Moteur.h"
#include<string>

class SmallSlot : public Slot
{
    public:
        SmallSlot(int slotId , string productName , int price , int motor1Id);
        virtual ~SmallSlot();
        void drop() const ;

    protected:

    private:
        Moteur *motor1 ;

};

#endif // SMALLSLOT_H
