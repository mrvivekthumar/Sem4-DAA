#include <iostream>
#include <algorithm>
#include <climits>
#include <chrono>
using namespace std::chrono;
using namespace std;

int changeMaking(int coin[], int n, int sum)
{
    int x, y;

    int dp[n + 1][sum + 1];

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= coin[i - 1])
            {
                x = dp[i - 1][j];
                y = 1 + dp[i][j - coin[i - 1]];
                dp[i][j] = min(x, y);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int i;
    int n, sum;

    cout << "Enter the amount whose change is required : ";
    cin >> sum;

    cout << endl;
    cout << "Enter the number of coins available : ";
    cin >> n;
    cout << endl;

    int coin[n];

    cout << "Enter the values of coins : ";
    for (i = 0; i < n; i++)
        cin >> coin[i];

    cout << endl;

    auto start = high_resolution_clock::now();

    cout << "The least number of coins whose sum is equal to required sum is : ";

    cout << changeMaking(coin, n, sum) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}