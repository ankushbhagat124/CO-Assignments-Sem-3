//Question: Display 5 names aligned top/bottom/left and right

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[5];        //Input String Array
    int max_len = 0;
    cout << "Enter names:\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> s[i];
        int len = s[i].length();
        if (s[i].length() >= max_len)
            max_len = s[i].length();
    }

    cout << "\nLEFT ALIGNMENT:" << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << s[i] << "\n";
    }

    cout << "\n" << "RIGHT ALIGNMENT:" << "\n";
    for (int i = 0; i < 5; i++)
    {
        int spaces = max_len - s[i].length();
        for (int j = 0; j < spaces; j++)
            cout << " ";

        cout << s[i] << "\n";
    }

    cout << "\n" << "TOP ALIGNMENT:" << "\n";
    for (int i = 0; i < max_len; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i < s[j].length())
                cout << s[j][i] << " ";
            else
                cout << " " << " ";
        }
        cout << "\n";
    }

    cout << "\n" << "BOTTOM ALIGNMENT:" << "\n";
    for (int i = 0; i < max_len; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int spaces = max_len - s[j].length();
            if (i < spaces)
                cout << " " << " ";
            else
                cout << s[j][i - spaces] << " ";
        }
        cout << "\n";
    }
}
