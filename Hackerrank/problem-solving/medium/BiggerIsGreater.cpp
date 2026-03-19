//  https://www.hackerrank.com/challenges/bigger-is-greater
#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w)
{
    bool impossible = true;
    int index = -1;
    int s = w.size();
    string ans = "no answer";
    for (int i = s - 1; i > 0 && impossible; i--)
    {

        if (w[i - 1] < w[i])
        {
            // if we dont find that position it means that actually we have
            // the biggest one.
            impossible = false;
            index = i - 1;
        }
    }
    if (!impossible)
    {
        // if we found such position that w[i-1] < w[i]
        // then we want the next one that is bigger but is the smallest possible
        // So, the next possible bigger needs to fail against w[i-1]
        // i.e., we need the next one should start with the next character bigger
        // than w[i]. Once we find that character we should swap them.
        // Finally, to achieve the smaller one after the characater at w[i-1], now bigger,
        // we sort w[i] to w[w.size -1]
        int i = s - 1;
        while (i >= 0)
        {
            if (w[i] > w[index])
            {
                swap(w[i], w[index]);
                break;
            }
            i--;
        }
        sort(w.begin() + index + 1, w.end());
        return w;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
