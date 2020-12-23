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


//============= for draw outline ========================
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
//============ Class List ===================

class BookInfo{
    int bookId;
    string bookName;
    string bookCategory;
    string bookAuthorName;
    string bookSSNO;
    int bookRackNumber;
};


class Category{
public:
    int categoryId;
    string categoryName;
};

class Author{
public:
    int authorId;
    string authorName;
};

class IssueBook{
public:
    int tagNumber;
    string stdId;
    string stdName;
    BookInfo book;
};

//==================================



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


void addAuthor(){

    Author author;
    ofstream file ("author-info.txt",ofstream::app);

    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Author Information "<<(char)219;
    gotoxy(12,7); cout<<"ID: ";
    gotoxy(12,8); cout<<"Author Name: ";
    rightSide();
    footerPart();

    gotoxy(30,7); cin>>author.authorId;
    gotoxy(30,8); cin>>author.authorName;

    file<<author.authorId<<":"<<author.authorName<<"#";
    file.close();
}

void addCategory(){

    Category category;
    ofstream file ("category-info.txt",ofstream::app);

    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Category Information "<<(char)219;
    gotoxy(12,7); cout<<"ID: ";
    gotoxy(12,8); cout<<"Category Name: ";
    rightSide();
    footerPart();

    gotoxy(30,7); cin>>category.categoryId;
    gotoxy(30,8); cin>>category.categoryName;

    file <<category.categoryId<<":"<<category.categoryName<<"#";
    file.close();
}



int main(){

    addAuthor();
    return 0;
}
