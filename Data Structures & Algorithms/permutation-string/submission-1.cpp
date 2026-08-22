class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(n>s2.size()){
            return false;
        }

        int left = 0;
        int right = 0;
        unordered_map<char,int>freq;
        unordered_map<char,int>window;

        for(char c: s1){
            freq[c]++;
        }

        while(right<s2.size()){
            window[s2[right]]++;
            if(right - left + 1 > n){
                window[s2[left]]--;
                if(window[s2[left]] == 0){
                    window.erase(s2[left]);
                }
                left++;
            }
            if(right - left + 1 == n){
                if(freq == window){
                    return true;
                }
            }
            right++;
        }
        return false;
    }
};
