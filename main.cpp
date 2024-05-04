#include <iostream>
using namespace std ;
void displayVendingMachine() {
    cout << "   _______________________________" << endl;
    cout << "  |        Vending Machine        |" << endl;
    cout << "  |  _________       _________    |" << endl;
    cout << "  | |Popcorn  |     |  Chips  |   |" << endl;
    cout << "  | |  500¢   |     |   400¢  |   |" << endl;
    cout << "  | |_________|     |_________|   |" << endl;
    cout << "  |      1                2       |" << endl;
    cout << "  |  _________       _________    |" << endl;
    cout << "  | |CocaCola |     |   Oreo  |   |" << endl;
    cout << "  | |  250¢   |     |   100¢  |   |" << endl;
    cout << "  | |_________|     |_________|   |" << endl;
    cout << "  |      3                4       |" << endl;
    cout << "  |                               |" << endl;
    cout << "  |_______________________________|" << endl;
    cout <<endl ;
   cout <<endl ;

}

#include "Automat.h"
#include "WideSlot.h"
#include "SmallSlot.h"
#include "Keypad.h"
#include "CoinSlot.h"
enum STATE {IDLE, COLLECT_MONEY, DROP, RETURN_MONEY};

int main()
{
    Automat vending_machine(4 , 6);
    Slot *slot1 = new WideSlot(1, "Popcorn", 500, 1, 2);
    vending_machine.addSlot(slot1) ;

    Slot *slot2 = new WideSlot(2, "Chips", 400, 3, 4);
    vending_machine.addSlot(slot2) ;

    Slot *slot3 = new SmallSlot(3,"Coca Cola",250,5);
    vending_machine.addSlot(slot3) ;

    Slot *slot4 = new SmallSlot(4, "Oreo", 100, 6);
    vending_machine.addSlot(slot4) ;

    int state = IDLE;
    int selection ;
    int value =0 ;

    Slot* selected_slot ;
    vending_machine.fillAll() ;

  while (true) {
        switch (state) {
            case IDLE: {
                displayVendingMachine() ;
                selection = vending_machine.getKeypad().getSelection();
                selected_slot = vending_machine.searchSlot(selection);
                if (selection == -1) {
                    return 0;
                } else if (selection >= 0 && selection <= vending_machine.getNumSlots()) {
                    state = COLLECT_MONEY;
                    int price = vending_machine.getPrice(selection);
                    vending_machine.getCached()->setPrice(price);
                    cout<<endl;
                    cout<< "  Price: " << price << endl;
                } else {
                    cout<< "  Invalid ID." << endl;
                }
                break;
            }

            case COLLECT_MONEY: {
                int coins = vending_machine.getCoinSlot().updateCoinAmount(vending_machine.getCached()->getPrice());
                if (coins == -1) {
                    state = RETURN_MONEY;
                    cout<<endl;
                } else {
                    value = coins;
                    state = DROP;
                    cout<<endl;
                }
                break;
            }

            case DROP: {
                if (vending_machine.dropSlot(vending_machine.getCached()->getId())) {
                    if (vending_machine.getDropcheck().productReleased()) {
                        state = RETURN_MONEY;
                        vending_machine.getCached()->setNumProducts(vending_machine.getCached()->getNumProducts() - 1);
                    } else {
                        // Product dropped successfully
                    }
                } else {
                    cout << "  Product stuck." << endl;
                }
                break;
            }

            case RETURN_MONEY: {
                vending_machine.getCoinSlot().returnCoins(vending_machine.getCached()->getPrice(), value);
                state = IDLE;
                value = 0 ;
                char choice;
                  cout<<endl;
                cout << "  Do you want to buy again? (Y/N): ";
                cin >> choice;
                if (choice == 'N' || choice == 'n') {
                    cout << "  Thank you for using our vending machine. Goodbye!" << endl;
                    return 0;
                }
                break;
            }

            default:
                cout << "  Invalid state." << endl;
        }
    }

    return 0;
}
