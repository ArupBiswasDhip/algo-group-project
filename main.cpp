#include <iostream>

#include "prappo.h"
#include "arup.h"
#include "olid.h"
#include "rashmi.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "        SMART SHOPPING SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Total Product Combinations\n";
        cout << "2. 0/1 Knapsack\n";
        cout << "3. Fractional Knapsack\n";
        cout << "4. Minimum Coin Change\n";
        cout << "0. Exit\n";

        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                runTotalCombinations();
                break;

            case 2:
                run01Knapsack();
                break;

            case 3:
                runFractionalKnapsack();
                break;

            case 4:
                runMinCoins();
                break;

            case 0:
                cout << "\nThank you for using "
                     << "Smart Shopping System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while(choice != 0);

    return 0;
}
