#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cstring>
#include<string>
#include"phird.h"

using namespace std;

bool charchecker(string text_input)
// this function used to detect input on username must be only a-z,A-Z,0-9
{
    bool check;
    for (int i = 0; i < text_input.size(); i++)
        {
            if (((text_input[i] >= 65 && text_input[i] <= 92) || (text_input[i] >= 97 && text_input[i] <= 124) || (text_input[i] >= 48 && text_input[i] <= 57)))
            //User name must be only a-z,A-Z,0-9
            {
                //if true reture true to charchecker()
                check = true;
            }
            else
            {
                //if false reture false to charchecker()
                check = false;
                break;
            }
            
            
        }
    return check;
}

bool passchecker(string text_input)
// this function used to detect input on username must be only a-z,A-Z,0-9
{
    bool check;
    for (int i = 0; i < text_input.size(); i++)
        {
            if (((text_input[i] >= 65 && text_input[i] <= 90) || (text_input[i] >= 97 && text_input[i] <= 122) || (text_input[i] >= 48 && text_input[i] <= 57)))
            //User name must be only a-z,A-Z,0-9
            {
                //if true reture true to charchecker()
                check = true;
            }
            else
            {
                //if false reture false to charchecker()
                check = false;
                break;
            }
            
            
        }
    return check;
}



bool checkduplicateID(string ID)
/* this function used to detect input on username that user gave
 not in used in database */
{
    char cerent_name[100];
    ifstream file_in("database/user_data.txt");
    string textline;
    
    while (getline(file_in,textline))
    {
        //testcase
        //cout << "textline = " << textline << endl;
        sscanf(textline.c_str(),"ID = %s ",&cerent_name);
        //cout << cerent_name << endl;

        if (cerent_name == ID)
        {
            cout << "This username is already taken." << endl;
            return true;
        }
        

        
    }
    return false;
    file_in.close(); 
}


vector <string> VecID;
vector <string> VecPASS;

void sign_up_page()
/*This function is the main core for register page. It cin
 Username and password then put it back to VecID and VecPASS.*/
{ 
    bool charcheck;
    string textInput;
    string idEncryp;
    string passInput;
    string PassEncryp;
    //string str_id;
    //char str_idEnc[69];
    //string str_password;
    //char str_passwordEnc[69];
    do{


        cout << "Please enter your Username(Register) : ";
        getline(cin,textInput);
        charcheck = charchecker(textInput);
        
        if (checkduplicateID(textInput) == true)
        {
            continue;
        }
        idEncryp=EncryptionID(textInput);
        VecID.push_back(idEncryp);
        

        if (charcheck == true)
        {
            p1:
            cout << "Please enter your Password(Register) : ";
            getline(cin,passInput);

            charcheck = passchecker(passInput);
            if (charcheck == true)
            {
            PassEncryp=EncryptionPASS(passInput);
            VecPASS.push_back(PassEncryp);
                break;
            }
            else
            {
                cout << "Password must be only a-z,A-Z,0-9" << endl;
                goto p1;
            }
            
            
        }
        else
        {
            cout << "Username must be only a-z,A-Z,0-9" << endl;
    
        }


    } while (true);
   
}


void register_page() 
/*not spacial in this func just make absaction for easy way to use in main*/
{
char ID[69];
string id_one;
char Pass[69];
string pass_one;

    ofstream file_out("database/user_data.txt",ios::app);
    
    cout << "-------------------------------------------------------" << endl;
    sign_up_page();
    cout << "-------------------------------------------------------" << endl;
    /*id_one = VecID;
    strcpy(ID,id_one.c_str());
    pass_one = VecPASS;
    strcpy(Pass,pass_one.c_str());
    for (int i = 0; i < 69 && ID[i] != '\0'; i++){
        ID[i]=ID[i]-12;
    }
    for (int j = 0; j < 69 && Pass[j] != '\0'; j++){
        Pass[j]=Pass[j]-8;
    } */

    //cout << "ID  = " << VecID[0] << " PASSWORD : " << VecID[0] << endl;
    
    file_out << "ID = " << VecID[0] << " PASSWORD : " << VecPASS[0] << endl;
    
    
}

void login_page()
{   
    bool login_success = false;
    bool usernamecheck = false;
    bool charcheck;
    string text_input;
    string str_id;
    string str_password;
    string now_username;
    string now_password;
    
   
    do{
        cout << "-------------------------------------------------------" << endl;
       
        cout << "Please enter your Username(Login) : ";
        getline(cin,now_username);

        cout << "Please enter your Password(Login) : ";
        getline(cin,now_password);

        cout << "-------------------------------------------------------" << endl;

        char database_name[100];
        char database_pass[100];
        ifstream file_in("database/user_data.txt");
        string textline;

        while (getline(file_in,textline)) // find username and pass in database
        {
            //testcase
            //cout << "textline = " << textline << endl;
            sscanf(textline.c_str(),"ID = %s PASSWORD : %s",&database_name,&database_pass);
            string enID = EncryptionID(now_username);

            //cout << databzse_name << " " << database_pass << endl;
        
           if (database_name == enID) 
            /*If Username that user input it's already in database 
            program will change usernamecheck to true*/
            {
                usernamecheck = true;
                //cout << usernamecheck << 1;
                break;
            }
            
        }
        file_in.close();
        
        //cout << usernamecheck << 2;
        if (usernamecheck == true)
        {
            string enPASS = EncryptionPASS(now_password);
            if (database_pass == enPASS)
            {
                cout << "login success" << endl;
                cout << "-------------------------------------------------------" << endl;
                login_success = true;
                break;
                
            }
        }
        else
        {
            cout << "Username or Password  worng" << endl;
            cout << "Please enter your Username and Password again" << endl;
            continue;
            cout << "-------------------------------------------------------" << endl;
        }
        
    } while (login_success == false);
   
}



