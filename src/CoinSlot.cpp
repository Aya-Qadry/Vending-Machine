#include "CoinSlot.h"
using namespace std ;
#include<iostream>
#include <algorithm>

CoinSlot::CoinSlot()
{
    insertedAmount = 0 ;
}

CoinSlot::~CoinSlot()
{
    //dtor
}
int CoinSlot::updateCoinAmount(int p) {
    cout << "  Enter coins (-1 to cancel) : " ;

    int coin;
    cin >> coin;

    while (coin != -1) {
        bool valid = false;
        for (int i = 0; i < 7; i++) {
            if (coin == coinValues[i]) {
                valid = true;
                break;
            }
        }

        if (valid) {
            insertedAmount = getCoinAmount() + coin;
            cout << "  Inserted amount : " << insertedAmount << endl;

            if (insertedAmount >= p) {
                break;
            }
        } else {
            cout << "  Invalid coin!" << endl;
        }
        int r = p - insertedAmount ;
        cout<<"  Insert "<<r<<" : " ;
        cin >> coin;
    }

    if (coin == -1) {
        return -1;
    } else {
         return insertedAmount;
    }
}

int CoinSlot::getCoinAmount(){
    return insertedAmount ;
}

void CoinSlot::returnCoins(int price , int v) {
    int difference = v - price;

    if (difference == 0) {
        cout<<"  Exact amount ! "<<endl;
        return;
    }
    cout<<endl;
    cout<<"  Returning coins: "<<endl;
    for (int i = 0; i < 7; i++) {
        int nbrCoins = difference / coinValues[i];
        if (nbrCoins > 0) {
            cout<<"  "<< nbrCoins <<" x "<< coinValues[i]<<" c"<<endl;
            difference -= nbrCoins * coinValues[i];
        }
    }
    clear_() ;
}
void CoinSlot::clear_(){
    insertedAmount = 0 ;
}


