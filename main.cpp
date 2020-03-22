#include <iostream>
#include <string>
#include "Plib.h"

using namespace std;


/*
# Things I might want:
figure out how to determine key words
key words to bible search
voice to text
biblical definitions
Linked list Geanealogy
*/
int main(){
    string input;
    Plib p(5);
    p.uploadBible();

    do{
        p.printMenu();
        cin >> input;
        if(input == "P"){
            p.uploadPrayerFromDoc();
            
            cout<<"Pray: "<<endl;
            p.pushBack(); // send it back in the array
            // the array will be an array of current prayers
            cout<<"saving to document..."<<endl;
            p.save();
            // saves to the document, to the bottom of the list
            cout<<"saved"<<endl;
        }
        else if(input == "SP"){
            p.uploadPrayerFromDoc();
            string searchWord;
            cout<<endl<<"Enter the word you're looking for: ";
            cin >> searchWord;
            cout<<endl;
            p.wordFindPrayer(searchWord);
            cout<<endl;
            p.read_search();
            //search for keywords through the document
        }
        else if(input == "SB"){
            string searchWord;
            int num;
            cout<<"enter word to search: ";
            cin>>searchWord;
            cout<<endl;
            p.wordFindBible(searchWord);
            
            cout<<"enter how many references you want: ";
            cin >> num;
            cout<<endl;
            p.read_bible_search(num);

        }else if(input == "K"){
            p.keyWords();
        }
        else if(input == "Q"){
            p.makeNull(); // will stop core from being dumped
            break;
        }   
    }
    while(input != "Q");
return 0;
}
