class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 0, x, maxi = 0;
        set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        for(auto it: nums){
            if(st.find(it - 1) == st.end()){
                x = it;
                count = 1;
            }
            while(st.find(x+1) != st.end()){
                x++;
                count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
