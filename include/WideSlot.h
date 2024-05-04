#ifndef WIDESLOT_H
#define WIDESLOT_H
#include"Moteur.h"
#include<string>
#include"Slot.h"

class WideSlot : public Slot
{
    public:
        WideSlot(int slotId , string productName , int price , int motor1Id , int motor2Id);
        virtual ~WideSlot();
        void drop()const ;

    protected:

    private:
        Moteur *motor1 ;
        Moteur *motor2 ;

};

#endif // WIDESLOT_H
