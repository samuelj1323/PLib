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
    Parray = new int[capacity];
    Barray = new int[capacity];
    }

Plib::~Plib(){
    Pcapacity = 0;
    Bcapacity = 0;
    Pindex = 0;
    Bindex = 0;
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
    cout<<" Enter: [Q] to Quit"<<endl;
}
// keep working on this, it will be a \n delineation
void Plib::uploadBible(){
    ifstream myfile("FormattedBible.txt");
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
                if(i >= 2 && i < 1551){
                    cout<<"Genesis"<<endl;
                }else if(i >= 1551 && i < 2825){
                    cout<<"Exodus"<<endl; //1552
                }else if(i >= 2825 && i < 3784){
                    cout<<"Leviticus"<<endl; // 2826
                }else if( i >= 3784 && i < 4670){
                    cout<<"Numbers"<<endl;
                }else if( i >= 4670 && i < 5215){
                    cout<<"Deuteronomy"<<endl;
                }else if(i >= 5215 && i < 5433){
                    cout<<"Joshua"<<endl;
                }else if(i >= 5433 && i < 5743){
                    cout<<"Judges"<<endl;//5434
                }else if( i >= 5743 && i < 5786){
                    cout<<"Ruth"<<endl; //5744
                }else if(i >= 5786 && i < 6191){
                    cout<<"1 Samuel"<<endl;
                }else if( i >= 6191 && i < 6665){
                    cout<<"2 Samuel"<<endl; //6192
                }else if(i >= 6665 && i < 6912){
                    cout<<"1 Kings"<<endl;//6666
                }else if(i >= 6912 && i < 7210){
                    cout<<"2 Kings"<<endl;
                }else if(i >= 7210 && i < 8136){
                    cout<<"1 Chronicles"<<endl;
                }else if(i >= 8136 && i < 8406){
                    cout<<"2 Chronicles"<<endl;
                }else if(i >= 8406 && i < 8585){
                    cout<<"Ezra"<<endl;
                }else if(i >= 8585 && i < 8818){
                    cout<<"Nehemiah"<<endl;
                }else if(i >=8818 && i < 8910){
                    cout<<"Esther"<<endl;
                }else if(i >= 8910 && i < 11394){
                    cout<<"Job"<<endl;
                }else if(i >= 11394 & i < 17344){
                    cout<<"Psalms"<<endl;
                }else if(i >= 17344 && i < 19307){
                    cout<<"Proverbs"<<endl;
                }else if(i >= 19307 && i < 19961){
                    cout<<"Ecclesiastes"<<endl;
                }else if(i >= 19961 && i < 20454){
                    cout<<"Song of Solomon"<<endl;
                }else if(i >= 20454 && i < 24808){
                    cout<<"Isaiah"<<endl;
                }else if(i >= 24808 && i < 27767){
                    cout<<"Jeremiah"<<endl;
                }else if(i >= 27767 && i < 28404){
                    cout<<"Lamentations"<<endl;
                }else if(i >= 28404 && i < 29237){
                    cout<<"Ezekiel"<<endl;
                }else if(i >= 29237 && i < 29513){
                    cout<<"Daniel"<<endl;
                }else if(i >= 29513 && i < 30244){
                    cout<<"Hosea"<<endl;
                }else if(i >= 30244 && i < 30527){
                    cout<<"Joel"<<endl;
                }else if(i >= 30527 && i < 31019){
                    cout<<"Amos"<<endl;
                }else if(i >= 31019 && i < 31101){
                    cout<<"Obadiah"<<endl;
                }else if(i >= 31101 && i < 31142){
                    cout<<"Jonah"<<endl;
                }else if(i >= 31142 && i < 31559){
                    cout<<"Micah"<<endl;
                }else if(i >= 31559 && i < 31769){
                    cout<<"Nahum"<<endl;
                }else if(i >= 31769 && i < 31969){
                    cout<<"Habakkuk"<<endl;
                }else if(i >= 31969 && i < 32172){
                    cout<<"Zephaniah"<<endl;
                }else if(i >= 32172 && i < 32192){
                    cout<<"Haggai"<<endl;
                }else if(i >= 32192 && i < 32313){
                    cout<<"Zechariah"<<endl;
                }else if(i >= 32313 && i < 32356){
                    cout<<"Malachi"<<endl;
                }else if(i >= 32356 && i < 32945){
                    cout<<"Matthew"<<endl;
                }else if(i >= 32945 && i < 33271){
                    cout<<"Mark"<<endl;
                }else if(i >= 33271 && i < 33917){
                    cout<<"Luke"<<endl;
                }else if(i >= 33917 && i < 34390){
                    cout<<"John"<<endl;
                }else if(i >= 34390 && i < 34850){
                    cout<<"Acts"<<endl;
                }else if(i >= 34820 && i < 35057){
                    cout<<"Romans"<<endl;
                }else if(i >= 35057 && i < 35251){
                    cout<<"1 Corinthians"<<endl;
                }else if(i >= 35251 && i < 35336){
                    cout<<"2 Corinthians"<<endl;
                }else if(i >= 35336 && i < 35431){
                    cout<<"Galatians"<<endl;
                }else if(i >= 35431 && i < 35499){
                    cout<<"Ephesians"<<endl;
                }else if(i >= 35499 && i < 35572){
                    cout<<"Philippians"<<endl;
                }else if(i >= 35572 && i < 35633){
                    cout<<"Colossians"<<endl;
                }else if(i >= 35633 && i < 35678){
                    cout<<"1 Thessalonians"<<endl;
                }else if(i >= 35678 && i < 35710){
                    cout<<"2 Thessalonians"<<endl;
                }else if(i >= 35710 && i < 35774){
                    cout<<"1 Timothy"<<endl;
                }else if(i >= 35774 && i < 35817){
                    cout<<"2 Timothy"<<endl;
                }else if(i >= 35817 && i < 35841){
                    cout<<"Titus"<<endl;
                }else if(i >= 35841 && i < 35857){
                    cout<<"Philemon"<<endl;
                }else if(i >= 35857 && i < 35987){
                    cout<<"Hebrews"<<endl;
                }else if(i >= 35987 && i < 36038){
                    cout<<"James"<<endl;
                }else if(i >= 36038 && i < 36108){
                    cout<<"1 Peter"<<endl;
                }else if(i >= 36108 && i < 36140){
                    cout<<"2 Peter"<<endl;
                }else if(i >= 36140 && i < 36210){
                    cout<<"1 John"<<endl;
                }else if(i >= 36210 && i < 36227){
                    cout<<"2 John"<<endl;
                }else if(i >= 36227 && i < 36246){
                    cout<<"3 John"<<endl;
                }else if(i >= 36246 && i < 36268){
                    cout<<"Jude"<<endl;
                }else if(i >= 36268){
                    cout<<"Revelation"<<endl;
                }
                cout<<iterator+1<<": "<<bibleArray[i]<<endl<<endl;
                iterator +=1;
            }
            if(iterator == x){
                i = Bindex-1;
            }
    }
    cout<<endl;
}

