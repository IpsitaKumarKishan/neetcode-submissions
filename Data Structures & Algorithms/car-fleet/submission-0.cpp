class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], static_cast<double>(target - position[i]) / speed[i]};
        }
        
        // Sort descending by position (closest car to target first)
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        
        stack<double> st;
        for (const auto& car : cars) {
            double current_time = car.second;
            
            // Push only if this car takes longer than the fleet ahead of it
            if (st.empty() || current_time > st.top()) {
                st.push(current_time);
            }
        }
        
        return st.size();
    }
};
