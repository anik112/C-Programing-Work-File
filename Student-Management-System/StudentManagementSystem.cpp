#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

const string semesters[]= {"1st","2nd","3rd"};
const string subjects[]= {"CSE","EEE","MAT"};
const int lenOfSemesters = sizeof(semesters)/sizeof(semesters[0]);
const int lenOfSubjects=sizeof(subjects)/sizeof(subjects[0]);

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class StudentDao
{
public:
    int stdId;
    string stdName;
    string stdFatherName;
    string stdMotherName;
    string stdMobileNo;
    string stdPhoneNumber;
    string stdEmailAddress;
    string stdPresentAddress;
    string stdPermanentAddress;
    float stdCGPA;
    string stdSubject;
    string stdSemester;
};

void gotoxy(int x,int y)
{
    /*
    Console width: 100;
    Console hight: 30;
    */

    COORD coord;
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void headerPart()
{
    gotoxy(10,1);
    for(int i=0;i<80;i++){
        cout<<(char)220;
    }
    gotoxy(10,2);
    for(int i=0;i<80;i++){
        cout<<(char)219;
    }
}

void rightSide(){
    for(int i=2;i<27;i++){
        gotoxy(10,i);
        cout<<(char)219;
    }
}

void leftSide(){
    for(int i=2;i<27;i++){
        gotoxy(89,i);
        cout<<(char)219;
    }
}

void footerPart()
{
    gotoxy(10,27);
    for(int i=0;i<80;i++){
        cout<<(char)219;
    }
    gotoxy(10,28);
    for(int i=0;i<80;i++){
        cout<<(char)196;
    }
}

bool login()
{
    int pass;
    headerPart();
    leftSide();

    gotoxy(35,9);
    cout<<"########## Login ##########";
    gotoxy(35,11);
    cout<<"Password: ";
    gotoxy(35,13);
    cout<<"###########################";
    rightSide();
    footerPart();

    gotoxy(45,11);
    cin>>pass;
    if(pass==123)
    {
        system("cls");
        return true;
    }
    else
    {
        return false;
    }
}

void addStudent()
{
    headerPart();
    leftSide();

    StudentDao student;
    ofstream file ("student_info.txt",ofstream::app);
    gotoxy(15,5); cout<<(char)219<<" Add New Student "<<(char)219;
    gotoxy(15,7); cout<<"Student ID: ";
    gotoxy(15,8); cout<<"Student Name: ";
    gotoxy(15,9); cout<<"Father Name: ";
    gotoxy(15,10); cout<<"Mother Name: ";
    rightSide();
    footerPart();


    gotoxy(35,7); cin>>student.stdId;
    gotoxy(35,8); cin>>student.stdName;
    gotoxy(35,9); cin>>student.stdFatherName;
    gotoxy(35,10); cin>>student.stdMotherName;

    file <<student.stdId<<"#"<<student.stdName<<":";
    file.close();

}


int main()
{

    if(login()){
        addStudent();
    }

    return 0;
}

