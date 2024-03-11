#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool mycmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;

    return r1 > r2;
}
double knapsack(int w, struct Item arr[], int n)
{
    sort(arr, arr + n, mycmp);
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= w)
        {
            ans += arr[i].profit;
            w -= arr[i].weight;
        }
        else
        {
            ans += arr[i].profit * ((double)w / (double)arr[i].weight);
            break;
        }
    }
    return ans;
}

int main()
{

    int w = 50;
    Item arr[] = {{120, 30},
                  {100, 20},
                  {60, 10}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << knapsack(w, arr, n);

    return 0;
}