#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

vector<int> searchForIndex(string str, unordered_map<string, vector<pair<int, int>>>& mp) {
    vector<pair<int, int>> temp;
    string curr = "";
    vector<string> words;  
    
    for (char ch : str) {
        ch = tolower(ch);
        if (isalnum(ch)) {
            curr.push_back(ch);
        } else if (!curr.empty()) {
            words.push_back(curr);  
            curr = "";
        }
    }

    if (!curr.empty()) {
        words.push_back(curr);  
    }

    // Extract all matching positions
    for (string& word : words) {
        if (mp.find(word) != mp.end()) {
            temp.insert(temp.end(), mp[word].begin(), mp[word].end());
        }
    }

    sort(temp.begin(), temp.end(), cmp);  

    vector<int> ans;
    if (words.size() == 1) {
        for (auto& p : temp) {
            ans.push_back(p.first);
        }
    } else {
        unordered_map<int, vector<int>> docPositions; 
        for (auto& p : temp) {
            docPositions[p.first].push_back(p.second);
        }

        for (auto& [docID, positions] : docPositions) {
            sort(positions.begin(), positions.end()); 
            int matched = 1;
            for (size_t i = 1; i < positions.size(); i++) {
                if (positions[i] == positions[i - 1] + 1) {
                    matched++;
                    if (matched == words.size()) {
                        ans.push_back(docID);
                        break;
                    }
                } else {
                    matched = 1;  // Reset sequence count
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return ans;
}
void buildMapForSearch(vector < string > input, unordered_map < string, vector < pair < int, int >>> & mp) {
    for (int i = 0; i < input.size(); i++) {
        int index = 1;
        string str = input[i];
        string curr = "";
        for (int j = 0; j < str.size(); j++) {
            char ch = tolower(str[j]); 
            if (isalnum(ch)) { 
                curr.push_back(ch);
            } else if (!curr.empty()) {
                mp[curr].push_back({
                    i + 1,
                    index
                }); 
                curr = "";
                index++;
            }
        }

    
        if (!curr.empty()) {
            mp[curr].push_back({
                i + 1,
                index
            });
        }
    }
    // for (auto it : mp){
    //         cout<<it.first<<endl;
    //         vector<pair<int,int>>v = it.second;
    //         for(auto p : v){
    //             cout<<p.first << " " << p.second << endl;
    //         }
    //     }
}
int main() {

    vector < string > input = {
        "Cloud computing is the on-demand availability of computer system resources.",
        "One integrated service for metrics, uptime, cloud monitoring, dashboards, and alerts reduces time spent navigating between systems.",
        "Monitor entire cloud infrastructure, whether in the cloud computing is or in virtualized data centers."
    };
    unordered_map < string, vector < pair < int, int >>> mp;
    buildMapForSearch(input, mp);
    string query;
    cin >> query;
    vector < int > ans = searchForIndex("Cloud computing is", mp);
    for (auto val: ans) {
        cout << val << " ";
    }
}