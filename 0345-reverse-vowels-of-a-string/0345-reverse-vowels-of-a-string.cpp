class Solution {
public:
    string reverseVowels(string s) {
        // if(s== || s.length()<2){
        //     return s;
        // }
        int l=0,h=s.length()-1;
        while(l<h){
            while(l<h &&s[l]!='a'&& s[l]!='e'&&s[l]!='i' &&s[l]!='o' &&s[l]!='u'&&s[l]!='A'&&
            s[l]!='E'&& s[l]!='I'&&s[l]!='O'&&s[l]!='U'){
            l++;
            
            cout<<l<<"\t";
            }
        
            while(l<h && s[h]!='a'&&s[h]!='e'&&s[h]!='i'&&s[h]!='o'&&s[h]!='u'&&s[h]!='A'&&
            s[h]!='E'&&s[h]!='I'&&s[h]!='O'&&s[h]!='U'){
                h--;
            }
            if(l<h){
                swap(s[l],s[h]);
                }
                l++;
                h--;
            }

            cout<<h<<"\t";
        return s;
    }
};