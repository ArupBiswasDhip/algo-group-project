#ifndef ARUP_H
#define ARUP_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int run01Knapsack()
{
    int n, capacity;

    cout << "\n=== 0/1 Knapsack Algorithm ===\n";
    cout << "Enter number of items: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid number of items!\n";
        return 0;
    }

    vector<int> weight(n), profit(n);
    vector<string> name(n);

    cout << "Enter names of items:\n";
    for(int i = 0; i < n; i++)
        cin >> name[i];

    cout << "Enter weights of items:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        if(weight[i] <= 0)
        {
            cout << "Weight must be positive!\n";
            return 0;
        }
    }

    cout << "Enter profits of items:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> profit[i];
        if(profit[i] < 0)
        {
            cout << "Profit cannot be negative!\n";
            return 0;
        }
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if(capacity < 0)
    {
        cout << "Invalid capacity!\n";
        return 0;
    }

    vector<vector<int> > ks(
        n + 1, vector<int>(capacity + 1, 0)
    );

    for(int i = 1; i <= n; i++)
    {
        for(int c = 1; c <= capacity; c++)
        {
            if(weight[i-1] <= c)
            {
                ks[i][c] = max(
                    ks[i-1][c],
                    profit[i-1] + ks[i-1][c-weight[i-1]]
                );
            }
            else
            {
                ks[i][c] = ks[i-1][c];
            }
        }
    }

    cout << "\nMaximum profit: " << ks[n][capacity] << endl;

    int c = capacity;
    int totalWeight = 0;
    vector<string> selectedItems;

    for(int i = n; i > 0; i--)
    {
        if(ks[i][c] != ks[i-1][c])
        {
            selectedItems.push_back(name[i-1]);
            totalWeight += weight[i-1];
            c -= weight[i-1];
        }
    }

    reverse(selectedItems.begin(), selectedItems.end());

    cout << "\nSelected items:\n";
    if(selectedItems.empty())
        cout << "No items selected.\n";
    else
    {
        for(int i = 0; i < selectedItems.size(); i++)
            cout << selectedItems[i] << endl;
    }

    cout << "\nTotal selected weight: " << totalWeight << endl;
    cout << "Remaining capacity: "
         << capacity - totalWeight << endl;

    return ks[n][capacity];
}

#endif
