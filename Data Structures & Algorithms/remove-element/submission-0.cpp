class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        int count=0;
        for(int i : nums){
            if( i != val){
                nums[count] = i;
                count++;
            }
        }
        return count;
    }
};