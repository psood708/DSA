#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
  string addBinary(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        string c;
        int flag =0;// this is to mark carry
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
         if (l1 < l2) swap(a, b);
        for(int i =0;i<l2;i++){
            if((b[i]=='0' && a[i]=='1') || (b[i]=='1' && a[i]=='0') ){
                if(flag ==1){
                    c.push_back('1');
                    flag=1;
                }
                else{
                c.push_back('1');
                }
            }
            else if(b[i]=='1' && a[i]=='1'){

                if(flag==1){
                    c.push_back(1);
                    flag=1;
                }
                else{
                c.push_back('0');
                // we need to put a carry
                flag = 1;
                }
            }
            else{
                if(flag==1) {
                    c.push_back('1');
                    flag = 0;}
                else c.push_back('0');
                
            }
        }
        if(flag==1) c.push_back('1');
        reverse(c.begin(),c.end());
        return c;
    }
 
string addBinary(string a, string b) {
    int l1 = a.length();
    int l2 = b.length();
    string c;
    int carry = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

     if (l1 < l2) swap(a, b);

    for (int i = 0; i < l1; i++) {
        int sum = (a[i] - '0') + (i < l2 ? b[i] - '0' : 0) + carry;
        c.push_back(sum % 2 + '0');
        carry = sum / 2;
    }

    if (carry)
        c.push_back('1');

    reverse(c.begin(), c.end());
    return c;
}

int main() {
    string a = "1011";
    string b = "1010";
    cout << "Sum: " << addBinary(a, b) << endl;
    return 0;
}


