class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> data(nums.size());        
        for(int i = 0; i < nums.size(); i++){
            data[i].first = nums[i];
            data[i].second = i;
        }        
        sort(data.begin(), data.end());        
        for(int i = 0, j = data.size()-1; i < data.size(); ) {
            if(data[i].first + data[j].first == target)
                return {data[i].second, data[j].second};   
            else if (data[i].first + data[j].first < target)
                i++;            
            else
                j--;
        }        
        return {};
    }
};