// Anshul Saini
// 2010990095
// G-8
// Question 1

#include <bits/stdc++.h>  // header files included
using namespace std;

long mean(vector<long> grades){ // function to calculate mean
    return accumulate(begin(grades), end(grades), (long)0)/grades.size();
}

long median(vector<long> grades, int size){ // function to calculate median
    sort(begin(grades), end(grades));   // sorting the grades using c++ STL sort algorithm.
    
    if(size % 2 != 0){
        return grades[size/2];
    }
    
    int a = size/2;
    int b = a + 1;
    
    return (grades[a] + grades[b])/2; 
}

pair<vector<string>, int> mode(vector<string> names, vector<long> grades){ 
    unordered_map<int, int> freq;   // unodered map created.
    
    for(int i=0; i<grades.size(); i++)
        freq[grades[i]]++;
    
    int key, val = 0;
    for(auto& p: freq){
        if(p.second > val)
            key = p.first;
    }
    
    pair<vector<string>, int> ans;
    vector<string> studentsWithMode;
    for(int i=0; i<grades.size(); i++){
        if(grades[i] == freq[key])
            studentsWithMode.push_back(names[i]);
    }
    
    return ans;
}

int main()  // main function declared.
{
    vector<string> names;   // vector for string declared
    vector<long> grades;    // vector for grades declared
    
    int size;
    cin>>size;
    
    string name;
    int grade;
    
    for(int i=0; i<size; i++){
        cin>>name>>grade;
        names.push_back(name);
        grades.push_back(grade);
    }
    
    cout<<"mean: "<<mean(grades)<<endl; // printing the mean
    cout<<"median: "<<median(grades, size)<<endl;   // printing the median
    
    pair<vector<string>, int> p = mode(names, grades);
    cout<<"mode: "<<p.second<<endl<<"students with the mode ";
    for(int i=0;i<p.first.size(); i++){
        cout<<p.first[i]<<" ";
    }
        
    return 0;
}
