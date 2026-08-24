class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> de;
        vector<int> result;
        for(int i = 0;i<nums.size();i++){
            if(i-k == de.front()) de.pop_front();
            while(!de.empty() && nums[i] > nums[de.back()]){
                de.pop_back();
            }
            de.push_back(i);
            if(i >= k-1){
                result.push_back(nums[de.front()]);
            }

        }
        return result;
    }
};
