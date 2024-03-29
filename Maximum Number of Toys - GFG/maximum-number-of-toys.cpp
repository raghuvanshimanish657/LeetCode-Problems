//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      vector <int> res;
      vector <pair<long,long>> v(N + 1);
      for(long i = 1; i <= N; i++) {
          v[i].first  = A[i - 1];
          v[i].second = i;
      }
      sort(v.begin(), v.end());
      vector <long> pref(N + 1), idx(N + 1);
      for(long i = 1; i <= N; i++) {
          idx[v[i].second] = i;
          pref[i] += pref[i - 1] + v[i].first;
      }
      for(auto i : Queries) {
          long cost = i[0], size = i[1];
          long limit  = (upper_bound(pref.begin(), pref.end(), cost) - pref.begin()) - 1;
          long ans = limit, add = 0, spent = pref[limit];
          set <long> bad;
          for(long j = 0; j < size; j++) {
              bad.insert(i[2 + j]);
          }
          for(long j = 0; j < size; j++) {
              while(limit + add + 1 <= N && bad.find(v[limit + add + 1].second) != bad.end()) {
                  add += 1;
              }
              if(idx[i[2 + j]] <= limit) {
                  ans -= 1;
                  spent -= v[idx[i[2 + j]]].first;
                  if(limit + add +  1 <= N && A[v[limit + add + 1].second - 1] + spent <= cost) {
                      spent += A[v[limit + add + 1].second - 1];
                      add += 1;
                      ans += 1;
                  }
              }
          }
          res.push_back(ans);
      }
      return res;
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends