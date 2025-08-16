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

// Queue implementation
class Queue
{
  Node *front; // points to front element
  Node *rear;  // points to last element
  int curSize; // track size

public:
  Queue()
  {
    front = rear = nullptr;
    curSize = 0;
  }

  // Enqueue (push element into queue)
  void enqueue(int x)
  {
    Node *temp = new Node(x);
    cout << "Enqueued " << x << endl;
    if (rear == nullptr)
    { // empty queue
      front = rear = temp;
    }
    else
    {
      rear->next = temp;
      rear = temp;
    }
    curSize++;
  }

  // Dequeue (pop element from queue)
  int dequeue()
  {
    if (front == nullptr)
    {
      cout << "Queue Underflow\n";
      return -1;
    }
    int val = front->data;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
    { // queue became empty
      rear = nullptr;
    }
    delete temp;
    curSize--;
    return val;
  }

  // Get front element
  int peek()
  {
    if (front == nullptr)
    {
      cout << "Queue is empty\n";
      return -1;
    }
    return front->data;
  }

  // Get current size
  int size()
  {
    return curSize;
  }

  // Check if queue is empty
  bool empty()
  {
    return (front == nullptr);
  }
};

// Driver code
int main()
{
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  cout << "Front element: " << q.peek() << endl;
  cout << "Queue size: " << q.size() << endl;

  cout << "Dequeued: " << q.dequeue() << endl;
  cout << "Dequeued: " << q.dequeue() << endl;

  cout << "Front element: " << q.peek() << endl;
  cout << "Queue size: " << q.size() << endl;

  cout << (q.empty() ? "Queue is empty" : "Queue not empty") << endl;

  return 0;
}
