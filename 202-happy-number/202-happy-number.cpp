class Solution {
public:
    bool isHappy(int n) {
        while(n>9){
            int ans=0;
            while(n){
                int digit=n%10;
                ans+=(int)digit*digit;
                n/=10;
            }
            if(ans==1 or ans==7)return true;
            n=ans;
        }
        if(n==1 or n==7)return true;
        else return false;
    }
};