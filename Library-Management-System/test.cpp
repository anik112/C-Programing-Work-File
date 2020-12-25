#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{

    ofstream writeFile ("test2.txt",ofstream::app);

    /*for(int i=0; i<5; i++){
        writeFile<<i<<":asd:asdasd:3000\n";
    }
    writeFile.close();*/

    ifstream readFile("test.txt");
    string line="";
    while(getline(readFile, line))
    {
        char *str=strdup(line.c_str());
        // Returns first token
        cout<<line<<"\n";

        //char *token = strtok(str, ":");
        //token = strtok(NULL, ":");
    }

    /*
    string id,fs;
    cin>>id;
    while(getline(readFile, fs)){
        char *str=strdup(fs.c_str());
        char *token = strtok(str, ":");
        cout<<"\n"<<token;
        token = strtok(NULL, ":");

        if(token=="2"){
            cout<<"\n"<<token;
        token = strtok(NULL, ":");
        cout<<"\n"<<token;
        token = strtok(NULL, ":");
        cout<<"\n"<<token;
        token = strtok(NULL, ":");

        }
        writeFile<<fs;
    }

    readFile.close();
    readFile.close();*/
/*
    std::string firstlevel ("com");
    std::string secondlevel ("cplusplus");
    std::string scheme ("http://");
    std::string hostname;
    std::string url;

    hostname = "www." + secondlevel + '.' + firstlevel;
    url = scheme + hostname;

    std::cout << url << '\n';*/

    rename("book-info2.txt","as.txt");

    return 0;
}
