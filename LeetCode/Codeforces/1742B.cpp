#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n1;
    cin >> n1;

    while (n1--) {
        map<long long, long long> mp;
        long long n2, flag = 0;
        cin >> n2;

        vector<long long> a(n2);   
        
        for (long long i = 0; i < n2; i++) {
            cin >> a[i];
            mp[a[i]]++;
            if (mp[a[i]] > 1) flag = 1;
        }

        if (flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
