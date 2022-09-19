#include<bits/stdc++.h>
using namespace std;

int knapsack(int value[], int weigh_of_item[], int number_of_items, int Capacity_of_knapsack)
{
    if (number_of_items == 0 || Capacity_of_knapsack == 0)
    {
        return 0;
    }
    if (number_of_items-1 > Capacity_of_knapsack)
    {
        return knapsack(value, weigh_of_item, number_of_items-1, Capacity_of_knapsack);
    }
    
    return max(knapsack(value, weigh_of_item, number_of_items-1, Capacity_of_knapsack-weigh_of_item[number_of_items-1]) + value[number_of_items-1],
    knapsack(value, weigh_of_item, number_of_items-1, Capacity_of_knapsack));
}

int main()
{
    int value[] = {100, 50, 150};
    int weight[] = {10, 20, 30};
    cout << knapsack(value, weight, 3, 50) << "\n";
}