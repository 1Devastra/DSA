class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        
        stack<int>st;
        for(int i=0; i<n; i++){
            int curr=asteroids[i];
            bool flag=false;
            while(!st.empty()&&curr<0&&st.top()>0){
                if(st.top()<-curr){
                    st.pop();
                    continue;
                }
                else if(st.top()==-curr){
                    st.pop();
                    flag=true;
                    break;

                }else{
                    flag=true;
                    break;
                }
            }
                
                if(!flag){
                    st.push(curr);
                }
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1; i>=0; i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};