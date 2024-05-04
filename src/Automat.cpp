#include "Automat.h"
#include<vector>
#include"Slot.h"
#include<string>
using namespace std ;
#include<iostream>
Automat::Automat(int nSlots, int perslot)
{
    numSlots = nSlots ;
    numProductPerSlot = perslot ;
    slots.reserve(numSlots) ;
    cached = nullptr ;
}

Automat::~Automat()
{
    slots.clear();
    delete cached;
}


Slot* Automat::searchSlot(int slotId){
    if (cached == nullptr || cached->getId() != slotId) {
        for(int i=0 ; i<numSlots ; i++){
            if(slots[i]->getId() == slotId){
                cached = slots[i] ;
            }
        }
    }
    return cached ;
}
/*
bool Automat::addSlot(string name , int p , int slotId , int motorId){
    Slot *slot = new Slot(slotId,name,p) ;
    slots.push_back(slot);
}*/

void Automat::addSlot(Slot *s){
    slots.push_back(s) ;
}

void Automat::changeSlot(int id , string name , int p ){
    Slot* s = searchSlot(id);
        s->setPrice(p);
        s->setProductName(name);

}

int Automat::getPrice(int id){
    Slot* s = searchSlot(id) ;
    if (s != nullptr) {
        return s->getPrice();
    }
    return -1;
}

int Automat::getPieces(int id){
    if (Slot* slot = searchSlot(id)) {
        return slot->getNumProducts();
    }
    return -1;
}

bool Automat::estDisponible(int id){
    int number = getPieces(id) ;
    if(number != 0 ){
         return true ;
    }else{
        return false ;
    }
}

bool Automat::dropSlot(int id){
    if(estDisponible(id)){
        Slot *slot = searchSlot(id);
        slot->drop();
        return true;
    }
    return false;
}

void Automat::fillAll(){
    for(Slot *s : slots)
        s->setNumProducts(numProductPerSlot) ;
}

void Automat::fill_(int id, int numprdts ){
    Slot* s = searchSlot(id) ;
    if(s){
        s->setNumProducts(numprdts) ;
    }
}

