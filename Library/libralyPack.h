#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void Select_case(int num_case){
    ifstream data1;
    string local;
    switch (num_case)
    {
        case 1 : local = "database/postoperative_data/postoperative_abdominal";break;
        case 2 : local = "database/postoperative_data/postoperative_cesarean";break;
        case 3 : local = "database/postoperative_data/postoperative_eye";break;
        case 4 : local = "database/postoperative_data/postoperative_Gynecologic";break;
        case 5 : local = "database/postoperative_data/postoperative_hernia";break;
        case 6 : local = "database/postoperative_data/postoperative_hipjoint";break;
        case 7 : local = "database/postoperative_data/postoperative_spine";break;
    }
    
    data1.open(local.c_str());
    string textline;

    while(getline(data1,textline)){
        cout << textline << endl;
    }

}

