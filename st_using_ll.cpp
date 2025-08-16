#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

// Stack implementation
class Stack
{
  Node *topNode; // pointer to top
  int curSize;   // track size

public:
  Stack()
  {
    topNode = nullptr;
    curSize = 0;
  }

  // Push element on stack
  void push(int x)
  {
    Node *temp = new Node(x);
    temp->next = topNode; // new node points to old top
    topNode = temp;       // update top
    curSize++;
    cout << "Pushed " << x << " onto stack\n";
  }

  // Pop element from stack
  int pop()
  {
    if (topNode == nullptr)
    {
      cout << "Stack Underflow\n";
      return -1;
    }
    int val = topNode->data;
    Node *temp = topNode;
    topNode = topNode->next; // move top
    delete temp;             // free memory
    curSize--;
    return val;
  }

  // Get top element
  int top()
  {
    if (topNode == nullptr)
    {
      cout << "Stack is empty\n";
      return -1;
    }
    return topNode->data;
  }

  // Get current size
  int size()
  {
    return curSize;
  }

  // Check if stack is empty
  bool empty()
  {
    return topNode == nullptr;
  }
};

// Driver code
int main()
{
  Stack st;
  st.push(10);
  st.push(20);
  st.push(30);

  cout << "Top element is: " << st.top() << endl;
  cout << "Stack size is: " << st.size() << endl;

  cout << "Popped: " << st.pop() << endl;
  cout << "Popped: " << st.pop() << endl;

  cout << "Top element is: " << st.top() << endl;
  cout << "Stack size is: " << st.size() << endl;

  cout << (st.empty() ? "Stack is empty" : "Stack not empty") << endl;

  return 0;
}
