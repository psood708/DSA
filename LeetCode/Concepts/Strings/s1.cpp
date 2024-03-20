#include<bits/stdc++.h>
using namespace std;
// get length function
int getLength(char name[]){
    int count = 0;
    for(int i =0;name[i]!='\0';i++){
        count++;
    }
    return count;
}


// Reverse a string
void reverse(char name[],int n){
    int s =0;
    int c = n -1;
    while(s<c){
        swap(name[s++],name[c--]);
    }
}

int main ()
{
    char a = 'z';
    char ch[10];
    cin>> ch;
    cout << "Name is: " << ch << endl;
    cout<< "Length of string: "<<getLength(ch)<<endl;
    return 0;
}