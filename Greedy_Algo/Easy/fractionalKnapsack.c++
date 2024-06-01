// link->https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Define the structure for the items
struct Item
{
    int value, weight;
};

// Comparator function to sort items by value/weight ratio
static bool comp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort by decreasing value/weight ratio
}

// Function to calculate the maximum profit for fractional knapsack
double fractionalKnapsack(int W, Item arr[], int n)
{
    double profit = 0.0;
    std::sort(arr, arr + n, comp); // Sort items by value/weight ratio

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            profit += arr[i].value;
        }
        else
        {
            profit += (double)arr[i].value / arr[i].weight * W;
            break;
        }
    }
    return profit;
}

int main()
{
    int W = 50;                                    // Maximum weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // Array of items with {value, weight}
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Maximum profit in knapsack = " << fractionalKnapsack(W, arr, n) << std::endl;
    return 0;
}
