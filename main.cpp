#include <iostream>
#include <string>
#include "Plib.h"

using namespace std;


/*
# Problems I'm facing:
make own file csv that has a text version of the bible.
Need to take in dumb input
# Things I might want:
if i make my prayer finder 2d array i can use the first input the row, or the day, and then i can use the second for the index of the prayer in the string
Delete prayer function
figure out upload function
adding date and time at the beginning of prayer for sorting
figure out how to determine key words
voice to text
verse identification
biblical definitions
character referrences
gooey?
how to deploy
how to add voice in reading bible or response
ai part?
*/
int main(){
    string input;
    cout<<"howdy"<<endl;
    Plib p(5);
    do{
        p.printMenu();
        cin >> input;
        if(input == "P"){
            cout<<"Pray: "<<endl;
            p.pushBack(); // send it back in the array
            // the array will be an array of current prayers
            cout<<"saving to document"<<endl;
            p.save();
            // saves to the document, to the bottom of the list
            cout<<"saved"<<endl;
        }
        else if(input == "SP"){
            string searchWord;
            p.uploadPrayerFromDoc();
            cout<<endl<<"Enter the word you're looking for: ";
            cin >> searchWord;
            cout<<endl;
            p.wordFindPrayer(searchWord);
            cout<<"after found"<<endl;
            p.read_search();
            //search for keywords through the document
        }
        else if(input == "SB"){
            string searchWord;
            int num;
            
            p.uploadBible();
            cout<<"enter word to search"<<endl;
            cin>>searchWord;
            cout<<endl;
            
            p.wordFindBible(searchWord);
            cout<<"enter how many references you want"<<endl;
            cout<<"after found: "<<endl;
            cin >> num;
            p.read_bible_search(num);

        }else if(input == "Q"){
            p.makeNull(); // will stop core from being dumped
            break;
        }
        
        
    }
    while(input != "Q");
return 0;
}
