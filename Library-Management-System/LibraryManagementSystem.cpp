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
public:
    int bookId;
    string bookName;
    string bookCategory;
    string bookAuthorName;
    string bookSSNO;
    string bookRackNumber;
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

int viewAuthor()
{
lblStrt:
    int checker=-1;
    Category category;
    ifstream MyReadFile("author-info.txt");
    string lineText="";

    cout<<":: View All Author Information :: \n\n";
    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        cout<<"Author ID: "<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Author Name: "<<token<<"\n";
        cout<<"====\n";
    }

    cin>>checker;
    if((checker)==0)
    {
        system("cls");
        return 0;
    }
    else
    {
        goto lblStrt;
    }
}

// add author
int addAuthor()
{
strt:
    int check=-1;
    string massage="";
    Author author;
    ofstream file ("author-info.txt",ofstream::app);

    // view design
    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Author Information "<<(char)219;
    gotoxy(12,7);
    cout<<"ID: ";
    gotoxy(12,8);
    cout<<"Author Name: ";
    gotoxy(30,10);
    cout<<massage;
    gotoxy(20,25);
    cout<<": Press [0] For Cancel,[1] For Add Another,[2] For View :";
    rightSide();
    footerPart();

    // take input from console
    gotoxy(50,24);
    cin>>check;

    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
        gotoxy(30,7);
        cin>>author.authorId;
        gotoxy(30,8);
        cin>>author.authorName;
        if(author.authorId>0)
        {
            file <<author.authorId<<":"<<author.authorName<<"\n";
            massage="Data Save !!";
        }
        system("cls");
        file.close();
        goto strt;
        break;
    case 2:
        system("cls");
        viewAuthor();
        system("cls");
        goto strt;
        break;
    }
}

// view category function
int viewCategory()
{
lblStrt:
    int checker=-1;
    Category category;
    ifstream MyReadFile("category-info.txt");
    string lineText="";

    cout<<":: View All Category Information :: \n\n";
    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        cout<<"Category ID: "<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Category Name: "<<token<<"\n";
        cout<<"====\n";
    }

    cin>>checker;
    if((checker)==0)
    {
        system("cls");
        return 0;
    }
    else
    {
        goto lblStrt;
    }

}
// add new category function
int addCategory()
{
    int check=-1;
    string massage="";
strt:
    Category category;
    ofstream file ("category-info.txt",ofstream::app);

    // view design
    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Category Information "<<(char)219;
    gotoxy(12,7);
    cout<<"ID: ";
    gotoxy(12,8);
    cout<<"Category Name: ";
    gotoxy(30,10);
    cout<<massage;
    gotoxy(20,25);
    cout<<": Press [0] For Cancel,[1] For Add Another,[2] For View :";
    rightSide();
    footerPart();

    // take input from console
    gotoxy(50,24);
    cin>>check;

    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
        gotoxy(30,7);
        cin>>category.categoryId;
        gotoxy(30,8);
        cin>>category.categoryName;
        if(category.categoryId>0)
        {
            file <<category.categoryId<<":"<<category.categoryName<<"\n";
            massage="Data Save !!";
        }
        system("cls");
        file.close();
        goto strt;
        break;
    case 2:
        system("cls");
        viewCategory();
        system("cls");
        goto strt;
        break;
    }
}


// view category function
int viewBook()
{
lblStrt:
    int checker=-1;
    BookInfo bookInfo[100];
    ifstream MyReadFile("book-info.txt");
    string lineText="";

    cout<<":: View All Book Information :: \n\n";

    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        cout<<"Book ID: "<<token;
        token = strtok(NULL, ":");
        cout<<"Book Name: "<<token;
        token = strtok(NULL, ":");
        cout<<"Book ID: "<<token;
        token = strtok(NULL, ":");
        bookInfo[i].bookAuthorName=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookSSNO=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookRackNumber=token;
        i++;
    }

    cin>>checker;
    if((checker)==0)
    {
        system("cls");
        return 0;
    }
    else
    {
        goto lblStrt;
    }

}

int addBook()
{
strt:
    // get all book from file
    BookInfo bookInfo[100];
    ifstream MyReadFile("book-info.txt");
    string lineText="";
    int i=0;

    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        bookInfo[i].bookId=(int)token;
        token = strtok(NULL, ":");
        bookInfo[i].bookName=token;
        bookInfo[i].bookCategory=token;
        bookInfo[i].bookAuthorName=token;
        bookInfo[i].bookSSNO=token;
        bookInfo[i].bookRackNumber=token;
        i++;
    }
    //========================

    int check=-1;
    string massage="";

    BookInfo book;
    ofstream file ("book-info.txt",ofstream::app);

    // view design
    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Add Book Information "<<(char)219;
    gotoxy(12,7);
    cout<<"ID: ";
    gotoxy(12,8);
    cout<<"Book Name: ";
    gotoxy(12,9);
    cout<<"Book Category: ";
    gotoxy(12,10);
    cout<<"Book Author: ";
    gotoxy(12,11);
    cout<<"Book SSNO: ";
    gotoxy(12,12);
    cout<<"Book RACK NO: ";
    gotoxy(30,10);
    cout<<massage;
    gotoxy(20,25);
    cout<<": Press [0] For Cancel,[1] For Add Another,[2] For View :";
    rightSide();
    footerPart();

    // take input from console
    gotoxy(50,24);
    cin>>check;

    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
        book.bookId=bookInfo[i-1].bookId+1;
        gotoxy(30,7);
        cout<<book.bookId;
        gotoxy(30,8);
        cin>>book.bookName;
        gotoxy(30,9);
        cin>>book.bookCategory;
        gotoxy(30,10);
        cin>>book.bookAuthorName;
        gotoxy(30,11);
        cin>>book.bookSSNO;
        gotoxy(30,12);
        cin>>book.bookRackNumber;

        file <<book.bookId<<":"<<book.bookName<<":"<<book.bookCategory<<":"<<book.bookAuthorName<<":"<<book.bookSSNO<<":"<<book.bookRackNumber<<"\n";
        massage="Data Save !!";

        system("cls");
        file.close();
        goto strt;
        break;
    case 2:
        system("cls");
        viewCategory();
        system("cls");
        goto strt;
        break;
    }
}




int mainWindow()
{
lblViewStart:
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
        system("cls");
        goto lblViewStart;

        break;
    case 2:
        system("cls");
        addAuthor();
        system("cls");
        goto lblViewStart;

        break;
    case 3:
        system("cls");
        addBook();
        system("cls");
        goto lblViewStart;
    case 0:
        return 0;
    }

}



int main()
{
    mainWindow();
    return 0;
}
