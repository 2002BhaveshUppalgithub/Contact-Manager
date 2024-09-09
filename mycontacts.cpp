#include<iostream>
#include<iomanip>
using namespace std;
class mycontact
{
private:
    char name[50],phone[50],email[50],insta[50],twitter[50];
public:
    void accept()
    {
        cout<<endl<<"enter name:";
        cin>>name;
        cout<<endl<<"enter phone number:";
        cin>>phone;
        cout<<endl<<"enter email id:";
        cin>>email;
        cout<<endl<<"enter insta id";
        cin>>insta;
        cout<<endl<<"enter twiiter id:";
        cin>>twitter;
    }
    void display()
    {
        cout<<endl<<endl;
        cout<<left;
        cout<<setw(30);
        cout<<name;
        cout<<setw(30);
        cout<<phone;
        cout<<setw(30);
        cout<<email;
        cout<<setw(30);
        cout<<insta;
        cout<<setw(30);
        cout<<twitter;
    }
    friend void remove_contact();
    friend void update_contact();
    friend void name_search();
    friend void phone_search();
    friend void email_search();
    friend void add_contact();

};
void remove_contact();
void update_contact();
void name_search();
void phone_search();
void email_search();
void add_contact();

