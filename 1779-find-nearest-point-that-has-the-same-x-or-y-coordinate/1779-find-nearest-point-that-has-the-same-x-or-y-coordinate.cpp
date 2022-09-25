class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {
        int n=p.size();
        int mini=INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++){
            if(x==p[i][0] or y==p[i][1]){
                int dist= abs(x-p[i][0])+abs(y-p[i][1]);
                if(dist<mini){
                    mini = dist;
                    index =i;
                }
            }
        }
        return index;
    }
};