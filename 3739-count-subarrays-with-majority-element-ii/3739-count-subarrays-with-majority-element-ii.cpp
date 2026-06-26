class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getIndex = [&](int x) {
            return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
        };

        vector<int> bit((int)vals.size() + 2, 0);

        auto add = [&](int idx, int val) {
            while (idx < (int)bit.size()) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        long long ans = 0;
        add(getIndex(0), 1);

        for (int i = 1; i <= n; i++) {
            int idx = getIndex(pref[i]);
            ans += query(idx - 1);
            add(idx, 1);
        }

        return ans;
    }
};