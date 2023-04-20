#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 20
int N;   
bool board[MAX_N][MAX_N];   


bool is_safe(int row, int col) {
  int i, j;

  //  conflicts in the same row
  for (i = 0; i < N; i++) {
    if (board[row][i]) {
      return false;
    }
  }

  //conflicts in the same column
  for (i = 0; i < N; i++) {
    if (board[i][col]) {
      return false;
    }
  }

  // conflicts in the diagonal
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }

  //  conflicts in the anti-diagonal
  for (i = row, j = col; i >= 0 && j < N; i--, j++) {
    if (board[i][j]) {
      return false;
    }
  }

  //when no conflicts
  return true;
}

 // here we have contructed a structure in order to store the position of the Queen
bool solve(int col, vector<pair<int, int>>& queen_positions) {
  if (col == N) {
    return true;  
    //allo queens placed
  }
//here we will be iterating through the loops and will be 
  int row;
  for (row = 0; row < N; row++) {
    if (is_safe(row, col)) {
      board[row][col] = true;   
      queen_positions.push_back({row, col});  
      if (solve(col + 1, queen_positions)) {
        //terminating the backtrack
        return true;  
      }
      // Backtrack and remove the queen from position (row, col)
      board[row][col] = false; 
      queen_positions.pop_back();  
    }
  }

  return false; 
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
    cout<<"The solution row array is   : "<<endl;
    for (auto queen_pos : queen_positions) {
      cout <<  queen_pos.first  << " "; // Print queen's position
    }
  } else {
    cout << "No solution found.\n"; // No solution found, print a message
  }

  return 0; 
}
