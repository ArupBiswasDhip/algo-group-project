#ifndef OLID_H
#define OLID_H

#include <iostream>
#include <vector>
using namespace std;

struct ItemRatio {
    int weight;
    int profit;
    double Ratio;
    string name;
};

void runFractionalKnapsack()
{
    int n;
    cout << "=== Fractional Knapsack (P/W Ratio) ===" << endl;
    cout << "Enter the number of items : ";
    cin >> n;

    ItemRatio item[n];
    for(int i=0; i<n; i++)
    {
        cout << "Enter the name of item " << i+1 << " : ";
        cin >> item[i].name;
        cout << "Enter the weight of item " << i+1 << " : ";
        cin >> item[i].weight;
        cout << "Enter the profit of item " << i+1 << " : ";
        cin >> item[i].profit;
        item[i].Ratio = (double)item[i].profit / item[i].weight;
    }

    int capacity;
    cout << "Enter the knapsack capacity : ";
    cin >> capacity;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(item[i].Ratio < item[j].Ratio)
            {
                ItemRatio temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    double profits = 0.0;
    int rem_capacity = capacity;

    for(int i=0; i<n; i++)
    {
        if(item[i].weight <= rem_capacity)
        {
            profits += item[i].profit;
            rem_capacity -= item[i].weight;
        }
        else
        {
            profits += item[i].Ratio * rem_capacity;
            break;
        }
    }
    cout << "Total Profit : " << profits << endl;
}

#endif
…
