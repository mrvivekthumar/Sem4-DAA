#include <bits/stdc++.h>
using namespace std;
int x[10000];
bool isPossible(int k, int col)
{
    for (int row = 0; row < k; row++)
    {
        if (x[row] == col || abs(x[row] - col) == abs(k - row))
        {
            return false;
        }
    }
    return true;
}
int cnt = 0;
void fun(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isPossible(k, i))
        {
            x[k] = i;
            if (k == n - 1)
            {
                cnt++;
                cout << "SOLUTION : " << cnt << "\n";
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (x[i] == j)
                        {
                            cout << "Q ";
                        }
                        else
                        {
                            cout << ". ";
                        }
                    }
                    cout << "\n";
                }
                cout << "\n";
                break;
            }
            else
            {
                fun(k + 1, n);
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;
    fun(0, n);
}