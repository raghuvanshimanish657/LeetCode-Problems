class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint a = n , count = 0;
        while(a)
        {
            count++;
            a=a&(a-1);
        }
        return count;
    }
};