#include<iostream>
#include<string>
#include<vector>
using namespace std;
//for doc search patient v0
void find_data(){
    int n=4; 
    vector<string> x(n);
    for(int i=0; i<n; i++){
        cout << "testcin : " ; 
        string nn;
        cin >> nn ;
        x[i] = nn ;
    }
    
    string b = ("bra bra bra") ;
    string c = ("information") ;
    for(int i=0; i<n; i++){
        cout << "[" << i+1 << "] " << x[i] << "\t" << b  << "\n" ;
    }

    while(true){
        cout << "select : " ;
        int i;
        cin >> i ;
        if(i==0)break;
        cout << "--------------------------------------------------\n" ;
        cout << x[i-1] << " : " << b << " " << c << "\n" ;
        cout << "--------------------------------------------------\n" ;
    }
    
}