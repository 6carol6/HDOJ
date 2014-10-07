#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T;
int start, end, maxSum;
string str;

void work(int index){
    start = end = 0;
    maxSum = -999999999;

    int tSum = 0;
    int tStart = 1;
    int count = 1;

    int num = 0;
    int num_count;
    cin >> num_count;
    for(int i = 0; i < num_count; i++){
        cin >> num;
        tSum += num;
        if(tSum > maxSum){
            maxSum = tSum;
            start = tStart;
            end = count;
        }
        if(tSum < 0){
            tSum = 0;
            tStart = count+1;
        }
        
        count++;
    }
   
    cout<<"Case "<<index<<":"<<endl;
    cout<<maxSum<<" "<<start<<" "<<end<<endl;
}

int main(){
    cin>>T;
    //char c = getchar();
    
    for(int i = 1;i < T; i++){
        work(i);
        cout<<endl;
    }
    work(T);
}