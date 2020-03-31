#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

/*string Encryption_ID(string text_input){
    string str_id;
    char str_idEnc[69];
    
    str_id = text_input;
    strcpy(str_idEnc,str_id.c_str());
    for (int i = 0; i<69 && str_idEnc[i]!='\0' ; i++) 
        {
            str_idEnc[i]=str_idEnc[i]+12;
        }
    //VecID.push_back(str_idEnc);
return str_idEnc;
} */

string EncryptionID(string x){
    char encryp[69];
    strcpy(encryp,x.c_str());
    for (int i = 0; i < 69 && encryp[i] != '\0' ; i++)
    {
        encryp[i]=encryp[i]+2;
    }
    string a = encryp;
    //cout <<"WHAT DAFUQ :: " << a << " ";
return a;

}

string EncryptionPASS(string y){
    char encrypPass[69];

    strcpy(encrypPass,y.c_str());
    for (int j = 0; j < 69 && encrypPass[j] != '\0' ; j++)
    {
        encrypPass[j]=encrypPass[j]+3;
    }
    string p = encrypPass;
    //cout <<" Pass DAFUQ :: " << p << " ";
return p;
}

string DecrypttionID(string x){
    char decrypID[69];

    strcpy(decrypID,x.c_str());
    for (int i = 0; i < 69 && decrypID[i] != '\0' ; i++)
    {
        decrypID[i]=decrypID[i]-2;
    }
    string deID = decrypID;
return deID;
}

string DecrypttionPASS(string x){
    char decrypPASS[69];

    strcpy(decrypPASS,x.c_str());
    for (int i = 0; i < 69 && decrypPASS[i] != '\0' ; i++)
    {
        decrypPASS[i]=decrypPASS[i]-3;
    }
    string dePASS = decrypPASS;
return dePASS;
}