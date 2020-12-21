#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<ctype.h>

using namespace std;

class StudentDao{
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

void gotoxy(int x,int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void headerPart(){
    gotoxy(5,4);
    cout<<"=============================================================================";
}

void footerPart(){
    gotoxy(5,20);
    cout<<"=============================================================================";
}

bool login(){
    int pass;
    headerPart();
    gotoxy(25,7); cout<<"########## Login ##########";
    gotoxy(25,9); cout<<"Password: "; cin>>pass;
    gotoxy(25,11); cout<<"##########################";
    footerPart();

    if(pass==123){
        system("cls");
        return true;
    }else{
        return false;
    }
}

void addStudent(){
    FILE *sutd;
    sutd=fopen("student_info.txt","a");
    string is="anik paul";
    char buffer[] = { 'x' , 'y' , 'z' };
    fwrite(&buffer,sizeof(buffer),1,sutd);
    fclose(sutd);
}


int main(){
    string semesters[]={"1st","2nd","3rd"};
    string subjects[]={"CSE","EEE","MAT"};

    if(login()){
        addStudent();
    }

    return 0;
}

