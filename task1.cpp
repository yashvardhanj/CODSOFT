#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

signed main(){
    int t = 1;
    cout<<"Enter the range of numbers you want to guess in:(inclusive) ";
    int a,b;
    cin>>a>>b;
    int num=((rand()%(b-a+1))+a);
    
    
    int guess=-1;
    do{
        cout<<"enter your guess"<<endl;
        cin>>guess;
        if((guess-num)>0){
            if((guess-num)>((b-a)/2)){
                cout<<"too high"<<endl;
            }else{
                cout<<"high"<<endl;
            }
        }else if((guess-num)<0){
             if((num-guess)>((b-a)/2)){
                cout<<"too low"<<endl;
            }else{
                cout<<"low"<<endl;
            }
            
        
        }else{
            cout<<"congrats you got the right number"<<endl;
        }
        
    }while(guess!=num);
    
    
    return 0;
}