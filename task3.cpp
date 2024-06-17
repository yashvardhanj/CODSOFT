#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int chance=1;
int arr[3][3];

void drawBoard(){
    for(int i=0;i<3;i++){
        cout<<" _____ _____ ______"<<endl;
        cout<<"|     |     |      |"<<endl;
    }
    cout<<" _____ _____ ______"<<endl;
}

void askInput(){
    bool flag=false;
     int a,b;
    while(!flag){
       int a,b;
        cout<<"enter the co-ordinates of the points you want to mark";
        cin>>a>>b;
        if(arr[a][b]==100){
            flag=true;
            if(chance==1){
                arr[a][b]=1;
                chance--;
            }else{
                arr[a][b]=-1;
                chance++;
            }
            cout<<"thanks"<<endl;
        }else{
            cout<<"wrong input"<<endl;
        }
        
    }

}

int checkWin(){
    for(int i=0;i<3;i++){
        int sum1=0;
        int sum2=0;
        for(int j=0;j<3;j++){
            sum1+=arr[i][j];
            sum2+=arr[j][i];
        }
        if(sum1==3 || sum2==3){
            return 1;
        }else if(sum1==-3 || sum2==-3){
           return -1;
        }else{
            if((arr[0][0]+arr[1][1]+arr[2][2])==3||(arr[0][2]+arr[1][1]+arr[2][0])==3){
                return 1;
            }else if((arr[0][0]+arr[1][1]+arr[2][2])==-3||(arr[0][2]+arr[1][1]+arr[2][0])==-3){
                return -1;
            }
        }
    }
    return 0;
}

void drawSigns(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==1){
                for(int p=0;p<i;p++){
                    cout<<endl;
                }
                for(int p=0;p<i;p++){
                    cout<<"     ";
                }
                cout<<"X";
            }else if(arr[i][j]==-1){
                for(int p=0;p<i;p++){
                    cout<<endl;
                }
                for(int p=0;p<i;p++){
                    cout<<"     ";
                }
                cout<<"O";
            }
        }
    }
}

int checkSum(){
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

signed main(){
    drawBoard();
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=100;
        }
    }
    
    while(checkWin()!=1 ||checkWin()!=-1 ||checkSum()==1){
       drawBoard();
       drawSigns();
       askInput();
    }
    
    if(checkWin()==1){
        cout<<"X wins"<<endl;
    }else if(checkWin()==-1){
        cout<<"O wins"<<endl;
    }else{
        cout<<"Tie"<<endl;
    }
   
    
}