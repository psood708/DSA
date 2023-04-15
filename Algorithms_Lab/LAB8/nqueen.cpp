#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 20
int N;  // Size of the chessboard
bool board[MAX_N][MAX_N];  // Chessboard represented as a 2D boolean array

// Check whether it is safe to place a queen at position (row, col)
bool is_safe(int row, int col) {
  int i, j;

  // Check for conflicts in the same row
  for (i = 0; i < N; i++) {
    if (board[row][i]) {
      return false;
    }
  }

  // Check for conflicts in the same column
  for (i = 0; i < N; i++) {
    if (board[i][col]) {
      return false;
    }
  }

  // Check for conflicts in the diagonal
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }

  // Check for conflicts in the anti-diagonal
  for (i = row, j = col; i >= 0 && j < N; i--, j++) {
    if (board[i][j]) {
      return false;
    }
  }

  // No conflicts found, it is safe to place a queen at position (row, col)
  return true;
}

// Recursive function to solve the N-Queens problem using backtracking
// here we have contructed a structure in order to store the position of the Queen
bool solve(int col, vector<pair<int, int>>& queen_positions) {
  if (col == N) {
    return true; // All queens have been placed, a solution is found
  }
//here we will be iterating through the loops and will be 
  int row;
  for (row = 0; row < N; row++) {
    if (is_safe(row, col)) {
      board[row][col] = true;  // Place a queen at position (row, col)
      queen_positions.push_back({row, col}); // Add queen's position to vector
      if (solve(col + 1, queen_positions)) {
        return true; // Found a solution, terminate recursion and backtrack
      }
      board[row][col] = false; // Backtrack and remove the queen from position (row, col)
      queen_positions.pop_back(); // Remove queen's position from vector
    }
  }

  return false; // No solution found for the current configuration, backtrack
}

int main() {
  cout << "Enter the value of N: ";
  cin >> N;

  vector<pair<int, int>> queen_positions; // Vector to store queen positions
  if (solve(0, queen_positions)) {
    cout << "Solution:\n";
     for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
       if(board[i][j]){
        cout<<" Q";
       }
       else{
        cout<<" -";
       }
      }
      cout<<endl;
    }
    cout<<"The solution array is : "<<endl;
    for (auto queen_pos : queen_positions) {
      cout << N-queen_pos.first << " "; // Print queen's position
    }
  } else {
    cout << "No solution found.\n"; // No solution found, print a message
  }

  return 0;
}
