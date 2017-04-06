 class Solution
  {
  public:
      string simplifyPath(string path)
      {
          stack<string> ss; // 记录路径名
          for(int i = 0; i < path.size(); )
          {
              // 跳过斜线'/'
             while(i < path.size() && '/' == path[i])
                 ++ i;
             // 记录路径名
             string s = "";
             while(i < path.size() && path[i] != '/')
                 s += path[i ++];
             // 如果是".."则需要弹栈，否则入栈
             if(".." == s && !ss.empty())
                 ss.pop();
             else if(s != "" && s != "." && s != "..")
                 ss.push(s);
         }
         // 如果栈为空，说明为根目录，只有斜线'/'
         if(ss.empty())
             return "/";
         // 逐个连接栈里的路径名
         string s = "";
         while(!ss.empty())
         {
             s = "/" + ss.top() + s;
             ss.pop();
         }
         return s;
     }
 };