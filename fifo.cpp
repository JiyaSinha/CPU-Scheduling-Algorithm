// Implementation of FIFO Page Replacement Algorithm
#include<iostream>
using namespace std;
bool LSearch(int a[],int x,int element){
    for(int i=0;i<x;i++){
        if(a[i]==element)
          return true;
    }
    return false;
}
int FIFO_Algo(int arr[],int m,int n){
    int frame[m];
    bool temp;
    int j=0,fault=0,flag=0;
    for(int i=0;i<n;i++){
        temp=LSearch(frame,m,arr[i]);
        if(temp==true){
            continue;
        }
        else{
            fault++;
            if(j<m){
                frame[j]=arr[i];
                j++;
            }
            else{
                frame[flag]=arr[i];
                flag++;
                if(flag==m){
                    flag=0;
                }
            }
        }
    }
    return fault;
}
int main(){
    int arr[30];
    int n=3,m=3;
    cout<<"Enter the number of elements in the string : ";
    cin>>n;
    cout<<"Enter the number of frames : ";
    cin>>m;
    cout<<"Enter the elements in the string : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x=FIFO_Algo(arr,m,n);
    cout<<"The number of Page Faults : "<<x<<endl;
    return 0;
}
