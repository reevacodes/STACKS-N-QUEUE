#include <bits/stdc++.h>
#include <stack>
using namespace std;

string prefixToPostfix(string &s)
{
  stack<string> st;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (isalnum(s[i]))
    {
      string op(1, s[i]);
      st.push(op);
    }
    else
    {
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string converted_s = t1 + t2 + s[i];
      st.push(converted_s);
    }
  }
  return st.top();
}

int main()
{
  string s = "/-AB*+DEF";
  string ans = prefixToPostfix(s);
  cout << "Postfix exp: " << ans;
  return 0;
}