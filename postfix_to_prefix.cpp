#include <bits/stdc++.h>
#include <stack>
using namespace std;

string postfixToPrefix(string &s)
{
  stack<string> st;
  for (int i = 0; i < s.size(); i++)
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
      string converted_s = s[i] + t2 + t1;
      st.push(converted_s);
    }
  }
  return st.top();
}

int main()
{
  string s = "AB-DE+F*/";
  string ans = postfixToPrefix(s);
  cout << "Prefix exp: " << ans;
  return 0;
}