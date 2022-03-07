// Implementation of Shortest Job First, CPU Scheduling Algorithm
#include<iostream>
#include<iomanip>
using namespace std;
class Process{
    public:
    int p_id,a_time,b_time,f_time,tat,wt;
    bool x,y;
    Process(){
        x=false;
        y=false; // To see if the process has already been entertained or not
    }
    void getdata(){
        cout<<"-------------------------------\n";
        cout<<"P-id : ";
        cin>>p_id;
        cout<<"Arrival Time : ";
        cin>>a_time;
        cout<<"CPU burst Time : ";
        cin>>b_time;
        cout<<"-------------------------------\n";
    }
   
};
void TurnAroundTime(Process p[],int n){
    for(int i=0;i<n;i++){
        p[i].tat=p[i].f_time-p[i].a_time;
    }
}
void WaitingTime(Process p[],int n){
    for(int i=0;i<n;i++){
        p[i].wt=p[i].tat-p[i].b_time;
    }
}
void CalculateAverage(Process p[],int n){
    float avg1=0,avg2=0;
    for(int i=0;i<n;i++){
        avg1+=p[i].tat;
        avg2+=p[i].wt;
    }
    avg1=avg1/n;
    avg2=avg2/n;
    cout<<"Average Turn Around Time : "<<avg1<<endl;
    cout<<"Average Waiting Time : "<<avg2<<endl;
}
int FindMinimum(Process p[],int n,int sum){
    int min=sum;int res=-1;
    for(int i=0;i<n;i++){
        if(p[i].x==true&&p[i].b_time<min&&p[i].y==false){
            min=p[i].b_time;
            res=i;
        }
    }
    return res;
}
void FinishTime(Process p[],int n){
    int curr_time=0;
    bool flag=false;
    int i=0,j=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=p[i].b_time;
    }
    while(curr_time<sum){
        flag=false;
        while(i<n){
            if(p[i].a_time<=curr_time&&p[i].y==false){
                 p[i].x=true;
                 j++;
            }
            i++;
        }
        while(j>0){
            flag=true;
            int res=FindMinimum(p,n,sum);
            curr_time+=p[res].b_time;
            p[res].f_time=curr_time;
            p[res].x=false;
            p[res].y=true;
            j--;
        }
        if(flag==false){
            curr_time++;
        }
        i=j=0;
    }
    
}
int main(){
   int n;
   cout<<"Enter the total number of processes : ";
   cin>>n;
   Process obj[10];
   for(int i=0;i<n;i++){
       obj[i].getdata();
   }
   FinishTime(obj,n);
   TurnAroundTime(obj,n);
   WaitingTime(obj,n);
   cout<<endl;
    cout
        << left
        << setw(7)
        << "P_id"
        << left
        << setw(15)
        << "Arrival Time"
        << left
        << setw(20)
        << "CPU Burst Time"
        << left
        << setw(15)
        << "Finish Time"
        << left
        << setw(20)
        << "Turn Around Time"
        << left
        << setw(15)
        << "Waiting Time"
        << endl;

    for (int i = 0; i < n; i++)
    {
        cout
            << left
            << setw(7)
            << obj[i].p_id
            << left
            << setw(15)
            << obj[i].a_time
            << left
            << setw(20)
            << obj[i].b_time
            << left
            << setw(15)
            << obj[i].f_time
            << left
            << setw(20)
            << obj[i].tat
            << left
            << setw(15)
            << obj[i].wt
            << endl;
    }
    CalculateAverage(obj,n);
   return 0;
}
