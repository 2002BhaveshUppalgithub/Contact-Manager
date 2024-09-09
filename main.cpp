#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include "mycontacts.cpp"
using namespace std;
mycontact obj;
void email_search()
{
    char email[50];
    cout<<endl<<"enter email to search";
    cin>>email;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.email,email)==0)
        {
           cout<<endl<<"email is found in record";
           return ;
        }
    }
    rd.close();
    cout<<endl<<"email is not in record";
}
void phone_search()
{
    char phone[50];
    cout<<endl<<"enter phone number:";
    cin>>phone;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.phone,phone)==0)
        {
            cout<<endl<<"phone number id found";
            return;

        }
    }
    rd.close();
    cout<<endl<<"phone is not in record";
}
void name_search()
{
    char name[50];
    cout<<endl<<"enter name:";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"name is there in record";
            return;
        }

    }
    rd.close();
    cout<<endl<<"name is not in record";
}
void remove_contact()
{
    char name[50];
    cout<<endl<<"enter name";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size1=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size1;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            rd.close();
            cout<<endl<<"record is found";
            fstream rd1;
            rd1.open("mydatafile.txt",ios::in);
            rd1.seekg(0,ios::end);
            int size1=rd1.tellg()/sizeof(obj);
            rd1.seekg(0,ios::beg);
            fstream wr;
            wr.open("tempfile.txt",ios::app);
            for(int i=1;i<=size1;i++)
            {
                rd1.read((char *)&obj,sizeof(obj));
                if(strcmp(obj.name,name)==0)
                {
                   cout<<endl<<"record is removed";
                }
                else
                {
                    wr.write((char*)&obj,sizeof(obj));
                }

            }
            rd1.close();
            wr.close();
            remove("mydatafile.txt");
            rename("tempfile.txt","mydatafile.txt");
            return;

        }
    }
    rd.close();
    cout<<endl<<"record is not in list";

}
void update_contact()
{
    char name[50];
    cout<<endl<<"enter name to update";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size1=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size1;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            rd.close();
            cout<<endl<<"record is found";
            fstream rd1;
            rd1.open("mydatafile.txt",ios::in);
            rd1.seekg(0,ios::end);
            int size1=rd1.tellg()/sizeof(obj);
            rd1.seekg(0,ios::beg);
            fstream wr;
            wr.open("tempfile.txt",ios::app);
            for(int i=1;i<=size1;i++)
            {
                rd1.read((char *)&obj,sizeof(obj));
                if(strcmp(obj.name,name)==0)
                {
                   cout<<endl<<"record is there";
                   obj.accept();
                }
                wr.write((char*)&obj,sizeof(obj));

            }
            rd1.close();
            wr.close();
            remove("mydatafile.txt");
            rename("tempfile.txt","mydatafile.txt");
            return;

        }
    }
    rd.close();
    cout<<endl<<"record is not in list";

}

void read_data()
{
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    cout<<endl;
    cout<<left;
    cout<<setw(30);
    cout<<" NAME ";
    cout<<setw(30);
    cout<<" PHONE NO.";
    cout<<setw(30);
    cout<<" EMAIL ID ";
    cout<<setw(30);
    cout<<" INSTA ID.";
    cout<<setw(30);
    cout<<" TWITTER ";
    cout<<endl<<"*****************************************************************************************************************************************************";
    for(int i=1;i<=s;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        cout<<endl<<i<<".";
        obj.display();
        cout<<endl<<"************************************************************************************************************************************************";
    }
}
void add_contact()
{
    char name[50];
    cout<<endl<<"enter name to accept:";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"record is already there";
            return;
        }
    }
    obj.accept();
    fstream wr;
    wr.open("mydatafile.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    rd.close();
    wr.close();
    cout<<endl<<"file enter succesfully";


}
int main()
{
   int e=0;
   while(e==0)
   {
       int choice;
       cout<<endl<<"enter choice";
       cout<<endl<<"presss 1 to add contact";
       cout<<endl<<"presss 2 to read contact";
       cout<<endl<<"presss 3 to delete contact";
       cout<<endl<<"presss 4 to update contact";
       cout<<endl<<"presss  5 to search name in  contact";
       cout<<endl<<"press 6 to search phone";
       cout<<endl<<"press 7 to search email";
       cout<<endl<<"press 8 to exit";
       cin>>choice;
       if(choice==1)
       {
           add_contact();
       }
       else if(choice==2)
       {
           read_data();
       }
       else if(choice==3)
       {
           remove_contact();
       }
       else if(choice==4)
       {
           update_contact();
       }
       else if(choice==5)
       {
           name_search();
       }
       else if(choice==6)
       {
           phone_search();
       }
       else if(choice==7)
       {
           email_search();
       }
       else if(choice==8)
       {
           e=1;
       }
   }
}



