class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN;
        int max2=INT_MIN;
        for(int i:nums){
            if(i>=max1)max2=max1,max1=i;
            //cout<<"max1 : = "<<max1<<" , ";
            if(i>=max2 && i<max1)max2=i;
            //cout<<"max2 : = "<<max2<<endl;
        }
        return (max1-1)*(max2-1);
    }
};