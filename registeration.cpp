#include<iostream>
#include<fstream>
using namespace std;
class temp
{
    string username,email,password,searchname,searchemail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot_password();
}obj;


int main()
{
    char choice;
    cout<<"\n 1- LOGIN";
    cout<<"\n 2- SIGN UP";
    cout<<"\n 3- FORGOT PASSWORD ";
    cout<<"\n 4- EXIT"<<"\n Enter your choice\n";
    cin>>choice;
switch(choice)
{
case '1':
cin.ignore();
obj.login();
break;

case '2':
cin.ignore();
obj.signUp();
break;

case '3':
cin.ignore();
obj.forgot_password();
break;

case '4':
cout<<"THANK YOU FOR VISITING ON THIS PAGE!";
break;
 
defualt:
cout<<"INVALID SELECTION";
}  
return 0;  
}
void temp::signUp()
{
    cout<<"\nENTER YOUR USERNAME:";
    getline(cin,username);
    cout<<"\nENTER YOUR EMAIL:";
    getline(cin,email);
    cout<<"\nENTER YOUR PASSWORD:";
getline(cin,password);
cout<<endl<<username<<"!YOUR ACCOUNT IS CREATED SUCCESSFULLY";

    file.open("register.txt",ios::out|ios::app);
    file<<username<<"*"<<email<<"*"<<password<<endl;
    file.close();
}
void temp::login()
{
    string user,pass;
 cout<<"\n ENTER YOUR EMAIL";
 getline(cin,user);
 cout<<"\n ENTER YOUR PASSWORD";  
 getline(cin,pass); 

 file.open("register.txt",ios::in);
 getline(file,username,'*');
 getline(file,email,'*');
  getline(file,password,'\n');
  while(!file.eof())
  {
 if(user==email)
 {
    if(pass==password)
        cout<<"LOGIN SUCCESSFUL!";
 else
    cout<<"LOGIN FAILED!";
 }
  getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
 }
 file.close();
}
void temp::forgot_password()
{
    cout<<"ENTER YOUR USERNAME";
    getline(cin,searchname);
    cout<<"ENTER YOUR EMAIL";
    getline(cin,searchemail);

    file.open("register.txt",ios::in);
   getline(file,username,'*');
   getline(file,email,'*');
   getline(file,password,'\n');
   while(!file.eof())
   {
    if(username==searchname)
    {
        if(email==searchemail)
        {
            cout<<"ACCOUNT FOUND";
            cout<<"password:"<<password<<endl;
        }
    else
    cout<<"\n NOT FOUND";
    }
    else
    cout<<"\n NOT FOUND";
   }

}

