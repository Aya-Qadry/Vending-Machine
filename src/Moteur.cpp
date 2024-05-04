#include "Moteur.h"
using namespace std ;
#include<iostream>

Moteur::Moteur()
{
    //ctor
}

Moteur::~Moteur()
{
    //dtor
}
Moteur::Moteur(int motor)
{
    id = motor ;
}

void Moteur::Trigger(){
    cout<<"  Motor "<<id<<" is turning"<<endl ;

}
