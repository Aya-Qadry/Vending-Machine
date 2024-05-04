#include "SmallSlot.h"
#include<string>
using namespace std ;
#include<iostream>

SmallSlot::SmallSlot(int id , string name , int p , int motor): Slot(id, name, p)
{
    motor1 = new Moteur(motor) ;
}

SmallSlot::~SmallSlot()
{
    //dtor
}

void SmallSlot::drop() const{
    motor1->Trigger() ;
   // cout<<productName<<" dropping"<<endl ;
}
