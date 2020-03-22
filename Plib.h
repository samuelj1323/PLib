#ifndef PLIB_H
#define PLIB_H
#include <string>
using namespace std;
// I no longer need the prayer class,
// I can just write out a string array and use dynamic sizing.
// I will have to input the prayers from a file to have dynamic action on the information
// Make a word search function Word_find_prayer(string keyword)
// make a word search function word_find_bible(string keyword)

class Plib{
    int Bindex;
    int Pindex;
    int Pcapacity;
    int Bcapacity;
    string* prayerArray;
    string* bibleArray;
    string* kWords;
    int* Parray;
    int* Barray;
    
    public:
    Plib();
    Plib(int capacity);
    ~Plib();
    void printMenu();
    void makeNull();
    void resize();
    void pushBack();
    void save();
    int ret_Pcapacity();
    int ret_Bcapacity();
    int ret_Bindex();
    int ret_Pindex();
    void uploadPrayerFromDoc(); 
    void wordFindPrayer(string keyword);
    void read_search();
    void resize_bible();
    void uploadBible();
    void wordFindBible(string keyword);
    void read_bible_search(int x);
    void keyWords();// fill string array with key words from latest prayer to look through the bible for.
};

#endif