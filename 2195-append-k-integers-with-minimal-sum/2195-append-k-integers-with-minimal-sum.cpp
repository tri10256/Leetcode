class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
    long long res = (long long)k * (k + 1) / 2, last = k + 1;
    for (int n : set<int>(begin(nums), end(nums)))
        if (n < last)
            res += (last++) - n;
    return res;
}
};