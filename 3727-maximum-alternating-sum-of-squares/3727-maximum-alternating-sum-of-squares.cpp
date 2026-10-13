class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq;
        for (int x : nums) sq.push_back(1LL * x * x);

        sort(sq.begin(), sq.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) ans -= sq[i];
            else ans += sq[i];
        }

        return ans;
    }
};