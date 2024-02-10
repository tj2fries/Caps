#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Arts_Preps_Conjs.cpp"
#include <vector>

using namespace std;

string all_caps(string input){
    string output = input;
    for (int i = 0; i < input.length(); i++){
        if (96 < input[i] && input[i] < 123){
            output[i] = char(input[i] - 32);
        }
        else output[i] = char(input[i]);
    }
    return output;
}

string all_lower(string input){
    string output = input;
    for (int i = 0; i < input.length(); i++){
        if (64 < input[i] && input[i] < 91){
            output[i] = char(input[i] + 32);
        }
        else output[i] = char(input[i]);
    }
    return output;
}

string sentence(string input){
    string output = input;
    //ifstream fin ("words_alpha.txt");
    //if(!fin){
        //cout << "Unable to locate file";
        //return "Exit failure";
    //}
    //ifstream PnIn ("List of Proper Nouns.txt");
    //if(!PnIn){
        //cout << "Unable to locate file";
        //return "Exit failure";
    //}
    for (int i = 0; i < input.length(); i++){
        if (input[i-1] == 32||i == 0) {
            if (input[i-2] == 46||i == 0){
                if (96 < input[i] && input[i] < 123){
                    output[i] = char(input[i] - 32);
                }
            }
            else{
                if ((input[i] == 105 || input[i] == 73) && input[i+1] == 32){
                    output[i] = 'I';
                }
                else if (64 < input[i] && input[i] < 91){
                    output[i] = char(input[i] + 32);
                }
            }
            /*
            else{
                bool proper = false;
                char character = 'a';
                int a = 0;
                while (character != ' ' && character != '.' && character != ',' && character != ':' && character != ';'
                       && i+a-1 != input.length()){
                    character = input[i+a];
                    a++;
                }
                string word = input.substr(i,a-1);
                word = all_caps(word);
                string compare = "hi";
                PnIn.clear();
                PnIn.seekg(0, ios::beg);
                for (int i = 0; i < 370105; i++) {
                    PnIn >> compare;
                    if (word == compare) {
                        proper = true;
                    }
                }
                if (proper && 96 < input[i] && input[i] < 123){
                    output[i] = char(input[i] - 32);
                }
                else if (!proper && 64 < input[i] && input[i] < 91){
                    output[i] = char(input[i] + 32);
                }
            }
             */
        }
        else if (64 < input[i] && input[i] < 91){
            output[i] = char(input[i] + 32);
        }
        else output[i] = char(input[i]);
    }
    //fin.close();
    return output;
}

string title(string input){
    string output = input;
    for (int i = 0; i < input.length(); i++){
        if (input[i-1] == 32||i == 0){
            bool small = false;
            char character = 'a';
            int a = 0;
            while (character != ' ' && character != '.' && character != ',' && character != ':' && character != ';'
                   && i+a-1 != input.length()){
                character = input[i+a];
                a++;
            }
            string word = input.substr(i,a-1);
            word = all_lower(word);
            for (int i = 0; i < 29; i++) {
                if (word == smalls[i]) {
                    small = true;
                }
            }
            if (!small && 96 < input[i] && input[i] < 123){
                output[i] = char(input[i] - 32);
            }
            else if (small && 64 < input[i] && input[i] < 91){
                output[i] = char(input[i] + 32);
            }
        }
        else if (64 < input[i] && input[i] < 91){
            output[i] = char(input[i] + 32);
        }
        else output[i] = char(input[i]);
    }
    return output;
}

int main(){
    int func;
    cout << "input a string" << endl;
    string input;
    getline(cin, input);
    cout << "what do you want to do" << endl
         << "[1] ALL CAPS" << endl
         << "[2] all lowercase" << endl
         << "[3] Sentence case" << endl
         << "[4] Title Case" << endl;
    cin >> func;
    if (func == 1){
        cout << all_caps(input);
    }
    else if (func == 2){
        cout << all_lower(input);
    }
    else if (func == 3){
        cout << sentence(input);
    }
    else{
        cout << title(input);
    }
}