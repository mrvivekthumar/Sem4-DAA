#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
}

main()
{
    int n = 1000000;
    int *a = new int[n];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        // for best  case
        // a[i] = i;
        // for worst case
        a[i] = n - i;
    }

    selectionSort(a, 5000);

    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << "   ";
    }

    auto elapsed = high_resolution_clock::now() - start;
    long long time_taken = duration_cast<nanoseconds>(elapsed).count();

    cout << endl;
    cout << "Time taken by algoridhm is :" << time_taken << endl;
    return 0;
}