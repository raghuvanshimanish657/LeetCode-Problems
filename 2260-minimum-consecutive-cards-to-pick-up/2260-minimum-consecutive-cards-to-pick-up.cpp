class Solution {
public:
    
    int minimumCardPickup(vector<int>& v) {
        int ans = INT_MAX;
        unordered_map<int,int> m;
        for(int i=0;i<v.size();i++){
            if(m.find(v[i])!=m.end()){
                ans = min(ans,i-m[v[i]]+1);
            }
            m[v[i]] = i;
        }
        return ans==INT_MAX?-1:ans;
    }
};