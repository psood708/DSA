#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n); 
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int sumA = 0, sumB = 0;
    int left = 0, right = n - 1;  

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
 
            if (cards[left] > cards[right]) {
                sumA += cards[left];
                left++;
            } else {
                sumA += cards[right];
                right--;
            }
        } else {
     
            if (cards[left] > cards[right]) {
                sumB += cards[left];
                left++;
            } else {
                sumB += cards[right];
                right--;
            }
        }
    }

    cout << sumA << " " << sumB << endl;
    return 0;
}
