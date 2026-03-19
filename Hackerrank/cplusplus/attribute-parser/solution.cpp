// https://www.hackerrank.com/challenges/attribute-parser
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;


void findNextNonSpace(int& i, string s) {
    while(i < s.size() && s[i] == ' ') i++;
}

void extractPropertyValue(int& i, string s, string& word, char endChar) {
    while (i < s.size() && s[i] != '"') word += s[i++];
}

void extractPropertyName(int& i, string s, string& word) {
    while (i < s.size() && s[i] != ' ') word += s[i++];
}

void extractTagName(int& i, string s, string& word) {
    while (i < s.size() && (s[i] != ' ' && s[i] != '>')) word += s[i++];
}

string processOpenTag(unordered_map<string, string>& state, string currentTagTree, string s) {
    // cout << "Starting processing line " << s << endl;
    int i = 0;
    findNextNonSpace(i, s); // At <
    i++; // right after <
    findNextNonSpace(i, s); // Get to first char of tagName
    string newActiveTag = "";
    extractTagName(i, s, newActiveTag);
    string newTagTree = currentTagTree == "" ? newActiveTag : currentTagTree + "." + newActiveTag;
    
    // cout << "TagName: " << newActiveTag << endl;
    // cout << "New tree: " << newTagTree  << endl;
    // End Process tagName

    //  Process properties - char right after tagName

    string propertyName;
    string propertyValue;
    while(i < s.size()) {
        if (s[i] == ' ' || s[i] == '>' || s[i] == '=') i++;
        else if(s[i] == '"'){
            i++; // right after "
            propertyValue = "";
            extractPropertyValue(i, s, propertyValue, '"');
            // cout << "Property value: " << propertyValue << " ";
            string propertyKey = newTagTree + "~" + propertyName;
            // cout << "Property key: " << propertyKey << endl;
            state[propertyKey] = propertyValue;
            i++; // right after "
        } else {
            // at first non space char
            propertyName = "";
            extractPropertyName(i, s, propertyName);
            // cout << "propertyName: " << propertyName << " ";
            // right after propertyName end
        }
    }

    // cout << "Finished processing line" << endl;
    // End of properties processing
    return newTagTree;
}

bool isEndTag(string s) {
    int i = 0;
    findNextNonSpace(i, s); // Looking for <
    i++; // right after <
    findNextNonSpace(i, s); // Looking for /
    if (s[i] =='/')
        return true;
    return false;
}

void updateTagTree(string& tagTree) {
    while(!tagTree.empty() && tagTree[tagTree.size()-1] != '.') tagTree.pop_back();
    if (!tagTree.empty()) tagTree.pop_back(); // remove .
    // cout << "new tag tree " << tagTree << endl;
}


int main() {
    unordered_map<string, string> state;
    string tagTree = "";
    int n, q;
    string s;
    cin >> n >> q;
    std::getline(std::cin, s); // read endl
    while (n--) {
        std::getline(std::cin, s);
        // cout << "Processing s:" << s << endl;
        if (isEndTag(s)) {
            // cout << "It is endtag" << endl;
            updateTagTree(tagTree);
        } else {
            // cout << "It is not endtag" << endl;
            tagTree = processOpenTag(state, tagTree, s);
        }
    }

    // cout << "Parsing done\n";
    // for(auto v : state) {
    //     cout << v.first << ": " << v.second << endl;
    // }
    string qi = "";
    while (q--) {
        cin >> qi;
        auto it = state.find(qi);
        if (it != state.end())
            cout << it -> second << endl;
        else
            cout << "Not Found!" << endl;
    }
    return 0;
}
