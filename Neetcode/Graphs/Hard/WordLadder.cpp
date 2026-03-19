// https://leetcode.com/problems/word-ladder/

#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <queue>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<string>::iterator it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end())
            return 0;

        int finalIndex = distance(wordList.begin(), it);

        // add to construct
        wordList.push_back(beginWord);
        int wl = wordList.size();

        vector<set<pair<int, int>>> c_ind(wl);

        // create char set
        for (int i = 0; i < wl; i++)
        {
            int s = wordList[i].size();
            for (int j = 0; j < s; j++)
            {
                c_ind[i].insert(make_pair(wordList[i][j] - 'a', j));
            }
        }

        // Create graph
        cout << "Creating graph" << endl;
        vector<vector<int>> adj(wl + 2);

        for (int i = 0; i < wl; i++)
        {
            for (int j = 0; j < wl; j++)
            {
                if (i != j)
                {
                    int diff = 0;
                    for (auto p : c_ind[i])
                    {
                        if (!c_ind[j].contains(p))
                        {
                            diff++;
                        }

                        if (diff > 1)
                            break;
                    }

                    if (diff == 1)
                    {
                        cout << "Connecting " << wordList[i] << " and " << wordList[j] << endl;
                        // create edge between i and j
                        adj[i].push_back(j);
                    }
                }
            }
        }

        for (int i = 0; i < wl; i++)
        {
            for (int j : adj[i])
            {
                cout << wordList[i] << " connects with " << wordList[j] << endl;
            }
        }

        // Do BFS
        vector<short> visited(wl + 2, 0);
        queue<pair<int, int>> q;
        int initialIndex = wl - 1; // last
        q.push(make_pair(initialIndex, 1));
        // cout << "Starting BFS, target index: " << finalIndex << endl;
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            // cout << "curr.ind " <<  curr.first << " curr.step " << curr.second << endl;
            if (curr.first == finalIndex)
            {
                // cout << "Got to final" << (curr.first == finalIndex) << endl;
                return curr.second;
            }

            for (int c : adj[curr.first])
            {
                if (!visited[c])
                {
                    cout << "Adding to q " << c << endl;
                    q.push(make_pair(c, curr.second + 1));
                    visited[c] = 1;
                }
            }
        }

        return 0;
    }
};
