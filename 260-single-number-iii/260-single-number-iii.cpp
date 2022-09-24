class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {   
        //Step 1
        int xorall = 0;
        for(int num:nums) xorall ^= num;
        
        //Step 2
        int cnt=0;
        while(xorall){
            if(xorall&1) break;
            cnt++;
            xorall >>= 1;
        }
        
        //Step 3
        int n1=0,n2=0;
        for(int num : nums){
            if(num & (1<<cnt)){
                n1 ^= num;
            }
            else{
                n2 ^= num;
            }
        }
        
        //Step 4
        return {n1,n2};
    }
};