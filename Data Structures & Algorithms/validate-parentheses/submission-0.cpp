class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(char c : s){
            if(c=='(' || c=='{' || c=='['){
                st.push_back(c);
            }else{
                if(st.empty())return false;
                if(st.back()=='(' && c==')' || 
                    st.back()=='{' && c=='}' ||
                    st.back()=='[' && c==']' ){
                        st.pop_back();
                    }else{
                        return false;
                    }
            }
        }
        return st.empty();
    }
};
