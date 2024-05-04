#include "WideSlot.h"
#include<iostream>
using namespace std ;

WideSlot::WideSlot(int id , string name , int p , int motor1Id , int motor2Id): Slot(id, name, p)
{
    motor1 = new Moteur(motor1Id) ;
    motor2 = new Moteur(motor2Id) ;
}

WideSlot::~WideSlot()
{
    delete motor1 ;
    delete motor2 ;

}

void WideSlot::drop() const{
    motor1->Trigger() ;
    motor2->Trigger() ;

}
