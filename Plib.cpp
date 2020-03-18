#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "Plib.h"
using namespace std;
//that's hot
Plib::Plib(){ // default constructor
    capacity = 1;
    index = 0;
    array = new string[capacity];
    searchArray = new string[capacity];
    }

Plib::Plib(int capacity){ //parameter constructor
    this->capacity = capacity;
    index = 0;
    array = new string[capacity];
    searchArray = new string[capacity];
    }

Plib::~Plib(){
    capacity = 0;
    index = 0;
    delete[] searchArray;
    delete[] array;
    delete[] Parray;
    delete[] Barray;
    array = nullptr;
    Parray = nullptr;
    Barray = nullptr;
}

void Plib::makeNull(){
    array = nullptr;
    Parray = nullptr;
    Barray = nullptr;
    searchArray = nullptr;
}

void Plib::resize_bible(){
    capacity *=2;
    string* newArray = new string[capacity];
    for(int i = 0; i < index; i++){
        newArray[i] = searchArray[i];
    }
    delete[] searchArray;
    searchArray = newArray;
}

void Plib::resize(){ // growing the library 
    capacity *= 2;
    string* newArray = new string[capacity]; // make a new array
    for(int i = 0; i < index; i++){ // copies information over
        newArray[i] = array[i];
    }
    delete[] array; // delete old data
    array = newArray; // change data
}

void Plib::pushBack(){ // for adding prayers to the library
    index += 1;
    if(index == capacity){// in case we are at capacity
        resize();
    }
    getline(cin >> ws ,array[index]);
}

void Plib::save(){ // saves array to the document
    ofstream myfile("prayers.txt",ios_base::app);
    if(myfile.is_open()){
        myfile << array[index] << endl;
        myfile.close();
    }
    else{
        cout<<"unable to open file"<<endl;
    }
}

void Plib::uploadPrayerFromDoc(){
ifstream myfile("prayers.txt");
if(myfile.is_open()){
    cout<<"doc is open"<<endl;
    index = 0;
    while(!myfile.eof()){
       // getline(myfile,array[index],' ');
        getline(myfile,array[index],'\n');
        index+=1;
        if(index == capacity){
            resize();
        }
    }
    myfile.close();
    }else{
        cout<<"unable to open file"<<endl;
    }   // upload the prayers from the document
}
void Plib::wordFindPrayer(string keyword){
    Parray = new int[capacity]; // make new array of prayers to put the indexes in
    for(int i = 0; i < index; i++){ // run through all the prayers
        Parray[i] = 0;
        // array at index i will have the line #, but the i will be the word num
        string str = array[i]; // assign the string from the prayer
        size_t found = str.find(keyword); /// find the keyword
        if(found != string::npos){ // find the points /
            //cout<<endl<<"string found in word " << i<<": " <<endl; // index are words
            Parray[i] = 1; // 
            //cout<<"this is the string it matches: "<<array[i]<<endl<<endl;
        }    
    }   
}
void Plib::read_search(){
    for(int i = 0; i < index; i++){
        if(Parray[i] == 1){
            cout<<array[i]<<endl;
        }
    }
    cout<<endl;
}
void Plib::printMenu(){
    cout<<" Enter an input"<<endl;
    cout<<" Enter: P for Prayer"<<endl;
    cout<<" Enter: SP for Search Prayers"<<endl;
    cout<<" Enter: SB for Search Bible"<<endl;
    cout<<" Enter: Q to Quit"<<endl;
}
// keep working on this, it will be a \n delineation
void Plib::uploadBible(){
    ifstream myfile("FormattedBible.txt");
    if(myfile.is_open()){
        while(!myfile.eof()){ // this should get all of the string file.
            if(index == capacity){
                resize_bible();
            }
        getline(myfile, searchArray[index],'\n');
        index +=1;
        }
        cout<<"copied info to array"<<endl;
        myfile.close();
        cout<<"it made it to the array"<<endl;
    }else{
        cout<<"thisfile did not open"<<endl;
    }  // upload the prayers from the document
}
// the Parray will hold an array of occurrences 

void Plib::wordFindBible(string keyword){
    Barray = new int[capacity]; // make new array of prayers to put the indexes in
    for(int i = 0; i < index; i++){ // run through all the prayers
        Barray[i] = 0;
        string str = searchArray[i]; // assign the string from the prayer
        size_t found = str.find(keyword); /// find the keyword
        if(found != string::npos){ // find the points /
            Barray[i] = 1; 
        }    
    } 
}
void Plib::read_bible_search(int x){
    int iterator =0;
        for(int i = 0; i < index; i++){
        if(Barray[i] == 1){
            cout<<iterator+1<<": "<<searchArray[i]<<endl<<endl;
            iterator +=1;
        }
        if(iterator == x){
            i = index-1;
        }
    }
    cout<<endl;
}

