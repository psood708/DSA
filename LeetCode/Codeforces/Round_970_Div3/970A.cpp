#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
      
        int totalSum = a + 2 * b;
        
      
        if (totalSum % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
// Today, Sakurako has a math exam. The teacher gave the array, consisting of a
//  ones and b
//  twos.

// In an array, Sakurako must place either a '+' or a '-' in front of each element so that the sum of all elements in the array equals 0
// .

// Sakurako is not sure if it is possible to solve this problem, so determine whether there is a way to assign signs such that the sum of all elements in the array equals 0
// .

// Input
// The first line contains a single integer t
//  (1≤t≤100
// )  — the number of test cases.

// The only line of each test case contains two integers a
//  and b
//  (0≤a,b<10
// )  — the number of '1's and the number of '2's in the array.

// Output
// For each test case, output "Yes" if you can make the sum of the entire array equal to 0
// , and "No" otherwise.

// You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.