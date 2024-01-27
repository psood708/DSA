#include<bits/stdc++.h>
using namespace std;

// STL is being divided into 4 parts
// ALgorithms
// Containers
// Functions
// Iterators

void expPair(){

    pair<int,int> p = {1,3};
    // storing 3 values in a pair
    pair<int, pair<int,int>> p1 = {3,{4,5}};
    cout<<p1.first<< " "<< p1.second.first<<" - "<<p1.second.second;
}

// void expVector(){

//     vector<int> v;
//     // vectors is a container that is dynamic in nature
//     v.push_back(1);
//     v.emplace_back(2); // faster than push back

//     vector<pair<int,int>> vec;
//     vec.push_back({1,2});
//     vec.emplace_back(1,2);
//     vector<int> v3(5,100); // this will be [100,100,100,100,100]
//     vector<int> v2(v);



//     // now we'll be donig iterator

//     vector<int>::iterator it = v.begin(); // pointing to the memory of v first element
//     it++;
//     cout<<*(it) << " ";
//     it+=2;
//     cout<<*(it)<< " ";

//     vector<int>::iterator it = v.end(); // [10,20,30,40] _ end is pointing to after the element present in the array
//     vector<int>::iterator it = v.rend(); // reverse end
//     vector<int>::iterator it = v.rbegin(); // reverse begin

//     cout<< v[0] << " "<<v.at(0);
//     cout<< v.back()<<" ";

//     for(vector<int>::iterator it = v.begin(); it!=v.end();it++){
//             cout<<*(it)<<" ";
//     }
//     for(auto it = v.begin; it!=v.end();it++){
//         cout<< *(it)<<" ";
//     }
//     for(auto it:v){
//         cout<< it<<" ";
//     }
//     //deletion in a vector
//     v.erase(v.begin()+1);
//     v.erase(v.begin()+2,v.begin()+4);

//     //insert function

//     vector<int> v(2,100);
//     v.insert(v.begin(),300);
//     v.insert(v.begin()+1,2,10);

//     vector<int> copy(2,50);
//     v.insert(v.begin(),copy.begin(),copy.end());

//     cout<< v.size();
//     v.pop_back();
//     v1.swap(v2);
//     v.clear();
//     cout<< v.empty();
// }   

void explainList(){

    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front();
}

void expDeque(){
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);


    dq.pop_back();
    dq.pop_front();
    dq.back();
    dq.front();

    // rest same function s as vector - begin, end ,rbegin,rend,clear,insert,size ,swap
     for(auto it:dq){
        cout<< it<<" ";
    }
}

void explainStack(){

    //LIFO ( Last in first out)
    //everything happens in O(1)
    stack <int> stk;
    stk.push(10);                   // push() is used to insert an element
    stk.push(20);
    stk.push(30);
    stk.emplace(5);

    cout<<stk.top()<<endl;
    stk.pop();

    cout<<stk.top()<<endl;
    cout<<stk.size()<<endl;
    //stack does not have a direct iterator but we can use the stack::container type to
    //access elements using iterators
    // for(auto &i : stk) {
    //     cout << i << " ";
    //     }
}

void expQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back()+=5;
    cout<<q.back()<<endl;
    cout<<q.front()<<endl;
    q.pop(); // this will pop fromteh front
    cout<<q.front()<<endl;
}

void expPriorityQue(){
    // push , pop happens in  O(logn)
    // top happens in O(1)
    // this is the max heap
    priority_queue<int>pq;
    // the lexographical value will be atthe top
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    // this is the minimum heap
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(9);
    pq1.push(2);
    pq1.push(8);
    pq1.emplace(10);

    cout<<pq1.top()<<endl;
}

void expSet(){

    //everything happens in logrithmic time complexity
    //stores everything in sorted and unique
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(8);
    st.insert(4);
    // here a tree is maintained

    auto it = st.find(4);
    // auto it = st.find(6);

    cout<<it<<endl;
    // st.erase(5);
    // int cnt = st.count(1);
    // st.erase(8);

    // To do further research on this
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

}

void expMultiSet(){
// this only follows the unique propeorty

multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.insert(2);
// ms.erase(1); // this will delete all the occurence of 1
int cnt = ms.count(1);
cout<< cnt<<endl;
ms.erase(ms.find(1));
ms.erase(ms.find(1),ms.find(1)+2)

}


void expMap(){
    map<int,int> mpp;
    map<int,pair<int,int>> mpp1;
    map< pair<int,int>
}

int main(){
    // expPair();
    // expVector();
    // expDeque();
    // explainStack();
    // expQueue();
    // expPriorityQue();
    expSet();
    return 0;
}