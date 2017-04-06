class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        if(len==0) return true;
        if(len%2==1) return false;
        stack<char> div;
        for(int i=0;i<len;i++){
            if(s[i] == '(') div.push(')');  
            else if(s[i] == '{') div.push('}');  
            else if(s[i] == '[') div.push(']');  
            else if(div.empty()||div.top()!=s[i]) 
              return false;
            else div.pop();
        }
        return div.empty();
    }
};