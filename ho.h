#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<ctime>



//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
using namespace std;

//from jojo.h
int docpage_jojo(){
  cout << "Please input your username and password to login." << endl ;
  char usn[20];
  char pw[20];
  cout << "username: " ;
  cin >> usn;
  cout << "password: " ;
  cin >> pw;

  ifstream login_info;
  login_info.open("database\\user_data.txt");
  string textline;
  
  //how many of line
 // bool havetext;
 // havetext = getline(login_info, textline);
  //int n1=0;
 // while(havetext){
 //   n1++;
 //   havetext = getline(login_info, textline);
//  }

  int n2=0;
  int n=0 ;
  bool check=0;
  bool checkDorP=0;
  char text[50] ;
  getline(login_info, textline);
  while(getline(login_info, textline)){
    while(n<50){
      text[n]=textline[n];
      n++;
    }

    //sscanf for id and pass
    char format[] = "%[^=]= %s %[^:]: %s %[^:]: %s";
    char id[20];
    char pass[20];
    char type[3];
    char blank1[10];
    char blank2[10];
    char blank3[10];
    sscanf(text,format,blank1,id,blank2,pass,blank3,type);

    //how many of char id
    bool num ;
    int x=0;
    num = id[x];
    while(num){
		  x++;
		  num = id[x];
	  }
    //check username,id
    n=0;
    bool correctID=0;
    while(n<x){
      if(id[n]==usn[n]){
        n++;
        continue;
      }else{
        break;
      }
    }
    if(n==x) correctID=1 ;
    cout << "x = " << x << endl << "n = " << n << endl ;

    //how many of char pass
    bool num1 ;
    int y=0;
    num1 = pass[y];
    while(num1){
		  y++;
		  num1 = pass[y];
	  }
    //check password
    n=0;
    bool correctPASS=0;
    while(n<y){
      if(pass[n]==pw[n]){
        n++;
        continue;
      }else{
        break;
      }
    }
    if(n==y) correctPASS=1 ;
    cout << "y = " << y << endl << "n = " << n << endl ;

    //correct id and pass
    if(correctID==1&&correctPASS==1){
      //check type
      if(type[0]=='D'){
        checkDorP=1;
        check=1;
        break;
       }else{
         check=1;
         break;
         }
    }

   // n2++;
    getline(login_info, textline);
  }

  //check login sugsess or not
  if(check){
    cout << "Logging in sugsess" ;
  }else cout << "Invalid username or password";

  return 0;
}

//from Pack.h
char Select_case(int num_case){
    ifstream data1;
    string local;
    switch (num_case)
    {
        case 1 : local = "database/postoperative_data/abdominal";break;
        case 2 : local = "database/postoperative_data/cesarean";break;
        case 3 : local = "database/postoperative_data/eye";break;
        case 4 : local = "database/postoperative_data/gynecologic";break;
        case 5 : local = "database/postoperative_data/hernia";break;
        case 6 : local = "database/postoperative_data/hip replacement";break;
        case 7 : local = "database/postoperative_data/spine";break;
    }
    
    data1.open(local.c_str());
    string textline,text_read;
    

    char select;
    string skeyword,ekeyword;
    do{
        cout << "select data :" ;
        cin >> select;
        if(select == 'A' || select == 'a' )
        {
        skeyword = "!";
        ekeyword = "@";
        break;
        }
        else if(select == 'W' ||select == 'w' )
        {
        skeyword = "#";
        ekeyword = "$";
        break;
        }
        else if(select == 'D' ||select == 'd' )
        {
        skeyword = "%";
        ekeyword = "^";
        break;
        }
        else if(select == 'P' ||select == 'p' ){
        skeyword = "&";
        ekeyword = "*";
        break;
        }
        else
        {
        cout << "You entered incorrectly. Please enter again." << "\n";
    }
    }while(select != 'A' || select != 'a' || select != 'D' ||select != 'd' || select != 'W' || select != 'W' || select != 'P' ||select != 'p'  );
    
    int start,end,count=0;
    while(getline(data1,textline)){    
        int start = textline.find_first_of(skeyword);
        int end = textline.find_first_of(ekeyword);
        if(start==-1&&end==-1&&count==0){
            continue;
        }else if(start!=-1){
            cout << textline.substr(1,textline.size()) << "\n";
            count = 1;
        }else if(end==-1&&count==1) {
            cout << textline << "\n";
        }else{
            cout << textline.substr(0,textline.size()-1) << "\n";
            break;
            } ;
    }
    
    data1.close();
    return 0;
}


char check_if_read()
{
    ifstream file_userdata ("");



     char action;
    do{
        cout << "Please enter your selection : ";
        cin >> action;
        if(action == 'A' || action == 'a' )
        {
            cout << "OK, I got this." << "\n" << "----------------------------------------------------------------" << "\n";
        return 'A';
        }
        else if(action == 'E' ||action == 'e' )
        {
            cout << "Go to main menu." << "\n" << "----------------------------------------------------------------" << "\n";
        return 'E';
        }
        else
        {
            cout << "You entered incorrectly. Please enter again." << "\n";
        }
        }while(action != 'A' || action != 'a' || action != 'E' ||action != 'e' );
    
    return 0;
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
            //cout << "This username is already taken." << endl;
            return true;
        }
        

        
    } 
    file_in.close(); 
    return false;
}

bool check(char usn[20])
/* this function used to detect input on username that user gave
 not in used in database */
{
    string usUuEn = usn,usnEn;
    usnEn = EncryptionID(usUuEn);
    char current_name[100];
    ifstream file_in("database/user_data.txt");
    string textline;
    
    while (getline(file_in,textline))
    {
        //testcase
        //cout << "textline = " << textline << endl;
        sscanf(textline.c_str(),"ID = %s ",&current_name);
        //cout << cerent_name << endl;

        if (current_name == usnEn)
        {
            //cout << "This username is already taken." << endl;
            return true;
        }
        

        
    } 
    file_in.close(); 
    return false;
}


vector <string> VecID;
vector <string> VecPASS;

bool sign_up_page(char user[20],char pass[20],char conpass[20])
/*This function is the main core for register page. It cin
 Username and password then put it back to VecID and VecPASS.*/
{ 
    bool charcheck;
    string textInput;
    string idEncryp;
    string passInput;
    string passInput1;
    string passInput2;
    string PassEncryp;
    //string str_id;
    //char str_idEnc[69];
    //string str_password;
    //char str_passwordEnc[69];
    do{


        // cout << "Please enter your Username(Register) : ";
        // getline(cin,textInput);
        textInput = user;
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
            //cout << "Please enter your Password(Register) : "; // enter password for register
            //getline(cin,passInput1);
            passInput1 = pass;

            charcheck = passchecker(passInput1);
            if (charcheck == true)
            {
            //cout << "Please confirm your Password(Register) : "; // confirm password
            //getline(cin,passInput2);
            passInput2 = conpass;
            //cout << "-------------------------------------------------------" << endl;

            if (passInput1 == passInput2)
            {
                PassEncryp=EncryptionPASS(passInput2);
                VecPASS.push_back(PassEncryp);
                return false;
            }
            else // if dupicate
            {
                // cout << "Password and confirm password does not match" << endl;
                // cout << "Please try again" << endl;
                // cout << "-------------------------------------------------------" << endl;
                return true;   
            }
            
            
           
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


bool register_page(char user[20],char pass[20],char conpass[20]) 
/*not spacial in this func just make absaction for easy way to use in main*/
{
    char ID[69];
    string id_one;
    char Pass[69];
    string pass_one;

    ofstream file_out("database/user_data.txt",ios::app);
    if (sign_up_page(user,pass,conpass))
    {
        return false;
    }
    else
    {
        ifstream file_in("database/user_data.txt");
        string text1;
        int Sequence = 0;
        char temp1[1];

        while (getline(file_in,text1))
        {
            Sequence++;
        }

        file_in.close();
        file_out << "ID = " << VecID[0] << " PASSWORD : " << VecPASS[0] << " | TYPE : P No." << Sequence+1 <<  endl;
        file_out.close();
        VecID.clear();
        VecPASS.clear();
        return true;
    }
}

string login_page(char usn[20],char pass[20])
{   
    bool login_success = false;
    bool usernamecheck = false;
    bool charcheck;
    string text_input;
    string str_id;
    string str_password;
    string now_username(usn);
    string now_password(pass);

    
   
    do{
        /*cout << "-------------------------------------------------------" << endl;
       
        cout << "Please enter your Username(Login) : ";
        getline(cin,now_username);

        cout << "Please enter your Password(Login) : ";
        getline(cin,now_password);

        cout << "-------------------------------------------------------" << endl;*/

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
                /*cout << "login success" << endl;
                cout << "-------------------------------------------------------" << endl;*/
                login_success = true;

                string output = now_username+" "+type;
                return output;
            }
        }
        else
        {
            /*cout << "Username or Password  worng" << endl;
            cout << "Please enter your Username and Password again" << endl;
            continue;
            cout << "-------------------------------------------------------" << endl;*/
            
            return "false";
        }
        
    } while (login_success == false);
   return 0;
}

//from yoyo.h
void Start(){
    string detect;
    cout << setw(50) <<"Welcome To Post Operative Care\n";
    cout << setw(47) <<"Press Enter To Contineue\n" ;
    if(getline(cin,detect)){
    }
}

/*void selectPage(){
    string input;
    cout << "Did You Have An Accout?\n";
    cout << "[1] If you have\n[2] IF you don't have\n[3] If You are Medical Staff\n[4] For Exit\n";
    cout << "-------------------------------------------------------" << endl;
    do{cout << "Input Your Command Here: ";
    //cin >> input;
    getline(cin,input);
    cout << "-------------------------------------------------------" << endl;
    
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
}*/


int find_Sequence(string GetUsername)
{
    ifstream file_in("database/user_data.txt");
    string text1;
    char blank1[30],user[20];
    int sequ;
    while (getline(file_in,text1))
    {
        sscanf(text1.c_str(),"ID = %s %[^No.]No.%d",&user,&blank1,&sequ);
        if (DecrypttionID(user) == GetUsername)
        {
            
            return sequ;
        }
        
    }
    return 0;
    file_in.close();
}

/*char find_name(char name[]){
    ifstream file_in("database/userdatabase.txt");
    string text;
    char name[10],blank[20];
    while (getline(file_in,text))
    {
        sscanf(text.c_str(),"Name : %s %s",&name,blank[]);
        if (DecrypttionID(user) == GetUsername)
        {
            return sequ;
        }
        //userdatabase use108 col
    }
    return 0;
    file_in.close();
}
*/

//from pdatabase.h

bool isNotNumber(string s) 
 { 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == true) 
            return false; 
  
    return true; 
 } 


string upper_string(string str)
 {
    for(int i=0;str[i]!='\0';i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')   //checking for lowercase characters
            str[i] = str[i] - 32;        //converting lowercase to uppercase
    }
    return str;
 }

//THIS FOR CHANGE TEXT COLOR IN CONSOLE
/*void changeColor(int desiredColor)
 {
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
 }*/
//=====================================================================
//============================= OLD VERSION - And it's a new duplicate checker  ================================
 bool checkduplicateName(string fname,string lname)
  { 
    char current_fname[100];
    char current_lname[100];
    ifstream database_file("database/userdatabase.txt");
    string textline;
    
    while (getline(database_file,textline))
    {
        sscanf(textline.c_str(),"Name : %s LastName : %s  Date of Birth %d %d %d",&current_fname, &current_lname );
        //cout<<"DP Got From FName Is ::"<< current_fname << endl;
        //cout<<"DP Got From LName Is ::"<< current_lname << endl;
        string ucfn(current_fname);
        string ucln(current_lname);
         ucfn = upper_string(current_fname);
         ucln = upper_string(current_lname);
        string ufn=upper_string(fname);
        string uln=upper_string(lname);        
     
        if (ucfn == ufn && ucln == uln) //if (current_fname == fname && current_lname == lname)
        {
            database_file.close(); 
            return true;
            cout << "after return";
        }
        //cout << "LOOP IS ALIVE !!"<< endl;

    }
    return false;
    
  } 


//================================= END OF OLD VERSION =================================
//======================================================================
//THIS FOR FIND NAME OF MONTH BY INT THAT GET FROM USER 
string findNameMonth(int a)
 {
 switch (a)
    {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";   
    };
    return 0;
 }
//=======================================================================
 

//===========================================================================
void ShowHasDone(int day,int month,int year,string fname,string lname,string weight,string height){
 cout<< "\t\t\t-=========================================-"<< endl;
 cout<<"\t\t\t Data of  "<<" "<< fname << " " << lname <<endl;
 cout<<"\t\t\tWeight :"<< weight << " " << "Height :" << height <<endl;
 cout<<"\t\t\t"<< "Date of Birth is "<< day << " "<< findNameMonth(month) <<" "<< year <<endl;
 cout << "\t\t\thas added in database , THANKS !\n"  ;
 cout<< "\t\t\t-=========================================-"<<endl;
 }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



bool OverWeight(string we){
    double num;
    num = atof(we.c_str());
    if(num >= 700){
        return true;
    }else if(num < 0){
        return true;
    }else{
        return false;
    }
}

bool OverHeight(string He){
    double num;
    num = atof(He.c_str());
    if(num > 275){
        return true;
    }else{
        return false;
    }
}



int pdata_base(char Gender[10],char Illness[20],char Firstname[10],char Lastname[10],char Day[5],char Month[5],char Year[6],char Wei[5],char Hei[5])
{

string fname(Firstname),lname(Lastname),d(Day),mon(Month),yea(Year);
int day=atoi(d.c_str()), month=atoi(mon.c_str()), year=atoi(yea.c_str()) ;

 int acheck=1;
  do // IN DUOLICATE CHECK LOOP,LOOP ISN'T WORKIMG BUT USING GOTO INSTEAD !  
  {
    int acheck=1;
        int ch=1;
        //=========================== Loop FirstName Start here ==================================
       RegisterHere :
        do
        {
            ch = 1;
            /*cout<<"\t\t\t Input your patient FirstName :  ";
            getline(cin,fname);*/
            if(fname.find_first_not_of( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")!=string::npos)
            {
                ch = 0;/*
                changeColor(12);
                cout<<"\t\t\tYou can only input alpha here!\n";
                changeColor(7);*/
                return 10;
            }
            /*else if(fname.empty())
            {
                ch = 0;
                changeColor(12);
                cout<<"\n\t\t\tPlease enter your patient firstname!\n";
                changeColor(7);
            }
        cin.clear();*/
        } 
        while( ch !=1 );
    //==================================Loop FirstName End here=================================
    //THIS FOR CHECK AND GET LASTNAME !
        int che=1;
        //==================== Loop Lastname Start here =============================================== 
        do{
            che = 1;
            /*cout<<"\t\t\t Input your patient LastName :  ";
            getline(cin,lname);*/
            if(lname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")!=string::npos)
            {
                che = 0;
                /*changeColor(12);
                cout<<"\t\t\tYou can only input alpha here!\n";
                changeColor(7);*/
                return 10;
            }
            /*else if(lname.empty())
            {
                che = 0;
                changeColor(12);
                cout<<"\t\t\tPlease enter your patient lastname!\n";
                changeColor(7);
        }
        cin.clear();*/
        }while( che !=1 );
         //======================== Loop lasname end here ================================================
    if (checkduplicateName(fname,lname) == true)
    {
        acheck = 0;
        /*changeColor(12);
        cout<<"\t\t\tThis Patient has already Registred.\n";
        changeColor(7);*/
        return 11;
        goto RegisterHere ;
    }
    //cin.clear(); 
 }while ( acheck!=1 );

//========================================================================================

string weight(Wei),height(Hei);

int chw = 1 ;
do  //CHECK PATIENT WEIGHT AND HEIGHT
 {
    chw = 1;/*
    cout<<"\t\t\t Input your patient Weight (kg) : ";
    cin>>weight;*/
    if (OverWeight(weight))
    {
        return 12;
        chw = 0;
        /*changeColor(12);
        cout<<"\t\t\tPlease Check your patient Weight !! \n";
        changeColor(7);*/
    }
    //cin.clear();  
 } while (chw!=1);

 //=============================================================================================
 int chh=1;
 do
  {
    chh=1;
    /*cout<<"\t\t\t Input your patient height (cm) : ";
    cin>>height;*/
    if (OverHeight(height))
    {
        return 13;
        chh = 0;/*
        changeColor(12);
        cout<<"\t\t\tPlease Check your patient Height ! \n";
        changeColor(7);*/
    }
    //cin.clear();  
 } while (chh!=1);

//========================================================================================

  //THIS FOR CHECK AND GET DATE OF BIRTH !
 
  if(year<1919 || year > 2020)
    {
        return 17;
    }
    else if(month >= 1 && month <= 12)
    {
        if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        {
           if (day>31 || day<1)
           {
           return 14;
           }
        } 
        else if (month == 2)
        {
            if (day>29 || day<1)
            {
            return 15;
            }
        }
        else if (month==4 || month==6 || month==9 || month==11)
        { 
            if (day>30 || day<1)
            {
            return 16;
            }
        }   
    }
    else
    {
        return 18;
    }
    
    cout << day;
    
}    

//=======================================================================
// all here is for check before push back 
//ShowHasDone(day,month,year,fname,lname,weight,height);
//======================================================
void readcheck ();

void writeData(char Firstname[10],char Lastname[10],char Day[5],char Month[5],char Year[6],char Hei[5],char Wei[5],char Gen[10],char Ill[20],int id_doc){
//========================================================
    string fname(Firstname),lname(Lastname),d(Day),mon(Month),yea(Year), weight(Wei),height(Hei),Gender(Gen),Illness(Ill);
    int day=atoi(d.c_str()), month=atoi(mon.c_str()), year=atoi(yea.c_str());

    ifstream file_in("database\\userdatabase.txt");
    string text1;
    int Sequence = 0;
    char temp1[1];

    while (getline(file_in,text1))
    {
        Sequence++;
    }

    string format = "database\\"+to_string(id_doc)+"_patientlog.txt";
    
    string status_1 = "NULL",status_2 = "NULL",status_3 = "NULL",status_4 = "NULL";

    

    ofstream write("database\\userdatabase.txt",ios::out | ios::app); 
    ofstream write2(format.c_str(),ios::out | ios::app);//Plan to delete what we just added
    write << "Name : " <<fname<< " "<< "LastName : " <<lname << "  Date of Birth: "<<day<<" / "<<month<<" / "<< year << "   height:" << height << "  Weight:" << weight << " Gender:" << Gender << " Illness:" << Illness << " No." << Sequence+1 << " "<< "DoctorID :" << id_doc << endl;
    write2 << "Name : " <<fname<< " "<< "LastName : " <<lname  << " Illness : " << Illness << " | A : " << status_1 << " || W : " << status_2 << " || P : " << status_3 << " || D : " << status_4 << endl;
    write.close();
    write2.close();

}

int CalAge(int d,int m,int y) 
{
    int dn,mn,yn,age ;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    dn = ltm->tm_mday ;
    mn = (1 + ltm->tm_mon) ;
    yn = 1900 + ltm->tm_year;
    
    //cout << "now date = " << dn << " " << mn << " " << yn << endl;
    // กี่เดือน =(12-m)+mn
    // กี่วัน = 
    // age = (yn-y)-
    
    if (mn >= m)
    {
        if (dn >= d)
        {
            return yn-y; 
        }
        else
        {
            return yn-y-1;
        }
        
    }
    else
    {
        return yn-y-1;
    }
    
    
}


string SDataDB(int ID,char data_case) // N L D W H G I O
{
    ifstream file_input("database\\userdatabase.txt");
    string text1;
    char name[50],lastname[50],dofb[50],gender[50],illness[50] ;
    char height[10],weight[10],number[10] ;
    int date,month,year;
    //Name : Phirachat LastName : Kochanil  Date of Birth: 9 / 11 / 2000   height:171  Weight:71 Gender:Man Illness:Abdominal No.3
    char fomat[] = "Name : %s LastName : %s  Date of Birth: %d / %d / %d   height:%s  Weight:%s Gender:%s Illness:%s No.%s";
    while (getline(file_input,text1))
    {
        sscanf(text1.c_str(),fomat,&name,&lastname,&date,&month,&year,&height,&weight,&gender,&illness,&number);
        
        int Age = CalAge(date,month,year);
        
        string dob = to_string(date)+"/"+to_string(month)+"/"+to_string(year);
        
         if (ID == stoi(number))
         {
             switch (data_case)
             {
                case 'N': return name;           break;
                case 'L': return lastname;       break;
                case 'D': return dob;            break;
                case 'W': return weight;         break;
                case 'H': return height;         break;    
                case 'G': return gender;         break;
                case 'I': return illness;        break;
                case 'O': return number;         break;
                case 'A': return to_string(Age); break;    
                default: return "Error, Please Try Again ! "; break;
            }
        } 
    }
    
}


void readcheck (int id_pt,int num_botton)
{
    ifstream file_input("database/userdatabase.txt");
    string textline;
    char name[50],lastname[50],dofb[50],gender[50],illness[50] ;
    char height[10],weight[10],number[10] ;
    int date,month,year,doc_id;
    //Name : Phirachat LastName : Kochanil  Date of Birth: 9 / 11 / 2000   height:171  Weight:71 Gender:Man Illness:Abdominal No.3
    char fomat[] = "Name : %s LastName : %s  Date of Birth: %d / %d / %d   height:%s  Weight:%s Gender:%s Illness:%s No.%s DoctorID :%d";
    while (getline(file_input,textline))
    {
        sscanf(textline.c_str(),fomat,&name,&lastname,&date,&month,&year,&height,&weight,&gender,&illness,&number,&doc_id);
        if (id_pt == stoi(number))
        {
            break; // for find doc_id
        }
        
    }
    file_input.close();
                                    //usd doc id to access file
    string formatout = "database\\"+to_string(doc_id)+"_patientlog.txt";
    ifstream main_input(formatout.c_str());
    ofstream temp_out("database/temp.txt");

    string from_main;
    
    while (getline(main_input,from_main)) // create temp.txt that is a copy of patientlog.txt
    {
        temp_out << from_main << endl;
    }

    temp_out.close();
    main_input.close();

    ifstream status("database\\temp.txt");

    char my_name[30],my_Lname[30],my_ill[30];
    char format_status[] = "Name : %s LastName : %s  Illness : %s | A : %s || W : %s || P : %s || D : %s";
    string findstatus,str_name = name,str_myname,str_lastname = lastname,str_mylname;
    char status_1[5],status_2[5],status_3[5],status_4[5];
    while (getline(status,findstatus))
    {

        sscanf(findstatus.c_str(),format_status,&my_name,&my_Lname,&my_ill,status_1,&status_2,&status_3,&status_4);
        str_myname = my_name;
        str_mylname = my_Lname;
        if (str_name == str_myname)
        {
            //cout << 1;
            //cout << my_name << my_Lname << my_ill << status_1 << status_2 << status_3 << status_4 << endl;
            break;
        }
        //cout << status_1;
        
    }

    status.close();
    
    ifstream temp_in("database/temp.txt");
    ofstream main_output(formatout.c_str());
    string from_temp;

    string statusA = status_1;
    string statusW = status_2;
    string statusP = status_3;
    string statusD = status_4;

    switch (num_botton)
    {
    case 1 : statusA = "READ"; break;
    case 2 : statusW = "READ"; break;
    case 3 : statusP = "READ"; break;
    case 4 : statusD = "READ"; break;
    }
    
    
    while (getline(temp_in,from_temp))
    {      
                                    // Activity / Wound care / Prohibition / Diet care //  
        sscanf(from_temp.c_str(),format_status,&my_name,&my_Lname,&my_ill,status_1,&status_2,&status_3,&status_4);  
        str_myname = my_name;
        str_mylname = my_Lname;       
       //cout << str_myname  << str_name <<endl;
        if (str_myname == str_name && str_mylname == str_lastname)
        {
            //cout << 2;
            main_output << "Name : " << my_name <<" "<< "LastName : " << my_Lname << "  Illness : " << my_ill << " | A : " << statusA << " || W : " << statusW << " || P : " << statusP << " || D : " << statusD << endl;
        }
        else
        {
            main_output << from_temp << endl;
        }
        
        
    }
    temp_in.close();
    main_output.close();
   
   remove("database/temp.txt");
    
}
