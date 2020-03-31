#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<windows.h>

HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
using namespace std;

//from jojo.h
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

//from Pack.h
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

//from phird.h
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


//from mek.h
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
    file_in.close(); 
    return false;
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
    
    file_out << "ID = " << VecID[0] << " PASSWORD : " << VecPASS[0] << " | TYPE : P" << endl;
    
    
}

char login_page()
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
        char type;
        ifstream file_in("database/user_data.txt");
        string textline;

        while (getline(file_in,textline)) // find username and pass in database
        {
            //testcase
            //cout << "textline = " << textline << endl;
            sscanf(textline.c_str(),"ID = %s PASSWORD : %s | TYPE : %c",&database_name,&database_pass,&type);
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
                return(type);
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

//from yoyo.h
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
        //login
        login_page();
        break;
    }else if(input == "2"){
        //register and login
        register_page();
        login_page();
        break;
    }else if(input == "3"){
        //wait for medical staff func
        break;
    }else if(input == "4"){
        //exit
        break;
    }else{
        cout << "Error Invalid Input\n";
    }
    }while(true);
}

