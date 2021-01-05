#include<iostream>
#include<string>

using namespace std;

int main(){
    string userTxt;
    char txt[userTxt.length()];
    // for remove
    /*getline(cin,userTxt);
    string tmpStr=userTxt.substr(0,userTxt.find("//"));
    cout<<"Without Comment Line: "<<tmpStr;*/

    // int i=12; for(i<1); float r=0.2; if(i==r) true else{"hello"}
    string keywords[]={"for(","while(","if(","int ","float ","else"};
    string operators[]={"+", "-", "*", "=","==","<",">" "/"};
    string separators[]={",",";"};
    int arrSize=sizeof(keywords)/sizeof(keywords[0]);
    int arrSizeOp=sizeof(operators)/sizeof(operators[0]);
    int arrSizeSep=sizeof(separators)/sizeof(separators[0]);

    strcpy(txt,userTxt.c_str());

    getline(cin,userTxt);
    for(int i=0;i<arrSize;i++){
        int findSize=userTxt.find(keywords[i]);
        if(findSize!=(4294967295)){
            cout<<"' "<<keywords[i]<<" ' is a Keyword. Point: "<<findSize<<endl;
        }
    }

    for(int i=0; i<arrSizeOp; i++){
        int findSize=userTxt.find(operators[i]);
        if(findSize!=(4294967295)){
            cout<<"' "<<operators[i]<<" ' is a Operator. Point: "<<findSize<<endl;
        }
    }

    for(int i=0; i<arrSizeSep; i++){
        int findSize=userTxt.find(separators[i]);
        if(findSize!=(4294967295)){
            cout<<"' "<<separators[i]<<" ' is a Separator. Point: "<<findSize<<endl;
        }
    }


    return 0;
}
