/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//sort map by values

// Anshul Saini
// 2010990095
// G-8
// Set-2
//Question 1

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    //checking a.second ==b.second if true then a.first<b.first is returned in form of true or false
    //else a.second<b.second is returned in form of a.second < b.second
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

vector<pair<int, int>> sortmap(unordered_map<int, int>& mp){
    vector<pair<int, int>> v;
    
    for(auto& p: mp)
        v.push_back(p);
        
    //sort function from stl c++ with cmp function
    sort(begin(v), end(v), cmp);
    return v;
}

int main()
{
    //initializing map
    unordered_map<int, int> mp;
    
    int size;
    cin>>size;
    int a, b;
    //taking user input
    for(int i=0; i<size; i++){
        cin>>a>>b;
        mp[a] = b;
    }
    
    //calling function sortmap and storing its returning value in result 
    vector<pair<int, int>> result = sortmap(mp);
    for(auto& x: result){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    return 0;
}


