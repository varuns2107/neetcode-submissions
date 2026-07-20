class Solution {
public:
    bool helper(vector<int>& arr, int capacity, int hours) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += arr[i]/capacity;
            if(arr[i]%capacity != 0) count++;
        }
        return count <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = 0;
        int left = 1; 
        int right = *max_element(piles.begin(), piles.end());
        while(left <= right) {
            int mid = left + (right - left)/2;
            if (helper(piles, mid, h)) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
