class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int leng=s.length();
       for(int i=0;i<leng;i++){
            if(s[i]!=' ')
             len++;
            if(s[i]&&s[i]!=' '&&s[i-1]==' '){
                len=1;   
             }
        }
        return len;
    }
};
