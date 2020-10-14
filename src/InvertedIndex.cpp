
#include "../include/InvertedIndex.h"
#include <boost/tokenizer.hpp>
#include <caca_conio.h>

using namespace std;
using namespace boost;

InvertedIndex::InvertedIndex() {
    cout<<"We create inverted index for documents!\n";
}

void InvertedIndex::getPath() {
    helpVariable=0;
    int number;
    cout<<"Enter file of path:\n";
    cin>>helpString;
    ifstream input(helpString);
    while(getline(input,pathFile)){
        for(auto dastgire:listOfDocument){
            if(dastgire.first==pathFile){
                helpVariable++;
                number=dastgire.second.second;
                break;
            }
        }
        if(helpVariable==0){
            fileName="";
            for(int i=pathFile.length();i>=0;i--){
                if(pathFile[i]!='/'){
                    fileName+=pathFile[i];
                }
                else{
                    break;
                }
            }
            fileName=inverse(fileName);
            number=listOfDocument.size()+1;
            listOfDocument[pathFile].first=fileName;
            listOfDocument[pathFile].second=number;
        }
        invertedIndex(number,pathFile);
    }
}

void InvertedIndex::invertedIndex(int numberOfFile,string path) {
    ifstream input(path);
    if(input.fail()){
        cout<<"Don't exist this file! please correction of file of path:\n";
        cout<<path;
        //listOfDocument.erase(path);
        // getPath();
        exit(0);
    }
    string text;
    while(getline(input,text)) {
        char_separator<char> sep(" ,|;-!?+-=./()*&^%$#@~><`:0123456789");
        tokenizer<char_separator<char>> tokens(text, sep);
        for(auto &t : tokens) {
            helpVariable=0;
            if(inverted_Index.find(t)!=inverted_Index.end()){//hast
                int length= (int) inverted_Index[t].size();
                for(int i=0;i<length;i++){
                    if(inverted_Index[t][i]==numberOfFile){
                        helpVariable++;
                        break;
                    }
                }
                if(helpVariable==0){//yani az in file in kalameh bodeh
                    inverted_Index[t].push_back(numberOfFile);
                }
            }
            else{
                inverted_Index[t].push_back(numberOfFile);
            }
        }
    }
}

std::string InvertedIndex::inverse(std::string nameOfFile) {
    string local="";
    for(int i=nameOfFile.length();i>=0;i--){
        local+=(nameOfFile[i]);
    }
    return local;
}

void InvertedIndex::printExerciseOne() {

    for(map<string,vector<int> >::iterator it=inverted_Index.begin();it!=inverted_Index.end();++it){
        cout<<it->first<<" : ";
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<"\n";
    }
}

void InvertedIndex::printExerciseTwo() {
    string incidenceMatrix[inverted_Index.size()+1][listOfDocument.size()+1];
    incidenceMatrix[0][0]="IncidenceMatrix";
    helpVariable=1;
    for(map<string,pair<string,int>>::iterator it=listOfDocument.begin();it!=listOfDocument.end();++it){
        helpString=convertToString(it->second.second);
        incidenceMatrix[0][helpVariable]=((it->second.first)+"/"+helpString);
        helpVariable++;
    }
    helpVariable=1;
    for(map<string,vector<int> >::iterator it=inverted_Index.begin();it!=inverted_Index.end();++it){
        incidenceMatrix[helpVariable][0]=it->first;
        helpVariable++;
    }
    string help2;
    for(int i=1;i<inverted_Index.size()+1;i++){
        for(int j=1;j<listOfDocument.size()+1;j++){
            helpString=incidenceMatrix[0][j];
            help2="";
            for(int k=helpString.length();k>=0;k--){
                if(helpString[k]!='/'){
                    help2+=helpString[k];
                }
                else{
                    break;
                }
            }
            int flag=0;
            helpVariable=convertToInt(help2);//shomare sand ro bedast avordim ta berim to vectoresh begardim
            for(int l=0;l<inverted_Index[incidenceMatrix[i][0]].size();l++){
                if(inverted_Index[incidenceMatrix[i][0]][l]==helpVariable){
                    incidenceMatrix[i][j]="1";
                    flag++;
                }
            }
            if(flag==0){
                incidenceMatrix[i][j]="0";
            }
        }
    }
    for(int i=0;i<inverted_Index.size()+1;i++){
        for(int j=0;j<listOfDocument.size()+1;j++){
            cout<<incidenceMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

std::string InvertedIndex::convertToString(int variable) {
    helpString="";
    while(variable!=0){
        helpString+=(char)((variable%10)+48);
        variable=variable/10;
    }
    helpString=inverse(helpString);
    return helpString;
}

int InvertedIndex::convertToInt(std::string variable) {
    int local=1;
    int result=0;
    for(int i=0;i<variable.length();i++){
        int h=(int)(variable[i]-48);
        result+=(h*local);
        local*=10;
    }
    return result;
}
