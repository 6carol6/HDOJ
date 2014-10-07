#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N!=0){
        map<string, int> count;
        string b;
        for(int i = 0; i < N; i++){
            cin >> b;
            count[b]++;
        }
        int max = 0;
        string m_b_str;
        map<string, int>::iterator it;
        for(it=count.begin(); it!=count.end();it++){
            if(it->second > max){
                max = it->second;
                m_b_str = it->first;
            }
        }
        cout<<m_b_str<<endl;
        cin >> N;
    }
   // printf("%s\n", m_b_str);
    return 0;
}