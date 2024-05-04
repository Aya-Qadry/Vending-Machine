#include "Keypad.h"
#include<iostream>
using namespace std ;

Keypad::Keypad()
{
    //ctor
}

Keypad::~Keypad()
{
    //dtor
}

int Keypad::getSelection(){
    cout<<"  Enter the product's number : " ;
    int id ;
    cin>>id  ;
    return id ;
}
