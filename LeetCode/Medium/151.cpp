#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    string ans = "",temp="";
    int n = s.size();
    bool first = true;
    for(int i =0;i<n;i++){
        if(s[i]!=' '){
            temp+=s[i];
        }else{
            if(temp.size()>0){
                if(first){
                    ans+=temp;
                    first= false;
                }else{
                    ans=(temp+" "+ans);
                }
            }
            temp="";
        }
    }
    if(temp.size() > 0){
        if(first){
            ans+=temp;
            first = false;

        }else{
            ans = (temp+" "+ans);
        }
    }
    return ans;
}

int main ()
{
    string s1 = "parth is a good boy";
    
    cout<<"This is normal sent.: "<<s1<<endl;
    cout<<"This is your reversed sent. : "<<reverseWords(s1)<<endl;
     
    return 0;
}