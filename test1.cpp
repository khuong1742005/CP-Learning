#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string diary;
        cin >> diary;

        int totalTime = 0;
        int solvedProblems = 0;

        // Process the diary
        for (int i = 0; i < n; ++i)
        {
            // Calculate the time required to solve this problem
            int timeRequired = 'Z' - diary[i] + 1;

            // Check if we have enough time to solve this problem
            if (totalTime + timeRequired <= n)
            {
                solvedProblems++;
                totalTime += timeRequired;
            }
            else
            {
                break; // No need to continue if we can't solve more problems
            }
        }

        cout << solvedProblems << endl;
    }

    return 0;
}
