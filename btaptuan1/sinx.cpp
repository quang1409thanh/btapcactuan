#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double x;
    cin>>x;
    const double PI_TEST = 3.14159265359;
    while(x>PI_TEST){
        x-=2*PI_TEST;
    }
    while(x<-PI_TEST){
        x+=2*PI_TEST;
    }
    double sum=x, old_sum=0;
    long long factorial=1;
    double exponential=x;
    int i=1;
    while(abs(sum-old_sum)>0.0001){
        old_sum=sum;
        exponential=exponential*(x*x);
        factorial=factorial*(2*i)*(2*i+1);
        sum+=(pow(-1,i)/(factorial))*exponential;
        i++;
    }
    cout<<i<<endl;
    cout<<fixed<<setprecision(4)<<sum<<endl;
    cout<<sin(x)<<endl;
    return 0;
}