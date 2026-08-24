class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n = temp.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && temp[i]>temp[st.top()]){
                int idx = st.top();
                st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }
        return result;
    }
};
