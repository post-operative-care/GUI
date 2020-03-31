#include<iostream>
#include"library(Mekkwiz).h"
#include<cstdlib>
#include<iomanip>
#include<string>

using namespace std;
void Start(){
    string detect;
    cout << setw(50) <<"Welcome To Post Operative Care\n";
    cout << setw(47) <<"Press Enter To Contineue\n" ;
    if(getline(cin,detect)){
    }
}

void selectPage(){
    string input;
    cout << "Did You Have An Accout?\n";
    cout << "[1] If you have\n[2] IF you don't have\n[3] If You are Medical Staff\n[4] For Exit\n";
    do{cout << "Input Your Command Here: ";
    //cin >> input;
    getline(cin,input);
    if(input == "1"){
        login_page();
        break;
    }else if(input == "2"){
        register_page();
        login_page();
        break;
    }else if(input == "3"){
        //wait for medical staff func
        break;
    }else if(input == "4"){
        break;
    }else{
        cout << "Error Invalid Input\n";
    }
    }while(true);
}