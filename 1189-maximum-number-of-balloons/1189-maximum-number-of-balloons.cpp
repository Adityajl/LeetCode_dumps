class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> count;

        for(char c: text)
            count[c]++;

        int b = count['b'];
        int a = count['a'];
        int l = count['l'] / 2;
        int o = count['o'] / 2;
        int n = count['n'];
        
        // Return the minimum of all required counts
        return min({b, a, l, o, n});
    }
};