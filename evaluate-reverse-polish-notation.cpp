class Solution {
public:
    bool isOperator(char c) {
        return c < '0' || c > '9';
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i].size() == 1 && isOperator(tokens[i][0])) {
                int tmp1 = sta.top(); sta.pop();
                int tmp2 = sta.top(); sta.pop();
                switch(tokens[i][0]) {
                    case '+':
                        sta.push(tmp1+tmp2);
                        break;
                    case '-':
                        sta.push(tmp2-tmp1);
                        break;
                    case '*':
                        sta.push(tmp1*tmp2);
                        break;
                    case '/':
                        sta.push(tmp2/tmp1);
                }
            } else {
                sta.push(atoi(tokens[i].c_str()));
            }
        }
        return sta.top();
    }
};


//解法二：
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len=tokens.size();
        stack<int> S;
        for(int i = 0; i < len; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/")
            {
                int op2 = S.top();
                S.pop();
                int op1 = S.top();
                S.pop();
                S.push( op(op1, op2, tokens[i][0]) );
            }
            else
                S.push(stoi(tokens[i]));//stoi() 把字符串转换成数字
        }
        return S.top();
    }
    int op(int op1, int op2, char optor)
    {
        if(optor == '+')return op1 + op2;
        else if(optor == '-')return op1 - op2;
        else if(optor == '*')return op1 * op2;
        else return op1 / op2;
    }
};