#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

bool isRightAssociative(char c)
{
  return (c == '^');
}

void infixToPostfix(string &s)
{
  stack<char> st;
  string ans = ""; // ✅ postfix expression
  int n = s.size();

  for (int i = 0; i < n; i++)
  {
    char c = s[i];

    // ✅ Operand (letters or digits)
    if (isalnum(c))
    {
      ans += c;
    }
    // ✅ Opening bracket
    else if (c == '(')
    {
      st.push(c);
    }
    // ✅ Closing bracket
    else if (c == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        ans += st.top();
        st.pop();
      }
      st.pop(); // remove '('
    }
    // ✅ Operator
    else
    {
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

  // ✅ Pop remaining operators
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }

  cout << "Postfix expression: " << ans << endl;
}

int main()
{
  string s = "a+b*(c^d-e)";
  cout << "Infix Expression: " << s << endl;
  infixToPostfix(s);
  return 0;
}
