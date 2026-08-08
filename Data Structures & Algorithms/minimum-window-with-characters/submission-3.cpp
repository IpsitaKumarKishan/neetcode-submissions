class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()) return "";

        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for(int c : t){
            need[c]++;
        }
        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int have = 0;
        int required = need.size();
        for(int right = 0; right < s.size();right++){
            char c = s[right];
            window[c]++;
            if(need.count(c) && window[c] == need[c]){
                have++;
            }
            while(have == required){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                char leftchar = s[left];
                window[leftchar]--;
                if(need.count(leftchar) && window[leftchar] < need[leftchar]){
                    have--;
                }
                left++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start, minLen);
    }
};
