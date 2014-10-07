#include <iostream>
using namespace std;

int main(){
    int A,B,n;
    cin >> A >> B >> n;
    int num[100];
    while(A != 0 || B != 0 || n != 0){

        num[1] = 1;
        num[2] = 1;
        
        for(int i = 3; i <= 48; i++){
            num[i] = (A*num[i-1] + B*num[i-2])%7;
            //num[(i+1)%2] = (A*num[i%2]+B*num[(i+1)%2])%7;
          //  cout<<num[(i+1)%2]<<"a"<<endl;
        }
        cout<<num[n%48]<<endl;
        cin >> A >> B >> n;
    }
    return 0;
}