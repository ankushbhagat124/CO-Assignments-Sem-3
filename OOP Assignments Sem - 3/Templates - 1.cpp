// Question
// 1. Create a class template array for creating array
// with one non type argument for size of array .
//
// sort array
//
//
//
//
// 2. find the square of
// members of a class using friend template function for different set of
// arguments

#include <iostream>
using namespace std;

template <typename t, int N>
class array
{
    t arr[N];

public:

    t *getArray()
    {
        return arr;
    }

    void input(int n)
    {
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void display(int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void sortArr(t arr[], int l, int r, int n)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            sortArr(arr, l, m, n);
            sortArr(arr, m + 1, r, n);
            mergeSortedArray(arr, l, m, r, n);
        }
    }

    void mergeSortedArray(t arr[], int l, int m, int r, int n)
    {
        int i = l, j = m + 1, k = l;
        int tempArr[n];

        while (i <= m && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                tempArr[k++] = arr[i];
                i++;
            }
            else if (arr[j] < arr[i])
            {
                tempArr[k++] = arr[j];
                j++;
            }
        }

        while (i <= m)
        {
            tempArr[k++] = arr[i++];
        }
        while (j <= r)
        {
            tempArr[k++] = arr[j++];
        }

        for (int m = l; m <= r; m++)
        {
            arr[m] = tempArr[m];
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    array<int, 1000> a;
    a.input(n);
    a.sortArr(a.getArray(), 0, n - 1, n);
    cout << "Array after sorting: \n";
    a.display(n);
    return 0;
}
