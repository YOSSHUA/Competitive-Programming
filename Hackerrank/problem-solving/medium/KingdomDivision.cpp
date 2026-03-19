// https://www.hackerrank.com/challenges/kingdom-division/problem
/**
    Divide his kingdom between his two children, by giving each of them  or more cities;
    he must divide the kingdom in such a way that they will not invade each other's cities.

    The first sibling will invade the second sibling's city
    if the second sibling has no other cities directly connected to it.

    The all possibilities are (C1a +C1b)*(C2a + C2b)*...*(CNa + CNb),
    but we are taking some invalid ways.
    Then we have to subtract that.
    So,
    we notice that a combination is invalid
    when parent color is a and parent parent's parent is a
    else we have a bad combination.
    Also, that bad combinations are valid
    if parent and parent's parent color are the same.(other case)

    So, if they are of the same color we don't have to subtract else yes, we have to subtract
*/
#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long int ll;
const int MAXN = 100005;
vector<vector<int>> adjL(MAXN);

ll dp[MAXN][3][3];
ll f(int node, short color, short united, int parent)
{

    if (dp[node][color][united] == -1)
    {
        if (adjL[node].size() == 1 && node != 1)
        { /// Leaf and different of root=1
            if (united)
                return dp[node][color][united] = 1; /// this is a good one
            else
                return dp[node][color][united] = 0; /// this is a bad one
        }
        ll ans = 1;
        ll invalid = 1;
        ll valid;
        for (int u : adjL[node])
        {
            if (u != parent)
            {
                valid = f(u, !color, false, node);
                invalid = (invalid * f(u, !color, false, node)) % mod;
                valid += f(u, color, true, node);
                ans = (ans * valid) % mod;
            }
        }

        if (!united) /// si estuviera unido significa que son puras combinaciones buenas
            ans = (ans - invalid + mod) % mod;
        dp[node][color][united] = ans;
    }
    return dp[node][color][united];
}

void clean()
{
    for (int i = 0; i < 100002; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }
    clean();
    ll ans = (2 * f(1, 0, 0, -1)) % mod;
    cout << ans << '\n';
    return 0;
}
