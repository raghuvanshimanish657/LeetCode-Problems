class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> add;
        if (s1 == s2) {
            return true;
        }
        if(s1.size()!=s2.size())return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) 
                continue;
            else {
                add.push_back(i);
            }
        }
        if (add.size() != 2) {
            return false;
        }
        else {
            swap (s1[add[0]], s1[add[1]]);
            if (s2 == s1) return true;
        }
        return false;
    }
        
//         unordered_map<char,int>m1,m2;
//         int cnt=0;
//         for(int i=0;i<s1.size();i++){
//             if(s1[i]!=s2[i]){
//                 cnt++;
//             }
//             m1[s1[i]]++; 
//         }
//         for(int i=0;i<s2.size();i++){
           
//             m2[s2[i]]++; 
//         }
//         if((cnt==2 || s1==s2) && m1==m2){
//             return true;
//         }
//         return false;

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
        
    }*/
};