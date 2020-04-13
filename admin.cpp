#include "ho.h"

void Admin_register_ext();
void AdminRegister();
void AdminLogin();

int main()
{
    AdminRegister();
    //AdminLogin();
}

void Admin_register_ext()
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


        cout << "Please enter your Admin-Username(Register) : ";
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
            cout << "Please enter your Admin-Password(Register) : ";
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

void AdminRegister() 
/*not spacial in this func just make absaction for easy way to use in main*/
{
char ID[69];
string id_one;
char Pass[69];
string pass_one;

    ofstream file_out("database/admin_data.txt",ios::app);
    
    cout << "-------------------------------------------------------" << endl;
    Admin_register_ext();
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

void AdminLogin()
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
       
        cout << "Please enter your Admin-Username(Login) : ";
        getline(cin,now_username);

        cout << "Please enter your Admin-Password(Login) : ";
        getline(cin,now_password);

        cout << "-------------------------------------------------------" << endl;

        char database_name[100];
        char database_pass[100];
        ifstream file_in("database/admin_data.txt");
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