#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
#include<ctime>
using namespace std;

char date[10];

class Extra{
    private:
        char id[10];
        int quantity;
        float amount;
        char UTR[12];

        void waitForEnter(void){
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
        void listExtra(void){ //To list total employees with Name, Id and Designation
            system("cls");
            FILE *file;
            file= fopen("extra.txt", "r");

            cout<<"\n\t\t\t\tDetails of Extra Served\n";
            cout<<"\n-----------------------------------------------------------------------------------------";
            cout<<"\n  Date     |     Roll No       |     Quantity     |   Amount    |            UTR         ";
            cout<<"\n-----------------------------------------------------------------------------------------";
            while(fscanf(file, "%s %s %d %f %s ", &date[0], &id[0] , &quantity, &amount, &UTR[0])!= EOF)
            cout<<"\n"<<date<<"\t"<<id<<"\t\t"<<quantity<<"\t\t"<<amount<<"\t\t"<<UTR;
            fclose(file);
            waitForEnter();
        }

        //Adding Details
        void addExtra(void){ //adding records
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Roll No of Student: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Quantity Required: ";
            cin>>quantity;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Amount Paid: ";
            cin>>amount;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter UTR Number: ";
            cin>>UTR;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("extra.txt","a");
                fprintf(file, "%s %s %d %f %s  \n", date, id, quantity, amount, UTR );
                fclose(file);
                cout<<"\nNew DATA has been added to database\n";
            }
            else
                addExtra();
            waitForEnter();
        }

    public:
        // Function to serve as end point
        void options(void){
            while(true){
                system("cls");

                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  MESS MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<endl<<endl;
                cout<<"\n\t\t\t  T T T T   O     K    K   E E E   N      N  ";
                cout<<"\n\t\t\t     T    O   O   K  K     E       N N    N  ";
                cout<<"\n\t\t\t     T   O     O  K K      E E E   N  N   N  ";
                cout<<"\n\t\t\t     T    O    O  K   K    E       N    N N  ";
                cout<<"\n\t\t\t     T      O     K    K   E E E   N      N  ";
                cout<<"\n";
                cout<<"\n";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Extra Taken";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To Add New Data";
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
                        cout<<"\n\n THANK YOU !! Have a Nice Day..\n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listExtra();
                        break;
                    case 2:
                        addExtra();
                        break;
                    default:
                        cout<<"\n Sorry! I don't understand that! \n";
                        break;
                }

            }
        }

};
