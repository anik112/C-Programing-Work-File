#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstdio>


using namespace std;


//============= for draw outline ========================
void gotoxy(int x,int y)
{
    /*
    Console width: 120;
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
    int bookQty;
    int active;
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
    int bookId;
    int issueQTY;
    BookInfo book;
};

//==================================



bool login()
{
    int pass;
    headerPart();
    leftSide();

    gotoxy(32,6);
    cout<<"+++++++++++++++++++++++++++++++";
    gotoxy(32,7);
    cout<<"@@ Library Management System @@";
    gotoxy(32,8);
    cout<<"+++++++++++++++++++++++++++++++";

    gotoxy(32,15);
    cout<<"########## Login ##########";
    gotoxy(32,17);
    cout<<"Password: ";
    gotoxy(32,19);
    cout<<"###########################";
    rightSide();
    footerPart();

    gotoxy(45,17);
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
        cout<<"Author ID   :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Author Name :"<<token<<"\n";
        cout<<"-------------\n\n";
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

/// add author
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
    gotoxy(40,20);
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

/// view category function
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
        cout<<"Category ID   :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Category Name :"<<token<<"\n";
        cout<<"---------------\n\n";
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


/// add new category function
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
    gotoxy(40,20);
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


/// view category function
int viewBook()
{
lblStrt:
    int checker=-1;
    //=================
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
        int id=atoi(token);
        token = strtok(NULL, ":");
        string name=token;
        token = strtok(NULL, ":");
        string categry=token;
        token = strtok(NULL, ":");
        string authName=token;
        token = strtok(NULL, ":");
        string ssn=token;
        token = strtok(NULL, ":");
        string rakNo=token;
        token = strtok(NULL, ":");
        int bookQty=atoi(token);
        token = strtok(NULL, ":");
        int active=atoi(token);

        if(active==0)
        {
            cout<<"Book ID       :"<<id<<"\n";
            cout<<"Book Name     :"<<name<<"\n";
            cout<<"Book Category :"<<categry<<"\n";
            cout<<"Author Name   :"<<authName<<"\n";
            cout<<"SSN NO        :"<<ssn<<"\n";
            cout<<"RACK NO       :"<<rakNo<<"\n";
            cout<<"Book QTY      :"<<bookQty<<"\n";
            cout<<"---------------\n\n";
        }
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

/// Add Book information
int addBook()
{
    int check=-1;
    string massage="";

strt:
    // get all book from file
    BookInfo bookInfo[100];
    Category category[100];
    Author author[100];
    ifstream MyReadFile("book-info.txt");
    ifstream readCategory ("category-info.txt");
    ifstream readAuthor ("author-info.txt");
    string readLineCategory="";
    string readLineAuthor="";
    string lineText="";
    int i=0;

    // get book Information
    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        bookInfo[i].bookId=atoi(token);
        token = strtok(NULL, ":");
        bookInfo[i].bookName=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookCategory=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookAuthorName=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookSSNO=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookRackNumber=token;
        token = strtok(NULL, ":");
        bookInfo[i].bookQty=atoi(token);
        i++;
    }
    // get Category information
    int j=0;
    while(getline(readCategory, readLineCategory))
    {
        char *str=strdup(readLineCategory.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        category[j].categoryId=atoi(token);
        token = strtok(NULL, ":");
        category[j].categoryName=token;
        j++;
    }
    // get Author Information
    int k=0;
    while(getline(readAuthor, readLineAuthor))
    {
        char *str=strdup(readLineAuthor.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        author[k].authorId=atoi(token);
        token = strtok(NULL, ":");
        author[k].authorName=token;
        k++;
    }
    //========================

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
    // Show author and category list
    gotoxy(95,2);
    cout<<"<<Category List>>";
    for(int i=0; i<j; i++)
    {
        gotoxy(96,i+3);
        cout<<category[i].categoryName<<"\n";
    }
    gotoxy(95,j+4);
    cout<<"<<Author List>>";
    for(int i=0; i<k; i++)
    {
        gotoxy(96,i+(j+5));
        cout<<author[i].authorName<<"\n";
    }
    // =================
    gotoxy(12,10);
    cout<<"Book Author: ";
    gotoxy(12,11);
    cout<<"Book SSNO: ";
    gotoxy(12,12);
    cout<<"Book RACK NO: ";
    gotoxy(12,13);
    cout<<"Book QTY: ";
    gotoxy(40,20);
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
        book.bookId=1;
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
        gotoxy(30,13);
        cin>>book.bookQty;

        file <<book.bookId<<":"<<book.bookName<<":"<<book.bookCategory<<":"<<book.bookAuthorName<<":"
             <<book.bookSSNO<<":"<<book.bookRackNumber<<":"<<book.bookQty<<":"<<"0"<<"\n";
        massage="Data Save !!";

        system("cls");
        file.close();
        goto strt;
        break;
    case 2:
        system("cls");
        viewBook();
        system("cls");
        goto strt;
        break;
    }
}

/// Search Book information
int searchBook()
{
lblStrt:
    int checker=-1;
    //=================
    ifstream MyReadFile("book-info.txt");
    string lineText="";
    BookInfo bookInfo;
    int getKey=0;

    cout<<":: Search Book Information :: \n\n";
    cout<<"Search [1]byID,[2]byName,[3]bySSNNO,[4]byRACKNO,[0] BACK: ";
    cin>>getKey;

    int id=0;
    string name="";
    string ssnNo="";
    string rackNo="";

    switch(getKey)
    {
    case 1:
        cout<<"\nBook ID: ";
        cin>>id;
        break;
    case 2:
        cout<<"\nBook Name: ";
        cin>>name;
        break;
    case 3:
        cout<<"\nBook SSNNO: ";
        cin>>ssnNo;
        break;
    case 4:
        cout<<"\nBook RACKNO: ";
        cin>>rackNo;
        break;
    case 0:
        return 0;
    }

    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");
        // Keep printing tokens while one of the
        // delimiters present in str[].
        bookInfo.bookId=atoi(token);
        token = strtok(NULL, ":");
        bookInfo.bookName=token;
        token = strtok(NULL, ":");
        bookInfo.bookCategory=token;
        token = strtok(NULL, ":");
        bookInfo.bookAuthorName=token;
        token = strtok(NULL, ":");
        bookInfo.bookSSNO=token;
        token = strtok(NULL, ":");
        bookInfo.bookRackNumber=token;
        token = strtok(NULL, ":");
        bookInfo.bookQty=atoi(token);
        token = strtok(NULL, ":");
        int active=atoi(token);

        if((bookInfo.bookId==id) || (bookInfo.bookName==name)
                || (bookInfo.bookSSNO==ssnNo) || (bookInfo.bookRackNumber==rackNo) && (active==0))
        {
            cout<<"\n\nBook ID       :"<<bookInfo.bookId<<"\n";
            cout<<"Book Name     :"<<bookInfo.bookName<<"\n";
            cout<<"Book Category :"<<bookInfo.bookCategory<<"\n";
            cout<<"Author Name   :"<<bookInfo.bookAuthorName<<"\n";
            cout<<"SSN NO        :"<<bookInfo.bookSSNO<<"\n";
            cout<<"RACK NO       :"<<bookInfo.bookRackNumber<<"\n";
            cout<<"Book QTY      :"<<bookInfo.bookQty<<"\n";

            break;
        }
    }

    cout<<"\n[1]Search Again,[0]Exit: ";
    cin>>checker;
    if((checker)==0)
    {
        system("cls");
        return 0;
    }
    else
    {
        system("cls");
        goto lblStrt;
    }

}

/// Delete Book
int deleteBook()
{
    int check=-1;
    string massage="";
strt:
    // view design
    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Delete Book Information "<<(char)219;
    gotoxy(12,7);
    cout<<"Book ID: ";
    gotoxy(40,20);
    cout<<massage;

    gotoxy(95,2);
    cout<<"<<Book List>>";
    string read="";
    int i=1;
    ifstream tmpReadBookLink ("book-info.txt");
    while(getline(tmpReadBookLink, read))
    {
        char *str=strdup(read.c_str());
        // Returns first token
        char *token = strtok(str, ":");
        // Keep printing tokens while one of the
        // delimiters present in str[].
        int id=atoi(token);
        token = strtok(NULL, ":");
        string name=token;
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        int active=atoi(token);
        if(active==0)
        {
            gotoxy(95,i+2);
            cout<<" "<<id<<" - "<<name;
            i++;
        }
    }
    tmpReadBookLink.close();
    gotoxy(30,25);
    cout<<": Press [0] For Cancel,[1] For Delete Another :";
    rightSide();
    footerPart();

    // call file
    ifstream readBookLink ("book-info.txt");
    ofstream bookLink ("book-info2.txt",ofstream::app);
    // take input from console
    gotoxy(50,24);
    cin>>check;

    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
    {
        int userGivenId=0;
        gotoxy(30,7);
        cin>>userGivenId;

        string lineText="";
        while(getline(readBookLink, lineText))
        {
            char *str=strdup(lineText.c_str());
            // Returns first token
            char *token = strtok(str, ":");
            // Keep printing tokens while one of the
            // delimiters present in str[].
            BookInfo bookInfo;
            bookInfo.bookId=atoi(token);
            if(bookInfo.bookId==userGivenId)
            {
                token = strtok(NULL, ":");
                bookInfo.bookName=token;
                token = strtok(NULL, ":");
                bookInfo.bookCategory=token;
                token = strtok(NULL, ":");
                bookInfo.bookAuthorName=token;
                token = strtok(NULL, ":");
                bookInfo.bookSSNO=token;
                token = strtok(NULL, ":");
                bookInfo.bookRackNumber=token;
                token = strtok(NULL, ":");
                bookInfo.bookQty=atoi(token);
                token = strtok(NULL, ":");
                int active=1;

                bookLink<<bookInfo.bookId<<":"<<bookInfo.bookName<<":"<<bookInfo.bookCategory<<":"<<bookInfo.bookAuthorName<<":"<<bookInfo.bookSSNO<<":"
                        <<bookInfo.bookRackNumber<<":"<<bookInfo.bookQty<<":"<<active<<"\n";

                massage="Data Delete !!";
                continue;
            }
            else
            {
                massage="Data Not Found !!";
            }

            bookLink<<lineText<<"\n";
        }
        readBookLink.close();
        bookLink.close();
        remove("book-info.txt");
        rename("book-info2.txt","book-info.txt");
        remove("book-info2.txt");
        system("cls");
        goto strt;

    }
    break;
    }
}

/// View Book issue
int viewBookIssue()
{
lblStrt:
    int checker=-1;
    //=================
    ifstream MyReadFile("issue-book.txt");
    string lineText="";

    cout<<":: View All Book Issue Information :: \n\n";

    while(getline(MyReadFile, lineText))
    {
        char *str=strdup(lineText.c_str());
        // Returns first token
        char *token = strtok(str, ":");

        // Keep printing tokens while one of the
        // delimiters present in str[].
        cout<<"Tag No        :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Student ID    :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Student Name  :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Book ID       :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Issue QTY     :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Book Name     :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Book Category :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"Author Name   :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"SSN NO        :"<<token<<"\n";
        token = strtok(NULL, ":");
        cout<<"RACK NO       :"<<token<<"\n";

        cout<<"---------------\n\n";
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
    return 0;
}

/// Issue book
int issueBook()
{

    /* int tagNumber;
        string stdId;
        string stdName;
        int bookId;
        int issueQTY;
        BookInfo book; */

    int check=-1,i=1;
    string massage="";
strt:
    // view design
    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Issue Book Information "<<(char)219;
    gotoxy(12,7);
    cout<<"Tag NO: ";
    gotoxy(12,8);
    cout<<"Student ID: ";
    gotoxy(12,9);
    cout<<"Student Name: ";
    gotoxy(12,10);
    cout<<"Book ID: ";
    gotoxy(12,11);
    cout<<"Issue QTY: ";
    gotoxy(40,20);
    cout<<massage;
    gotoxy(20,25);
    cout<<": Press [0] For Cancel,[1] For Add Another,[2] For View :";
    rightSide();
    footerPart();

    gotoxy(95,2);
    cout<<"<<Book List>>";
    string read="";
    ifstream tempReadBookLink ("book-info.txt");
    while(getline(tempReadBookLink, read))
    {
        char *str=strdup(read.c_str());
        // Returns first token
        char *token = strtok(str, ":");
        // Keep printing tokens while one of the
        // delimiters present in str[].
        int id=atoi(token);
        token = strtok(NULL, ":");
        string name=token;
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        token = strtok(NULL, ":");
        int active=atoi(token);
        if(active==0)
        {
            gotoxy(95,i+2);
            cout<<" "<<id<<" - "<<name;
            i++;
        }
    }
    tempReadBookLink.close();
    // END DESIGN VIEW

    // take input from console
    gotoxy(50,24);
    cin>>check;

    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
    {
        IssueBook issueBooks;
        ofstream issueBookLink ("issue-book.txt",ofstream::app);
        BookInfo bookInfo;
        ifstream readBookLink ("book-info.txt");
        ofstream bookLink ("book-info2.txt",ofstream::app);

        ifstream readIssueBookLink ("issue-book.txt");
        int tagNumber=0;
        string rd="";
        while(getline(readIssueBookLink, rd))
        {
            char *str=strdup(rd.c_str());
            char *token = strtok(str, ":");
            tagNumber=atoi(token);
        }
        readIssueBookLink.close();

        gotoxy(30,7);
        issueBooks.tagNumber=(tagNumber+1);
        cout<<issueBooks.tagNumber;
        gotoxy(30,8);
        cin>>issueBooks.stdId;
        gotoxy(30,9);
        cin>>issueBooks.stdName;
        gotoxy(30,10);
        cin>>issueBooks.bookId;
        gotoxy(30,11);
        cin>>issueBooks.issueQTY;

        string lineText="";
        while(getline(readBookLink, lineText))
        {
            string tmpLine=lineText;
            char *str=strdup(tmpLine.c_str());
            // Returns first token
            char *token = strtok(str, ":");
            // Keep printing tokens while one of the
            // delimiters present in str[].
            bookInfo.bookId=atoi(token);
            issueBooks.book.bookId=atoi(token);
            token = strtok(NULL, ":");
            bookInfo.bookName=token;
            issueBooks.book.bookName=token;
            token = strtok(NULL, ":");
            bookInfo.bookCategory=token;
            issueBooks.book.bookCategory=token;
            token = strtok(NULL, ":");
            bookInfo.bookAuthorName=token;
            issueBooks.book.bookAuthorName=token;
            token = strtok(NULL, ":");
            bookInfo.bookSSNO=token;
            issueBooks.book.bookSSNO=token;
            token = strtok(NULL, ":");
            bookInfo.bookRackNumber=token;
            issueBooks.book.bookRackNumber=token;
            token = strtok(NULL, ":");
            bookInfo.bookQty=atoi(token);
            token = strtok(NULL, ":");
            bookInfo.active=atoi(token);

            if((bookInfo.bookId==issueBooks.bookId) && (bookInfo.bookId>0) && (bookInfo.active==0))
            {
                bookLink<<bookInfo.bookId<<":"<<bookInfo.bookName<<":"<<bookInfo.bookCategory<<":"<<bookInfo.bookAuthorName<<":"<<bookInfo.bookSSNO<<":"
                        <<bookInfo.bookRackNumber<<":"<<(bookInfo.bookQty-issueBooks.issueQTY)<<":"<<bookInfo.active<<"\n";

                issueBookLink <<issueBooks.tagNumber<<":"<<issueBooks.stdId<<":"<<issueBooks.stdName<<":"<<issueBooks.book.bookId<<":"<<issueBooks.issueQTY<<":"<<issueBooks.book.bookName<<":"
                              <<issueBooks.book.bookCategory<<":"<<issueBooks.book.bookAuthorName<<":"<<issueBooks.book.bookSSNO<<":"<<issueBooks.book.bookRackNumber<<"\n";
                massage="Book Issue !!";
                continue;
            }
            else
            {
                gotoxy(40,20);
                cout<<"Book is not Available !!";
            }
            bookLink <<lineText<<"\n";
        }

        readBookLink.close();
        issueBookLink.close();
        bookLink.close();

        remove("book-info.txt");
        rename("book-info2.txt","book-info.txt");
        remove("book-info2.txt");
        massage="Data Save !!";
        system("cls");
        goto strt;
    }
    break;
    case 2:
        system("cls");
        viewBookIssue();
        system("cls");
        goto strt;
        break;
    }
}



/// Return Issue book
int returnBook()
{

    /* int tagNumber;
        string stdId;
        string stdName;
        int bookId;
        int issueQTY;
        BookInfo book; */

    int check=-1,i=0;
    string massage="";
strt:
    // view design
    headerPart();
    leftSide();
    gotoxy(12,5);
    cout<<(char)219<<" Issue Book Information "<<(char)219;
    gotoxy(12,7);
    cout<<"Tag NO: ";
    gotoxy(12,8);
    cout<<"Student ID: ";
    gotoxy(12,9);
    cout<<"Book ID: ";
    gotoxy(40,20);
    cout<<massage;
    gotoxy(20,25);
    cout<<": Press [0] For Cancel,[1] For Add Another,[2] For View :";
    rightSide();
    footerPart();
    // END VIEW DESIGN

    // take input from console
    gotoxy(50,24);
    cin>>check;

    switch(check)
    {
    case 0:
        return 0;
        break;
    case 1:
    {
        IssueBook issueBooks;
        BookInfo bookInfo;
        ifstream readIssueBookLink ("issue-book.txt");
        ofstream issueBookLink ("issue-book2.txt",ofstream::app);
        ifstream readBookLink ("book-info.txt");
        ofstream bookLink ("book-info2.txt",ofstream::app);
        int tagNo=0;
        string stdId="";
        int bookId=0;
        int returnQty=0;

        gotoxy(30,7);
        cin>>tagNo;
        gotoxy(30,8);
        cin>>stdId;
        gotoxy(30,9);
        cin>>bookId;

        string lineText="";
        while(getline(readIssueBookLink, lineText))
        {
            string tmpLine=lineText;
            char *str=strdup(tmpLine.c_str());
            // Returns first token
            char *token = strtok(str, ":");
            // Keep printing tokens while one of the
            // delimiters present in str[].
            int tmpTage=atoi(token);
            token = strtok(NULL, ":");
            string tmpStdId=token;
            token = strtok(NULL, ":");
            token = strtok(NULL, ":");
            int tmpBookId=atoi(token);
            token = strtok(NULL, ":");
            returnQty=atoi(token);

            if((tagNo==tmpTage) && (stdId==tmpStdId) && (bookId==tmpBookId))
            {

                string lineText="";
                while(getline(readBookLink, lineText))
                {
                    string tmpLine=lineText;
                    char *str=strdup(tmpLine.c_str());
                    // Returns first token
                    char *token = strtok(str, ":");
                    // Keep printing tokens while one of the
                    // delimiters present in str[].
                    bookInfo.bookId=atoi(token);
                    token = strtok(NULL, ":");

                    if(bookInfo.bookId==bookId)
                    {
                        bookInfo.bookName=token;
                        token = strtok(NULL, ":");
                        bookInfo.bookCategory=token;
                        token = strtok(NULL, ":");
                        bookInfo.bookAuthorName=token;
                        token = strtok(NULL, ":");
                        bookInfo.bookSSNO=token;
                        token = strtok(NULL, ":");
                        bookInfo.bookRackNumber=token;
                        token = strtok(NULL, ":");
                        bookInfo.bookQty=atoi(token);
                        token = strtok(NULL, ":");
                        bookInfo.active=atoi(token);

                        bookLink<<bookInfo.bookId<<":"<<bookInfo.bookName<<":"<<bookInfo.bookCategory<<":"<<bookInfo.bookAuthorName<<":"<<bookInfo.bookSSNO<<":"
                                <<bookInfo.bookRackNumber<<":"<<(bookInfo.bookQty+returnQty)<<":"<<bookInfo.active<<"\n";
                        returnQty=0;
                        continue;
                    }
                    bookLink <<lineText<<"\n";
                }
                readBookLink.close();
                bookLink.close();
                remove("book-info.txt");
                rename("book-info2.txt","book-info.txt");
                remove("book-info2.txt");
                continue;
            }
            issueBookLink<<lineText<<"\n";
        }

        readIssueBookLink.close();
        issueBookLink.close();

        remove("issue-book.txt");
        rename("issue-book2.txt","issue-book.txt");
        remove("issue-book2.txt");
        massage="Data Update !!";
        system("cls");
        goto strt;
    }
    break;
    case 2:
        system("cls");
        viewBookIssue();
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
    cout<<"5> Delete Book";
    gotoxy(30,13);
    cout<<"6> Issue Book";
    gotoxy(30,14);
    cout<<"7> Return Issue Book";
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
        break;
    case 4:
        system("cls");
        searchBook();
        system("cls");
        goto lblViewStart;
        break;
    case 5:
        system("cls");
        deleteBook();
        system("cls");
        goto lblViewStart;
        break;
    case 6:
        system("cls");
        issueBook();
        system("cls");
        goto lblViewStart;
        break;
    case 7:
        system("cls");
        returnBook();
        system("cls");
        goto lblViewStart;
    case 0:
        system("cls");
    }
}



int main()
{
    if(login())
    {
        mainWindow();
    }
    return 0;
}
