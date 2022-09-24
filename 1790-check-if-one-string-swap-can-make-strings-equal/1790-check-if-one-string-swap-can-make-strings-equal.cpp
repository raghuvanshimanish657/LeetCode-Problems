class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        unordered_map<char,int>m1,m2;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
            m1[s1[i]]++; 
        }
        for(int i=0;i<s2.size();i++){
           
            m2[s2[i]]++; 
        }
        if((cnt==2 || s1==s2) && m1==m2){
            return true;
        }
        return false;

        /*
        if(s1.length()!=s2.length())
        return false;
    
        vector<int> v;
        for(int i=0;i<s1.length();i++){
           if(s1[i]!=s2[i])
               v.push_back(i);   
        }

        if(v.size()==2){
            swap(s2[v[0]],s2[v[1]]);   
        }

        for(int i=0;i<s1.length();i++){
           if(s1[i]!=s2[i])
               return false;   
        }

        return true;
        */
    }
};