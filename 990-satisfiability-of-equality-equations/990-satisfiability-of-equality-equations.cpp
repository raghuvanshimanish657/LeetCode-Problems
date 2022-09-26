class UF{
private:
    vector<int> root;
    int size=26;
    
public:
    UF(){
        root.resize(26);
        for(int i=0; i<26; ++i){
            root[i]=i;
        }
    }
    int find(int x){
        if(root[x]==x)return x;
        return root[x]=find(root[x]);
    }
    void unionF(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            root[rootX]=rootY;
            size--;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF union_find;
        int index=0;
        for(auto equation:equations){
            if(equation[1]=='!'){
                if(union_find.find(equation[0]-'a')==union_find.find(equation[3]-'a')){
                    return false;
                }
                equations[index++]=equation;
            }else{
                union_find.unionF(equation[0]-'a',equation[3]-'a');
            }
        }
        for(int i=0;i<index;++i){
            if(union_find.find(equations[i][0]-'a')==union_find.find(equations[i][3]-'a')){
                    return false;
            }
        }
        return true;
    }
};