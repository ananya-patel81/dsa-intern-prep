#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of the stack
void generate(int n,string curr,vector< string>& result ){
    if(curr.length()==n){
        result.push_back(curr);
        return;
        
    }
    generate(n,curr+"0",result);
    if(curr.empty()||curr.back()!='1'){
        generate(n,curr+"1",result);
        
    }
    
}


int main() {
    // Input length n
    int n = 3;

    // Vector to store results
    vector<string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
