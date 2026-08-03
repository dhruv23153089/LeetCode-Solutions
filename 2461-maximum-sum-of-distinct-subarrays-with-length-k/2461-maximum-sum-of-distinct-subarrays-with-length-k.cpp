class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        long long windowSum = 0;
        long long ans = 0;

        for(int i=0;i<nums.size();i++)
        {
            windowSum += nums[i];
            freq[nums[i]]++;

            if(i >= k)
            {
                windowSum -= nums[i-k];

                freq[nums[i-k]]--;

                if(freq[nums[i-k]]==0)
                    freq.erase(nums[i-k]);
            }

            if(i >= k-1 && freq.size()==k)
            {
                ans = max(ans, windowSum);
            }
        }

        return ans;
    }
};