class Solution {
    int max(int a,int b){
        if(a>b) return a;
        return b;
    }
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        int l = 0, count = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            count = max(count, mp[s[i]]);
            int j = i+1;
            while ((j - l) - count > k) {
                mp[s[l]]--;
                l++;
            }
            result = max(result, j - l );
        }
        return result;
    }
};
