# include <iostream>
# include <cstdio>
using namespace std;
long long t[200010];
long long n,k;
void work(long long id)
{
    long long i,j,m,u;
    cout<<"Case #"<<id<<": ";
    if (k>113000)m=113000;
    else m=k;
    t[1]=n;
    for (i=2;i<=m;i++)
        if (t[i-1]%i)t[i]=t[i-1]+(i-t[i-1]%i);
        else t[i]=t[i-1];
    if (k<=113000)cout<<t[m]<<endl;
    else cout<<k*(t[m]/m)<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    long long i=1;
    cin>>n>>k;
    while (!(n==0 && k==0))
    {
        work(i);
        cin>>n>>k;i++;
    }
    return 0;
}