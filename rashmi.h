ifndef RASHMI_H
#define RASHMI_H

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void runMinCoins()
{
    int n, amount;
    cout << "=== Minimum Coins / Change Return ===" << endl;
    cout << "Enter number of coin/note types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter values of coins/notes:\n";
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter the change amount: ";
    cin >> amount;

    vector<vector<int> > dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amount; j++)
        {
            if(coins[i-1] <= j)
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int result = (dp[n][amount] == INT_MAX - 1) ? -1 : dp[n][amount];
    cout << "Minimum coins/notes needed: " << result << endl;
}

#endif
