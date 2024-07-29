#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void maximizeString(string &s, int k)
{
    int n = s.size();

    for (int i = 0; i < n && k > 0; ++i)
    {
        // Find the maximum digit to the right of the current position
        char maxChar = s[i];
        int maxPos = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (s[j] > maxChar)
            {
                maxChar = s[j];
                maxPos = j;
            }
        }

        // If the maximum digit is not in the current position, swap
        if (maxPos != i)
        {
            // Perform the swap to bring the maximum digit to the current position
            while (maxPos > i)
            {
                swap(s[maxPos], s[maxPos - 1]);
                --maxPos;
                --k;
                if (k == 0)
                    break;
            }
        }
    }
}

int main()
{
    int k;
    string s;

    cin >> k;
    cin >> s;

    maximizeString(s, k);
    cout << s << endl;

    return 0;
}
