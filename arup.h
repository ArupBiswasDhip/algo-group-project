#ifndef ARUP_H
#define ARUP_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int run01Knapsack()
{
    int n, capacity;
    cout << "=== 0/1 Knapsack Algorithm ===" << endl;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), profit(n);
    vector<string> name(n);

    cout << "Enter names of items:\n";
    for(int i=0; i<n; i++) cin >> name[i];

    cout << "Enter weights of items:\n";
    for(int i=0; i<n; i++) cin >> weight[i];

    cout << "Enter profit of items:\n";
    for(int i=0; i<n; i++) cin >> profit[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<vector<int> > ks(n+1, vector<int>(capacity+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int c=1; c<=capacity; c++)
        {
            if(weight[i-1] <= c)
                ks[i][c] = max(ks[i-1][c], profit[i-1] + ks[i-1][c-weight[i-1]]);
            else
                ks[i][c] = ks[i-1][c];
        }
    }

    cout << "Maximum profit: " << ks[n][capacity] << endl;
    return ks[n][capacity];
}

#endif
