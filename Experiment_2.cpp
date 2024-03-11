#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
// function start
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
// function end
int main()
{
    int v;
    cin >> v;
    int arr[v];
    for (int i = 0; i < v; i++)
    {
        arr[i] = i;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1234567;
    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, x);
    auto elapsed = high_resolution_clock::now() - start;
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result << endl;

    long long nanosecands = duration_cast<std::chrono::microseconds>(elapsed).count();

    cout << endl;
    cout << endl;
    cout << fixed << nanosecands;
}