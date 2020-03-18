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
    int index;
    int capacity;
    string* array;
    int* Parray;
    int* Barray;
    string* searchArray;
    public:
    Plib();
    Plib(int capacity);
    ~Plib();
    void printMenu();
    void makeNull();
    void resize();
    void pushBack();
    void save();
    void uploadPrayerFromDoc(); 
    void wordFindPrayer(string keyword);
    void read_search();
    void resize_bible();
    void uploadBible();
    void wordFindBible(string keyword);
    void read_bible_search(int x);
};

#endif