class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    double average(vector<int>& salary) {
        double sum = 0;
        int maxv = INT_MIN, minv = INT_MAX;
        for (auto s : salary) {
            sum += s;
            maxv = max(maxv, s);
            minv = min(minv, s);
        }
        return (sum - maxv - minv) / (salary.size() - 2);
    }
};