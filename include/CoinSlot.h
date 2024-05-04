#ifndef COINSLOT_H
#define COINSLOT_H


class CoinSlot
{
    public:
        CoinSlot();
        virtual ~CoinSlot();

        int updateCoinAmount(int p) ;
        int getCoinAmount() ;
        void clear_() ;
        void returnCoins(int price, int v) ;
        void setCoinAmount(int s){insertedAmount = s ; } ;

    protected:

    private:
        int insertedAmount ;
        int coinValues[7] = {200,100,50,20,10,5,1};
};

#endif // COINSLOT_H
