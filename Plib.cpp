#include <iostream>
#include <string>
#include <fstream>
#include "Plib.h"

using namespace std;
//that's hot
Plib::Plib(){ // default constructor
    Pcapacity = 1;
    Bcapacity =1;
    Pindex = 0;
    Bindex = 0;
    prayerArray = new string[Pcapacity];
    bibleArray = new string[Bcapacity];
    kWords = new string[Pcapacity];
    Parray = new int[Pcapacity];
    Barray = new int[Bcapacity];
    }

Plib::Plib(int capacity){ //parameter constructor
    Pcapacity = capacity;
    Bcapacity = capacity;
    Pindex = 0;
    Bindex = 0;
    prayerArray = new string[capacity];
    bibleArray = new string[capacity];
    kWords = new string[Pcapacity];
    Parray = new int[capacity];
    Barray = new int[capacity];
    }

Plib::~Plib(){
    Pcapacity = 0;
    Bcapacity = 0;
    Pindex = 0;
    Bindex = 0;
    delete[] kWords;
    delete[] bibleArray;
    delete[] prayerArray;
    delete[] Parray;
    delete[] Barray;
    prayerArray = nullptr;
    Parray = nullptr;
    Barray = nullptr;
}

void Plib::makeNull(){
    prayerArray = nullptr;
    Parray = nullptr;
    Barray = nullptr;
    bibleArray = nullptr;
    kWords = nullptr;
}

void Plib::resize_bible(){
    Bcapacity *=2;
    string* newArray = new string[Bcapacity];
    int* thisArray = new int[Bcapacity];
    for(int i = 0; i < Bindex; i++){
        newArray[i] = bibleArray[i];
        thisArray[i] = Barray[i];
    }
    delete[] Barray;
    delete[] bibleArray;
    bibleArray = newArray;
    Barray = thisArray;
}

void Plib::resize(){ // growing the library 
    Pcapacity *= 2;
    int* thisArray = new int[Pcapacity];
    string* newArray = new string[Pcapacity]; // make a new array
    for(int i = 0; i < Pindex; i++){ 
        thisArray[i] = Parray[i];// copies information over
        newArray[i] = prayerArray[i];
    }
    delete[] Parray;
    delete[] prayerArray; // delete old data
    prayerArray = newArray; // change data
    Parray = thisArray;
}

void Plib::pushBack(){ // for adding prayers to the library
    Pindex += 1;
    if(Pindex == Pcapacity){// in case we are at capacity
        resize();
    }
    getline(cin >> ws ,prayerArray[Pindex]);
}

void Plib::save(){ // saves array to the document
    ofstream myfile("prayers.txt",ios_base::app);
    if(myfile.is_open()){
        myfile << prayerArray[Pindex] << endl;
        myfile.close();
    }
    else{
        cout<<"unable to open file"<<endl;
    }
}
int Plib::ret_Pcapacity(){
    return Pcapacity;
}
int Plib::ret_Bcapacity(){
    return Bcapacity;
}
int Plib::ret_Pindex(){
    return Pindex;
}
void Plib::uploadPrayerFromDoc(){
ifstream myfile("prayers.txt");
if(myfile.is_open()){
    //cout<<"doc is open"<<endl;
    Pindex = 0;
    while(!myfile.eof()){
        getline(myfile,prayerArray[Pindex],'\n');
        Pindex+=1;
        if(Pindex == Pcapacity){
            resize();
        }
    }
    myfile.close();
    }else{
        cout<<"unable to open file"<<endl;
    }   // upload the prayers from the document
}
void Plib::wordFindPrayer(string keyword){
 // make new array of prayers to put the indexes in
    for(int i = 0; i < Pindex; i++){ // run through all the prayers
        Parray[i] = 0;
        // array at index i will have the line #, but the i will be the word num
        string str = prayerArray[i]; // assign the string from the prayer
        size_t found = str.find(keyword); /// find the keyword
        if(found != string::npos){ // find the points /
            Parray[i] = 1; // 
        }    
    }   
}
void Plib::read_search(){
    int iterator = 0;
    for(int i = 0; i < Pindex; i++){
        if(Parray[i] == 1){
            iterator +=1;
            cout<<iterator<<": "<<prayerArray[i]<<endl;
        }
    }
    cout<<endl;
}
void Plib::printMenu(){
    cout<<" Enter an input"<<endl;
    cout<<" Enter: [P] for Prayer"<<endl;
    cout<<" Enter: [SP] for Search Prayers"<<endl;
    cout<<" Enter: [SB] for Search Bible"<<endl;
    cout<<" Enter: [K] for Key Words from your Prayers to be Searched"<<endl;
    cout<<" Enter: [Q] to Quit"<<endl;
}
// keep working on this, it will be a \n delineation
void Plib::uploadBible(){
    ifstream myfile("kjvBible.txt");
    Bindex = 0;
    if(myfile.is_open()){
        while(!myfile.eof()){
            //cout<<index<<endl; // this should get all of the string file.
            if(Bindex == Bcapacity){
                resize_bible();
            }
        getline(myfile, bibleArray[Bindex],'\n');
        Bindex +=1;
        }
        cout<<"copied info to prayerArray"<<endl;
        myfile.close();
        cout<<"it made it to the prayerArray"<<endl;
    }else{
        cout<<"thisfile did not open"<<endl;
    }  // upload the prayers from the document
}
// the Parray will hold an array of occurrences 

void Plib::wordFindBible(string keyword){
    // make new array of prayers to put the indexes in
    for(int i = 0; i < Bindex; i++){ // run through all the prayers
        Barray[i] = 0;
        string str = bibleArray[i]; // assign the string from the prayer
        size_t found = str.find(keyword); /// find the keyword
        if(found != string::npos){ // find the points /
            Barray[i] = 1; 
        }    
    } 
}
int Plib::ret_Bindex(){
    return Bindex;
}
void Plib::read_bible_search(int x){
    int iterator = 0;
        for(int i = 0; i < Bindex; i++){
            if(Barray[i] == 1){
                cout<<iterator+1<<": "<<bibleArray[i]<<endl<<endl;
                iterator +=1;
            }
            if(iterator == x){
                i = Bindex-1;
            }
    }
    string context;
    cout<<"Do you need more context?"<<endl;
    cout<<"Yes [y] / No [n]: ";
    cin >> context;
    if(context == "y"){
        int iterator = 0;
                for(int i = 0; i < Bindex; i++){
                    if(Barray[i] == 1){
                        cout<<iterator+1<<endl<<": "<<bibleArray[i-1]<<endl;
                        cout<<": "<<bibleArray[i]<<endl;
                        cout<<": "<<bibleArray[i+1]<<endl;
                        iterator +=1;
                    }
                    if(iterator == x){
                        i = Bindex-1;
                    }
            }
    }
    cout<<"aight cool"<<endl;    
    cout<<endl;
}
string removeWord(string str, string word){ 
    if (str.find(word) != string::npos){ 
        size_t p = 0; 
        string tempWord = word + " "; 
        while ((p = str.find(word)) != string::npos) 
            str.replace(p, tempWord.length(), ""); 
        tempWord = " " + word; 
        while ((p = str.find(word)) != string::npos) 
            str.replace(p, tempWord.length(), ""); 
    } 
    // Return the resultant string 
    return str; 
} 
void Plib::keyWords(){ 
    string lastPrayer = prayerArray[Pindex];
    cout<<lastPrayer<<endl;
    string word[19] = {"this","or","and","is","well","The","I","am","ok","a","my","me","was","be","there","their","they're","other","you"};
    for(int i = 0; i <19; i++){
        lastPrayer = removeWord(lastPrayer,word[i]);
        cout<<lastPrayer<<endl;
    }
    
}

