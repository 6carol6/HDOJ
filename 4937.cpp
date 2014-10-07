#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int count;

int is_lucky(int x){
    if(x == 3 || x == 4 || x == 5 || x == 6)
        return 1;
    return 0;
}

void work(){
    long long n;
    cin >> n;
    if(n == 3 || n == 4 || n == 5 || n == 6){
        count = -1;
        return;
    }
    map<long long, int> a_map;
    for(int i = 3; i <=6; i++){
        for(int j = 3; j <= 6; j++){
            double result = (double)(n-j)/i;
           // cout << n <<","<<i<<","<<j<<","<<result<<endl;
            if(result == (long long)result && result > i && result > j){
                //cout << result<<endl;
                a_map[result]++;
                //cout<<n<<" "<<(n-j)/i<<endl;
                //return;
            }
        }
    }
    //cout << a_map.size();
    for(int i = 3; i <= 6; i++){
        for(int j = 3; j <= 6; j++){
            for(int k = 3; k <= 6; k++){
                int temp = k-n;
                if(temp >= 0) continue;
                double delta = sqrt((double)(j*j-4*i*temp));
                double result = (delta-j)/(2*i);
                if(result != (long long)result) continue;
                if(result > i && result > j && result > k)
                    a_map[result]++;
            }
        }
    }
    //count+=a_map.size();
    //cout << a_map.size();
    for(int i = 4; i <=7000; i++){
        long long temp = n;
        while(temp/i){
            if(!is_lucky(temp%i))
                break;
            temp /= i;
        }
        if(temp/i == 0){
            if(is_lucky(temp%i)){
                a_map[i]++;
            }
        }
    }
    count+=a_map.size();
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        count = 0;
        work();
        cout << "Case #"<<i<<": "<<count<<endl;
    }
    return 0;
}