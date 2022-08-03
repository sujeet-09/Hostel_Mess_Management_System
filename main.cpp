#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
#include<ctime>
#include<iomanip>

#include "tokens1.h"
using namespace std;
int login(); //login declaration

class Student{
    private:
        char date[11];
        char roll_no[11];
        char name[30];
        char dept[15];
        char startfrom[11];
        char upto[11];
        char paid[6];
        char UTR[13];
        char mob[11];

        void waitForEnter(void){
            cout<<"\n\n\n Press enter to Continue \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
        void listStudents(void){ //To list total Students
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");

            cout<<"\n\t\tList of Students\n";
            cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n    Date    |    Roll_No   |       Name        |     Department     |   STARTFROM  |      UPTO    |  PAID  |      UTR_No    |     Mob_No    ";
            cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------";
            while(fscanf(file, "%s %s %s %s %s %s %s %s %s", &date[0],&roll_no[0], &name[0] , &dept[0], &startfrom[0], &upto[0],&paid[0],&UTR[0],&mob[0])!= EOF)
            cout<<"\n"<<left<<setfill(' ')
            <<setw(10)<<date<<"    "
            <<setw(10)<<roll_no<<"      "
            <<setw(18)<<left<<name<<"    "
            <<setw(15)<<dept<<"    "
            <<setw(10)<<startfrom<<"    "
            <<setw(10)<<upto<<"    "
            <<setw(10)<<paid<<" "
            <<setw(12)<<UTR<<"    "
            <<setw(10)<<mob;
            fclose(file);
            waitForEnter();
        }
        bool showdetail_roll(char check[]){
            bool t=false;
            FILE *file;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s %s  %s %s %s %s",&date[0], &roll_no[0], &name[0] , &dept[0], &startfrom[0], &upto[0],  &paid[0], &UTR[0],&mob[0])!=EOF)
                if(strcmp(check,roll_no)==0){
                    t=true;
                	cout<<"\n---------------------";
                    cout<<"\nDate Issued: "<<date;
                    cout<<"\n---------------------";
                    cout<<"\nRoll_No: "<<roll_no;
                    cout<<"\n---------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nDepartment: "<<dept;
                    cout<<"\n---------------------";
                    cout<<"\nStartfrom: "<<startfrom;
                    cout<<"\n---------------------";
                    cout<<"\nUpto: "<<upto;
                    cout<<"\n---------------------";
                    cout<<"\nPaid: "<<paid;
                    cout<<"\n---------------------";
                    cout<<"\nUTR_No: "<<UTR;
                    cout<<"\n---------------------";
                    cout<<"\nMob_No: "<<mob;
                    cout<<"\n---------------------";
                }
            if(t==false){
                cout<<"Record DO NOT exist corresponding to roll no"<<endl;}
            fclose(file);
            return t;

        }
        void showDetails(void){ //Displays all details according to Students's roll_no
            system("cls");
            char check[10];
            cout<<"\n\nEnter Student's Roll_No:  ";
            cin>>check;
            bool t=showdetail_roll(check);
            waitForEnter();
        }

        void editExisting(void){ //edits Details of existing student
            system("cls");
            char check[10];
            cout<<"\nEnter Student's Roll_No: ";
            cin>>check;

            bool t=showdetail_roll(check);

            if(t==true){
                char newStartfrom[10];
                cout<<"\n-----------------------------";
                cout<<"\nEnter Startfrom Date: ";
                cin>>newStartfrom;
                char newUpto[10];
                cout<<"\n-----------------------------";
                cout<<"\nEnter Upto Date: ";
                cin>>newUpto;
                char newPaid[10];
                cout<<"\n-----------------------------";
                cout<<"\nEnter Amount Paid: ";
                cin>>newPaid;
                char utr[10];
                cout<<"\n-----------------------------";
                cout<<"\nEnter UTR_No: ";
                cin>>utr;
                cout<<"\n-----------------------------";
                char newmob[10];
                cout<<"\nEnter Mob_No: ";
                cin>>newmob;

                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %s %s %s %s %s %s",&date[0], &roll_no[0], &name[0] , &dept[0],&startfrom[0], &upto[0],  &paid[0], &UTR[0],&mob[0])!=EOF){
                    if(strcmp(check,roll_no)==0)
                        fprintf(tempfile, "%s %s %s %s %s %s %s %s %s\n", date, roll_no, name, dept, newStartfrom, newUpto,  newPaid ,utr,newmob);
                    else
                        fprintf(tempfile, "%s %s %s %s %s  %s %s  %s %s\n", date, roll_no, name, dept, startfrom, upto,  paid , UTR, mob);
                }
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                waitForEnter();
            }

    }

        void addNewStudent(void){ //adding records
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Students's Roll_No: ";
            cin>>roll_no;
            char check[11];for(int i=0;i<11;i++)check[i]=roll_no[i];
            bool t=showdetail_roll(check);
            cout<<"\n----------------------------------------";
            if(t==false){
                cout<<"\n Enter Student's First Name: ";
                cin>>name;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter Department: ";
                cin>>dept;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter Date (Startfrom): ";
                cin>>startfrom;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter Date (Upto): ";
                cin>>upto;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter Amount Paid: ";
                cin>>paid;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter UTR_No: ";
                cin>>UTR;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter Mob_No: ";
                cin>>mob;
                cout<<"\n----------------------------------------";

                char ch;
                cout<<"\nEnter 'y' to save above information\n";
                cin>>ch;
                if(ch=='y'){
                    FILE  *file;
                    file= fopen("data.txt","a");
                    fprintf(file, "%s %s %s %s %s %s %s %s %s\n", date, check, name, dept, startfrom, upto,  paid, UTR, mob);
                    fclose(file);
                    cout<<"\nNew Student has been added to database\n";
                }
                else
                    addNewStudent();
            }
            waitForEnter();
        }

        void deleteStudentDetails(void){ //removing records
            system("cls");
            char check[10];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Student's Roll_No to Remove: ";
            cin>>check;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %s %s %s %s  %s %s", &date[0],&roll_no[0], &name[0] ,&dept[0], &startfrom[0], &upto[0], &paid[0], &UTR[0],&mob[0])!=EOF)
                    if(strcmp(check,roll_no)!=0)
                        fprintf(tempfile, "%s %s %s %s %s %s %s %s %s\n", date, roll_no, name, dept, startfrom, upto,  paid, UTR, mob);
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
            waitForEnter();
            }
            else
                deleteStudentDetails();
        }

        void Total_Record(){
            system("cls");
            int t_stu=0,t_money=0;
            FILE *file;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s %s  %s %s %s %s",&date[0], &roll_no[0], &name[0] , &dept[0], &startfrom[0], &upto[0],  &paid[0], &UTR[0],&mob[0])!=EOF){
                t_money+=stoi(paid);
                t_stu++;

            }
            fclose(file);
            cout<<"\n\n\n\t\t\tTotal Students: "<<t_stu<<endl;
            cout<<"\n\n\t\t\tTotal Amount  : "<<t_money<<endl;
            waitForEnter();
        }

    public:

        Student(){
            date[10]='\0';
            roll_no[10]='\0';
            dept[14]='\0';
            startfrom[10]='\0';
            upto[10]='\0';
            UTR[12]='\0';
            mob[10]='\0';
        }

        // Function to serve as end point
        void options(void){ //Showing Options
        setdate();

                login();//login screen
            while(true){
                system("cls");
                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>> COLLEGE MESS MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Students";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Student's Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Student's Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Student Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Student Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   6:   To Generate TOKENS for Today";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   7:   To Get Total Students & Amount";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nCOLLEGE MESS MANAGEMENT SYSTEM \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listStudents();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewStudent();
                        break;
                    case 5:
                        deleteStudentDetails();
                        break;
                    case 6:
                        Extra e;e.options();
                        break;
                    case 7:
                        Total_Record();
                        break;
                    default:
                        cout<<"\n Sorry! I don't understand that! \n";
                        break;
                }

            }
        }
        void setdate(){
            time_t now=time(0);
            tm *ltm = localtime(&now);
            string s=to_string(ltm->tm_mday)+"/"+to_string(ltm->tm_mon)+"/"+to_string(1900+ltm->tm_year);
            for(int i=0;i<s.size();i++)date[i]=s[i];
        }

};

int main(){

    // Call the options function
    Student st;
    st.options();
    return 0;
}

int login(){ //login procedure
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tCOLLEGE MESS MANAGEMENT SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13){//Enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++)
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";

      //system("PAUSE");
      system("CLS");
   }else{
      cout << "\n\t\t\t\tAccess Aborted...\n";
      login();
   }
}
