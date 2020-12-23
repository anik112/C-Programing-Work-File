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
    for(int i=0; i<80; i++)
    {
        cout<<(char)220;
    }
    gotoxy(10,2);
    for(int i=0; i<80; i++)
    {
        cout<<(char)219;
    }
}

void rightSide()
{
    for(int i=2; i<27; i++)
    {
        gotoxy(10,i);
        cout<<(char)219;
    }
}

void leftSide()
{
    for(int i=2; i<27; i++)
    {
        gotoxy(89,i);
        cout<<(char)219;
    }
}
void footerPart()
{
    gotoxy(10,27);
    for(int i=0; i<80; i++)
    {
        cout<<(char)219;
    }
    gotoxy(10,28);
    for(int i=0; i<80; i++)
    {
        cout<<(char)196;
    }
}
//============ Class List ===================

class BookInfo
{
    int bookId;
    string bookName;
    string bookCategory;
    string bookAuthorName;
    string bookSSNO;
    int bookRackNumber;
};


class Category
{
public:
    int categoryId;
    string categoryName;
};

class Author
{
public:
    int authorId;
    string authorName;
};

class IssueBook
{
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


void addAuthor()
{

    Author author;
    ofstream file ("author-info.txt",ofstream::app);

    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Author Information "<<(char)219;
    gotoxy(12,7);
    cout<<"ID: ";
    gotoxy(12,8);
    cout<<"Author Name: ";
    rightSide();
    footerPart();

    gotoxy(30,7);
    cin>>author.authorId;
    gotoxy(30,8);
    cin>>author.authorName;

    file<<author.authorId<<":"<<author.authorName<<"#";
    file.close();
}


int viewCategory(){
    Category category;
    ofstream file ("category-info.txt",ofstream::app);

    headerPart();
    gotoxy(12,5);
    cout<<(char)219<<" Add Category Information "<<(char)219;

}
int addCategory()
{
    int check=-1;
strt:
    Category category;
    ofstream file ("category-info.txt",ofstream::app);

    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Category Information "<<(char)219;
    gotoxy(12,7);
    cout<<"ID: ";
    gotoxy(12,8);
    cout<<"Category Name: ";
    gotoxy(20,25);
    cout<<": Press [0] For Cancel,[1] For Add Another,[2] For View :";
    rightSide();
    footerPart();

    gotoxy(30,7);
    cin>>category.categoryId;
    gotoxy(30,8);
    cin>>category.categoryName;
    if(category.categoryId>0)
    {
        file <<category.categoryId<<":"<<category.categoryName<<"\n";
        gotoxy(30,10);
        cout<<"Data Save !!";
    }
    gotoxy(50,24);
    cin>>check;
    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
        system("cls");
        goto strt;
        break;
    case 2:

    }
    file.close();
}


void mainWindow()
{

    int checker=-1;

    headerPart();
    leftSide();
    gotoxy(35,5);
    // Header Text
    cout<<(char)16<<(char)219<<" Library Management System "<<(char)219<<(char)17;

    // draw menu list
    gotoxy(30,8);
    cout<<"1> Add Category";
    gotoxy(30,9);
    cout<<"2> Add Author";
    gotoxy(30,10);
    cout<<"3> Add Book";
    gotoxy(30,11);
    cout<<"4> Search Book";
    gotoxy(30,12);
    cout<<"5> View All Book";
    gotoxy(30,13);
    cout<<"6> Delete Book";
    gotoxy(30,14);
    cout<<"7> Issue Book";
    gotoxy(30,15);
    cout<<"8> Return Issue Book";
    gotoxy(30, 18);
    cout<<"0> Exit The System";
    gotoxy(45,25);
    cout<<(char)219<<(char)16;
    gotoxy(55,25);
    cout<<(char)17<<(char)219;
    rightSide();
    footerPart();


    gotoxy(50,25);
    cin>>checker;

    switch(checker)
    {
    case 1:
        system("cls");
        addCategory();
        break;
    case 2:
        system("cls");
        addAuthor();
        break;
    }

}



int main()
{
    mainWindow();
    return 0;
}
