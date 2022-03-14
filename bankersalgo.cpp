#include<iostream>
using namespace std;
void NeedMatrixCalc(int allocation[][],int max[][],int need[][],int m,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}
void CheckSafeState(int allocation[][],int need[][],int available[],int m,int n){
    int work[m];
    int sequence[n];
    int k=0;
    int flag=0;
    for(int i=0;i<m;i++){
        work[i]=available[i];
    }
    bool done[n];
    for(int i=0;i<n;i++){
        done[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(need[i][j]>work[j])
              break;
            else
              flag++;
        }
        if(flag==4){
            sequence[k]=i;
            k++;
            flag=0;
            for(int x=0;x<m;x++){
                work[x]+=allocation[i][x];
            }
            done[i]=true;
        }
        if(i==m-1&&j==n-1){
            for(int y=0;y<n;y++){
                if(done[y]==false)
                {
                    i=-1;
                    j=-1;
                    break;
                }
            }
        }
    }
    int dstate=0;
    for(int i=0;i<n;i++){
        if(done[i]==false){
            dstate=1;
            break;
        }
    }
    if(dstate==0){
        cout<<"System is in safe state!!"<<endl;
        cout<<"Required safe sequence :  "<<endl;
        for(int i=0;i<n;i++){
            cout<<sequence[i]<<"-->";
        }
    }
    else
    {
        cout<<"There is a deadlock!!"<<endl;
        cout<<"Processes creating deadlock are : "<<endl;
        for(int i=0;i<n;i++){
            if(done[i]==false){
                cout<<"P[ "<<i<<" ]"<<endl;
            }
        }
    }
}
int main(){
    int m,n; // n is the number of processes, m is the number of resources
    cout<<"Enter the number of processes : ";
    cin>>m;
    cout<<"Enter the number of resources : ";
    cin>>n;
    int allocation[n][m],max[n][m],need[n][m];
    int available[m];
    cout<<"Enter the values in allocation matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];
        }
    cout<<endl;
    }
    cout<<"Enter the values in max matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>max[i][j];
        }
    cout<<endl;
    }
    cout<<"Enter the values in the available array : ";
    for(int i=0;i<m;i++){
        cin>>available[i];
    }
    int need[m];
    NeedMatrixCalc(allocation,max,need,m,n);
    CheckSafeState(allocation,need,available,m,n);
    return 0;
}
