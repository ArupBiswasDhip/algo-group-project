#ifndef PRAPPO_H
#define PRAPPO_H

#include <iostream>
#include <vector>
using namespace std;

void runTotalCombinations()
{
    int n, targetBudget;

    cout << "\n=== Total Product Combinations ===\n";

    cout << "Enter number of available products: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid number of products!\n";
        return;
    }

    vector<int> productPrices(n);

    cout << "Enter prices of the products:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> productPrices[i];

        if(productPrices[i] <= 0)
        {
            cout << "Product price must be positive!\n";
            return;
        }
    }

    cout << "Enter the target shopping budget: ";
    cin >> targetBudget;

    if(targetBudget < 0)
    {
        cout << "Invalid budget!\n";
        return;
    }

    vector<vector<long long> > dp(
        n + 1,
        vector<long long>(targetBudget + 1, 0)
    );

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= targetBudget; j++)
        {
            if(productPrices[i-1] <= j)
            {
                dp[i][j] =
                    dp[i-1][j] +
                    dp[i][j - productPrices[i-1]];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << "\nTarget Budget: " << targetBudget << endl;

    cout << "Total possible product combinations: "
         << dp[n][targetBudget] << endl;
}

#endif
