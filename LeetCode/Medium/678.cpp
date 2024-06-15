#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
        stack<int> leftParen, asterisk;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftParen.push(i);
            } else if (s[i] == ')') {
                if (!leftParen.empty()) {
                    leftParen.pop();
                } else if (!asterisk.empty()) {
                    asterisk.pop();
                } else {
                    return false;
                }
            } else {
                asterisk.push(i);
            }
        }
        
        while (!leftParen.empty() && !asterisk.empty()) {
            if (leftParen.top() > asterisk.top()) {
                return false;
            }
            leftParen.pop();
            asterisk.pop();
        }
        
        return leftParen.empty();
    }

int main()
{
    string s = "{*}}";
    cout<< checkValidString(s);
    return 0;
}