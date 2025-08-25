// #include <bits/stdc++.h>
// using namespace std;

// // --------- Function to check if person a knows person b ---------
// bool knows(int a, int b, vector<vector<int>> &M)
// {
//   return M[a][b] == 1;
// }

// // --------- Function to find Celebrity ---------
// int findCelebrity(int n, vector<vector<int>> &M)
// {
//   int el1 = -1;
//   int el2 = -1;
//   ;
//   int m = M[0].size();
//   for (int i = 0; i < n; i++)
//   {
//     bool rowZero = true;
//     for (int j = 0; j < m; j++)
//     {
//       if (i != j && M[i][j] == 1)
//       {
//         rowZero = false;
//         break;
//       }
//     }
//     if (rowZero)
//     {
//       el1 = i;
//       break;
//     }
//   }
//   if (el1 == -1)
//     return -1;

//   bool colCheck = true;
//   for (int i = 0; i < n; i++)
//   {
//     if (i != el1 && M[i][el1] == 0)
//     {
//       colCheck = false;
//       break;
//     }
//   }

//   if (colCheck)
//     return el1;

//   return -1; // placeholder
// }

// int main()
// {
//   // Example input
//   vector<vector<int>> M = {
//       {0, 1, 1},
//       {0, 0, 1},
//       {0, 0, 0}};

//   int n = M.size();

//   int celeb = findCelebrity(n, M);

//   if (celeb == -1)
//   {
//     cout << "No celebrity found\n";
//   }
//   else
//   {
//     cout << "Celebrity is person " << celeb << endl;
//   }

//   return 0;
// }

// OPTIMAL

#include <bits/stdc++.h>
using namespace std;

// knows API using matrix
bool knows(int a, int b, vector<vector<int>> &M)
{
  return M[a][b] == 1;
}

int findCelebrity(int n, vector<vector<int>> &M)
{
  int a = 0, b = n - 1;

  // Step 1: Find candidate
  while (a < b)
  {
    if (knows(a, b, M))
    {
      a++; // a cannot be celebrity
    }
    else
    {
      b--; // b cannot be celebrity
    }
  }

  int candidate = a;

  // Step 2: Verify candidate
  for (int i = 0; i < n; i++)
  {
    if (i != candidate)
    {
      if (knows(candidate, i, M) || !knows(i, candidate, M))
      {
        return -1; // not a celebrity
      }
    }
  }

  return candidate;
}

int main()
{
  vector<vector<int>> M = {
      {0, 1, 1},
      {0, 0, 1},
      {0, 0, 0}};

  int n = M.size();
  int celeb = findCelebrity(n, M);

  if (celeb == -1)
  {
    cout << "No celebrity found\n";
  }
  else
  {
    cout << "Celebrity is person " << celeb << endl;
  }

  return 0;
}
