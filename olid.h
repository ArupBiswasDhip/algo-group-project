#ifndef OLID_H
#define OLID_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct ItemRatio
{
    double weight;
    double profit;
    double Ratio;
    string name;
};

void runFractionalKnapsack()
{
    int n;

    cout << "\n=== Fractional Knapsack ===\n";

    cout << "Enter the number of items: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid number of items!\n";
        return;
    }

    vector<ItemRatio> item(n);

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter name of item " << i+1 << ": ";
        cin >> item[i].name;

        cout << "Enter weight: ";
        cin >> item[i].weight;

        cout << "Enter profit: ";
        cin >> item[i].profit;

        if(item[i].weight <= 0 || item[i].profit < 0)
        {
            cout << "Invalid weight or profit!\n";
            return;
        }

        item[i].Ratio =
            item[i].profit / item[i].weight;
    }

    double capacity;

    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;

    if(capacity < 0)
    {
        cout << "Invalid capacity!\n";
        return;
    }

    // Sort by Profit/Weight Ratio

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(item[i].Ratio < item[j].Ratio)
            {
                ItemRatio temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    double totalProfit = 0.0;
    double remaining = capacity;

    cout << "\nSelected items:\n";

    for(int i = 0; i < n && remaining > 0; i++)
    {
        if(item[i].weight <= remaining)
        {
            totalProfit += item[i].profit;

            remaining -= item[i].weight;

            cout << item[i].name
                 << " - Full item"
                 << " (Weight: " << item[i].weight << ")"
                 << endl;
        }
        else
        {
            double fraction =
                remaining / item[i].weight;

            double gainedProfit =
                item[i].Ratio * remaining;

            totalProfit += gainedProfit;

            cout << item[i].name
                 << " - Fraction: "
                 << fraction * 100 << "%"
                 << " (Weight: " << remaining << ")"
                 << endl;

            remaining = 0;
        }
    }

    cout << fixed << setprecision(2);

    cout << "\nTotal Profit: "
         << totalProfit << endl;

    cout << "Used Capacity: "
         << capacity - remaining << endl;

    cout << "Remaining Capacity: "
         << remaining << endl;
}

#endif
