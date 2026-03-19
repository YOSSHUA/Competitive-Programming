// https://www.hackerrank.com/challenges/richie-rich/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    int mid = n/2;
    vector<bool> changed(mid+2,0);
    for(int i = 0; i < mid; i++){
        if(s[i] != s[n-1-i]){
            changed[i] = true;
            int bigger = max(s[i]-'0', s[n-1-i]-'0');
            s[i] = s[n-1-i] = (bigger+'0');
            k--;
        }
    }
    if(k < 0)
        return "-1";
    else if(k == 0)
        return s;
    else{        
        int i = 0;
        while (k > 0 && i < mid) {
            if(s[i] != '9'){
                if(!changed[i]){
                    if(k >=2){
                        s[i] = s[n-1-i] = '9';
                        k-=2;
                    }
                }else{
                    s[i] = s[n-1-i] = '9';
                    k--;
                }
            }
            i++;
        }        
        if(n%2 == 1 && k >=1){            
           s[mid] = '9'; 
        }
        return s;
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
