#ifndef FUNCTIOS_H_INCLUDED
#define FUNCTIOS_H_INCLUDED

#include<.h>
#include<iostream>

class BookInfo{
    int bookId;
    string bookName;
    string bookCategory;
    string bookAuthorName;
    string bookSSNO;
    int bookRackNumber;
};


class Category{
    int categoryId;
    string categoryName;
};

class Author{
    int authorId;
    string authorName;
};

class IssueBook{
    int tagNumber;
    string stdId;
    string stdName;
    BookInfo book;
};

#endif // FUNCTIOS_H_INCLUDED
