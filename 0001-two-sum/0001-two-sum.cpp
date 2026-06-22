class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numToIndex;

        for(int i=0; i<nums.size(); i++) {
            int need = target-nums[i];

            if(numToIndex.find(need) != numToIndex.end()){
                return {numToIndex[need], i};
            }

            numToIndex[nums[i]] = i;

        }

        return {};      
    }
};