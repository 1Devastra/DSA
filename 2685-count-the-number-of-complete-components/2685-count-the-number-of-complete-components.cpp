class Solution {
private:
vector<int>parent;
int find(int n){
    return parent[n]==n? n :parent[n]=find(parent[n]);
}
void Union(int n1,int n2){
    int u=find(n1);
    int v=find(n2);
    if(u==v)return;
    else{
        parent[u]=v;
    }

}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        for(auto&edge:edges){
            int u=find(edge[0]);
            int v=find(edge[1]);
            Union(u,v);
        }
        vector<int>count(n);
        vector<int>size(n);
        for(auto &edge:edges){
            int u=find(edge[0]);
            ++count[u];
            }
        
        for(int i=0; i<n; i++){
            int u=find(i);
            ++size[u];
            }
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(size[i]==0)continue;
           int k=size[i];
           if(count[i]==(k*(k-1))>>1)
           ans++;
        }
        return ans;
        
    }
};