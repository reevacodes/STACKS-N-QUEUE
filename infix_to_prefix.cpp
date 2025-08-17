#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  return -1;
}

bool isRightAssociative(char c)
{
  return (c == '^');
}

string infixToPostfix(string s)
{
  stack<char> st;
  string ans = "";

  for (char c : s)
  {
    if (isalnum(c))
    { // operand
      ans += c;
    }
    else if (c == '(')
    {
      st.push(c);
    }
    else if (c == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        ans += st.top();
        st.pop();
      }
      st.pop();
    }
    else
    { // operator
      while (!st.empty() &&
             (prec(c) < prec(st.top()) ||
              (prec(c) == prec(st.top()) && !isRightAssociative(c))) &&
             st.top() != '(')
      {
        ans += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }
  return ans;
}

string infixToPrefix(string s)
{
  // 1. Reverse the infix
  reverse(s.begin(), s.end());

  // 2. Swap ( and )
  for (char &c : s)
  {
    if (c == '(')
      c = ')';
    else if (c == ')')
      c = '(';
  }

  // 3. Convert to postfix
  string postfix = infixToPostfix(s);

  // 4. Reverse postfix → prefix
  reverse(postfix.begin(), postfix.end());
  return postfix;
}

int main()
{
  string s = "a+b*(c^d-e)";
  cout << "Infix:   " << s << endl;
  cout << "Prefix:  " << infixToPrefix(s) << endl;
  return 0;
}
