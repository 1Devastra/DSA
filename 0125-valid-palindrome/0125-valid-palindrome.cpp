class Solution {
public:
 bool isalphanumeric(char ch){
            if((ch>='0'&&ch<='9')||(tolower(ch)>='a'&&tolower(ch)<='z')){
                return true;
            }
            return false;
        }
    bool isPalindrome(string s) {
        // int n=s.length(),a=0;
        // string str="";
        // for(int i=0; i<n; i++)
        // {
        //     if(s[i]>='A'&&s[i]<='Z')
        //     {
        //         str+=(s[i]+32);
        //     }
        //     else if(s[i]>='a'&& s[i]<='z'){
                
        //             str+=s[i];
                
        //     }
        //     else{
        //         if( s[i]>='0'&& s[i]<='9'){
        //             str+=s[i];
        //         }

        //     }
        // }
        // cout<<str;
        // int l=0, h=str.length()-1;
        // while(l<h)
        // {
        //     if(str[l]!=str[h]){
        //         return false;
        //     }
        //     l++;
        //     h--;
        // }
        // return true;
       
        int st=0;
        int end=s.length()-1;
        while(st<end){
            if(!isalphanumeric(s[st])){
                st++;
                continue;
            }
            if(!isalphanumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};