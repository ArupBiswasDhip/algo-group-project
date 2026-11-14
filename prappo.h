#ifndef PRAPPO_H
#define PRAPPO_H

#include <iostream>
#include <vector>
using namespace std;

void runTotalCombinations()
{
    int n, targetBudget;
    cout << "=== Total Product Combinations ===" << endl;
    cout << "Enter number of available products: ";
    cin >> n;

    vector<int> productPrices(n);
    cout << "Enter prices of the products:\n";
    for (int i = 0; i < n; i++) {
        cin >> productPrices[i];
    }

    cout << "Enter the target shopping budget: ";
    cin >> targetBudget;

    vector<vector<int> > dp(n + 1, vector<int>(targetBudget + 1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=targetBudget; j++)
        {
            if(productPrices[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j - productPrices[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << "Total possible product combinations: " << dp[n][targetBudget] << endl;
}

#endif
