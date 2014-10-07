#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string input;

int handle_isth(int i){
    //printf("i\n");
    if(i+3 > input.length()){
        return input.length();
    }
    if(input[i+1] != 'P'){
        return i;
    }
    if((input[i+2] == 'a' || input[i+2] == 'o') && input[i+3] == 'd'){
        printf("MAI MAI MAI!\n");
        return i+3;
    }
    else if(i+5 > input.length()){
        return input.length();
    }
    if(input[i+2] == 'h' && input[i+3] == 'o' && input[i+4] == 'n' && input[i+5] == 'e'){
        printf("MAI MAI MAI!\n");
        return i+4;
    }
}

int handle_apple(int i){
    //printf("A\n");
    if(i+4 > input.length()){
        return input.length();
    }
    if(input[i+1] == 'p' && input[i+2] == 'p' && input[i+3] == 'l' && input[i+4] == 'e'){
        printf("MAI MAI MAI!\n");
        return i+4;
    }
}

int handle_sony(int i){
    //printf("S\n");
    if(i+3 > input.length()){
        return input.length();
    }
    if(input[i+1] == 'o' && input[i+2] == 'n' && input[i+3] == 'y'){
        printf("SONY DAFA IS GOOD!\n");
        return i+3;
    }
}

int main(){
    while(cin >> input){
    //cout << input;
        int i;
        for(i = 0; i < input.length(); i++){
            if(input[i] == 'i'){
                i = handle_isth(i);
            }
            else if(input[i] == 'A'){
                i = handle_apple(i);
            }
            else if(input[i] == 'S'){
                i = handle_sony(i);
            }
        }
    }
    return 0;
}