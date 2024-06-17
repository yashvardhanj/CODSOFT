#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

signed main(){
    cout<<"choose two numbers: "<<endl;
    int a,b;
    cin>>a>>b;
    
    bool flag;
    while(!flag){
    cout<<"enter the operation to perform";
    char c;
    cin>>c;
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='%'){
        flag=true;
        if(c=='+'){
            cout<<a+b;
        }else if(c=='-'){
            cout<<a-b;
        }else if(c=='*'){
            cout<<a*b;
        }else if(c=='/'){
            cout<<a/b;
        }else if(c=='^'){
            cout<<pow(a,b);
        }else{
            cout<<a%b;
        }
        cout<<c;
    }else{
        flag=false;
        cout<<"invalid operator";
    }
    }
    
    
    
    return 0;
}