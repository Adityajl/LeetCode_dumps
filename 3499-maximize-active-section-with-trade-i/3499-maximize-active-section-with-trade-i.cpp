class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        vector<int> zeroGroups;

        int n = (int)s.size();
        int i = 0;

        while (i < n) {
            if (s[i] == '1') {
                ones++;
                i++;
            } else {
                int j = i;
                while (j < n && s[j] == '0') j++;
                zeroGroups.push_back(j - i);
                i = j;
            }
        }

        int bestMerge = 0;
        for (int k = 0; k + 1 < (int)zeroGroups.size(); k++) {
            bestMerge = max(bestMerge, zeroGroups[k] + zeroGroups[k + 1]);
        }

        return ones + bestMerge;
    }
};